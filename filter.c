#include "helpers.h"
#include <math.h>
#include <stdio.h>
// Convert image to grayscale
void grayscale(int height, int width, RGBTRIPLE image[height][width])
{
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            int n =
                round((image[i][j].rgbtRed + image[i][j].rgbtGreen + image[i][j].rgbtBlue) / 3.0);
            image[i][j].rgbtRed = n;
            image[i][j].rgbtGreen = n;
            image[i][j].rgbtBlue = n;
        }
    }
    return;
}
// Convert image to sepia
void sepia(int height, int width, RGBTRIPLE image[height][width])
{
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            int sepiaRed = round(.393 * image[i][j].rgbtRed + .769 * image[i][j].rgbtGreen +
                                 .189 * image[i][j].rgbtBlue);
            int sepiaGreen = round(.349 * image[i][j].rgbtRed + .686 * image[i][j].rgbtGreen +
                                   .168 * image[i][j].rgbtBlue);
            int sepiaBlue = round(.272 * image[i][j].rgbtRed + .534 * image[i][j].rgbtGreen +
                                  .131 * image[i][j].rgbtBlue);
            if (sepiaRed > 255)
            {
                image[i][j].rgbtRed = 255;
            }
            else
            {
                image[i][j].rgbtRed = sepiaRed;
            }
            if (sepiaGreen > 255)
            {
                image[i][j].rgbtGreen = 255;
            }
            else
            {
                image[i][j].rgbtGreen = sepiaGreen;
            }
            if (sepiaBlue > 255)
            {
                image[i][j].rgbtBlue = 255;
            }
            else
            {
                image[i][j].rgbtBlue = sepiaBlue;
            }
        }
    }
    return;
}
// Reflect image horizontally
void reflect(int height, int width, RGBTRIPLE image[height][width])
{
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width / 2; j++)
        {
            RGBTRIPLE temp = image[i][j];
            image[i][j] = image[i][width - 1 - j];
            image[i][width - 1 - j] = temp;
        }
    }
    return;
}
// Blur image
void blur(int height, int width, RGBTRIPLE image[height][width])
{
    RGBTRIPLE copy[height][width];
    int Red;
    int Green;
    int Blue;
    float count;
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            Red = 0;
            count = 0;
            Green = 0;
            Blue = 0;
            copy[i][j] = image[i][j];
            int red = copy[i][j].rgbtRed;
            Red = Red + red;
            count++;
            if (j < width - 1)
            {
                red = copy[i][j + 1].rgbtRed;
                Red = Red + red;
                count++;
            }
            if (i < height - 1)
            {
                red = copy[i + 1][j].rgbtRed;
                Red = Red + red;
                count++;
            }
            if (i < height - 1 && j < width - 1)
            {
                red = copy[i + 1][j + 1].rgbtRed;
                Red = Red + red;
                count++;
            }
            if (i > 0 && j > 0)
            {
                red = copy[i - 1][j - 1].rgbtRed;
                Red = Red + red;
                count++;
            }
            if (i > 0)
            {
                red = copy[i - 1][j].rgbtRed;
                Red = Red + red;
                count++;
            }
            if (i > 0 && j < width - 1)
            {
                red = copy[i - 1][j + 1].rgbtRed;
                Red = Red + red;
                count++;
            }
            if (j > 0)
            {
                red = copy[i][j - 1].rgbtRed;
                Red = Red + red;
                count++;
            }
            if (i < height - 1 && j > 0)
            {
                red = copy[i + 1][j - 1].rgbtRed;
                Red = Red + red;
                count++;
            }
            Red = round(Red / count);
            if (Red > 255)
            {
                image[i][j].rgbtRed = 255;
            }
            else
            {
                image[i][j].rgbtRed = Red;
            }
            count = 0;
            int green = copy[i][j].rgbtGreen;
            Green = Green + green;
            count++;
            if (j < width - 1)
            {
                green = copy[i][j + 1].rgbtGreen;
                Green = Green + green;
                count++;
            }
            if (i < height - 1)
            {
                green = copy[i + 1][j].rgbtGreen;
                Green = Green + green;
                count++;
            }
            if (i < height - 1 && j < width - 1)
            {
                green = copy[i + 1][j + 1].rgbtGreen;
                Green = Green + green;
                count++;
            }
            if (i > 0 && j > 0)
            {
                green = copy[i - 1][j - 1].rgbtGreen;
                Green = Green + green;
                count++;
            }
            if (i > 0)
            {
                green = copy[i - 1][j].rgbtGreen;
                Green = Green + green;
                count++;
            }
            if (i > 0 && j < width - 1)
            {

                green = copy[i - 1][j + 1].rgbtGreen;
                Green = Green + green;
                count++;
            }
            if (j > 0)
            {
                green = copy[i][j - 1].rgbtGreen;
                Green = Green + green;
                count++;
            }
            if (i < height - 1 && j > 0)
            {
                green = copy[i + 1][j - 1].rgbtGreen;
                Green = Green + green;
                count++;
            }
            Green = round(Green / count);
            if (Green > 255)
            {
                image[i][j].rgbtGreen = 255;
            }
            else
            {
                image[i][j].rgbtGreen = Green;
            }
            count = 0;
            int blue = copy[i][j].rgbtBlue;
            Blue = Blue + blue;
            count++;
            if (j < width - 1)
            {
                blue = copy[i][j + 1].rgbtBlue;
                Blue = Blue + blue;
                count++;
            }
            if (i < height - 1)
            {
                blue = copy[i + 1][j].rgbtBlue;
                Blue = Blue + blue;
                count++;
            }
            if (i < height - 1 && j < width - 1)
            {
                blue = copy[i + 1][j + 1].rgbtBlue;
                Blue = Blue + blue;
                count++;
            }
            if (i > 0 && j > 0)
            {
                blue = copy[i - 1][j - 1].rgbtBlue;
                Blue = Blue + blue;
                count++;
            }
            if (i > 0)
            {
                blue = copy[i - 1][j].rgbtBlue;
                Blue = Blue + blue;
                count++;
            }
            if (i > 0 && j < width - 1)
            {
                blue = copy[i - 1][j + 1].rgbtBlue;
                Blue = Blue + blue;
                count++;
            }
            if (j > 0)
            {
                blue = copy[i][j - 1].rgbtBlue;
                Blue = Blue + blue;
                count++;
            }
            if (i < height - 1 && j > 0)
            {
                blue = copy[i + 1][j - 1].rgbtBlue;
                Blue = Blue + blue;
                count++;
            }

            Blue = round(Blue / count);
            if (Blue > 255)
            {
                image[i][j].rgbtBlue = 255;
            }
            else
            {
                image[i][j].rgbtBlue = Blue;
            }
        }
    }
    return;
}
