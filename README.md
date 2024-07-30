# trickery
Collection of script/code tools/tricks I like to think I've invented/discovered/mastered (none of that's true), such as:  

+ Procedural generation
+ Obfuscation
+ Self-modifying code
+ Self-generating code
+ /etc

Useful for everything from lulz to world domination.

*See also*: https://github.com/diemastermonkey/doors, https://github.com/diemastermonkey/iterator

# Discussion

# Python: yesno 
6 lines answers any question consistently with this one simple Procedural Generation trick

yesno: Example (quotes are required)

./yesno "Am I cute?"

  Yes
  
./yesno "Is this clever?"

  No
  
./yesno "Pineapple on pizza?"

  No
  
yesno: Explanation

Aside of handling input, this code does almost nothing!

This may be the lowest-effort method to generate random but consistent responses to arbitrary input: Using the input as part of seeding a Pseudo Random Number Generator (PRNG). Here, the user input is 1) converted to lowercase 2) base64 encoded and 3) converted to an integer that can be fed to random.seed. 

  random.seed(int.from_bytes(base64.b64encode(sys.argv[1].lower().encode()), byteorder='big'))

Seeded with value X, Python's PRNG will generate the same "random" values in the same order, every time.
That means the same input string will produce the same answer always, forever. Kinda cool huh. The PRNG has an opinion on pineapple. ;)

PS: Rather than bothering with "if" statements, we just flip a coin to choose from the "aNswers" array. ;)

  aNswers = ["Yes", "No"];
  
  (...)
  
  print (aNswers[random.randint(0,1)])

Disclaimer
I do like pineapple on pizza.

# Shell: maclookup

Identifying a device by its MAC address - it's A Hacker Thing. Usually you do a web search, but I wanted to 'have it handy'. 

This shell script embeds the entire MAC vendor database (about 50,000 lines) within itself, and provides flexible search from the command line. It accepts full or partial MAC addresses, and you can skip the colons in case someone's shouting a MAC address at you from across the room (it happens). Coming soon: Self-update database.

Examples:

./maclookup

maclookup usage:

maclookup <MAC address or first 3 bytes>

./maclookup 00:15:5d:bb:74:ce

  maclookup : Searching 50578 entries for MAC prefix: 00:15:5d
  
  maclookup : Microsoft Corporation
  
  maclookup : End of line


./maclookup 4001c6

  maclookup : Searching 50578 entries for MAC prefix: 40:01:c6
  
  maclookup : 3COM EUROPE LTD
  
  maclookup : End of line

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





