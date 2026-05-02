//
// Created by Huawei on 4/25/2026.
//

#include "waveform.h"

#include <math.h>

double getRmsValue(WaveformSample * wf , int samples_number , char p)
{
   double squaresTotal = 0.0;
   double phaseVolt=0.0;
   for(int i = 0 ; i < samples_number ; i++)
   {
      if (p=='A')
         phaseVolt=(wf+i)->phase_A;
      if (p=='B')
         phaseVolt=(wf+i)->phase_B;
      if (p=='C')
         phaseVolt=(wf+i)->phase_C;
      squaresTotal=squaresTotal+(phaseVolt*phaseVolt);
   }
   double mean = (squaresTotal/samples_number);
   return sqrt(mean);//rms
}

double getVoltagePeakToPeakValue(WaveformSample * wf , int samples_number , char p)
{
   double maximum_value=0;
   double minimum_value=0;
   double phaseVolt=0.0;
   for(int i = 0 ; i < samples_number ; i++)
   {
      if (p == 'A')
      {
         phaseVolt=(wf+i)->phase_A;
         if (phaseVolt > maximum_value)
            maximum_value=phaseVolt;
         if (phaseVolt < minimum_value)
            minimum_value=phaseVolt;
      }
      if (p=='B')
      {
         phaseVolt=(wf+i)->phase_B;
         if (phaseVolt > maximum_value)
            maximum_value=phaseVolt;
         if (phaseVolt < minimum_value)
            minimum_value=phaseVolt;
      }
      if (p=='C')
      {
         phaseVolt=(wf+i)->phase_C;
         if (phaseVolt > maximum_value)
            maximum_value=phaseVolt;
         if (phaseVolt < minimum_value)
            minimum_value=phaseVolt;
      }
   }
   return maximum_value-minimum_value;//VPP
}
