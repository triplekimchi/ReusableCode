#pragma once
#include <winsock2.h>
#include <ws2tcpip.h>
#include <iphlpapi.h>
#include <iostream>
#include <string>

#pragma comment(lib, "iphlpapi.lib")
#pragma comment(lib, "ws2_32.lib")

struct in_addr addr;

void ListTcpConnection()
{
	MIB_TCPTABLE_OWNER_PID *tcp_pid;
	MIB_TCPROW_OWNER_PID *owner_pid;
	DWORD size;
	DWORD dresult;

	dresult = GetExtendedTcpTable(NULL, &size, FALSE, AF_INET, TCP_TABLE_OWNER_PID_ALL, NULL);

	if(dresult < 0)
	{
		std::cout << "GetExtendedTcpTable failed" << std::endl;
		return;
	}

	tcp_pid = new MIB_TCPTABLE_OWNER_PID[size];
	dresult = GetExtendedTcpTable(tcp_pid, &size, FALSE, AF_INET, TCP_TABLE_OWNER_PID_ALL, NULL);

	for(int i = 0; i < tcp_pid->dwNumEntries; ++i)
	{
		owner_pid = &tcp_pid->table[i];

		std::cout << "pid = \t" << owner_pid->dwOwningPid;
		addr.S_un.S_addr = (unsigned long)owner_pid->dwLocalAddr;
		std::cout << "\t\tlocal addr = " << inet_ntoa(addr);
		addr.S_un.S_addr = (unsigned long)owner_pid->dwRemoteAddr;
		std::cout << "\t\t\tremot addr = " << inet_ntoa(addr) << std::endl;
	}

	delete[] tcp_pid;
}
