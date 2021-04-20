#ifndef Millis_impl_h
#define Millis_impl_h

class Millis_impl
{
private:
  int d;
  unsigned long t;

public:
  Millis_impl()
  {
    t = millis(); // default trigger
    d = 1000;     // default values
  }

  Millis_impl(int set_delay)
  {
    t = millis();
    d = set_delay;
  }

  void setDelay(int delay_time_in_milliseconds)
  {
    d = delay_time_in_milliseconds;
  }

  void startCount()
  {
    t = millis();
  }

  bool trigger(int delay_override)
  {
    d = delay_override;
    if ((millis() - t) > d)
    {
      t = millis();
      return true;
    }
    else
    {
      t = millis();
      return false;
    }
  }

  bool trigger()
  {
    if ((millis() - t) > d)
    {
      t = millis();
      return true;
    }
    else
    {
      return false;
    }
  }
};

#endif