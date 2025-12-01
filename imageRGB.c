/*!
 * \file imageRGB.c
 * \brief definition of fonctions associated to the RGB Image structure
 * \author ...
 * \date ...
 */

#include "imageRGB.h"
#include <stdio.h>
#include <stdlib.h>


/*!
 * Allocate an image as a rectangle whose size is specified.
 * \param[in] w image width
 * \param[in] h image height
 * \return a pointer on the new image
 */
ImageRGB *allocateImage( unsigned int h, unsigned int w)
{
    /* to be completed*/
    ImageRGB* im = malloc(sizeof(ImageRGB)); 
    im->height = h; 
    im->width = w ; 
    im->raw_data = malloc(h*w*sizeof(PixelRGB));
    return im;
}

/*!
 * \fn unsigned int getWidth(ImageRGB *image)
 * Returns the width of teh image
 * \param[in] image the image
 * \return unsigned int the image width
 */

unsigned int getWidth(ImageRGB *image)
{
    /* to be completed*/
    return image->width;
}

/*!
 * \fn unsigned int getHeight(ImageRGB *image)
 * Returns the height of teh image
 * \param[in] image the image
 * \return unsigned int the image height
 */
unsigned int getHeight(ImageRGB *image)
{
    /* to be completed*/
    return image->height;
}

/*!
 *  Free the memore allocated for a structure
 * \param[in] image ImageRGB to be deleted
 */
void  freeImage(ImageRGB * image)
{
    free(image->raw_data);
    free(image);
}


/*!
 * \fn void setPixel(ImageRGB *image, unsigned  int r, unsigned  int c , PixelRGB p)
 *  Copy a Pixel at a specified location in the raw data.
 *  c is the column number, r the row number of the Pixel to be set.
 *  Its position in the raw data is given by (c + r*width) since the rows are stored continuously.
 * \param[out] image ImageRGB to be modified
 * \param[in] c The column number of the Pixel to be set
 * \param[in] r The row number of the Pixel to be set
 * \param[in] p Pixel value to set at this location
 */
void setPixel(ImageRGB *image, unsigned int r, unsigned int c , PixelRGB p)
{
    image->raw_data[c+r*image->width]=p;

}

/*!
 * \fn PixelRGB getPixel(ImageRGB *image, unsigned int r, unsigned  int c)
 *  Give the pixel value of  specified location in the raw data.
 *  Its position in the raw data is given by (c + r*width) since the rows are stored continuously.
 * \param[in] image ImageRGB to read
 * \param[in] c The column number of the Pixel to read
 * \param[in] r The row number of the Pixel to read
 * \return PixelRGB Pixel value at this location
 */

PixelRGB getPixel(ImageRGB *image, unsigned int r, unsigned int c)
{
    PixelRGB p= image->raw_data[c+r*image->width];
    /* to be completed*/
    return  p;
}

/*!
 * \fn ImageRGB* createCross(int length)
 * The resulting image is a red square with a blue cross inside.
 * \param[in] length the square size
 * \return a pointer on the new image
 */

ImageRGB* createCross(int length)
{

    /* to be completed*/
    unsigned int i, j; 
    PixelRGB rouge = {0, 0,255};
    PixelRGB bleu = {255, 0,0};  
    ImageRGB* im = allocateImage(length, length);
    for (i =0; i<im->width; i++) {
        for (j =0; j < im->height; j++) {
            setPixel(im, i, j, rouge);
            if(i ==j  || i == length-j-1){ 
                setPixel(im, i , j, bleu); 
            } 
        }
    }

    return im;
}

/*!
 * \fn void modifyImage(ImageRGB * image, PixelRGB pix_initial, PixelRGB pix_final)
 *  Modify an image by replacing every pixel with a given value by another one
 * \param[in,out] image ImageRGB to be modified
 * \param[in] pix_initial initial value in the image to be replaced
 * \param[in] pix_final the new value for those pixels
 */

int compare_pix (PixelRGB p1, PixelRGB p2) { 
    return((p1.blue == p2.blue)&& (p1.green == p2.green)&& (p1.red == p2.red)); 

}
void modifyImage(ImageRGB * image, PixelRGB pix_initial, PixelRGB pix_final)
{
    /* to be completed*/
    int i,j ; 
    for(i = 0; i < image->width; i ++){ 
        for(j = 0; j<image->height; j++){ 
            if(compare_pix(pix_initial, image->raw_data[i+j*image->width])){ 
                image->raw_data[i+j*image->width]= pix_final;  
            }
        }
    }
}


