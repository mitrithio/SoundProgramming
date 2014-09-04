#include <windows.h>
#include "vld.h"
// #include "al.h" 
// #include "alc.h"
// #include "Code\Framework\Framework.h"
// #include "Code\AudioWrapper.h"
#include <iostream>
#include "Code\AudioController.h"

// #define	TEST_WAVE_FILE		"Engine_sfx.wav"

int main()
{
	AudioController oAudioController;

	ACRESULT eResult = oAudioController.Start();

	while ( eResult != AC_EXIT && eResult != AC_ERROR ) 
	{
		eResult = oAudioController.Update();
	}

	if ( eResult == AC_ERROR )
	{
		return -1;
	}

	oAudioController.Exit();

	return 0;
}