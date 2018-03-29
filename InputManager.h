#include <stdio.h>
#include <SFML/Graphics.hpp>
#include <map>

class InputManager {
private:
	static InputManager* pInstance;
	InputManager();
	struct Key {
		// Is the key down or up
		// 0 up
		// 1 down
		int curState;
		int prevState;
		// Holds the key being bound
		sf::Keyboard::Key key;
		Key(sf::Keyboard::Key k)
		{
			this->curState = 0;
			this->prevState = 0;
			this->key = k;
		}
	};
	// This maps a given key to another key as necessary
	std::map<int, Key> KeyboardBinds;
	// Check if a bind exists
	bool IsBound(int k);

public:
	static InputManager* Instance();
	// Is key down
	bool KeyDown(int code);
	// Is key up
	bool KeyUp(int code);
	// On key press
	bool KeyPress(int code);
	// On key release
	bool KeyRelease(int code);
	// Updates real-time inputs
	void Update();
	// Updates releases
	void KRUpdate(sf::Event e);
	// Rebinds a key
	void KBind(int code, sf::Keyboard::Key key);
};