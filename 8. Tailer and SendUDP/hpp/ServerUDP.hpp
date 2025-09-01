// Serverr.hpp (versione UDP essenziale)
#include <winsock2.h>
#include <Ws2tcpip.h>   // opzionale per inet_pton
#include <iostream>

class Serverr {
    WSADATA wsaData{};
public:
    std::string address;
    int port;
    sockaddr_in sockAddre{};
    SOCKET sock = INVALID_SOCKET;

    Serverr() {
        initSocket();
        createSocket();
        configureSocket();
        bindSocket();
        receiveLoop();           // <-- niente listen/accept
    }
    ~Serverr() { closeAll(); }

    void initSocket() {
        if (WSAStartup(MAKEWORD(2, 2), &wsaData) != 0)
            std::cerr << "WSAStartup failed\n";
    }

    void createSocket() {
        sock = socket(AF_INET, SOCK_DGRAM, IPPROTO_UDP);
        if (sock == INVALID_SOCKET) { std::cerr << "socket() failed\n"; WSACleanup(); }
    }
    
    void setAddressAndPort(const std::string& addr, int p) { address = addr; port = p; }
    
    void configureSocket() {
        setAddressAndPort("127.0.0.1", 5514);            // meglio porta alta
        sockAddre.sin_family = AF_INET;
        sockAddre.sin_addr.s_addr = inet_addr(address.c_str());
        sockAddre.sin_port = htons(port);
    }
    
    void bindSocket() {
        if (bind(sock, (sockaddr*)&sockAddre, sizeof(sockAddre)) == SOCKET_ERROR) {
            std::cerr << "bind() failed\n"; closesocket(sock); WSACleanup();
        }
        std::cout << "[UDP Server] bind su " << address << ":" << port << "\n";
    }

    void receiveLoop() {
        char buf[4096];
        sockaddr_in src{};
        int srclen = sizeof(src);
        for (;;) {
            int n = recvfrom(sock, buf, sizeof(buf), 0, (sockaddr*)&src, &srclen);
            if (n == SOCKET_ERROR) { std::cerr << "recvfrom error\n"; continue; }

            std::cout << "[from " << inet_ntoa(src.sin_addr) << ":" << ntohs(src.sin_port) << "] ";
            std::cout.write(buf, n);                      // stampa come testo (se è testo)
            std::cout << "\n";

            // se vuoi anche il dump hex dei byte:
            // for (int i=0;i<n;++i) printf("%02X ", (unsigned char)buf[i]); printf("\n");
        }
    }

    void closeAll() { if (sock != INVALID_SOCKET) closesocket(sock); WSACleanup(); }
};
