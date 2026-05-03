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
void generateResultFile(char * fileName,
    double rms_phaseA,
    double rms_phaseB,
    double rms_phaseC,
    double vpp_phaseA,
    double vpp_phaseB,
    double vpp_phaseC,
    double dc_offsetA,
    double dc_offsetB,
    double dc_offsetC,
    int clipping_phaseA,
    int clipping_phaseB,
    int clipping_phaseC)
{
    FILE * file;
    file = fopen(fileName, "w");
    if (!file)
    {
        printf("Error opening file check file name : %s\n", fileName);
    }
    fprintf(file , "**Phase A ** : \n");
    fprintf(file , "Rms value was :%lf ", rms_phaseA);
    if (checkRmsTolerance(rms_phaseA))
        fprintf(file , " within [207-253] 10 percent \n");
    else
        fprintf(file , " outside [207-253] 10 percent \n");

    fprintf(file , "Voltage peak to peak value was :%lf \n ", vpp_phaseA);
    fprintf(file , "Dc offset value is :%lf \n", dc_offsetA);
    fprintf(file , "Clipping detected is : %d \n", clipping_phaseA);
    fprintf(file,"********************************************** \n");
    fprintf(file , "**Phase B** : \n");

    fprintf(file , "Rms value was :%lf ", rms_phaseB);
    if (checkRmsTolerance(rms_phaseB))
        fprintf(file , " within [207-253] 10 percent \n");
    else
        fprintf(file , " outside [207-253] 10 percent \n");
    fprintf(file , "Voltage peak to peak value was :%lf \n", vpp_phaseB);
    fprintf(file , "Dc offset value is :%lf\n", dc_offsetB);
    fprintf(file , "Clipping detected is : %d \n", clipping_phaseB);


    fprintf(file,"********************************************** \n");
    fprintf(file , "**Phase C** : \n");

    fprintf(file , "Rms value was :%lf ", rms_phaseC);
    if (checkRmsTolerance(rms_phaseC))
        fprintf(file , " within [207-253] 10 percent \n");
    else
        fprintf(file , " outside [207-253] 10 percent \n");

    fprintf(file , "Voltage peak to peak value was :%lf \n ", vpp_phaseC);
    fprintf(file , "Dc offset value is :%lf \n ", dc_offsetC);
    fprintf(file , "Clipping detected is : %d \n", clipping_phaseC);

    fclose(file);

}

int checkRmsTolerance(double value)
{
    double lowerLimit = 230-(0.1*230);
    double upperLimit =230.0+(0.1*230);
    if (value >= lowerLimit && value<=upperLimit)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}