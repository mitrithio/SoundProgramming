#include "InputController.h"
#include <iostream>
#include "OutputVideoController.h"

InputController::InputController()
{
}

InputController::~InputController()
{
}

int InputController::GetMenuValidInput()
{
	m_eCurrentInput = NONE;
	while ( m_eCurrentInput == NONE )
	{
		WaitForInput();
		switch ( m_eCurrentInput )
		{
		case BTN_0:
		case BTN_1:
		case BTN_2:
			break;
		default:
			m_eCurrentInput = NONE;
			break;
		}
	}
	return m_eCurrentInput;
}

void InputController::WaitForInput()
{
	OutputVideoController::SHOW_MESSAGE( "\nWaiting for an input: ");
	char cInput;
	std::cin >> cInput;
	m_eCurrentInput = int(cInput);
}

int InputController::GetEffectsMenuValidInput()
{
	m_eCurrentInput = NONE;
	while ( m_eCurrentInput == NONE )
	{
		WaitForInput();
		switch ( m_eCurrentInput )
		{
		case BTN_P:
		case BTN_p:
		case BTN_S:
		case BTN_s:
			break;
		default:
			m_eCurrentInput = NONE;
			break;
		}
	}
	return m_eCurrentInput;
}
