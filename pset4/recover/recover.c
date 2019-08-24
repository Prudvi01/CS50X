//program to recover a memory card
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <stdint.h>


int main(int argc, char *argv[])
{
    // ensure proper usage
    if (argc != 2)
    {
        fprintf(stderr, "Usage: ./restore filename\n");
        return 1;
    }

    char *rawfile = argv[1];

    // open input file
    FILE *inptr = fopen(rawfile, "r");
    if (inptr == NULL)
    {
        fprintf(stderr, "Could not open %s.\n", rawfile);
        return 2;
    }
    //declaring data type BYTE of unsigned int of size 8 bytes
    typedef uint8_t  BYTE;
    BYTE buffer[512];
    int i=0;
    bool first_file=false;
    FILE *rimg;
        //check whether the buffer block contains 512 bytes and then proceed
        while(fread(buffer, 1, 512, inptr)==512)
        {
            //to check if the block is the start of a new JPG image
            if(buffer[0]==0xff && buffer[1]==0xd8 &&
            buffer[2]==0xff && (buffer[3] & 0xf0)==0xe0)
            {
                //to check if the file is opening for the first time
                if(!first_file)
                {
                    first_file=true;
                    char filename[8];
                    //opening new jpg file
                    sprintf(filename,"%03i.jpg",i++);
                    rimg=fopen(filename,"w");
                        if(rimg==NULL)
                        {
                            return 3;
                        }
                    fwrite(buffer, 1, 512, rimg);
                }
                else
                {
                    fclose(rimg);
                    char filename[8];
                    //opening new jpg file
                    sprintf(filename,"%03i.jpg",i++);
                    rimg=fopen(filename,"w");
                        if(rimg==NULL)
                        {
                            return 4;
                        }
                    fwrite(buffer, 1, 512, rimg);
                }

            }
            else
            {
                if(first_file)
                {
                    fwrite(buffer, 1, 512, rimg);
                }
            }
        }
        //closing the remaining open files
        fclose(rimg);
        fclose(inptr);
        return 0;
    }