#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
typedef uint8_t BYTE;

int main(int argc, char *argv[])
{
    if (argc != 2)
    {
        printf("Usage: ./recover image\n");
        return 1;
    }

    // open file
    FILE *input = fopen(argv[1], "r");
    if (!input)
    {
        printf("ERROR: File could not be opened\n");
        return 2;
    }

    BYTE buffer[512]; // create a buffer to read 512 bytes
    FILE *img = NULL; // create an img file pointer
    char filename[8]; // create an array to store img name
    int count = 0;    // create an image counter

    // loop until card is empty
    while (fread(buffer, 512, 1, input))
    {
        // check for jpeg header
        if (buffer[0] == 0xff && buffer[1] == 0xd8 && buffer[2] == 0xff && (buffer[3] & 0xf0) == 0xe0)
        {
            // if not first file close the current jpeg
            if (count > 0)
                fclose(img);

            sprintf(filename, "%03i.jpg", count++); // and create a new jpeg filename
            img = fopen(filename, "w");             // open new created jpeg file
            // count++;                              //increase the counter for each new file
        }
        if (count > 0)
        {
            fwrite(buffer, 512, 1, img);
        }
    }
    fclose(input);
    fclose(img);
}
