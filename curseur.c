const char *dataCurseur[] = {   //données XPM pour construire les curseurs
      "16 16 3 1",
      "     c None",
      ".    c #FFFFFF",
      "+    c #000000",
      "                ",
      "     .. ..      ",
      "     .+++.      ",
      "      .+.       ",
      "      .+.       ",
      "      .+.       ",
      "      .+.       ",
      "      .+.       ",
      "      .+.       ",
      "      .+.       ",
      "      .+.       ",
      "      .+.       ",
      "      .+.       ",
      "     .+++.      ",
      "     .. ..      ",
      "                ",
      "7,7"
};
SDL_Cursor* CreerCurseur(const char *image[])   //créé un curseur à partir du format XPM. Fourni par la doc de la SDL.
{
  int i, row, col;
  Uint8 data[4*16];
  Uint8 mask[4*16];
  int hot_x, hot_y;

  i = -1;
  for ( row=0; row<16; ++row ) {
    for ( col=0; col<16; ++col ) {
      if ( col % 8 ) {
        data[i] <<= 1;
        mask[i] <<= 1;
      } else {
        ++i;
        data[i] = mask[i] = 0;
      }
      switch (image[4+row][col]) {
        case '+':
          data[i] |= 0x01;
          mask[i] |= 0x01;
          break;
        case '.':
          mask[i] |= 0x01;
          break;
        case ' ':
          break;
      }
    }
  }
  sscanf(image[4+row], "%d,%d", &hot_x, &hot_y);
  return SDL_CreateCursor(data, mask, 16, 16, hot_x, hot_y);
}
