# trickery
Collection of script/code tools/tricks I like to think I've invented/discovered/mastered (none of that's true):  

+ Utilities for scripts
+ Procedural generation
+ Obfuscation
+ Self-modifying / self-generating code
+ /etc

Useful for everything from lulz to world domination.

*See also*: https://github.com/diemastermonkey/doors, https://github.com/diemastermonkey/iterator

# Discussion

# Python: yesno 
6 lines answers any question consistently with this one simple Procedural Generation trick

Example (quotes are required)

./yesno "Am I cute?"

  Yes
  
./yesno "Is this clever?"

  No
  
./yesno "Pineapple on pizza?"

  No
  
Explanation

This code does almost nothing!

Perhaps the lowest-effort method to generate seemingly random yet consistent responses to arbitrary input: Use the input in seeding a Pseudo Random Number Generator (PRNG). User input is 1) lowercased 2) base64 encoded and 3) converted to an integer fed to random.seed. 

In other words: 

  random.seed(int.from_bytes(base64.b64encode(sys.argv[1].lower().encode()), byteorder='big'))

Seeded in this way, the PRNG will generate the same "random" values in the same order, every time.
That means the same input string will produce the same answer always, forever. Kinda cool huh. This script has an opinion on pineapple. ;)

PS: Rather than "if" statements, we simply flip a coin to choose from the "aNswers" array. ;)

  aNswers = ["Yes", "No"];
  
  (...)
  
  print (aNswers[random.randint(0,1)])

Disclaimer
I DO like pineapple on pizza.

# Shell: maclookup

Identifying devices by MAC address - it's a Hacker Thing. Usually you do a web search, but I wanted to 'have it handy'. 

This shell script embeds the entire MAC vendor database (about 50,000 lines) within itself, and provides flexible search from the command line. It accepts full or partial MAC addresses, and you can skip the colons in case someone's shouting a MAC address at you from across the room (it happens). Coming soon: Self-update database.

Examples:

./maclookup

Usage:

maclookup <MAC address or first 3 bytes>

./maclookup 00:15:5d:bb:74:ce

  maclookup : Searching 50578 entries for MAC prefix: 00:15:5d
  
  maclookup : Microsoft Corporation
  
  maclookup : End of line


./maclookup 4001c6

  maclookup : Searching 50578 entries for MAC prefix: 40:01:c6
  
  maclookup : 3COM EUROPE LTD
  
  maclookup : End of line

# ANSI C: gad-hotkeys.c

Work in progress: Simple utility in C to support 'hotkeys' for scripts. 

Run it with a list of your menu items as strings, and it will return the same list with one letter per item in camelCase. Display the new list to the user so they can select an item by single keystroke of the upper-case key. The code ensures each item has a unique hotkey assigned. If no unique hotkey is determined, that item is returned unmodified (i.e. no hotkey).

Not yet implemented: Run it a second time passing the user's selected hotkey and the same menu listing. It will tell you which option they selected. This /could/ be done fairly easy in the script itself with some pattern matching, but I think this feature will be an easier workflow. 

Compile

gcc gad-hotkeys.c -o gad-hotkeys

Run

./gad-hotkeys dog dude frog frame rug pug couch cone bone strong

Dog
dUde
Frog
fRame
ruG
Pug
Couch
cOne
Bone
Strong

# Python: 7070 (aka haha)

File under "Obfuscation Techniques". 6 lines of Python print out 'haha', IF the filename is '7070'.

$ ./7070

H

A

H

A

# Shell: countdown

Do a simple countdown in shell, with default time or specify on command line.

$ ./countdown

Count down: 50
(...)

$ ./countdown 10

Count down: 10
(...)





