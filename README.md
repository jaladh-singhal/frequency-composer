# Frequency Composer :musical_keyboard:
A menu-driven application completely built in C Language, which creates :musical_score:Music:musical_score: by the *logical manipulation of frequency values* of the output sound beeps.:sound:

:notes: **Highlight:** All the music and sounds in entire application is produced by using a *single sound generating function* viz. ``Beep()`` which produces a sound beep of a specified frequency for the specified time. 


## Functionalities
The application is primarily capable of 3 functionalities:
1. :trumpet: User can *input a string of Digits* which is used to **produce Sound-Show** by harnessing frequencies from the digits.
2. :headphones: User can **listen to pre-recorded Music** by choosing one from the list. 
3. :microphone: User can **compose Music** on its own by *inputting the Musical Notes*.

Besides, while listening to music/sound, program also shows the **Frequency-Graph** of the sound being played. :bar_chart:


## Demo
[![Snap](https://drive.google.com/uc?id=1G7J-YOyYSys_cvkKILBs9BRAVJGiW6_2)](https://drive.google.com/open?id=1OShNYdHPQmz_8aocIhyPHCKYyu-aU7FD)


## Dependencies
1. *``<windows.h>`` header file is included* as the ``Beep()`` function belongs to Windows API. So make necessary adjustments when running it on OS other than Windows, to access the Windows API.
2. *Extended ASCII character - ``220`` (bottom half block)* is used to draw the horizontal bar graphs. So there are chances that the terminal you use may interpret it differently. If it is so, then replace 220 with ``124`` (the pipe character).


## Ignore following if you don't have spare time!
### A Fun Fact -
:eyes: Human ear can hear only those frequencies which lie in the range of 20Hz to 20,000Hz.

So run this application & get ready for testing your ears! :wink:

### Better to keep in mind!
> The thrill should not be at the cost of physical damage! :sweat_smile:
  
~ To avoid piercing of your eardrums by high frequency sound beeps, reduce the volume of your speakers according to your tolerance.
> The Music Synthesizers in market are quite expensive! :stuck_out_tongue_winking_eye:
  
~ Original Music is made by composition of various frequencies at the same time, along with amplitude fluctuations and other factors. So this application obviously has limitations for Music Composition!
  
### Request -
Please spare your valuable time to share your suggestions. Bring out the true essence of open source! :raised_hands:
