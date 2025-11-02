#include "ultrasons.h"

void setup ()
{
  Serial.begin(115200);
}

void loop ()
{
  int D = distance();
  Serial.print("Distance = ");
  Serial.print(D);
  Serial.println(" cm");
  delay(250);

}
