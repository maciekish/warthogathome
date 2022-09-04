const uint8_t CDU_Bitmaps[] PROGMEM = {
  0xFA, 0xFA, 0xB4, 0x57, 0xD5, 0xF5, 0x00, 0xC0, 0x2A, 0x48, 0x88, 0x88, 
  0x92, 0xA0, 0x51, 0x3E, 0x45, 0x00, 0x21, 0x3E, 0x42, 0x00, 0xC0, 0xF8, 
  0x80, 0x08, 0x88, 0x88, 0x00, 0x74, 0x67, 0x5C, 0xC5, 0xC0, 0x59, 0x24, 
  0xB8, 0x74, 0x42, 0xE8, 0x43, 0xE0, 0xF8, 0x44, 0x60, 0xC5, 0xC0, 0x11, 
  0x95, 0x2F, 0x88, 0x40, 0xFC, 0x3C, 0x10, 0xC5, 0xC0, 0x3A, 0x21, 0xE8, 
  0xC5, 0xC0, 0xF8, 0x44, 0x44, 0x42, 0x00, 0x74, 0x62, 0xE8, 0xC5, 0xC0, 
  0x74, 0x62, 0xF0, 0x8B, 0x80, 0xA0, 0xB0, 0x2A, 0x22, 0xF8, 0x3E, 0x88, 
  0xA8, 0x74, 0x44, 0x42, 0x00, 0x80, 0x74, 0x63, 0x7B, 0xC5, 0xC0, 0x74, 
  0x63, 0x1F, 0xC6, 0x20, 0xF4, 0x63, 0xE8, 0xC7, 0xC0, 0x74, 0x61, 0x08, 
  0x45, 0xC0, 0xF4, 0x63, 0x18, 0xC7, 0xC0, 0xFC, 0x21, 0xE8, 0x43, 0xE0, 
  0xFC, 0x21, 0xE8, 0x42, 0x00, 0x74, 0x61, 0x09, 0xC5, 0xE0, 0x8C, 0x63, 
  0xF8, 0xC6, 0x20, 0xE9, 0x24, 0xB8, 0x08, 0x42, 0x10, 0xC5, 0xC0, 0x8C, 
  0xA9, 0x8A, 0x4A, 0x20, 0x84, 0x21, 0x08, 0x43, 0xE0, 0x8E, 0xEB, 0x58, 
  0xC6, 0x20, 0x8C, 0x73, 0x59, 0xC6, 0x20, 0x74, 0x63, 0x18, 0xC5, 0xC0, 
  0xF4, 0x63, 0xE8, 0x42, 0x00, 0x74, 0x63, 0x18, 0xB8, 0x20, 0xF4, 0x63, 
  0xEA, 0x4A, 0x20, 0x74, 0x60, 0xE0, 0xC5, 0xC0, 0xF9, 0x08, 0x42, 0x10, 
  0x80, 0x8C, 0x63, 0x18, 0xC5, 0xC0, 0x8C, 0x62, 0xA5, 0x10, 0x80, 0x8C, 
  0x63, 0x5A, 0xD5, 0x40, 0x8C, 0x54, 0x45, 0x46, 0x20, 0x8C, 0x54, 0x42, 
  0x10, 0x80, 0xF8, 0x44, 0x44, 0x43, 0xE0, 0xF8, 0x88, 0x88, 0xF0, 0x82, 
  0x08, 0x20, 0x80, 0xF8, 0x42, 0x10, 0x87, 0xE0, 0x22, 0xA2, 0xF8, 0x90, 
  0xDC, 0x63, 0x18, 0xC7, 0x60, 0x74, 0x6B, 0x17, 0x00, 0x22, 0x3E, 0x82, 
  0x00, 0x23, 0xAA, 0x4A, 0xB8, 0x80, 0xF7, 0x80, 0x27, 0xC8, 0x42, 0x7C, 
  0xFF, 0xFF, 0xFF, 0xFF, 0xE0, 0x20, 0xBE, 0x22, 0x00
};

