/*
SDL_ColorDef.h v0.8
by Jonathan Dearborn

Just a bunch of defines for SDL color calls.  This is so you can set colors with
quick, short calls.  The advantage to having them as defines is that they take
up absolutely no space in your program, regardless of number of colors, unless
you use them.

Typically, one would use SDL_MapRGB, like so:
Uint32 color = SDL_MapRGB(surface->format, red, green, blue);

With SDL_ColorDef, it looks like:
Uint32 color = RGB_steelblue(surface);

Or with alpha:
SDL_MapRGBA(surface->format, red, green, blue, alpha);
RGBA_lightgreen(surface, alpha);

You get less typing and a specified color.  A very slight drawback is that
you need an actual surface (SDL_Surface*) to use the defines instead of a format
(SDL_PixelFormat*).  This was done to further reduce typing.  You can still
recover a similar functionality if you make a surface of zero width and
height just for a particular format.

Included are the W3C HTML colors.  They are all in lowercase to distinguish
them.  Also, some fixes were made to these colors (found below the main block
of colors).
<Gray was darker than darkgray and lightgoldenrodyellow is unnecessarily long>

v0.8 8-15-08: Fixed my colors to look right.  Switched to RGB prefix.  Added
  RGBA colors.  Added W3C web colors, found at...
http://www.w3schools.com/HTML/html_colornames.asp

Email me at Grimfang4@hotmail.com if you'd like to add some
colors in the official copy.

*/

#ifndef _SDL_COLORDEF_H__
#define _SDL_COLORDEF_H__

