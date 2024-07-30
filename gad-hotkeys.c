/* gad-hotkeys: Hotkey helper for CLI stuff
 * Generate and handle hotkeys for menus, etc
 * unhacker@gmail.com 2024
 *
 * 1. Run once with list of items. Returns hotkeyed version.
 * 2. Run again with selected char first, then the same list
 *    ...it returns which item user must have selected.
 *
 * Ex: Return provided list with one char per item CamelCased
 *
 *    Input:  gad-hotkeys <owls oaks toads toes [...]>
 *    Output: Owls oAks Toads toEs
 *   
 * Ex: Report which item was selected, assuming our lists 
 *
 *    Input:  gad-hotkeys <T owls oaks toads toes [...]>
 *    Output: toads
 *
*/

#include <ctype.h>       // For toupper()
#include <memory.h>
#include <stdio.h>
#include <stdlib.h>

// Global
char* sGHotkeys = NULL;

// Locates first char from arg not already a hotkey
// Appends to global assigned hotkeys
// Returns the entire camelCased string
char* fnMakeHotkey (char* sArg) { 
  char cChar;	
  int iPos = 0;
  int iLoc = -1;
  int iLen = strlen(sArg); 

  // Iterate chars in sArg
  while (iPos < iLen) { 
    cChar = sArg[iPos];
    // If char found in hotkeys
    if (strchr (sGHotkeys, cChar) == NULL) { 
      strcat (sGHotkeys, &cChar); // Add to hotkeys
      cChar = toupper (cChar);    // Rudely UC hotkey
      sArg[iPos] = cChar;
      iPos = iLen;                // Rudely end loop
    }
	  
    iPos++;            // Next char
  }                    // End while

  return (sArg);       // Return modified string
}                      // End func

// Main
void main (int argc, char* argv[]) {
  if (argc < 2) {
    printf ("%s <string [string...]>\n", argv[0]);
    exit(0);
  }

  // Allocate one char per item (except argv[0]) + 1
  sGHotkeys = malloc (argc); 
  if (! sGHotkeys) { 
    printf ("%s malloc fail. Aborted.\n", argv[0]);
    exit(-1);
  }

  // Iterate all args, pick hotkey, output for use
  for (int i=1; i < argc; i++) { 
    printf ("%s\n", fnMakeHotkey (argv[i]));
  }
  
  // printf ("\nHotkeys: %s", sGHotkeys);
  
} // End main

