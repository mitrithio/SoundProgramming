#pragma once

class AudioWrapper;
class InputController;
class OutputVideoController;

enum ACRESULT
{
	AC_EXIT		= 1,
	AC_CONTINUE = 2,
	AC_OK		= 10,
	AC_ERROR	= 11
};

enum ACSTATES
{
	AC_MENU		= 1,
	AC_STATIC	= 2,
	AC_EFFECTS	= 3
};

class AudioController
{
public:
	AudioController();
	~AudioController();

	ACRESULT Start();
	ACRESULT Update();
	ACRESULT Exit();

private:

	ACRESULT PlayStatic();
	ACRESULT PlayEffects();

private:
	AudioWrapper*			m_pAudioWrapper;
	InputController*		m_pInputController;
	OutputVideoController*	m_pOutputController;

	unsigned int m_uiState;
	unsigned int m_uiSource;
	unsigned int m_uiBuffer;

	ACSTATES m_eCurrentState;

	static const char* TEST_WAVE_FILE;
};

namespace States
{
	class State
	{
	public:
		virtual void OnEnter() = 0;
		virtual void Update() = 0;
		virtual void OnExit() = 0;
	};

	class MainMenu : public State
	{
	public:
		MainMenu();
		~MainMenu();

		virtual void OnEnter();

		virtual void Update();

		virtual void OnExit();

	private:
	};

	class Static : public State
	{
	public:
		Static();
		~Static();

		virtual void OnEnter();

		virtual void Update();

		virtual void OnExit();

	};

	class Effects : public State
	{
	public:
		Effects();
		~Effects();

		virtual void OnEnter();

		virtual void Update();

		virtual void OnExit();

	};
}