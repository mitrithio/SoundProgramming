#pragma once

class InputController
{
public:
	InputController();
	~InputController();

	int GetMenuValidInput();
	int GetEffectsMenuValidInput();

private:
	void WaitForInput();

private:
	int	m_eCurrentInput;

};

enum InputDefinition
{
	NONE = -1,
	BTN_0 = 48,
	BTN_1,
	BTN_2,
	BTN_P = 80,
	BTN_S = 83,
	BTN_p = 112,
	BTN_s = 115
};