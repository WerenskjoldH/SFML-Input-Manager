#include "InputManager.h"
#include <iostream>

InputManager* InputManager::pInstance = NULL;

InputManager* InputManager::Instance()
{
	if (pInstance == NULL)
		pInstance = new InputManager;

	return pInstance;
}

InputManager::InputManager() {
	// Initialization
}

// Checks if key is bound
bool InputManager::IsBound(int k)
{
	if (InputManager::KeyboardBinds.find(k) != InputManager::KeyboardBinds.end())
		return true;
	return false;
}

// Is key down
bool InputManager::KeyDown(int code)
{
	if (!IsBound(code))
		return false;

	if (InputManager::KeyboardBinds.find(code)->second.curState)
		return true;

	return false;
}

// Is key up
bool InputManager::KeyUp(int code)
{
	if (!IsBound(code))
		return false;

	if (!InputManager::KeyboardBinds.find(code)->second.curState)
		return true;

	return false;
}
// On key press
bool InputManager::KeyPress(int code)
{
	if (!IsBound(code))
		return false;

	if (InputManager::KeyboardBinds.find(code)->second.prevState == 0 && InputManager::KeyboardBinds.find(code)->second.curState == 1)
		return true;

	return false;
}

// On key release
bool InputManager::KeyRelease(int code)
{
	if (!IsBound(code))
		return false;

	if (InputManager::KeyboardBinds.find(code)->second.prevState == 1 && InputManager::KeyboardBinds.find(code)->second.curState == 0)
		return true;

	return false;
}

// Binds a reference number to a key
void InputManager::KBind(int code, sf::Keyboard::Key key)
{
	if (InputManager::IsBound(code))
		InputManager::KeyboardBinds.find(code)->second.key = key;
	else
		InputManager::KeyboardBinds.insert(std::make_pair(code, key));
}

// Updates releases
// Maybe I'll look into making this a bit nicer in the future
// Also, the only reason we can search by value is because the mapping is bijective so keep that in mind
void InputManager::KRUpdate(sf::Event e)
{
	if (e.type == sf::Event::KeyReleased)
		for each(auto k in InputManager::KeyboardBinds)
			if (k.second.key == e.key.code)
				InputManager::KeyboardBinds.find(k.first)->second.curState = 0;
	if (e.type == sf::Event::KeyPressed)
		for each(auto k in InputManager::KeyboardBinds)
			if (k.second.key == e.key.code)
				InputManager::KeyboardBinds.find(k.first)->second.curState = 1;
}

// Updates real-time inputs ALWAYS place at end of Update function/end of gameloop such that keys can retake input
void InputManager::Update()
{
	// Updates the previous state with the current state at the end of the current update
	for each(auto k in InputManager::KeyboardBinds)
	{
		InputManager::KeyboardBinds.find(k.first)->second.prevState = k.second.curState;
	}

}