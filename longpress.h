#ifndef longpress_h
#define longpress_h

class longpress
{
private:
    unsigned long long_press_trigger;
    int lpt_c_v = 0; // long_press_trigger control variable
public:
    void long_press_millis()
    {
        long_press_trigger = millis();
        lpt_c_v = 1;
    }

    bool trigger(int pin, int long_press_delay, int trigger_state)
    {
        if (digitalRead(pin) == trigger_state)
        {
            if ((millis() - long_press_trigger) > long_press_delay)
            {
                if (lpt_c_v == 1)
                {
                    lpt_c_v = 0;
                    return true;
                }
            }
        }

        // removing false positives
        if (digitalRead(pin) == HIGH)
            lpt_c_v = 0;

        return false;
    }
};

#endif