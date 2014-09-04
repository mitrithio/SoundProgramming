#pragma once

class OutputVideoController
{
public:
	OutputVideoController();
	~OutputVideoController();

	void ShowState( int i_iState, int i_iSource = -1, int i_iBuffer = -1, const char* i_szFileName = nullptr );
	void ShowMenu();

	static void SHOW_MESSAGE( const char* i_szString );
	static void SHOW_MESSAGE_NOENDL( const char* i_szString );
};