/* W3C colors */
#define RGB_aliceblue(surface) SDL_MapRGB(surface->format, 0xf0, 0xf8, 0xff)
#define RGB_antiquewhite(surface) SDL_MapRGB(surface->format, 0xfa, 0xeb, 0xd7)
#define RGB_aqua(surface) SDL_MapRGB(surface->format, 0x00, 0xff, 0xff)
#define RGB_aquamarine(surface) SDL_MapRGB(surface->format, 0x7f, 0xff, 0xd4)
#define RGB_azure(surface) SDL_MapRGB(surface->format, 0xf0, 0xff, 0xff)
#define RGB_beige(surface) SDL_MapRGB(surface->format, 0xf5, 0xf5, 0xdc)
#define RGB_bisque(surface) SDL_MapRGB(surface->format, 0xff, 0xe4, 0xc4)
#define RGB_black(surface) SDL_MapRGB(surface->format, 0x00, 0x00, 0x00)
#define RGB_blanchedalmond(surface) SDL_MapRGB(surface->format, 0xff, 0xeb, 0xcd)
#define RGB_blue(surface) SDL_MapRGB(surface->format, 0x00, 0x00, 0xff)
#define RGB_blueviolet(surface) SDL_MapRGB(surface->format, 0x8a, 0x2b, 0xe2)
#define RGB_brown(surface) SDL_MapRGB(surface->format, 0xa5, 0x2a, 0x2a)
#define RGB_burlywood(surface) SDL_MapRGB(surface->format, 0xde, 0xb8, 0x87)
#define RGB_cadetblue(surface) SDL_MapRGB(surface->format, 0x5f, 0x9e, 0xa0)
#define RGB_chartreuse(surface) SDL_MapRGB(surface->format, 0x7f, 0xff, 0x00)
#define RGB_chocolate(surface) SDL_MapRGB(surface->format, 0xd2, 0x69, 0x1e)
#define RGB_coral(surface) SDL_MapRGB(surface->format, 0xff, 0x7f, 0x50)
#define RGB_cornflowerblue(surface) SDL_MapRGB(surface->format, 0x64, 0x95, 0xed)
#define RGB_cornsilk(surface) SDL_MapRGB(surface->format, 0xff, 0xf8, 0xdc)
#define RGB_crimson(surface) SDL_MapRGB(surface->format, 0xdc, 0x14, 0x3c)
#define RGB_cyan(surface) SDL_MapRGB(surface->format, 0x00, 0xff, 0xff)
#define RGB_darkblue(surface) SDL_MapRGB(surface->format, 0x00, 0x00, 0x8b)
#define RGB_darkcyan(surface) SDL_MapRGB(surface->format, 0x00, 0x8b, 0x8b)
#define RGB_darkgoldenrod(surface) SDL_MapRGB(surface->format, 0xb8, 0x86, 0x0b)
#define RGB_darkgreen(surface) SDL_MapRGB(surface->format, 0x00, 0x64, 0x00)
#define RGB_darkkhaki(surface) SDL_MapRGB(surface->format, 0xbd, 0xb7, 0x6b)
#define RGB_darkmagenta(surface) SDL_MapRGB(surface->format, 0x8b, 0x00, 0x8b)
#define RGB_darkolivegreen(surface) SDL_MapRGB(surface->format, 0x55, 0x6b, 0x2f)
#define RGB_darkorange(surface) SDL_MapRGB(surface->format, 0xff, 0x8c, 0x00)
#define RGB_darkorchid(surface) SDL_MapRGB(surface->format, 0x99, 0x32, 0xcc)
#define RGB_darkred(surface) SDL_MapRGB(surface->format, 0x8b, 0x00, 0x00)
#define RGB_darksalmon(surface) SDL_MapRGB(surface->format, 0xe9, 0x96, 0x7a)
#define RGB_darkseagreen(surface) SDL_MapRGB(surface->format, 0x8f, 0xbc, 0x8f)
#define RGB_darkslateblue(surface) SDL_MapRGB(surface->format, 0x48, 0x3d, 0x8b)
#define RGB_darkslategray(surface) SDL_MapRGB(surface->format, 0x2f, 0x4f, 0x4f)
#define RGB_darkslategrey(surface) SDL_MapRGB(surface->format, 0x2f, 0x4f, 0x4f)
#define RGB_darkturquoise(surface) SDL_MapRGB(surface->format, 0x00, 0xce, 0xd1)
#define RGB_darkviolet(surface) SDL_MapRGB(surface->format, 0x94, 0x00, 0xd3)
#define RGB_deeppink(surface) SDL_MapRGB(surface->format, 0xff, 0x14, 0x93)
#define RGB_deepskyblue(surface) SDL_MapRGB(surface->format, 0x00, 0xbf, 0xff)
#define RGB_dimgray(surface) SDL_MapRGB(surface->format, 0x69, 0x69, 0x69)
#define RGB_dimgrey(surface) SDL_MapRGB(surface->format, 0x69, 0x69, 0x69)
#define RGB_dodgerblue(surface) SDL_MapRGB(surface->format, 0x1e, 0x90, 0xff)
#define RGB_firebrick(surface) SDL_MapRGB(surface->format, 0xb2, 0x22, 0x22)
#define RGB_floralwhite(surface) SDL_MapRGB(surface->format, 0xff, 0xfa, 0xf0)
#define RGB_forestgreen(surface) SDL_MapRGB(surface->format, 0x22, 0x8b, 0x22)
#define RGB_fuchsia(surface) SDL_MapRGB(surface->format, 0xff, 0x00, 0xff)
#define RGB_gainsboro(surface) SDL_MapRGB(surface->format, 0xdc, 0xdc, 0xdc)
#define RGB_ghostwhite(surface) SDL_MapRGB(surface->format, 0xf8, 0xf8, 0xff)
#define RGB_gold(surface) SDL_MapRGB(surface->format, 0xff, 0xd7, 0x00)
#define RGB_goldenrod(surface) SDL_MapRGB(surface->format, 0xda, 0xa5, 0x20)
#define RGB_green(surface) SDL_MapRGB(surface->format, 0x00, 0x80, 0x00)
#define RGB_greenyellow(surface) SDL_MapRGB(surface->format, 0xad, 0xff, 0x2f)
#define RGB_honeydew(surface) SDL_MapRGB(surface->format, 0xf0, 0xff, 0xf0)
#define RGB_hotpink(surface) SDL_MapRGB(surface->format, 0xff, 0x69, 0xb4)
#define RGB_indianred(surface) SDL_MapRGB(surface->format, 0xcd, 0x5c, 0x5c)
#define RGB_indigo(surface) SDL_MapRGB(surface->format, 0x4b, 0x00, 0x82)
#define RGB_ivory(surface) SDL_MapRGB(surface->format, 0xff, 0xff, 0xf0)
#define RGB_khaki(surface) SDL_MapRGB(surface->format, 0xf0, 0xe6, 0x8c)
#define RGB_lavender(surface) SDL_MapRGB(surface->format, 0xe6, 0xe6, 0xfa)
#define RGB_lavenderblush(surface) SDL_MapRGB(surface->format, 0xff, 0xf0, 0xf5)
#define RGB_lawngreen(surface) SDL_MapRGB(surface->format, 0x7c, 0xfc, 0x00)
#define RGB_lemonchiffon(surface) SDL_MapRGB(surface->format, 0xff, 0xfa, 0xcd)
#define RGB_lightblue(surface) SDL_MapRGB(surface->format, 0xad, 0xd8, 0xe6)
#define RGB_lightcoral(surface) SDL_MapRGB(surface->format, 0xf0, 0x80, 0x80)
#define RGB_lightcyan(surface) SDL_MapRGB(surface->format, 0xe0, 0xff, 0xff)
#define RGB_lightgoldenrodyellow(surface) SDL_MapRGB(surface->format, 0xfa, 0xfa, 0xd2)
#define RGB_lightgray(surface) SDL_MapRGB(surface->format, 0xd3, 0xd3, 0xd3)
#define RGB_lightgrey(surface) SDL_MapRGB(surface->format, 0xd3, 0xd3, 0xd3)
#define RGB_lightgreen(surface) SDL_MapRGB(surface->format, 0x90, 0xee, 0x90)
#define RGB_lightpink(surface) SDL_MapRGB(surface->format, 0xff, 0xb6, 0xc1)
#define RGB_lightsalmon(surface) SDL_MapRGB(surface->format, 0xff, 0xa0, 0x7a)
#define RGB_lightseagreen(surface) SDL_MapRGB(surface->format, 0x20, 0xb2, 0xaa)
#define RGB_lightskyblue(surface) SDL_MapRGB(surface->format, 0x87, 0xce, 0xfa)
#define RGB_lightslategray(surface) SDL_MapRGB(surface->format, 0x77, 0x88, 0x99)
#define RGB_lightslategrey(surface) SDL_MapRGB(surface->format, 0x77, 0x88, 0x99)
#define RGB_lightsteelblue(surface) SDL_MapRGB(surface->format, 0xb0, 0xc4, 0xde)
#define RGB_lightyellow(surface) SDL_MapRGB(surface->format, 0xff, 0xff, 0xe0)
#define RGB_lime(surface) SDL_MapRGB(surface->format, 0x00, 0xff, 0x00)
#define RGB_limegreen(surface) SDL_MapRGB(surface->format, 0x32, 0xcd, 0x32)
#define RGB_linen(surface) SDL_MapRGB(surface->format, 0xfa, 0xf0, 0xe6)
#define RGB_magenta(surface) SDL_MapRGB(surface->format, 0xff, 0x00, 0xff)
#define RGB_maroon(surface) SDL_MapRGB(surface->format, 0x80, 0x00, 0x00)
#define RGB_mediumaquamarine(surface) SDL_MapRGB(surface->format, 0x66, 0xcd, 0xaa)
#define RGB_mediumblue(surface) SDL_MapRGB(surface->format, 0x00, 0x00, 0xcd)
#define RGB_mediumorchid(surface) SDL_MapRGB(surface->format, 0xba, 0x55, 0xd3)
#define RGB_mediumpurple(surface) SDL_MapRGB(surface->format, 0x93, 0x70, 0xd8)
#define RGB_mediumseagreen(surface) SDL_MapRGB(surface->format, 0x3c, 0xb3, 0x71)
#define RGB_mediumslateblue(surface) SDL_MapRGB(surface->format, 0x7b, 0x68, 0xee)
#define RGB_mediumspringgreen(surface) SDL_MapRGB(surface->format, 0x00, 0xfa, 0x9a)
#define RGB_mediumturquoise(surface) SDL_MapRGB(surface->format, 0x48, 0xd1, 0xcc)
#define RGB_mediumvioletred(surface) SDL_MapRGB(surface->format, 0xc7, 0x15, 0x85)
#define RGB_midnightblue(surface) SDL_MapRGB(surface->format, 0x19, 0x19, 0x70)
#define RGB_mintcream(surface) SDL_MapRGB(surface->format, 0xf5, 0xff, 0xfa)
#define RGB_mistyrose(surface) SDL_MapRGB(surface->format, 0xff, 0xe4, 0xe1)
#define RGB_moccasin(surface) SDL_MapRGB(surface->format, 0xff, 0xe4, 0xb5)
#define RGB_navajowhite(surface) SDL_MapRGB(surface->format, 0xff, 0xde, 0xad)
#define RGB_navy(surface) SDL_MapRGB(surface->format, 0x00, 0x00, 0x80)
#define RGB_oldlace(surface) SDL_MapRGB(surface->format, 0xfd, 0xf5, 0xe6)
#define RGB_olive(surface) SDL_MapRGB(surface->format, 0x80, 0x80, 0x00)
#define RGB_olivedrab(surface) SDL_MapRGB(surface->format, 0x6b, 0x8e, 0x23)
#define RGB_orange(surface) SDL_MapRGB(surface->format, 0xff, 0xa5, 0x00)
#define RGB_orangered(surface) SDL_MapRGB(surface->format, 0xff, 0x45, 0x00)
#define RGB_orchid(surface) SDL_MapRGB(surface->format, 0xda, 0x70, 0xd6)
#define RGB_palegoldenrod(surface) SDL_MapRGB(surface->format, 0xee, 0xe8, 0xaa)
#define RGB_palegreen(surface) SDL_MapRGB(surface->format, 0x98, 0xfb, 0x98)
#define RGB_paleturquoise(surface) SDL_MapRGB(surface->format, 0xaf, 0xee, 0xee)
#define RGB_palevioletred(surface) SDL_MapRGB(surface->format, 0xd8, 0x70, 0x93)
#define RGB_papayawhip(surface) SDL_MapRGB(surface->format, 0xff, 0xef, 0xd5)
#define RGB_peachpuff(surface) SDL_MapRGB(surface->format, 0xff, 0xda, 0xb9)
#define RGB_peru(surface) SDL_MapRGB(surface->format, 0xcd, 0x85, 0x3f)
#define RGB_pink(surface) SDL_MapRGB(surface->format, 0xff, 0xc0, 0xcb)
#define RGB_plum(surface) SDL_MapRGB(surface->format, 0xdd, 0xa0, 0xdd)
#define RGB_powderblue(surface) SDL_MapRGB(surface->format, 0xb0, 0xe0, 0xe6)
#define RGB_purple(surface) SDL_MapRGB(surface->format, 0x80, 0x00, 0x80)
#define RGB_red(surface) SDL_MapRGB(surface->format, 0xff, 0x00, 0x00)
#define RGB_rosybrown(surface) SDL_MapRGB(surface->format, 0xbc, 0x8f, 0x8f)
#define RGB_royalblue(surface) SDL_MapRGB(surface->format, 0x41, 0x69, 0xe1)
#define RGB_saddlebrown(surface) SDL_MapRGB(surface->format, 0x8b, 0x45, 0x13)
#define RGB_salmon(surface) SDL_MapRGB(surface->format, 0xfa, 0x80, 0x72)
#define RGB_sandybrown(surface) SDL_MapRGB(surface->format, 0xf4, 0xa4, 0x60)
#define RGB_seagreen(surface) SDL_MapRGB(surface->format, 0x2e, 0x8b, 0x57)
#define RGB_sienna(surface) SDL_MapRGB(surface->format, 0xa0, 0x52, 0x2d)
#define RGB_silver(surface) SDL_MapRGB(surface->format, 0xc0, 0xc0, 0xc0)
#define RGB_skyblue(surface) SDL_MapRGB(surface->format, 0x87, 0xce, 0xeb)
#define RGB_slateblue(surface) SDL_MapRGB(surface->format, 0x6a, 0x5a, 0xcd)
#define RGB_slategray(surface) SDL_MapRGB(surface->format, 0x70, 0x80, 0x90)
#define RGB_slategrey(surface) SDL_MapRGB(surface->format, 0x70, 0x80, 0x90)
#define RGB_snow(surface) SDL_MapRGB(surface->format, 0xff, 0xfa, 0xfa)
#define RGB_springgreen(surface) SDL_MapRGB(surface->format, 0x00, 0xff, 0x7f)
#define RGB_steelblue(surface) SDL_MapRGB(surface->format, 0x46, 0x82, 0xb4)
#define RGB_tan(surface) SDL_MapRGB(surface->format, 0xd2, 0xb4, 0x8c)
#define RGB_teal(surface) SDL_MapRGB(surface->format, 0x00, 0x80, 0x80)
#define RGB_thistle(surface) SDL_MapRGB(surface->format, 0xd8, 0xbf, 0xd8)
#define RGB_tomato(surface) SDL_MapRGB(surface->format, 0xff, 0x63, 0x47)
#define RGB_turquoise(surface) SDL_MapRGB(surface->format, 0x40, 0xe0, 0xd0)
#define RGB_violet(surface) SDL_MapRGB(surface->format, 0xee, 0x82, 0xee)
#define RGB_wheat(surface) SDL_MapRGB(surface->format, 0xf5, 0xde, 0xb3)
#define RGB_white(surface) SDL_MapRGB(surface->format, 0xff, 0xff, 0xff)
#define RGB_whitesmoke(surface) SDL_MapRGB(surface->format, 0xf5, 0xf5, 0xf5)
#define RGB_yellow(surface) SDL_MapRGB(surface->format, 0xff, 0xff, 0x00)
#define RGB_yellowgreen(surface) SDL_MapRGB(surface->format, 0x9a, 0xcd, 0x32)
/* Fixed W3C colors */
#define RGB_darkgray(surface) SDL_MapRGB(surface->format, 0x80, 0x80, 0x80)
#define RGB_darkgrey(surface) SDL_MapRGB(surface->format, 0x80, 0x80, 0x80)
#define RGB_gray(surface) SDL_MapRGB(surface->format, 0xa9, 0xa9, 0xa9)
#define RGB_grey(surface) SDL_MapRGB(surface->format, 0xa9, 0xa9, 0xa9)
#define RGB_lightgoldenrod(surface) SDL_MapRGB(surface->format, 0xfa, 0xfa, 0xd2)



