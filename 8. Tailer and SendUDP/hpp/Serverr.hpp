#ifndef SERVERR_H
#define SERVERR_H


#include <winsock2.h>
#include <windows.h> // Sleep()
#include <iostream>
#include <cstdio>
#include <thread>


class Serverr {
    WSADATA wsaData{};

public:
    std::string address;
    int port;
    sockaddr_in sockAddre{};
    SOCKET sock = INVALID_SOCKET;
    SOCKET clientSocket = INVALID_SOCKET;
    sockaddr_in clientAddr{};

    Serverr() {
        initSocket();
        createSocket();
        configureSocket();
        bindSocket();
        listenSocket();
        acceptConnection();
        //receiveBytes();
    }

    ~Serverr() {
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

    void listenSocket() {
        if (listen(sock, SOMAXCONN) == SOCKET_ERROR) {
            //log.printError("Listen failed");
            closesocket(sock);
            WSACleanup();
        }
        //log.printInfo("[Server] In ascolto su " + address + ":" + std::to_string(port));
        std::cout << ("[Server] In ascolto su " + address + ":" + std::to_string(port));
    }

    void bindSocket() {
        if (bind(sock, (sockaddr*)&sockAddre, sizeof(sockAddre)) == SOCKET_ERROR) {
            // Se un altro processo ha già preso quella porta → errore!
            //log.printError("Bind Failed");
            std::cerr << "Bind failed\n";
            closesocket(sock);
            WSACleanup();
        }
    }

    /*static void handleClient(SOCKET clientSock) {
        char oneByte;
        int bytesRead;
        std::vector<char> packNet;
        PacketParser parser;

        std::cout << "[THREAD] Gestione client avviata.\n";

        while ((bytesRead = recv(clientSock, &oneByte, 1, 0)) > 0) {
            std::cout << "[Socket] ID: " << clientSock << std::endl;
            printf("[BYTE] 0x%02X\n", static_cast<unsigned char>(oneByte));
            packNet.push_back(static_cast<unsigned char>(oneByte));

            if (packNet.size() == 6) {
                parser.decodeAndRecreatePacket(packNet);
                packNet.clear();
            }
        }

        std::cout << "[THREAD] Connessione client terminata.\n";
        closesocket(clientSock);  // Chiude solo la socket del singolo client
    }*/

    void acceptConnection() {
        int clientSize = sizeof(clientAddr);
        // Blocca l’esecuzione fino a che un client si connette
        // Quando un client arriva, viene creata una nuova socket per quella connessione specifica (clientSocket)
        // serverSocket resta libero per accettare altri client (non usato qui, ma importante saperlo)

        while (true) {
            this->clientSocket = accept(sock, (sockaddr*)&clientAddr, &clientSize);
            if (this->clientSocket == INVALID_SOCKET) {
                std::cerr << "Accept failed\n";
                closesocket(sock);
                WSACleanup();
            }
            else {
                // Lancia un thread per gestire quel client
                std::cout << "[Server] Connessione accettata da: " << inet_ntoa(clientAddr.sin_addr) << "\n";
                //std::thread t(handleClient, newClientSocket);
                //t.detach(); // oppure tieni traccia dei thread
                receiveBytes();
            }
        }
        //  Dopo accept(), puoi inviare/ricevere dati dal client.

    }

    void receiveBytes() {
        /*
        - Legge 1 byte alla volta dalla connessione TCP
        - recv() blocca finché riceve qualcosa
        - Stampa ogni byte ricevuto in esadecimale (es: 0xA5, 0x04...)
        */
        int i = 0;
        char byte;
        int bytesRead;
        while ((bytesRead = recv(clientSocket, &byte, 1, 0)) > 0) {
            printf("[BYTE] 0x%02X\n", static_cast<unsigned char>(byte));
            printf("char=%c hex=0x%02X dec=%3u\n", (unsigned char)byte, (unsigned char)byte, (unsigned char)byte);
        }

        printf("\n\n");
    }


    void closeConnection() {
        if (this->clientSocket != INVALID_SOCKET) closesocket(this->clientSocket);
        if (sock != INVALID_SOCKET) closesocket(sock);
        WSACleanup();
    }

};

#endif