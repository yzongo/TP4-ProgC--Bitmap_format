#include <stdio.h>
#include <stdlib.h>

#include "BMPFile.h"
#include "imageRGB.h" 
#include "test.h"

/*!\def MY_FILENAME_MAX
* Taille maximum du nom d'un fichier
*/
#define MY_FILENAME_MAX 24

int main(int argc, char *argv[])
{
    char filename[MY_FILENAME_MAX];
    ImageRGB* cross = NULL;
    ImageRGB* f = NULL;
    PixelRGB pixel_background = {0,0,0};
    PixelRGB pixel_white = {255,255,255};


    /*Uncomment after a  llocateImage/getWidth/getHeight/getPixel/setPixel implementation*/
    
  /*  f = allocateImage(200,100);
    display_test_uint("Test allocateImage (getWidth)", 100, getWidth(f));
    display_test_uint("Test allocateImage (getHeight)", 200, getHeight(f));
    display_test_uint("Test allocateImage (getPixel)", 0, getPixel(f, 3, 3).red);
    setPixel(f,3,3,pixel_white);
    display_test_int("Test setPixel", 255, getPixel(f, 3, 3).blue);
    display_test_int("Test setPixel", 255, getPixel(f, 3, 3).green);
    display_test_int("Test setPixel", 255, getPixel(f, 3, 3).red);
     
    /*      Uncomment for question 2*/
   /* sprintf(filename,"test_allocate.bmp");
    writeBMPFile(filename, f, 0); // source d'erreur 
    freeImage(f);
    


    sprintf(filename,"test_allocate.bmp");
    f = readBMPFile_teacher(filename,1);


    modifyImage(f,pixel_background,pixel_white);
    sprintf(filename,"result.bmp");
    writeBMPFile(filename,f,1);
    freeImage(f);
    
     
    /*Uncomment after createCross implementation*/
   /* 
    cross = createCross(100);
    sprintf(filename,"cross.bmp");
    writeBMPFile(filename, cross, 1);


    int opt_l = 0;

    sprintf(filename,"cross2.bmp");
    writeBMPFile(filename, f, 1);
    freeImage(f);
    */

    ImageRGB *crosstest = createCross(200);
    writeBMPFile("filename2.bmp", crosstest, 0); 

    return 0;
}
