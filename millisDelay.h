#ifndef millisDelay_h
#define millisDelay_h

void msDelay(int ms)
{
  unsigned long pl = millis();
  while (1)
  {
    if ((millis() - pl) > ms)
      break;
  }
}

#endif