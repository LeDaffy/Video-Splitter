#include<stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char *argv[]){


    char input_file_name[512];
    char timestamp_file_name[512];
    int reencode = 0;
    int valid = 1;

    ////printf("Arg 1: %s \t Arg 2: %s\n", argv[1], argv[2]);
    for (int i = 0; i < argc; i++){
        if (strcmp(argv[i], "-i") ==0) {
            strcpy(input_file_name, argv[i+1]);
            printf("Input filename: %s\n", input_file_name);
            valid = 1;
        } else if (strcmp(argv[i], "-t") ==0) {
            strcpy(timestamp_file_name, argv[i+1]);
            printf("Timestamp filename: %s\n", timestamp_file_name);
            valid = 1;
        } else {
            if (valid == 1){
                valid = 0;
            } else {
                printf("Invalid Argument\n");
                return 0;
            }

        }
    }




    FILE *timestamps_file;
    FILE *write_file = fopen( "splitter.bat", "w");
    unsigned int num_items = 0;


    timestamps_file=fopen(timestamp_file_name, "r");
    fscanf(timestamps_file, "%d", &num_items);

    printf("Read num_items is: %d\n", num_items);

    //int *timestamps = (int*)malloc(num_items*sizeof(int));

    char temp[256];
    char filename[512];
    char filename1[512];

    //First Timestamp
    int hours, minutes, seconds;
    int startseconds, endseconds, lengthseconds;

    //next timestamp
    int hours1, minutes1, seconds1;


    //read first timestamp line
    fscanf(timestamps_file, "%2d %1c %2d %1c %2d %s", &hours, temp, &minutes, temp, &seconds,filename);
    startseconds = hours*60*60 + minutes*60 +seconds;

    //read in the next files
    for (int i = 0; i < num_items-1; i++){
        fscanf(timestamps_file, "%2d %1c %2d %1c %2d %s", &hours1, temp, &minutes1, temp, &seconds1,filename1);
        endseconds = hours1*60*60 + minutes1*60 +seconds1;
        lengthseconds = endseconds-startseconds;
        fprintf(write_file, "ffmpeg -i %s -ss %d -c copy -t %d %s\n", input_file_name, startseconds, lengthseconds, filename);

        //set up for next loop
        startseconds = endseconds;
        hours = hours1;
        minutes = minutes;
        seconds = seconds1;
        strcpy(filename, filename1);

    }
    fclose(timestamps_file);
    fclose(write_file);
    system("splitter.bat");

    remove("splitter.bat");

    return 0;
}