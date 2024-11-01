# RndwstCL

[![sampctl](https://img.shields.io/badge/sampctl-RndwstCL-2f2f2f.svg?style=for-the-badge)](https://github.com/renodwi/RndwstCL)

This is a library made to facilitate the selection of colors for players. Using the code is very easy, for example as follows

## Installation

Simply install to your project:

```bash
sampctl package install renodwi/RndwstCL
```

Include in your code and start using the library:

```pawn
#include <RndwstCL>
```

## Usage

```pawn
YCMD:test(playerid, params[], help)
{
    ShowPlayerColorList(playerid, ColorList, “This is Caption”, “Button 1”, “Button 2”);
    return 1;
}

// Then from the above function, the dialog response will be captured with

ColorSelector:ColorList(playerid, response, color)
{
    // Debugging
    printf(“playerid: %d response: %d color: %d”, playerid, response, color);
    return 1;
}

// IMPORTANT NOTE: THE OUTPUT OF THE COLOR SELECTED BY THE PLAYER IS IN RGBA FORMAT!!!
```

## Testing

<!--
Depending on whether your package is tested via in-game “demo tests” or
y_testing unit-tests, you should indicate to readers what to expect below here.
-->

To test, simply run the package:

``bash
sampctl package run
```