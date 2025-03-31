# Sleep

## Use-Case
I remember a long time ago I had a Sony VAIO Laptop and it had a dedicated hardware button called "DISPLAY OFF" that would, turn the display off (likely in the same way as this Application) and I wanted to replicate that functionality, especially as I have a tendancy to use the laptop during youtube ads 😆.

## Operation

Instead of the User Inactivity Timer triggering a monitor down power state, after a one second delay this application will 
send that message to the Windows 
subsystem.

Therefore functionally its the same thing, although triggered on your command and ofcourse moving the mouse will wake the monitor 
turn back on again.

## Sleep_Native vs Sleep_Managed
Sleep_Native is written in C and produces a pure machine-code executable (as reflected by its size of 10KB) Sleep_Managed is written 
in C# and is more modern, conventional, transparent etc. 

Strangely they both call the same function 
```C
  LRESULT SendMessage(HWND, UINT, WPARAM, LPARAM);
```
within the Windows subsystem 
using the C Message based system that has operated Windows IPC (Inter Process Communication) since (coincidently) 
"going graphical" in '85 with Windows 1.0 (was I around then? No, but I have used actual DOS, Win 3.1 & '95), so in many regards theres a bit of OS 101 right there.

<i>But whats the difference between the two in a modern context?</i> \
Some may argue Native (C) is more efficient and responsive, some may argue that with todays processors the difference is negligable and 
the marginal performance gains are overshadowed by the benefits of readability, familiarity, testability and the security involved with the 
isolated run-time nature of Managed (C#) Code, and the level of Operating System trust that reflects this.

<i>So hows that relevant here?</i> \
Simply put, Group Policy, Antivirus and/or default Operating System setting will be much more inclined to block the Native version of this Application from running.<br>
Group Policy is likely to absolutely deny the running of a unknown executable, though I wouldnt expect this application to be used in an Administrated System, ie at work.<br>
Antivirus, especially the less capable ones have been know to arbitrarily flag Native programs, not the case with the major ones though.<br>
These days (not the case earlier) the Operating system and User Account Control (starting in Vista) will prompt the user to confirm the execution of a native program.<br>
All these factors are lessenend or downright negated by the use of a Managed (C#) Application.
