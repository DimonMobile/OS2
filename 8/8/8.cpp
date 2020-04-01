#include <iostream>
#include <fstream>

#include <Windows.h>

HANDLE hThread;
DWORD IDThread;
DWORD dwRet;

bool threadStarter;

void CALLBACK a_proc(DWORD p)
{
	int n;
	DWORD* ptr = (DWORD*)p;
	std::cout << "The async proc is called!" << std::endl;
	std::cout << "Input integer:";
	std::cin >> n;
	*ptr += n;
	std::cout << "The async proc returned!!" << std::endl;
}


DWORD WINAPI add(LPVOID ptr)
{
	DWORD* zz = (DWORD*)ptr;
	std::cout << "Thread says: initial count is " << *zz << std::endl;
	SleepEx(INFINITE, TRUE);
	std::cout << "Thread says: Final count from async proc is " << *zz << std::endl;
	getchar();
	return 0;
}

void CALLBACK write(DWORD p)
{
	std::cout << __FUNCSIG__ << std::endl;
	std::ofstream stream("output.txt");
	stream << "123" << std::endl;
}

void CALLBACK read(DWORD p)
{
	std::cout << __FUNCSIG__ << std::endl;
	std::string line;
	std::ifstream stream("output.txt");
	stream >> line;
	std::cout << "Readed from file: " << line << std::endl;
}

DWORD WINAPI test(LPVOID ptr)
{
	threadStarter = false;
	std::cout << __FUNCSIG__ << std::endl;
	std::cout << "Thread started" << std::endl;
	SleepEx(INFINITE, TRUE);
	std::cout << "Thread finished" << std::endl;
	return 0;
}


int main()
{
	threadStarter = true;
	std::cout << __FUNCSIG__ << std::endl;
	DWORD count = 10;

	hThread = CreateThread(NULL, 0, test, nullptr, 0, &IDThread);
	while (threadStarter) {}
	QueueUserAPC(write, hThread, NULL);
	QueueUserAPC(read, hThread, NULL);

	std::cout << "Before wait" << std::endl;
	WaitForSingleObject(hThread, INFINITE);
	std::cout << "After wait" << std::endl;

	CloseHandle(hThread);


	/*hThread = CreateThread(NULL, 0, add, &count, 0, &IDThread);
	Sleep(100);
	dwRet = QueueUserAPC(a_proc, hThread, (DWORD)&count);
	dwRet = QueueUserAPC(a_proc, hThread, (DWORD)&count);
	WaitForSingleObject(hThread, INFINITE);
	CloseHandle(hThread);*/

	// The second thread
	/*CreateThread(NULL, 0, add, &count, 0, &IDThread);
	Sleep(100);
	dwRet = QueueUserAPC(a_proc, hThread, (DWORD)&count);
	dwRet = QueueUserAPC(a_proc, hThread, (DWORD)&count);
	WaitForSingleObject(hThread, INFINITE);
	CloseHandle(hThread);*/
	getchar();
	return 0;
}
