//
// Created by Huawei on 4/25/2026.
//

#include "io.h"
#include <stdio.h>
#include <stdlib.h>
#define line_size 500
WaveformSample * readFromCsvFile (char * fileName , int * dataSize)
{
    //1- OPEN FILE
    FILE * file;
    file = fopen(fileName, "r");
    if (!file)
    {
        printf("Error opening file %s\n", fileName);
        return NULL;
    }

    char line [line_size];
    int rows_number=0;
    fgets(line, sizeof(line), file); // read one line

    while (fgets(line, sizeof(line), file)) {rows_number++;} //count the rows

    WaveformSample * waveform =  malloc (rows_number * sizeof(WaveformSample)); //100 * 8 fields
    rewind(file);

    fgets(line, sizeof(line), file); // read one line
    int i=0;
    while (fgets(line, sizeof(line), file))
    {
       sscanf(line ,"%lf,%lf,%lf,%lf,%lf,%lf,%lf,%lf",
           &waveform[i].timestamp,
           &waveform[i].phase_A,
           &waveform[i].phase_B,
          &waveform[i].phase_C,
          &waveform[i].current,
          &waveform[i].frequency,
          &waveform[i].power_factor,
          &waveform[i].percentage
           );
        i++;
    }

    fclose(file);
    *dataSize=rows_number; //update counter of rows
    return waveform;

}
