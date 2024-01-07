# trickery
Collection of script/code tricks I like to think I've invented/discovered/mastered (none of that's true), such as:  

+ Procedural generation
+ Obfuscation
+ Self-modifying code
+ Self-generating code
+ /etc

Useful for everything from lulz to world domination.

*See also*: https://github.com/diemastermonkey/doors, https://github.com/diemastermonkey/iterator

# Discussion

# yesno 
6 lines answers any question consistently with this one simple Procedural Generation trick

# yesno: Example (quotes are required)

./yesno "Am I cute?"

  Yes
  
./yesno "Is this clever?"

  No
  
./yesno "Pineapple on pizza?"

  No
  
# yesno: Explanation

Aside of handling input, this code does almost nothing!

This may be the lowest-effort method to generate random but consistent responses to arbitrary input: Using the input as part of seeding a Pseudo Random Number Generator (PRNG). Here, the user input is 1) converted to lowercase 2) base64 encoded and 3) converted to an integer that can be fed to random.seed. 

  random.seed(int.from_bytes(base64.b64encode(sys.argv[1].lower().encode()), byteorder='big'))

Seeded with value X, Python's PRNG will generate the same "random" values in the same order, every time.
That means the same input string will produce the same answer always, forever. Kinda cool huh. The PRNG has an opinion on pineapple. ;)

PS: Rather than bothering with "if" statements, we just flip a coin to choose from the "aNswers" array. ;)

  aNswers = ["Yes", "No"];
  
  (...)
  
  print (aNswers[random.randint(0,1)])

# Disclaimer
I like pineapple on pizza.