const GFXglyph CDU_Glyphs[] PROGMEM = {
  {     0,   0,   0,   6,    0,    0 },   // 0x20 ' '
  {     1,   1,   7,   6,    2,   -7 },   // 0x21 '!'
  {     2,   3,   2,   6,    1,   -7 },   // 0x22 '"'
  {     3,   5,   5,   6,    0,   -6 },   // 0x23 '#'
  {     0,   0,   0,   0,    0,    0 },   // 0x24 '$'
  {     0,   0,   0,   0,    0,    0 },   // 0x25 '%'
  {     0,   0,   0,   0,    0,    0 },   // 0x26 '&'
  {     7,   1,   2,   6,    1,   -7 },   // 0x27 '''
  {     8,   3,   7,   6,    1,   -7 },   // 0x28 '('
  {    11,   3,   7,   6,    1,   -7 },   // 0x29 ')'
  {    14,   5,   5,   6,    0,   -6 },   // 0x2A '*'
  {    18,   5,   5,   6,    0,   -6 },   // 0x2B '+'
  {    22,   1,   2,   6,    2,   -1 },   // 0x2C ','
  {    23,   5,   1,   6,    0,   -4 },   // 0x2D '-'
  {    24,   1,   1,   6,    2,   -1 },   // 0x2E '.'
  {    25,   5,   5,   6,    0,   -6 },   // 0x2F '/'
  {    29,   5,   7,   6,    0,   -7 },   // 0x30 '0'
  {    34,   3,   7,   6,    1,   -7 },   // 0x31 '1'
  {    37,   5,   7,   6,    0,   -7 },   // 0x32 '2'
  {    42,   5,   7,   6,    0,   -7 },   // 0x33 '3'
  {    47,   5,   7,   6,    0,   -7 },   // 0x34 '4'
  {    52,   5,   7,   6,    0,   -7 },   // 0x35 '5'
  {    57,   5,   7,   6,    0,   -7 },   // 0x36 '6'
  {    62,   5,   7,   6,    0,   -7 },   // 0x37 '7'
  {    67,   5,   7,   6,    0,   -7 },   // 0x38 '8'
  {    72,   5,   7,   6,    0,   -7 },   // 0x39 '9'
  {    77,   1,   3,   6,    2,   -4 },   // 0x3A ':'
  {    78,   1,   4,   6,    2,   -4 },   // 0x3B ';'
  {    79,   3,   5,   6,    1,   -5 },   // 0x3C '<'
  {    81,   5,   3,   6,    0,   -4 },   // 0x3D '='
  {    83,   3,   5,   6,    1,   -5 },   // 0x3E '>'
  {    85,   5,   7,   6,    0,   -7 },   // 0x3F '?'
  {    90,   5,   7,   6,    0,   -7 },   // 0x40 '@'
  {    95,   5,   7,   6,    0,   -7 },   // 0x41 'A'
  {   100,   5,   7,   6,    0,   -7 },   // 0x42 'B'
  {   105,   5,   7,   6,    0,   -7 },   // 0x43 'C'
  {   110,   5,   7,   6,    0,   -7 },   // 0x44 'D'
  {   115,   5,   7,   6,    0,   -7 },   // 0x45 'E'
  {   120,   5,   7,   6,    0,   -7 },   // 0x46 'F'
  {   125,   5,   7,   6,    0,   -7 },   // 0x47 'G'
  {   130,   5,   7,   6,    0,   -7 },   // 0x48 'H'
  {   135,   3,   7,   6,    1,   -7 },   // 0x49 'I'
  {   138,   5,   7,   6,    0,   -7 },   // 0x4A 'J'
  {   143,   5,   7,   6,    0,   -7 },   // 0x4B 'K'
  {   148,   5,   7,   6,    0,   -7 },   // 0x4C 'L'
  {   153,   5,   7,   6,    0,   -7 },   // 0x4D 'M'
  {   158,   5,   7,   6,    0,   -7 },   // 0x4E 'N'
  {   163,   5,   7,   6,    0,   -7 },   // 0x4F 'O'
  {   168,   5,   7,   6,    0,   -7 },   // 0x50 'P'
  {   173,   5,   7,   6,    0,   -7 },   // 0x51 'Q'
  {   178,   5,   7,   6,    0,   -7 },   // 0x52 'R'
  {   183,   5,   7,   6,    0,   -7 },   // 0x53 'S'
  {   188,   5,   7,   6,    0,   -7 },   // 0x54 'T'
  {   193,   5,   7,   6,    0,   -7 },   // 0x55 'U'
  {   198,   5,   7,   6,    0,   -7 },   // 0x56 'V'
  {   203,   5,   7,   6,    0,   -7 },   // 0x57 'W'
  {   208,   5,   7,   6,    0,   -7 },   // 0x58 'X'
  {   213,   5,   7,   6,    0,   -7 },   // 0x59 'Y'
  {   218,   5,   7,   6,    0,   -7 },   // 0x5A 'Z'
  {   223,   4,   7,   6,    0,   -7 },   // 0x5B '['
  {   227,   5,   5,   6,    0,   -6 },   // 0x5C '\'
  {   231,   5,   7,   6,    0,   -7 },   // 0x5D ']'
  {   236,   5,   3,   6,    0,   -7 },   // 0x5E '^'
  {   238,   5,   1,   6,    0,   -1 },   // 0x5F '_'
  {   239,   2,   2,   6,    0,   -7 },   // 0x60 '`'
  {     0,   0,   0,   0,    0,    0 },   // 0x61 'a'
  {     0,   0,   0,   0,    0,    0 },   // 0x62 'b'
  {     0,   0,   0,   0,    0,    0 },   // 0x63 'c'
  {     0,   0,   0,   0,    0,    0 },   // 0x64 'd'
  {     0,   0,   0,   0,    0,    0 },   // 0x65 'e'
  {     0,   0,   0,   0,    0,    0 },   // 0x66 'f'
  {     0,   0,   0,   0,    0,    0 },   // 0x67 'g'
  {     0,   0,   0,   0,    0,    0 },   // 0x68 'h'
  {     0,   0,   0,   0,    0,    0 },   // 0x69 'i'
  {     0,   0,   0,   0,    0,    0 },   // 0x6A 'j'
  {     0,   0,   0,   0,    0,    0 },   // 0x6B 'k'
  {     0,   0,   0,   0,    0,    0 },   // 0x6C 'l'
  {     0,   0,   0,   0,    0,    0 },   // 0x6D 'm'
  {     0,   0,   0,   0,    0,    0 },   // 0x6E 'n'
  {     0,   0,   0,   0,    0,    0 },   // 0x6F 'o'
  {     0,   0,   0,   0,    0,    0 },   // 0x70 'p'
  {     0,   0,   0,   0,    0,    0 },   // 0x71 'q'
  {     0,   0,   0,   0,    0,    0 },   // 0x72 'r'
  {     0,   0,   0,   0,    0,    0 },   // 0x73 's'
  {     0,   0,   0,   0,    0,    0 },   // 0x74 't'
  {     0,   0,   0,   0,    0,    0 },   // 0x75 'u'
  {     0,   0,   0,   0,    0,    0 },   // 0x76 'v'
  {     0,   0,   0,   0,    0,    0 },   // 0x77 'w'
  {     0,   0,   0,   0,    0,    0 },   // 0x78 'x'
  {     0,   0,   0,   0,    0,    0 },   // 0x79 'y'
  {     0,   0,   0,   0,    0,    0 },   // 0x7A 'z'
  {     0,   0,   0,   0,    0,    0 },   // 0x7B '{'
  {     0,   0,   0,   0,    0,    0 },   // 0x7C '|'
  {     0,   0,   0,   0,    0,    0 },   // 0x7D '}'
  {     0,   0,   0,   0,    0,    0 },   // 0x7E '~'
  {     0,   0,   0,   0,    0,    0 },   // 0x7F 'non-printable'
  {     0,   0,   0,   0,    0,    0 },   // 0x80 'non-printable'
  {     0,   0,   0,   0,    0,    0 },   // 0x81 'non-printable'
  {     0,   0,   0,   0,    0,    0 },   // 0x82 'non-printable'
  {     0,   0,   0,   0,    0,    0 },   // 0x83 'non-printable'
  {     0,   0,   0,   0,    0,    0 },   // 0x84 'non-printable'
  {     0,   0,   0,   0,    0,    0 },   // 0x85 'non-printable'
  {     0,   0,   0,   0,    0,    0 },   // 0x86 'non-printable'
  {     0,   0,   0,   0,    0,    0 },   // 0x87 'non-printable'
  {     0,   0,   0,   0,    0,    0 },   // 0x88 'non-printable'
  {     0,   0,   0,   0,    0,    0 },   // 0x89 'non-printable'
  {     0,   0,   0,   0,    0,    0 },   // 0x8A 'non-printable'
  {     0,   0,   0,   0,    0,    0 },   // 0x8B 'non-printable'
  {     0,   0,   0,   0,    0,    0 },   // 0x8C 'non-printable'
  {     0,   0,   0,   0,    0,    0 },   // 0x8D 'non-printable'
  {     0,   0,   0,   0,    0,    0 },   // 0x8E 'non-printable'
  {     0,   0,   0,   0,    0,    0 },   // 0x8F 'non-printable'
  {     0,   0,   0,   0,    0,    0 },   // 0x90 'non-printable'
  {     0,   0,   0,   0,    0,    0 },   // 0x91 'non-printable'
  {     0,   0,   0,   0,    0,    0 },   // 0x92 'non-printable'
  {     0,   0,   0,   0,    0,    0 },   // 0x93 'non-printable'
  {     0,   0,   0,   0,    0,    0 },   // 0x94 'non-printable'
  {     0,   0,   0,   0,    0,    0 },   // 0x95 'non-printable'
  {     0,   0,   0,   0,    0,    0 },   // 0x96 'non-printable'
  {     0,   0,   0,   0,    0,    0 },   // 0x97 'non-printable'
  {     0,   0,   0,   0,    0,    0 },   // 0x98 'non-printable'
  {     0,   0,   0,   0,    0,    0 },   // 0x99 'non-printable'
  {     0,   0,   0,   0,    0,    0 },   // 0x9A 'non-printable'
  {     0,   0,   0,   0,    0,    0 },   // 0x9B 'non-printable'
  {     0,   0,   0,   0,    0,    0 },   // 0x9C 'non-printable'
  {     0,   0,   0,   0,    0,    0 },   // 0x9D 'non-printable'
  {     0,   0,   0,   0,    0,    0 },   // 0x9E 'non-printable'
  {     0,   0,   0,   0,    0,    0 },   // 0x9F 'non-printable'
  {     0,   0,   0,   0,    0,    0 },   // 0xA0 ' '
  {   240,   5,   7,   6,    0,   -7 },   // 0xA1 '¡'
  {     0,   0,   0,   0,    0,    0 },   // 0xA2 '¢'
  {     0,   0,   0,   0,    0,    0 },   // 0xA3 '£'
  {     0,   0,   0,   0,    0,    0 },   // 0xA4 '¤'
  {     0,   0,   0,   0,    0,    0 },   // 0xA5 '¥'
  {     0,   0,   0,   0,    0,    0 },   // 0xA6 '¦'
  {     0,   0,   0,   0,    0,    0 },   // 0xA7 '§'
  {     0,   0,   0,   0,    0,    0 },   // 0xA8 '¨'
  {   245,   5,   5,   6,    0,   -6 },   // 0xA9 '©'
  {     0,   0,   0,   0,    0,    0 },   // 0xAA 'ª'
  {   249,   5,   5,   6,    0,   -6 },   // 0xAB '«'
  {     0,   0,   0,   0,    0,    0 },   // 0xAC '¬'
  {     0,   0,   0,   0,    0,    0 },   // 0xAD 'non-printable'
  {   253,   5,   7,   6,    0,   -7 },   // 0xAE '®'
  {     0,   0,   0,   0,    0,    0 },   // 0xAF '¯'
  {   258,   3,   3,   6,    1,   -7 },   // 0xB0 '°'
  {   260,   5,   6,   6,    0,   -6 },   // 0xB1 '±'
  {     0,   0,   0,   0,    0,    0 },   // 0xB2 '²'
  {     0,   0,   0,   0,    0,    0 },   // 0xB3 '³'
  {     0,   0,   0,   0,    0,    0 },   // 0xB4 '´'
  {     0,   0,   0,   0,    0,    0 },   // 0xB5 'µ'
  {   264,   5,   7,   6,    0,   -7 },   // 0xB6 '¶'
  {     0,   0,   0,   0,    0,    0 },   // 0xB7 '·'
  {     0,   0,   0,   0,    0,    0 },   // 0xB8 '¸'
  {     0,   0,   0,   0,    0,    0 },   // 0xB9 '¹'
  {     0,   0,   0,   0,    0,    0 },   // 0xBA 'º'
  {   269,   5,   5,   6,    0,   -6 }    // 0xBB '»'
};

const GFXfont CDU PROGMEM = {(uint8_t *) CDU_Bitmaps,    (GFXglyph *)CDU_Glyphs, 0x20, 0xBB,    8};
