// Clientt.hpp (versione UDP essenziale)
#include <winsock2.h>
#include <iostream>

class Clientt {
    WSADATA wsaData{};

public:
    std::string address;
    int port;
    sockaddr_in dst{};
    SOCKET sock = INVALID_SOCKET;

    Clientt() {
        WSAStartup(MAKEWORD(2, 2), &wsaData);
        sock = socket(AF_INET, SOCK_DGRAM, IPPROTO_UDP);
        address = "127.0.0.1"; port = 5514;

        dst.sin_family = AF_INET;
        dst.sin_addr.s_addr = inet_addr(address.c_str());
        dst.sin_port = htons(port);

        std::cout << "[UDP Client] pronto verso " << address << ":" << port << "\n";
    }
    
    ~Clientt() { if (sock != INVALID_SOCKET) closesocket(sock); WSACleanup(); }

    void sendSocket(const std::string& message) {
        sendto(sock, message.data(), (int)message.size(), 0, (sockaddr*)&dst, sizeof(dst));
    }
};