/* My colors */
#define RGB_REDVDK(surface) SDL_MapRGB(surface->format, 64, 0, 0)
#define RGB_REDDK(surface) SDL_MapRGB(surface->format, 128, 0, 0)
#define RGB_RED(surface) SDL_MapRGB(surface->format, 255, 0, 0)
#define RGB_REDLT(surface) SDL_MapRGB(surface->format, 255, 128, 128)
#define RGB_REDVLT(surface) SDL_MapRGB(surface->format, 255, 192, 192)

#define RGB_GREENVDK(surface) SDL_MapRGB(surface->format, 0, 64, 0)
#define RGB_GREENDK(surface) SDL_MapRGB(surface->format, 0, 128, 0)
#define RGB_GREEN(surface) SDL_MapRGB(surface->format, 0, 255, 0)
#define RGB_GREENLT(surface) SDL_MapRGB(surface->format, 128, 255, 128)
#define RGB_GREENVLT(surface) SDL_MapRGB(surface->format, 192, 255, 192)

#define RGB_BLUEVDK(surface) SDL_MapRGB(surface->format, 0, 0, 64)
#define RGB_BLUEDK(surface) SDL_MapRGB(surface->format, 0, 0, 128)
#define RGB_BLUE(surface) SDL_MapRGB(surface->format, 0, 0, 255)
#define RGB_BLUELT(surface) SDL_MapRGB(surface->format, 64, 128, 255)
#define RGB_BLUEVLT(surface) SDL_MapRGB(surface->format, 96, 192, 255)

#define RGB_PERIWINKLEVDK(surface) SDL_MapRGB(surface->format, 32, 32, 64)
#define RGB_PERIWINKLEDK(surface) SDL_MapRGB(surface->format, 64, 64, 128)
#define RGB_PERIWINKLE(surface) SDL_MapRGB(surface->format, 128, 128, 255)
#define RGB_PERIWINKLELT(surface) SDL_MapRGB(surface->format, 192, 192, 255)
#define RGB_PERIWINKLEVLT(surface) SDL_MapRGB(surface->format, 224, 224, 255)

#define RGB_LAVENDERVDK(surface) SDL_MapRGB(surface->format, 96, 32, 160)
#define RGB_LAVENDERDK(surface) SDL_MapRGB(surface->format, 128, 64, 192)
#define RGB_LAVENDER(surface) SDL_MapRGB(surface->format, 160, 96, 212)
#define RGB_LAVENDERLT(surface) SDL_MapRGB(surface->format, 192, 128, 255)
#define RGB_LAVENDERVLT(surface) SDL_MapRGB(surface->format, 224, 160, 255)


