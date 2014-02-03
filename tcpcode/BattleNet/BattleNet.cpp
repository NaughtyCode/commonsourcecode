#include "stdafx.h"

int main(int argc,const char* argv[])
{
	WSADATA wsaData;
	int iResult = WSAStartup(MAKEWORD(2, 2), &wsaData);
	if (iResult != NO_ERROR) {
		printf("winsock初始化失败: %ld\n", iResult);
		return 1;
	}
	
	SOCKET ListenSocket;
	ListenSocket = socket(AF_INET, SOCK_STREAM, 0);
	if (ListenSocket == INVALID_SOCKET){
		WSACleanup();
		printf("创建监听套接字失败\n");
		return 1;
	}

	sockaddr_in serverddr;
	serverddr.sin_family = AF_INET;
	serverddr.sin_port = 12000;
	serverddr.sin_addr.s_addr = inet_addr("127.0.0.1");
	if (bind(ListenSocket, (sockaddr*)&serverddr, sizeof(sockaddr_in)) != 0){
		closesocket(ListenSocket);
		WSACleanup();
		printf("绑定套接字失败\n");
		return 1;
	}

	listen(ListenSocket,1024);

	SOCKET ClientSocket;
	sockaddr_in clientddr;
	int addrlen = sizeof(sockaddr_in);
	ClientSocket = accept(ListenSocket, (sockaddr*)&clientddr, &addrlen);
	if (ClientSocket == INVALID_SOCKET){
		printf("接受客户端连接失败\n");
		closesocket(ListenSocket);
		WSACleanup();
	}
	printf("开始数据传输\n");
	char buffer[2048];
	int protoid = 1;
	int data = 120;
	memcpy(buffer, &protoid,sizeof(int));
	memcpy(buffer + sizeof(int), &data, sizeof(int));
	int size = sizeof(int)* 2;
	int recvdata[2] = { 0 };
	while (true){
		send(ClientSocket, buffer, size, 0);

		if (size == recv(ClientSocket, (char*)recvdata, size, 0)){
			printf("（%d，%d）\n", recvdata[0],recvdata[1]);
		}

	}


	printf("数据传输结束\n");
	closesocket(ListenSocket);
	WSACleanup();
	Sleep(10000);
	return 0;
}

