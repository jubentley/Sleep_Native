# Sleep

## Use-Case

Your watching a movie, and you have a laptop in front of you as your creating that linkedin post thats gonna go more viral than 
triple-bubble extra large 
bubble tea, but something really cool comes up on the movie, but you cant enjoy it cause theres a bright laptop obstructiong 
your vision and you just want a quick little button to press to turn that monitor off. 

## Operation

Instead of the User Inactivity Timer triggering a monitor down power state, after a one second delay this application will 
send that message to the Windows 
subsystem.

Therefore functionally its the same thing, although triggered on your command and ofcourse moving the mouse will wake the monitor 
turn back on again.

## Sleep_Native VS Sleep_Managed
Sleep_Native is written in C and produces a pure machine-code executable (as reflected by its size of 10KB) Sleep_Managed is written 
in C# and is more modern, conventional, transparent etc. Strangely they both call the same C function 
```C
  LRESULT SendMessage(HWND, UINT, WPARAM, LPARAM);
```
within the Windows subsystem 
using the Win32API Message based system that operates Windows IPC (Inter Process Communication) 