#define RGB_PURPLEVDK(surface) SDL_MapRGB(surface->format, 64, 0, 96)
#define RGB_PURPLEDK(surface) SDL_MapRGB(surface->format, 96, 0, 128)
#define RGB_PURPLE(surface) SDL_MapRGB(surface->format, 128, 0, 160)
#define RGB_PURPLELT(surface) SDL_MapRGB(surface->format, 192, 64, 212)
#define RGB_PURPLEVLT(surface) SDL_MapRGB(surface->format, 212, 128, 255)



#define RGB_BRIGHTPINK(surface) SDL_MapRGB(surface->format, 255, 0, 255)

#define RGB_PINKVDK(surface) SDL_MapRGB(surface->format, 128, 64, 96)
#define RGB_PINKDK(surface) SDL_MapRGB(surface->format, 212, 92, 212)
#define RGB_PINK(surface) SDL_MapRGB(surface->format, 255, 128, 255)
#define RGB_PINKLT(surface) SDL_MapRGB(surface->format, 255, 160, 255)
#define RGB_PINKVLT(surface) SDL_MapRGB(surface->format, 255, 192, 255)

#define RGB_YELLOWVDK(surface) SDL_MapRGB(surface->format, 64, 64, 0)
#define RGB_YELLOWDK(surface) SDL_MapRGB(surface->format, 128, 128, 0)
#define RGB_YELLOW(surface) SDL_MapRGB(surface->format, 255, 255, 0)
#define RGB_YELLOWLT(surface) SDL_MapRGB(surface->format, 255, 255, 128)
#define RGB_YELLOWVLT(surface) SDL_MapRGB(surface->format, 255, 255, 192)

#define RGB_ORANGEVDK(surface) SDL_MapRGB(surface->format, 180, 64, 0)
#define RGB_ORANGEDK(surface) SDL_MapRGB(surface->format, 224, 96, 0)
#define RGB_ORANGE(surface) SDL_MapRGB(surface->format, 255, 128, 0)
#define RGB_ORANGELT(surface) SDL_MapRGB(surface->format, 255, 160, 32)
#define RGB_ORANGEVLT(surface) SDL_MapRGB(surface->format, 255, 192, 64)

#define RGB_BROWNVDK(surface) SDL_MapRGB(surface->format, 32, 16, 0)
#define RGB_BROWNDK(surface) SDL_MapRGB(surface->format, 64, 32, 0)
#define RGB_BROWN(surface) SDL_MapRGB(surface->format, 128, 64, 0)
#define RGB_BROWNLT(surface) SDL_MapRGB(surface->format, 192, 128, 32)
#define RGB_BROWNVLT(surface) SDL_MapRGB(surface->format, 255, 192, 64)

#define RGB_TEALVDK(surface) SDL_MapRGB(surface->format, 0, 64, 64)
#define RGB_TEALDK(surface) SDL_MapRGB(surface->format, 0, 128, 128)
#define RGB_TEAL(surface) SDL_MapRGB(surface->format, 0, 255, 255)
#define RGB_TEALLT(surface) SDL_MapRGB(surface->format, 128, 255, 255)
#define RGB_TEALVLT(surface) SDL_MapRGB(surface->format, 192, 255, 255)

#define RGB_TURQUOISEVDK(surface) SDL_MapRGB(surface->format, 0, 64, 64)
#define RGB_TURQUOISEDK(surface) SDL_MapRGB(surface->format, 0, 128, 128)
#define RGB_TURQUOISE(surface) SDL_MapRGB(surface->format, 0, 255, 255)
#define RGB_TURQUOISELT(surface) SDL_MapRGB(surface->format, 128, 255, 255)
#define RGB_TURQUOISEVLT(surface) SDL_MapRGB(surface->format, 192, 255, 255)

#define RGB_BLACK(surface) SDL_MapRGB(surface->format, 0, 0, 0)
#define RGB_BLACK1(surface) SDL_MapRGB(surface->format, 1, 1, 1)
#define RGB_BLACK2(surface) SDL_MapRGB(surface->format, 2, 2, 2)

#define RGB_GRAYVDK(surface) SDL_MapRGB(surface->format, 32, 32, 32)
#define RGB_GRAYDK(surface) SDL_MapRGB(surface->format, 64, 64, 64)
#define RGB_GRAY(surface) SDL_MapRGB(surface->format, 128, 128, 128)
#define RGB_GRAYLT(surface) SDL_MapRGB(surface->format, 192, 192, 192)
#define RGB_GRAYVLT(surface) SDL_MapRGB(surface->format, 224, 224, 224)

#define RGB_WHITE(surface) SDL_MapRGB(surface->format, 255, 255, 255)
#define RGB_WHITE1(surface) SDL_MapRGB(surface->format, 254, 254, 254)
#define RGB_WHITE2(surface) SDL_MapRGB(surface->format, 253, 253, 253)
#define RGB_WHITEOFF(surface) SDL_MapRGB(surface->format, 255, 255, 224)



// RGBA -----------------------------


