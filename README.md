# SFML-Input-Manager
Date:     3-29-18  
Purpose:  Provide a light-weight easily ported input manager for SFML programs  
Name:     Hunter Werensjold  

# How-To-Use:  
  1. Add the files to your program, ensure you have linked the proper library and include directories.
  2. Add #include "InputManager.h" to the top of your file
## Updating The Instance:  
To keep the keyboard running in line with the rest of the program:  
### To-do: 
1. Firstly, add the following line of code to the *end* of your event loop.  
<code>InputManager::Instance()->KRUpdate(event);</code>  
2. Secondly, add the following line of code to the *end* of your game loop.  
<code>InputManager::Instance()->Update();</code>  

Now you're good to go defining binds!

 ## Defining Binds:  
To add a bind you just have to call the InputManager's singleton instance and call the KBind function:  
### Template:  
             InputManager::Instance()->(int key, Keyboard::<Key Name>)   
### Example:

             InputManager::Instance()->KBind(0, Keyboard::Space);

  
### Checking Input: 
This is best shown by example:  

    if (InputManager::Instance()->KeyPress(0))  
		    cout << "Space was pressed" << endl;  
    if (InputManager::Instance()->KeyDown(0))  
		    cout << "Space is held down" << endl;  
	if (InputManager::Instance()->KeyRelease(0))  
		  cout << "Space was released" << endl;  
	if (InputManager::Instance()->KeyUp(0))  
		  cout << "Space is up" << endl;  

# License

This project is licensed under the MIT License - see the LICENSE.md file for details
