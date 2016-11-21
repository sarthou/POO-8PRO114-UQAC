#pragma once

#ifndef MUTEX_H
#define MUTEX_H

#include<windows.h>

class Mutex 
{
public:
	Mutex() { m_mutex = CreateMutex(NULL, false, NULL); };
	~Mutex() {};

	void synchroniser() { WaitForSingleObject(m_mutex, INFINITE); };

	void liberer() { ReleaseMutex(m_mutex); };

private:
	HANDLE m_mutex;
};

#endif