/* W3C colors */
#define RGBA_aliceblue(surface, alpha) SDL_MapRGBA(surface->format, 0xf0, 0xf8, 0xff, alpha)
#define RGBA_antiquewhite(surface, alpha) SDL_MapRGBA(surface->format, 0xfa, 0xeb, 0xd7, alpha)
#define RGBA_aqua(surface, alpha) SDL_MapRGBA(surface->format, 0x00, 0xff, 0xff, alpha)
#define RGBA_aquamarine(surface, alpha) SDL_MapRGBA(surface->format, 0x7f, 0xff, 0xd4, alpha)
#define RGBA_azure(surface, alpha) SDL_MapRGBA(surface->format, 0xf0, 0xff, 0xff, alpha)
#define RGBA_beige(surface, alpha) SDL_MapRGBA(surface->format, 0xf5, 0xf5, 0xdc, alpha)
#define RGBA_bisque(surface, alpha) SDL_MapRGBA(surface->format, 0xff, 0xe4, 0xc4, alpha)
#define RGBA_black(surface, alpha) SDL_MapRGBA(surface->format, 0x00, 0x00, 0x00, alpha)
#define RGBA_blanchedalmond(surface, alpha) SDL_MapRGBA(surface->format, 0xff, 0xeb, 0xcd, alpha)
#define RGBA_blue(surface, alpha) SDL_MapRGBA(surface->format, 0x00, 0x00, 0xff, alpha)
#define RGBA_blueviolet(surface, alpha) SDL_MapRGBA(surface->format, 0x8a, 0x2b, 0xe2, alpha)
#define RGBA_brown(surface, alpha) SDL_MapRGBA(surface->format, 0xa5, 0x2a, 0x2a, alpha)
#define RGBA_burlywood(surface, alpha) SDL_MapRGBA(surface->format, 0xde, 0xb8, 0x87, alpha)
#define RGBA_cadetblue(surface, alpha) SDL_MapRGBA(surface->format, 0x5f, 0x9e, 0xa0, alpha)
#define RGBA_chartreuse(surface, alpha) SDL_MapRGBA(surface->format, 0x7f, 0xff, 0x00, alpha)
#define RGBA_chocolate(surface, alpha) SDL_MapRGBA(surface->format, 0xd2, 0x69, 0x1e, alpha)
#define RGBA_coral(surface, alpha) SDL_MapRGBA(surface->format, 0xff, 0x7f, 0x50, alpha)
#define RGBA_cornflowerblue(surface, alpha) SDL_MapRGBA(surface->format, 0x64, 0x95, 0xed, alpha)
#define RGBA_cornsilk(surface, alpha) SDL_MapRGBA(surface->format, 0xff, 0xf8, 0xdc, alpha)
#define RGBA_crimson(surface, alpha) SDL_MapRGBA(surface->format, 0xdc, 0x14, 0x3c, alpha)
#define RGBA_cyan(surface, alpha) SDL_MapRGBA(surface->format, 0x00, 0xff, 0xff, alpha)
#define RGBA_darkblue(surface, alpha) SDL_MapRGBA(surface->format, 0x00, 0x00, 0x8b, alpha)
#define RGBA_darkcyan(surface, alpha) SDL_MapRGBA(surface->format, 0x00, 0x8b, 0x8b, alpha)
#define RGBA_darkgoldenrod(surface, alpha) SDL_MapRGBA(surface->format, 0xb8, 0x86, 0x0b, alpha)
#define RGBA_darkgreen(surface, alpha) SDL_MapRGBA(surface->format, 0x00, 0x64, 0x00, alpha)
#define RGBA_darkkhaki(surface, alpha) SDL_MapRGBA(surface->format, 0xbd, 0xb7, 0x6b, alpha)
#define RGBA_darkmagenta(surface, alpha) SDL_MapRGBA(surface->format, 0x8b, 0x00, 0x8b, alpha)
#define RGBA_darkolivegreen(surface, alpha) SDL_MapRGBA(surface->format, 0x55, 0x6b, 0x2f, alpha)
#define RGBA_darkorange(surface, alpha) SDL_MapRGBA(surface->format, 0xff, 0x8c, 0x00, alpha)
#define RGBA_darkorchid(surface, alpha) SDL_MapRGBA(surface->format, 0x99, 0x32, 0xcc, alpha)
#define RGBA_darkred(surface, alpha) SDL_MapRGBA(surface->format, 0x8b, 0x00, 0x00, alpha)
#define RGBA_darksalmon(surface, alpha) SDL_MapRGBA(surface->format, 0xe9, 0x96, 0x7a, alpha)
#define RGBA_darkseagreen(surface, alpha) SDL_MapRGBA(surface->format, 0x8f, 0xbc, 0x8f, alpha)
#define RGBA_darkslateblue(surface, alpha) SDL_MapRGBA(surface->format, 0x48, 0x3d, 0x8b, alpha)
#define RGBA_darkslategray(surface, alpha) SDL_MapRGBA(surface->format, 0x2f, 0x4f, 0x4f, alpha)
#define RGBA_darkslategrey(surface, alpha) SDL_MapRGBA(surface->format, 0x2f, 0x4f, 0x4f, alpha)
#define RGBA_darkturquoise(surface, alpha) SDL_MapRGBA(surface->format, 0x00, 0xce, 0xd1, alpha)
#define RGBA_darkviolet(surface, alpha) SDL_MapRGBA(surface->format, 0x94, 0x00, 0xd3, alpha)
#define RGBA_deeppink(surface, alpha) SDL_MapRGBA(surface->format, 0xff, 0x14, 0x93, alpha)
#define RGBA_deepskyblue(surface, alpha) SDL_MapRGBA(surface->format, 0x00, 0xbf, 0xff, alpha)
#define RGBA_dimgray(surface, alpha) SDL_MapRGBA(surface->format, 0x69, 0x69, 0x69, alpha)
#define RGBA_dimgrey(surface, alpha) SDL_MapRGBA(surface->format, 0x69, 0x69, 0x69, alpha)
#define RGBA_dodgerblue(surface, alpha) SDL_MapRGBA(surface->format, 0x1e, 0x90, 0xff, alpha)
#define RGBA_firebrick(surface, alpha) SDL_MapRGBA(surface->format, 0xb2, 0x22, 0x22, alpha)
#define RGBA_floralwhite(surface, alpha) SDL_MapRGBA(surface->format, 0xff, 0xfa, 0xf0, alpha)
#define RGBA_forestgreen(surface, alpha) SDL_MapRGBA(surface->format, 0x22, 0x8b, 0x22, alpha)
#define RGBA_fuchsia(surface, alpha) SDL_MapRGBA(surface->format, 0xff, 0x00, 0xff, alpha)
#define RGBA_gainsboro(surface, alpha) SDL_MapRGBA(surface->format, 0xdc, 0xdc, 0xdc, alpha)
#define RGBA_ghostwhite(surface, alpha) SDL_MapRGBA(surface->format, 0xf8, 0xf8, 0xff, alpha)
#define RGBA_gold(surface, alpha) SDL_MapRGBA(surface->format, 0xff, 0xd7, 0x00, alpha)
#define RGBA_goldenrod(surface, alpha) SDL_MapRGBA(surface->format, 0xda, 0xa5, 0x20, alpha)
#define RGBA_green(surface, alpha) SDL_MapRGBA(surface->format, 0x00, 0x80, 0x00, alpha)
#define RGBA_greenyellow(surface, alpha) SDL_MapRGBA(surface->format, 0xad, 0xff, 0x2f, alpha)
#define RGBA_honeydew(surface, alpha) SDL_MapRGBA(surface->format, 0xf0, 0xff, 0xf0, alpha)
#define RGBA_hotpink(surface, alpha) SDL_MapRGBA(surface->format, 0xff, 0x69, 0xb4, alpha)
#define RGBA_indianred(surface, alpha) SDL_MapRGBA(surface->format, 0xcd, 0x5c, 0x5c, alpha)
#define RGBA_indigo(surface, alpha) SDL_MapRGBA(surface->format, 0x4b, 0x00, 0x82, alpha)
#define RGBA_ivory(surface, alpha) SDL_MapRGBA(surface->format, 0xff, 0xff, 0xf0, alpha)
#define RGBA_khaki(surface, alpha) SDL_MapRGBA(surface->format, 0xf0, 0xe6, 0x8c, alpha)
#define RGBA_lavender(surface, alpha) SDL_MapRGBA(surface->format, 0xe6, 0xe6, 0xfa, alpha)
#define RGBA_lavenderblush(surface, alpha) SDL_MapRGBA(surface->format, 0xff, 0xf0, 0xf5, alpha)
#define RGBA_lawngreen(surface, alpha) SDL_MapRGBA(surface->format, 0x7c, 0xfc, 0x00, alpha)
#define RGBA_lemonchiffon(surface, alpha) SDL_MapRGBA(surface->format, 0xff, 0xfa, 0xcd, alpha)
#define RGBA_lightblue(surface, alpha) SDL_MapRGBA(surface->format, 0xad, 0xd8, 0xe6, alpha)
#define RGBA_lightcoral(surface, alpha) SDL_MapRGBA(surface->format, 0xf0, 0x80, 0x80, alpha)
#define RGBA_lightcyan(surface, alpha) SDL_MapRGBA(surface->format, 0xe0, 0xff, 0xff, alpha)
#define RGBA_lightgoldenrodyellow(surface, alpha) SDL_MapRGBA(surface->format, 0xfa, 0xfa, 0xd2, alpha)
#define RGBA_lightgray(surface, alpha) SDL_MapRGBA(surface->format, 0xd3, 0xd3, 0xd3, alpha)
#define RGBA_lightgrey(surface, alpha) SDL_MapRGBA(surface->format, 0xd3, 0xd3, 0xd3, alpha)
#define RGBA_lightgreen(surface, alpha) SDL_MapRGBA(surface->format, 0x90, 0xee, 0x90, alpha)
#define RGBA_lightpink(surface, alpha) SDL_MapRGBA(surface->format, 0xff, 0xb6, 0xc1, alpha)
#define RGBA_lightsalmon(surface, alpha) SDL_MapRGBA(surface->format, 0xff, 0xa0, 0x7a, alpha)
#define RGBA_lightseagreen(surface, alpha) SDL_MapRGBA(surface->format, 0x20, 0xb2, 0xaa, alpha)
#define RGBA_lightskyblue(surface, alpha) SDL_MapRGBA(surface->format, 0x87, 0xce, 0xfa, alpha)
#define RGBA_lightslategray(surface, alpha) SDL_MapRGBA(surface->format, 0x77, 0x88, 0x99, alpha)
#define RGBA_lightslategrey(surface, alpha) SDL_MapRGBA(surface->format, 0x77, 0x88, 0x99, alpha)
#define RGBA_lightsteelblue(surface, alpha) SDL_MapRGBA(surface->format, 0xb0, 0xc4, 0xde, alpha)
#define RGBA_lightyellow(surface, alpha) SDL_MapRGBA(surface->format, 0xff, 0xff, 0xe0, alpha)
#define RGBA_lime(surface, alpha) SDL_MapRGBA(surface->format, 0x00, 0xff, 0x00, alpha)
#define RGBA_limegreen(surface, alpha) SDL_MapRGBA(surface->format, 0x32, 0xcd, 0x32, alpha)
#define RGBA_linen(surface, alpha) SDL_MapRGBA(surface->format, 0xfa, 0xf0, 0xe6, alpha)
#define RGBA_magenta(surface, alpha) SDL_MapRGBA(surface->format, 0xff, 0x00, 0xff, alpha)
#define RGBA_maroon(surface, alpha) SDL_MapRGBA(surface->format, 0x80, 0x00, 0x00, alpha)
#define RGBA_mediumaquamarine(surface, alpha) SDL_MapRGBA(surface->format, 0x66, 0xcd, 0xaa, alpha)
#define RGBA_mediumblue(surface, alpha) SDL_MapRGBA(surface->format, 0x00, 0x00, 0xcd, alpha)
#define RGBA_mediumorchid(surface, alpha) SDL_MapRGBA(surface->format, 0xba, 0x55, 0xd3, alpha)
#define RGBA_mediumpurple(surface, alpha) SDL_MapRGBA(surface->format, 0x93, 0x70, 0xd8, alpha)
#define RGBA_mediumseagreen(surface, alpha) SDL_MapRGBA(surface->format, 0x3c, 0xb3, 0x71, alpha)
#define RGBA_mediumslateblue(surface, alpha) SDL_MapRGBA(surface->format, 0x7b, 0x68, 0xee, alpha)
#define RGBA_mediumspringgreen(surface, alpha) SDL_MapRGBA(surface->format, 0x00, 0xfa, 0x9a, alpha)
#define RGBA_mediumturquoise(surface, alpha) SDL_MapRGBA(surface->format, 0x48, 0xd1, 0xcc, alpha)
#define RGBA_mediumvioletred(surface, alpha) SDL_MapRGBA(surface->format, 0xc7, 0x15, 0x85, alpha)
#define RGBA_midnightblue(surface, alpha) SDL_MapRGBA(surface->format, 0x19, 0x19, 0x70, alpha)
#define RGBA_mintcream(surface, alpha) SDL_MapRGBA(surface->format, 0xf5, 0xff, 0xfa, alpha)
#define RGBA_mistyrose(surface, alpha) SDL_MapRGBA(surface->format, 0xff, 0xe4, 0xe1, alpha)
#define RGBA_moccasin(surface, alpha) SDL_MapRGBA(surface->format, 0xff, 0xe4, 0xb5, alpha)
#define RGBA_navajowhite(surface, alpha) SDL_MapRGBA(surface->format, 0xff, 0xde, 0xad, alpha)
#define RGBA_navy(surface, alpha) SDL_MapRGBA(surface->format, 0x00, 0x00, 0x80, alpha)
#define RGBA_oldlace(surface, alpha) SDL_MapRGBA(surface->format, 0xfd, 0xf5, 0xe6, alpha)
#define RGBA_olive(surface, alpha) SDL_MapRGBA(surface->format, 0x80, 0x80, 0x00, alpha)
#define RGBA_olivedrab(surface, alpha) SDL_MapRGBA(surface->format, 0x6b, 0x8e, 0x23, alpha)
#define RGBA_orange(surface, alpha) SDL_MapRGBA(surface->format, 0xff, 0xa5, 0x00, alpha)
#define RGBA_orangered(surface, alpha) SDL_MapRGBA(surface->format, 0xff, 0x45, 0x00, alpha)
#define RGBA_orchid(surface, alpha) SDL_MapRGBA(surface->format, 0xda, 0x70, 0xd6, alpha)
#define RGBA_palegoldenrod(surface, alpha) SDL_MapRGBA(surface->format, 0xee, 0xe8, 0xaa, alpha)
#define RGBA_palegreen(surface, alpha) SDL_MapRGBA(surface->format, 0x98, 0xfb, 0x98, alpha)
#define RGBA_paleturquoise(surface, alpha) SDL_MapRGBA(surface->format, 0xaf, 0xee, 0xee, alpha)
#define RGBA_palevioletred(surface, alpha) SDL_MapRGBA(surface->format, 0xd8, 0x70, 0x93, alpha)
#define RGBA_papayawhip(surface, alpha) SDL_MapRGBA(surface->format, 0xff, 0xef, 0xd5, alpha)
#define RGBA_peachpuff(surface, alpha) SDL_MapRGBA(surface->format, 0xff, 0xda, 0xb9, alpha)
#define RGBA_peru(surface, alpha) SDL_MapRGBA(surface->format, 0xcd, 0x85, 0x3f, alpha)
#define RGBA_pink(surface, alpha) SDL_MapRGBA(surface->format, 0xff, 0xc0, 0xcb, alpha)
#define RGBA_plum(surface, alpha) SDL_MapRGBA(surface->format, 0xdd, 0xa0, 0xdd, alpha)
#define RGBA_powderblue(surface, alpha) SDL_MapRGBA(surface->format, 0xb0, 0xe0, 0xe6, alpha)
#define RGBA_purple(surface, alpha) SDL_MapRGBA(surface->format, 0x80, 0x00, 0x80, alpha)
#define RGBA_red(surface, alpha) SDL_MapRGBA(surface->format, 0xff, 0x00, 0x00, alpha)
#define RGBA_rosybrown(surface, alpha) SDL_MapRGBA(surface->format, 0xbc, 0x8f, 0x8f, alpha)
#define RGBA_royalblue(surface, alpha) SDL_MapRGBA(surface->format, 0x41, 0x69, 0xe1, alpha)
#define RGBA_saddlebrown(surface, alpha) SDL_MapRGBA(surface->format, 0x8b, 0x45, 0x13, alpha)
#define RGBA_salmon(surface, alpha) SDL_MapRGBA(surface->format, 0xfa, 0x80, 0x72, alpha)
#define RGBA_sandybrown(surface, alpha) SDL_MapRGBA(surface->format, 0xf4, 0xa4, 0x60, alpha)
#define RGBA_seagreen(surface, alpha) SDL_MapRGBA(surface->format, 0x2e, 0x8b, 0x57, alpha)
#define RGBA_sienna(surface, alpha) SDL_MapRGBA(surface->format, 0xa0, 0x52, 0x2d, alpha)
#define RGBA_silver(surface, alpha) SDL_MapRGBA(surface->format, 0xc0, 0xc0, 0xc0, alpha)
#define RGBA_skyblue(surface, alpha) SDL_MapRGBA(surface->format, 0x87, 0xce, 0xeb, alpha)
#define RGBA_slateblue(surface, alpha) SDL_MapRGBA(surface->format, 0x6a, 0x5a, 0xcd, alpha)
#define RGBA_slategray(surface, alpha) SDL_MapRGBA(surface->format, 0x70, 0x80, 0x90, alpha)
#define RGBA_slategrey(surface, alpha) SDL_MapRGBA(surface->format, 0x70, 0x80, 0x90, alpha)
#define RGBA_snow(surface, alpha) SDL_MapRGBA(surface->format, 0xff, 0xfa, 0xfa, alpha)
#define RGBA_springgreen(surface, alpha) SDL_MapRGBA(surface->format, 0x00, 0xff, 0x7f, alpha)
#define RGBA_steelblue(surface, alpha) SDL_MapRGBA(surface->format, 0x46, 0x82, 0xb4, alpha)
#define RGBA_tan(surface, alpha) SDL_MapRGBA(surface->format, 0xd2, 0xb4, 0x8c, alpha)
#define RGBA_teal(surface, alpha) SDL_MapRGBA(surface->format, 0x00, 0x80, 0x80, alpha)
#define RGBA_thistle(surface, alpha) SDL_MapRGBA(surface->format, 0xd8, 0xbf, 0xd8, alpha)
#define RGBA_tomato(surface, alpha) SDL_MapRGBA(surface->format, 0xff, 0x63, 0x47, alpha)
#define RGBA_turquoise(surface, alpha) SDL_MapRGBA(surface->format, 0x40, 0xe0, 0xd0, alpha)
#define RGBA_violet(surface, alpha) SDL_MapRGBA(surface->format, 0xee, 0x82, 0xee, alpha)
#define RGBA_wheat(surface, alpha) SDL_MapRGBA(surface->format, 0xf5, 0xde, 0xb3, alpha)
#define RGBA_white(surface, alpha) SDL_MapRGBA(surface->format, 0xff, 0xff, 0xff, alpha)
#define RGBA_whitesmoke(surface, alpha) SDL_MapRGBA(surface->format, 0xf5, 0xf5, 0xf5, alpha)
#define RGBA_yellow(surface, alpha) SDL_MapRGBA(surface->format, 0xff, 0xff, 0x00, alpha)
#define RGBA_yellowgreen(surface, alpha) SDL_MapRGBA(surface->format, 0x9a, 0xcd, 0x32, alpha)
/* Fixed W3C colors */
#define RGBA_darkgray(surface, alpha) SDL_MapRGBA(surface->format, 0x80, 0x80, 0x80, alpha)
#define RGBA_darkgrey(surface, alpha) SDL_MapRGBA(surface->format, 0x80, 0x80, 0x80, alpha)
#define RGBA_gray(surface, alpha) SDL_MapRGBA(surface->format, 0xa9, 0xa9, 0xa9, alpha)
#define RGBA_grey(surface, alpha) SDL_MapRGBA(surface->format, 0xa9, 0xa9, 0xa9, alpha)
#define RGBA_lightgoldenrod(surface, alpha) SDL_MapRGBA(surface->format, 0xfa, 0xfa, 0xd2, alpha)





