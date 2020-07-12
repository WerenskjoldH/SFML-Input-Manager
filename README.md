<p align="center"><img width=100% src="media/sfmlInputManagerTitle.png"></p>

<h4 align="center">A Light-weight Header-only Input Manager for SFML-based Projects</p>

[![License: MIT](https://img.shields.io/badge/License-MIT-yellow.svg)](https://opensource.org/licenses/MIT)
[![Repository Size](https://img.shields.io/github/repo-size/WerenskjoldH/SFML-Input-Manager)]()

---

---

## Purpose

This is a singleton approach to creating a light-weight and performant input manager for the SFML 2.5 API. One of the common issues you will find with SFML's input handling is the lack of support for functionality like: press and release. This is a recurring issue for projects I work on, and so I decided to create a light-weight manager I can simply drop into all my SFML projects and expand if necessary. 

---

## How To Implement:  
  1. Clone this repository
  2. Add the files to your program, ensure you have linked the proper library and include directories.
  3. Add #include "InputManager.h" to the top of your file so the pre-compiler can add it to the project.

---

### Updating The Instance:  
To keep the keyboard running in line with the rest of the program:  
#### Setup: 
1. Firstly, add the following line of code to the **end** of your **event** loop.  
<code>InputManager::Instance()->KRUpdate(event);</code>  
2. Secondly, add the following line of code to the **end** of your **game** loop.  
<code>InputManager::Instance()->Update();</code>  

Now you're good to start defining binds!

---

### Defining Binds:  
To add a bind you just have to call the InputManager's singleton instance and call the KBind function:  
#### Template:  
``` c++
InputManager::Instance()->KBind(int key, Keyboard::<Key Name>)   
```
#### Example:
``` c++
InputManager::Instance()->KBind(0, Keyboard::Space);
```
  
#### Checking Input: 
This is best shown by example, extending from the binding above:  
``` c++
if (InputManager::Instance()->KeyPress(0))  
        cout << "Space was pressed" << endl;  
if (InputManager::Instance()->KeyDown(0))  
        cout << "Space is held down" << endl;  
if (InputManager::Instance()->KeyRelease(0))  
        cout << "Space was released" << endl;  
if (InputManager::Instance()->KeyUp(0))  
        cout << "Space is up" << endl;  
```

---

## Dependencies

This project was built for the [SFML 2.5 API](https://www.sfml-dev.org/), and as such, you will need to link the library to your project to use this input manager.

---

## Q&A

### _Q_: What if I don't want to use an integer to reference keys?

**A**: Don't worry, the adjustment is quite simple! You will just need to modify the mapping from `int -> Key` to `std::string -> Key` and make adjustments to all references to the map to pass a string instead of int. Huzzah!