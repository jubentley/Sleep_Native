# Sleep

## Versions
This application comes in two variaties:
* Native code in C: [github.com/jubentley/Sleep_Native ](https://github.com/jubentley/Sleep_Native)
* Managed code in C# [github.com/jubentley/Sleep_Managed](https://github.com/jubentley/Sleep_Managed)

## Use-Case
I remember a long time ago I had a Sony VAIO Laptop and it had a dedicated hardware button called "DISPLAY OFF" that would, turn the display off (likely in the same way as this Application) and I wanted to replicate that functionality.

I personally use this program as I tend to watch movies on the television while using the laptop and desired a quick and simple way to turn the monitor off when needed.

## Operation

Instead of the User Inactivity Timer triggering a monitor down power state, after a one second delay this application will 
send that message to the Windows 
subsystem.

Therefore functionally its the same thing, although triggered on your command and ofcourse moving the mouse will turn the monitor back on again.

The delay is present due to jitter of the mouse cursor following the clicking of the Appliciation. If the delay was not present this Application would be rendered inert (unless using the enter key) as it would indeed trigger the monitor power down state although be instantly woken up next frame as the user releases the mouse.

## Sleep_Native vs Sleep_Managed
Sleep_Native is written in C and produces a pure machine-code executable (as reflected by its size of 10KB, before the icon was added) whereas Sleep_Managed is written in C# which produces Intermediate Language (Bytecode) that is compiled upon execution Just-In-Time by the Common Language Runtime. Despite being a great exception to the norm Sleep_Managed does actually create some Native code wrapped in Managed.

Ergo, they both call the same C language function,
```C
  LRESULT SendMessage(HWND, UINT, WPARAM, LPARAM);
```
As (C),
```C
  SendMessage(HWND_BROADCAST, WM_SYSCOMMAND, SC_MONITORPOWER, (LPARAM)2);
```
Or (C# C),
```C#
  [DllImport("user32.dll", SetLastError = true)]
  private static extern IntPtr SendMessage(IntPtr hWnd, uint Msg, IntPtr wParam, IntPtr lParam);
```
        
within the Windows subsystem 
using the C Message based system that has operated Windows IPC (Inter Process Communication) since (coincidently) 
"going graphical" in '85 with Windows 1.0 (was I around then? No, but I have used actual DOS, Win 3.1 & '95), so in many regards theres a bit of OS 101 right there.

<i>But whats the difference between the two in a modern context?</i> \
Some may argue Native (C) is more efficient, responsive and ramps the CPU Fan less, some may argue that with todays processors the difference is negligable and 
the marginal performance gains are overshadowed by the benefits of readability, familiarity, testability and most importantly the security involved with the 
isolated run-time nature of Managed (C#) Code, and the level of Operating System trust that reflects this.

<i>So hows that relevant here?</i> \
Simply put, Group Policy, Antivirus and/or default Operating System setting will be much more inclined to block the Native version of this Application from running.<br>
Group Policy is likely to absolutely deny the running of a unknown executable, though I wouldnt expect this application to be used in an Administrated System, ie at work.<br>
Antivirus, especially the less capable ones have been know to arbitrarily flag Native programs, not the case with the major ones though, and also not the case with GitHub as it does scan uploaded Releases (such as the ones in these repositories) and will take them down (and likely have a negative impact on myself) if they believe them to be malicious.<br>
These days (not the case earlier) the Operating System and User Account Control (starting in Vista, a lot of people actually disabled UAC or atleast the popup, though they did have paid antivirus as a safeguard, some knowledge of what they were doing and were generally capable of reformatting the OS if it became compromised, mind you viruses wern't as nasty back then) will prompt the user to confirm the execution of a native program, especially one that has not been digitally signed (difficult to justify cost in my case), is not from a major organisation nor has the executable been seen before.<br>
All these factors are lessenend or downright negated by the use of a Managed (C#) Application.