/* My Colors*/


#define RGBA_REDVDK(surface, alpha) SDL_MapRGBA(surface->format, 64, 0, 0, alpha)
#define RGBA_REDDK(surface, alpha) SDL_MapRGBA(surface->format, 128, 0, 0, alpha)
#define RGBA_RED(surface, alpha) SDL_MapRGBA(surface->format, 255, 0, 0, alpha)
#define RGBA_REDLT(surface, alpha) SDL_MapRGBA(surface->format, 255, 128, 128, alpha)
#define RGBA_REDVLT(surface, alpha) SDL_MapRGBA(surface->format, 255, 192, 192, alpha)

#define RGBA_GREENVDK(surface, alpha) SDL_MapRGBA(surface->format, 0, 64, 0, alpha)
#define RGBA_GREENDK(surface, alpha) SDL_MapRGBA(surface->format, 0, 128, 0, alpha)
#define RGBA_GREEN(surface, alpha) SDL_MapRGBA(surface->format, 0, 255, 0, alpha)
#define RGBA_GREENLT(surface, alpha) SDL_MapRGBA(surface->format, 128, 255, 128, alpha)
#define RGBA_GREENVLT(surface, alpha) SDL_MapRGBA(surface->format, 192, 255, 192, alpha)

#define RGBA_BLUEVDK(surface, alpha) SDL_MapRGBA(surface->format, 0, 0, 64, alpha)
#define RGBA_BLUEDK(surface, alpha) SDL_MapRGBA(surface->format, 0, 0, 128, alpha)
#define RGBA_BLUE(surface, alpha) SDL_MapRGBA(surface->format, 0, 0, 255, alpha)
#define RGBA_BLUELT(surface, alpha) SDL_MapRGBA(surface->format, 64, 128, 255, alpha)
#define RGBA_BLUEVLT(surface, alpha) SDL_MapRGBA(surface->format, 96, 192, 255, alpha)

