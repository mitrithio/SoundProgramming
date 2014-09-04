#include <Windows.h>
#include "AudioController.h"
#include "AudioWrapper.h"
#include "InputController.h"
#include "OutputVideoController.h"

const char* AudioController::TEST_WAVE_FILE( "Engine_sfx.wav" );

AudioController::AudioController()
{
	m_pAudioWrapper = new AudioWrapper();
	m_pInputController = new InputController();
	m_pOutputController = new OutputVideoController();
}

AudioController::~AudioController()
{
	delete m_pAudioWrapper;
	delete m_pInputController;
	delete m_pOutputController;
}

ACRESULT AudioController::Start()
{
	m_eCurrentState = AC_MENU;

	if ( !m_pAudioWrapper->InitFramework() )
	{
		OutputVideoController::SHOW_MESSAGE( "Failed to initialize Framework OpenAL" );
		return AC_ERROR;
	}

	m_uiBuffer = m_pAudioWrapper->GenerateBuffer();

	m_uiSource = m_pAudioWrapper->GenerateSource();

	return AC_OK;
}

ACRESULT AudioController::Update()
{
	switch ( m_eCurrentState )
	{
	case AC_MENU:
		break;
	case AC_STATIC:
		break;
	case AC_EFFECTS:
		break;
	default:
		break;
	}

	m_pOutputController->ShowMenu();

	unsigned int uiInput = m_pInputController->GetMenuValidInput();
	if ( uiInput == BTN_0 )
	{
		return AC_EXIT;
	}
	else if ( uiInput == BTN_1 )
	{
		return PlayStatic();
	}
	else if ( uiInput == BTN_2 )
	{
		return PlayEffects();
	}

	OutputVideoController::SHOW_MESSAGE( "Input NOT found" );
	return AC_ERROR;
}

ACRESULT AudioController::Exit()
{
	m_pAudioWrapper->UnloadResources();
	return AC_OK;
}

ACRESULT AudioController::PlayStatic()
{
	if ( m_pAudioWrapper->LoadStatic( TEST_WAVE_FILE, m_uiSource ) )
	{
		OutputVideoController::SHOW_MESSAGE_NOENDL( "Load completed: " );
		OutputVideoController::SHOW_MESSAGE( TEST_WAVE_FILE );
	}
	else
	{
		OutputVideoController::SHOW_MESSAGE_NOENDL( "Error loading file" );
		return AC_ERROR;
	}

	m_pAudioWrapper->AttachSourceToBuffer( m_uiSource, m_uiBuffer );

	m_pOutputController->ShowState( m_pAudioWrapper->GetSourceState(), m_uiSource, m_uiBuffer, TEST_WAVE_FILE );
	do
	{
		Sleep( 500 );
		OutputVideoController::SHOW_MESSAGE_NOENDL( "." );
	} while ( m_pAudioWrapper->GetSourceState() == AL_PLAYING );
	OutputVideoController::SHOW_MESSAGE( "." );
	return AC_CONTINUE;
}

ACRESULT AudioController::PlayEffects()
{

}

namespace States
{
	// STATE MAIN MENU
	void MainMenu::OnEnter()
	{
	
	}

	void MainMenu::Update()
	{
	}

	void MainMenu::OnExit()
	{
	}

	// STATE STATIC PLAY
	void Static::OnEnter()
	{
	}

	void Static::Update()
	{
	}

	void Static::OnExit()
	{
	}

	// STATE EFFECTS PLAY
	void Effects::OnEnter()
	{
	}

	void Effects::Update()
	{
	}

	void Effects::OnExit()
	{
	}

}