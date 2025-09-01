#ifndef CLIENTT_H
#define CLIENTT_H


#include <winsock2.h>
#include <windows.h> // Sleep()
#include <iostream>
#include <cstdio>


class Clientt {
    WSADATA wsaData{};

public:
    std::string address;
    int port;
    sockaddr_in sockAddre{};
    SOCKET sock = INVALID_SOCKET;

    Clientt() {
        initSocket();
        createSocket();
        configureSocket();
        bindSocket();
    }

    ~Clientt() {
        closeConnection();
    }

    
    // inizializza Winsock
    void initSocket() {
        /*
        - Avvia Winsock, il sistema di gestione delle socket su Windows
        - MAKEWORD(2,2) richiede la versione 2.2
        - wsaData è una struttura dove il sistema scrive informazioni di stato

        Obbligatoria prima di usare qualsiasi funzione di rete su Windows.
        */
        int err = WSAStartup(MAKEWORD(2, 2), &wsaData);
        if (err != 0) {
            //log.printError(string("WSAStartup failed: " + err));
            std::cerr << "WSAStartup failed: " << err << "\n";
        }
    }              

    void createSocket() {
        /*
        - AF_INET: famiglia IPv4
        - SOCK_STREAM: socket di tipo stream, cioè TCP
        - IPPROTO_TCP: protocollo TCP
        Creazione "file descriptor" che rappresenta un canale di comunicazione in rete.
        */
        sock = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP);
        if (sock == INVALID_SOCKET) {
            //log.printError("Socket creation failed\n");
            std::cerr << "Socket creation failed\n";
            WSACleanup();
        }
    }

    void setAddressAndPort(const std::string& addr, int p) {
        this->address = addr;
        this->port = p;
    }

    // setta indirizzo IP/porta 
    void configureSocket() {
        setAddressAndPort("127.0.0.1", 3000);
        sockAddre.sin_family = AF_INET;                        // IPv4 (AF_INET)   
        sockAddre.sin_addr.s_addr = inet_addr(address.c_str());    // IP locale (localhost)
        sockAddre.sin_port = htons(port);                      // porta 3000 (convertita in network byte order con htons)
    }      

    void bindSocket() {
        if (connect(sock, (sockaddr*)&sockAddre, sizeof(sockAddre)) == SOCKET_ERROR) {
            std::cerr << "Connection failed\n";
            closesocket(sock);
            WSACleanup();
        }
        std::cout << "[CLIENT] Connesso al server.\n";
    }
    
    void sendSocket(std::string message) {
        send(sock, reinterpret_cast<const char*>(message.c_str()), static_cast<int>(message.size()), 0);
        Sleep(100);
    }

    void closeConnection() {
        closesocket(sock);
        WSACleanup();
    }

};

#endif