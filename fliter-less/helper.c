#include "helpers.h"
#include <math.h>

// Convert image to grayscale
void grayscale(int height, int width, RGBTRIPLE image[height][width])
{
    for(int i=0; i<height; i++){
        for(int j =0; j<width; j++){
            float red = image[i][j].rgbtRed;
            float green = image[i][j].rgbtGreen;
            float blue = image[i][j].rgbtBlue;

            int avg = round((red+green+blue)/3);
            image[i][j].rgbtRed = image[i][j].rgbtGreen = image[i][j].rgbtBlue = avg;
        }
    }
    return;
}

// Convert image to sepia
void sepia(int height, int width, RGBTRIPLE image[height][width])
{
    for(int i=0; i<height; i++){
        for(int j =0; j<width; j++){
            int sepiaRed = round(0.393 * image[i][j].rgbtRed + 0.769 * image[i][j].rgbtGreen + 0.189 * image[i][j].rgbtBlue) % 256;
            int sepiaGreen = round(0.349 * image[i][j].rgbtRed + 0.686 * image[i][j].rgbtGreen + 0.168 * image[i][j].rgbtBlue) % 256;
            int sepiaBlue = round(0.272 * image[i][j].rgbtRed + 0.534 * image[i][j].rgbtGreen + 0.131 * image[i][j].rgbtBlue) % 256;

            image[i][j].rgbtRed = sepiaRed;
            image[i][j].rgbtGreen = sepiaGreen;
            image[i][j].rgbtBlue = sepiaBlue;
        }

    }
    return;
}

// Reflect image horizontally
void reflect(int height, int width, RGBTRIPLE image[height][width])
{
    //swap operation to swap/reverse left right values
    for(int i=0; i<height; i++){
        for(int j =0; j<width/2; j++){
            RGBTRIPLE temp = image[i][j];
            image[i][j] = image[i][width-(j+1)];
            image[i][width-(j+1)] = temp;
        }
    }
    return;
}

/* Blur image

     0  1   2   3   4

0   [00 01  02  03  04]
1   [10 11  12  13  14]
2   [20 21  22  23  24]
3   [30 31  32  33  34]
4   [40 41  42  43  44]

*/

void blur(int height, int width, RGBTRIPLE image[height][width])
{
    //create a temporary image to be blurred
    RGBTRIPLE temp_img[height][width];
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
            temp_img[i][j] = image[i][j];
    }

    for(int i=0; i<height; i++){
        for(int j=0; j<width; j++){
            int sum_red = 0;
            int sum_green = 0;
            int sum_blue = 0;
            float c = 0;
        //iterate through the column, from -1 to +1
            for (int h = -1; h < 2; h++)
            {
                //iterate similarly through rows
                for (int w = -1; w < 2; w++)
                {
                    int row = i+h;   //current row
                    int col = j+w;    //current column

                    //if pixel is outside the matrix size(mxn) range
                    if (row < 0 || row > (height - 1) || col  < 0 || col > (width - 1))
                        continue;

                    //sum up the values of all the pixels
                    sum_blue += image[i + h][j + w].rgbtBlue;
                    sum_red += image[i + h][j + w].rgbtRed;
                    sum_green += image[i + h][j + w].rgbtGreen;
                    c++;
                }
            }
            //calculate average colour value
            image[i][j].rgbtRed = round(sum_red / c);
            image[i][j].rgbtGreen = round(sum_green / c);
            image[i][j].rgbtBlue = round(sum_blue / c);
        }
    }
    return;
}


