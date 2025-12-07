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
            .raster_address=sizeof(FileHeader)+sizeof(DIBHeader)
        };

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
            0
        };
        fwrite( &Dh, sizeof(DIBHeader), 1, f); 
        char x = '0';
        for(unsigned int i=0; i<image->height;i++){
             fwrite(image->raw_data+i*image->width, sizeof(PixelRGB), image->width, f); 
             for(int j=0; j<fill; j++){
                fwrite(&x, sizeof(char), 1, f);
             }
        }
        fclose(f); 
    }
}
void readFileHeader(FILE * fp, FileHeader * eFichier){
    if (fp != NULL || eFichier!= NULL)
    {
        if (fread(eFichier->identity, sizeof(char), 2,fp)!=2) return;
        if (fread(&eFichier->file_size, sizeof(int32_t), 1, fp)!=1) return;
        if (fread(eFichier->application_id, sizeof(char), 4, fp)!=4) return;
        if (fread(&eFichier->raster_address, sizeof(uint32_t), 1, fp)!=1) return;

    }
    else
    {
        return;
    }
}

void readDIBHeader(FILE * fp, DIBHeader * eImage)
{
    if (fp != NULL)
    {
        if (fread(&eImage->size_DIBHeader, sizeof(uint32_t), 1, fp)!=1) return;
        if (fread(&eImage->image_width, sizeof(uint32_t), 1, fp)!=1) return;
        if (fread(&eImage->image_height, sizeof(uint32_t), 1, fp)!=1)return;
        if (fread(&eImage->nbColorPlanes, sizeof(uint16_t),1, fp )!=1) return;
        if (fread(&eImage->nbBitPerPixel, sizeof(uint16_t), 1, fp)!=1)return;
        if (fread(&eImage->typeCompression, sizeof(uint32_t),1, fp)!=1)return;
        if (fread(&eImage->size_raw_image, sizeof(uint32_t),1, fp )!=1)return;
        if (fread(&eImage->hResolution, sizeof(int32_t), 1, fp)!=1)return;
        if (fread(&eImage->vResolution, sizeof(int32_t), 1, fp)!=1) return;
        if (fread((&eImage->nbUsedColours),sizeof(uint32_t), 1, fp )!=1)return;
        if (fread(&(eImage->nbImportantColours), sizeof(uint32_t), 1, fp)!=1)return;

    }
    else{
        return;
    }
}

ImageRGB* readRawImage(FILE*fp, unsigned int  address, int l, int h)
{
    if (fp== NULL)
    {
        return NULL;
    }
    else
    {
        fseek(fp, address,SEEK_SET);

        int padding1 = (4 - (( l*sizeof(PixelRGB)) % 4 ))%4;
        ImageRGB*im = allocateImage(h, l);

        if (im!=NULL)
        {
            for (int j=0; j<h; j++){

                int rowInImage = (h-1-j);
                PixelRGB * ligne = im->raw_data + rowInImage*l;
                for (int i= 0; i<l; i++)
                {
                    fread(&ligne[i], sizeof(PixelRGB), 1, fp);


                }
                unsigned char pad[3];
                fread(pad, 1, padding1,fp);
            }
            return im;
        }
        else
        {
            return NULL;
        }
    }
}