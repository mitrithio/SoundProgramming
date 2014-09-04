#include "OutputVideoController.h"
#include <iostream>
#include "al.h"
#include <ostream>


OutputVideoController::OutputVideoController()
{
}

OutputVideoController::~OutputVideoController()
{
}

void OutputVideoController::ShowState( int i_iState, int i_iSource /*= -1*/, int i_iBuffer /*= -1 */, const char* i_szFileName /*= nullptr */ )
{
	using namespace std;
	switch (i_iState)
	{
	case AL_PLAYING:
		cout << "Playing";
		break;
	case AL_PAUSED:
		cout << "Pausing";
		break;
	case AL_STOPPED:
		cout << "Stop";
		break;
	default:
		break;
	}

	if ( i_szFileName )
	{
		if ( i_iSource >= 0 )
		{
			cout << " Source " << i_iSource << " (" << i_szFileName << ")";
		}
		else
		{
			cout << " File " << i_szFileName;
		}
	}
	else
	{
		if ( i_iSource >= 0 )
		{
			cout << " Source " << i_iSource;
		}
	}

	if ( i_iBuffer >= 0)
	{
		cout << " on Buffer " << i_iBuffer << endl;
	}
	else
	{
		cout << endl;
	}
}

void OutputVideoController::ShowMenu()
{
	using namespace std;

	cout << "----------    MENU    ----------" << endl;
	cout << " Choose a voice and then press" << endl;
	cout << " the relative button!" << endl;
	cout << "--------------------------------" << endl;
	cout << " 1. Play Static!" << endl;
	cout << " 2. Effects Test" << endl;
	cout << " 0. Exit" << endl;
}

void OutputVideoController::SHOW_MESSAGE( const char* i_szString )
{
	std::cout << i_szString << std::endl;
}

void OutputVideoController::SHOW_MESSAGE_NOENDL( const char* i_szString )
{
	std::cout << i_szString;
}
