/*!
 * \file BMPFile.c
 * \brief definition of functions to handle a BMP file using RGB colour space
 * \author ...cons t char *restrhbujhbjubjhict 
 * \date ...
 */

#include <stdio.h>
#include "BMPFile.h"
#include "imageRGB.h"
void writeBMPFile(char *filename, ImageRGB *image, int verbose){ 
    FILE* f; 
    f = fopen(filename, "wb");
    if(f!=NULL){ 
        int fill = (4-((image->width)*sizeof(PixelRGB))%4) %4;
        FileHeader fH={
            .identity={'B','M'}, 
            .file_size=sizeof(FileHeader)+sizeof(DIBHeader)+(image->width+fill)*(image->height)*sizeof(PixelRGB),
            .raster_address=sizeof(FileHeader)+sizeof(DIBHeader)}; 
        fwrite(&fH, sizeof(FileHeader), 1, f);
        
        
        DIBHeader Dh = {
            sizeof(DIBHeader), 
            image->width, 
            image->height, 
            1,
            24,
            0, 
            (image->width+fill)*(image->height)*sizeof(PixelRGB),
            2800
            ,2800,
            0,
            0 }; 
        fwrite( &Dh, sizeof(DIBHeader), 1, f); 
        char x = '0';
        for(int i=0; i<image->height;i++){
             fwrite(image->raw_data+i*image->width, sizeof(PixelRGB), image->width, f); 
             for(int j=0; j<fill; j++){
                fwrite(&x, sizeof(char), 1, f);
             }
        }

        fclose(f); 
    }


}