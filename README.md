# Sleep

## Use-Case

Your watching a movie, and you have a laptop in front of you as your creating that linkedin post thats gonna go more viral than 
triple-bubble extra large 
bubble tea, but something really cool comes up on the movie, but you cant enjoy it cause theres a bright laptop obstructiong 
your vision and you just want a quick little button to press to turn that monitor off. Some laptops (and perhaps keyboards) have this functionality as a dedicated hardware button.

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


Two factors, Group Policy and Antivirus. Group Policy refers to an Administrated system where Native code is generally disabled by 
default though I wouldnt really expect this application (either Native or Managed) to be used in that sort of situation. Antivirus is 
a big one though as I ran the Native version through VirusTotal and ofcourse the lesser-known-if-at-all scanners flagged 
it but none of the major companies did, mainly because one saw it as "simply an executable" and an unknown one at that and the others 
actually looked into what it did on a machine-code/assembly level. While that happened with the Native version it would be less likely to occur with the Managed version.