#define RGBA_PERIWINKLEVDK(surface, alpha) SDL_MapRGBA(surface->format, 32, 32, 64, alpha)
#define RGBA_PERIWINKLEDK(surface, alpha) SDL_MapRGBA(surface->format, 64, 64, 128, alpha)
#define RGBA_PERIWINKLE(surface, alpha) SDL_MapRGBA(surface->format, 128, 128, 255, alpha)
#define RGBA_PERIWINKLELT(surface, alpha) SDL_MapRGBA(surface->format, 192, 192, 255, alpha)
#define RGBA_PERIWINKLEVLT(surface, alpha) SDL_MapRGBA(surface->format, 224, 224, 255, alpha)

#define RGBA_LAVENDERVDK(surface, alpha) SDL_MapRGBA(surface->format, 96, 32, 160, alpha)
#define RGBA_LAVENDERDK(surface, alpha) SDL_MapRGBA(surface->format, 128, 64, 192, alpha)
#define RGBA_LAVENDER(surface, alpha) SDL_MapRGBA(surface->format, 160, 96, 212, alpha)
#define RGBA_LAVENDERLT(surface, alpha) SDL_MapRGBA(surface->format, 192, 128, 255, alpha)
#define RGBA_LAVENDERVLT(surface, alpha) SDL_MapRGBA(surface->format, 224, 160, 255, alpha)


