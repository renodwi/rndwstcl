# Rndwst Color List (RndwstCL.inc)
ini merupakan library yang dibuat untuk memudahkan pemilihan warna untuk pemain. Penggunaan kodenya sangat mudah, contohnya sebagai berikut

```
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
```

## CATATAN PENTING: WARNA YANG DIHASILKAN / WARNA OUTPUT MENGGUNAKAN FORMAT RGBA!!!