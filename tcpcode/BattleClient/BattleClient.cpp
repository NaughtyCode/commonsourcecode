#include "stdafx.h"


int main(int argc, char* argv[])
{
	WSADATA wsaData;
	int iResult = WSAStartup(MAKEWORD(2, 2), &wsaData);
	if (iResult != NO_ERROR) {
		printf("winsock初始化失败: %ld\n", iResult);
		return 1;
	}

	SOCKET ClientSocket;
	ClientSocket = socket(AF_INET, SOCK_STREAM, 0);
	if (ClientSocket == INVALID_SOCKET){
		WSACleanup();
		printf("创建连接套接字失败\n");
		return 1;
	}

	sockaddr_in connectddr;
	connectddr.sin_family = AF_INET;
	connectddr.sin_port = 12000;
	connectddr.sin_addr.s_addr = inet_addr("127.0.0.1");

	if (connect(ClientSocket, (sockaddr*)&connectddr, sizeof(sockaddr_in)) != 0){
		closesocket(ClientSocket);
		WSACleanup();
		printf("连接服务器失败\n");
		return 1;
	}

	printf("开始数据传输\n");
	int buffer[2] = {0};
	int size = sizeof(int)* 2;
	while (true){
		if (size == recv(ClientSocket, (char*)&buffer[0], size, 0)){
			printf("（%d，%d）\n", buffer[0], buffer[1]);
		}
		buffer[0] = 100;
		buffer[1] = 200;
		send(ClientSocket, (char*)&buffer, size, 0);
	}

	closesocket(ClientSocket);
	WSACleanup();
	Sleep(10000);
	return 0;
}
