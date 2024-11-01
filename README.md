# RndwstCL

[![sampctl](https://img.shields.io/badge/sampctl-RndwstCL-2f2f2f.svg?style=for-the-badge)](https://github.com/renodwi/RndwstCL)

ini merupakan library yang dibuat untuk memudahkan pemilihan warna untuk pemain. Penggunaan kodenya sangat mudah, contohnya sebagai berikut

## Installation

Simply install to your project:

```bash
sampctl package install renodwi/RndwstCL
```

Include in your code and begin using the library:

```pawn
#include <RndwstCL>
```

## Usage

YCMD:test(playerid, params[], help)
{
    ShowPlayerColorList(playerid, ColorList, "Ini Caption", "Button 1", "Button 2");
    return 1;
}

// Kemudian dari fungsi diatas, response dialog akan ditangkap dengan

ColorSelector:ColorList(playerid, response, color)
{
    // Debuging
    printf("playerid: %d response: %d color: %d", playerid, response, color);
    return 1;
}

## Testing

<!--
Depending on whether your package is tested via in-game "demo tests" or
y_testing unit-tests, you should indicate to readers what to expect below here.
-->

To test, simply run the package:

```bash
sampctl package run
```
