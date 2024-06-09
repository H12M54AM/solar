#include <iostream>
#include <cmath>

class circuitMath
{
private:
    double power;
    double volts;
    double amps;
    double resistance;

public:
    // Constructors
    circuitMath(double p, double v, double i, double r)
    {
        power = p;
        volts = v;
        amps = i;
        resistance = r;
    }

    circuitMath(double p, double v, double i)
    {
        power = p;
        volts = v;
        amps = i;
    }

    circuitMath(double v, double i)
    {
        volts = v;
        amps = i;
    }

    circuitMath() {}

    // Setter methods
    void setPower(double p) { power = p; }
    void setVolts(double v) { volts = v; }
    void setAmps(double i) { amps = i; }
    void setResistance(double r) { resistance = r; }

    // Calculation methods
    double findPower(double i, double v)
    {
        return i * v;
    }

    double findVolts(double i, double r)
    {
        return i * r;
    }

    double findAmps(double v, double r)
    {
        return v / r;
    }

    double findResistance(double v, double i)
    {
        return v / i;
    }

    double findPanelWatts(double totalRequiredP, double budgetPower)
    {
        return round(totalRequiredP / budgetPower);
    }

    double findPower()
    {
        return amps * volts;
    }

    double findVolts()
    {
        return amps * resistance;
    }

    double findAmps()
    {
        return volts / resistance;
    }

    double findResistance()
    {
        return volts / amps;
    }

    double findWattsPerPanel(double totalRequiredP, double budgetPanel)
    {
        return round(totalRequiredP / budgetPanel);
    }
};