#define RGBA_PURPLEVDK(surface, alpha) SDL_MapRGBA(surface->format, 64, 0, 96, alpha)
#define RGBA_PURPLEDK(surface, alpha) SDL_MapRGBA(surface->format, 96, 0, 128, alpha)
#define RGBA_PURPLE(surface, alpha) SDL_MapRGBA(surface->format, 128, 0, 160, alpha)
#define RGBA_PURPLELT(surface, alpha) SDL_MapRGBA(surface->format, 192, 64, 212, alpha)
#define RGBA_PURPLEVLT(surface, alpha) SDL_MapRGBA(surface->format, 212, 128, 255, alpha)

#define RGBA_BRIGHTPINK(surface, alpha) SDL_MapRGBA(surface->format, 255, 0, 255, alpha)

#define RGBA_PINKVDK(surface, alpha) SDL_MapRGBA(surface->format, 64, 32, 64, alpha)
#define RGBA_PINKDK(surface, alpha) SDL_MapRGBA(surface->format, 128, 64, 128, alpha)
#define RGBA_PINK(surface, alpha) SDL_MapRGBA(surface->format, 255, 128, 255, alpha)
#define RGBA_PINKLT(surface, alpha) SDL_MapRGBA(surface->format, 255, 192, 255, alpha)
#define RGBA_PINKVLT(surface, alpha) SDL_MapRGBA(surface->format, 255, 224, 255, alpha)

#define RGBA_YELLOWVDK(surface, alpha) SDL_MapRGBA(surface->format, 64, 64, 0, alpha)
#define RGBA_YELLOWDK(surface, alpha) SDL_MapRGBA(surface->format, 128, 128, 0, alpha)
#define RGBA_YELLOW(surface, alpha) SDL_MapRGBA(surface->format, 255, 255, 0, alpha)
#define RGBA_YELLOWLT(surface, alpha) SDL_MapRGBA(surface->format, 255, 255, 128, alpha)
#define RGBA_YELLOWVLT(surface, alpha) SDL_MapRGBA(surface->format, 255, 255, 192, alpha)


#define RGBA_ORANGEVDK(surface, alpha) SDL_MapRGBA(surface->format, 180, 64, 0, alpha)
#define RGBA_ORANGEDK(surface, alpha) SDL_MapRGBA(surface->format, 224, 96, 0, alpha)
#define RGBA_ORANGE(surface, alpha) SDL_MapRGBA(surface->format, 255, 128, 0, alpha)
#define RGBA_ORANGELT(surface, alpha) SDL_MapRGBA(surface->format, 255, 160, 32, alpha)
#define RGBA_ORANGEVLT(surface, alpha) SDL_MapRGBA(surface->format, 255, 192, 64, alpha)


#define RGBA_BROWNVDK(surface, alpha) SDL_MapRGBA(surface->format, 32, 16, 0, alpha)
#define RGBA_BROWNDK(surface, alpha) SDL_MapRGBA(surface->format, 64, 32, 0, alpha)
#define RGBA_BROWN(surface, alpha) SDL_MapRGBA(surface->format, 128, 64, 0, alpha)
#define RGBA_BROWNLT(surface, alpha) SDL_MapRGBA(surface->format, 192, 128, 32, alpha)
#define RGBA_BROWNVLT(surface, alpha) SDL_MapRGBA(surface->format, 255, 192, 64, alpha)

#define RGBA_TEALVDK(surface, alpha) SDL_MapRGBA(surface->format, 0, 64, 64, alpha)
#define RGBA_TEALDK(surface, alpha) SDL_MapRGBA(surface->format, 0, 128, 128, alpha)
#define RGBA_TEAL(surface, alpha) SDL_MapRGBA(surface->format, 0, 255, 255, alpha)
#define RGBA_TEALLT(surface, alpha) SDL_MapRGBA(surface->format, 128, 255, 255, alpha)
#define RGBA_TEALVLT(surface, alpha) SDL_MapRGBA(surface->format, 192, 255, 255, alpha)

#define RGBA_TURQUOISEVDK(surface, alpha) SDL_MapRGBA(surface->format, 0, 64, 64, alpha)
#define RGBA_TURQUOISEDK(surface, alpha) SDL_MapRGBA(surface->format, 0, 128, 128, alpha)
#define RGBA_TURQUOISE(surface, alpha) SDL_MapRGBA(surface->format, 0, 255, 255, alpha)
#define RGBA_TURQUOISELT(surface, alpha) SDL_MapRGBA(surface->format, 128, 255, 255, alpha)
#define RGBA_TURQUOISEVLT(surface, alpha) SDL_MapRGBA(surface->format, 192, 255, 255, alpha)

#define RGBA_BLACK(surface, alpha) SDL_MapRGBA(surface->format, 0, 0, 0, alpha)
#define RGBA_BLACK1(surface, alpha) SDL_MapRGBA(surface->format, 1, 1, 1, alpha)
#define RGBA_BLACK2(surface, alpha) SDL_MapRGBA(surface->format, 2, 2, 2, alpha)

#define RGBA_GRAYVDK(surface, alpha) SDL_MapRGBA(surface->format, 32, 32, 32, alpha)
#define RGBA_GRAYDK(surface, alpha) SDL_MapRGBA(surface->format, 64, 64, 64, alpha)
#define RGBA_GRAY(surface, alpha) SDL_MapRGBA(surface->format, 128, 128, 128, alpha)
#define RGBA_GRAYLT(surface, alpha) SDL_MapRGBA(surface->format, 192, 192, 192, alpha)
#define RGBA_GRAYVLT(surface, alpha) SDL_MapRGBA(surface->format, 224, 224, 224, alpha)

#define RGBA_WHITE(surface, alpha) SDL_MapRGBA(surface->format, 255, 255, 255, alpha)
#define RGBA_WHITE1(surface, alpha) SDL_MapRGBA(surface->format, 254, 254, 254, alpha)
#define RGBA_WHITE2(surface, alpha) SDL_MapRGBA(surface->format, 253, 253, 253, alpha)
#define RGBA_WHITEOFF(surface, alpha) SDL_MapRGBA(surface->format, 255, 255, 224, alpha)


#endif
