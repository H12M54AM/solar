/**
 * @brief Create a CLI application that
 * calculates the different DC figures
 * so I dont have to do it over and
 * over on paper.
 *
 * This will help me make quick
 * desicions and revise on using
 * c++.
 *
 * @author Edward Naidoo
 * @date Jun 3, 2024
 */
#include <iostream>
#include "circuitMath.cpp"
using namespace std;

int main();
void menu(circuitMath &obj);
void alert();

/**
 * @brief Provides a small alert for the
 * user to be aware that they chose the
 * wrong option.
 *
 * void function\n
 * recursive
 */
void alert()
{
    cout << "Please use one of the provided options...";
    main();
}

void menu(circuitMath &obj)
{
    // I've added these variables to hold user inputs
    float volts = 0;
    float power = 0;
    float amps = 0;
    float resistance = 0;
    float totalWattsPerPanel = 0;
    float totalWatts = 0;
    int countPanels = 0;
    int case2Choice = 0;
    int case1Choice = 0;

    // Step 2: Let the user choose
    int menu_choice;
    cout << "Menu:\n\n\t1. Find Power\n\t1. V=IR\n\t2. P=IV\n\t3. Find Amps\n\t4. Find Resistance\n\t5. Calculates Watts per Panel\n\t6. Calculates Number of panels\n\nChoose a Calculation: ";
    cin >> menu_choice;

    /**
     * Power
     * Volts
     * Amps
     * Resistance
     * Watts per Panel
     * Num of Panels
     * Stats
     */

    // Step 3: Make those calculations
    switch (menu_choice)
    {
    case 1:
        cout << "Would you like to calculate by using the V = IR formula or the P = IV formula?\n\n\t1. V=IR\n\t2. P=IV\n\n=====>";
        cin >> case1Choice;
        if (case1Choice == 1)
        {
            // Calculates Power using P=IV
            cout << "Add Volts: ";
            cin >> volts;
            obj.setVolts(volts);
            cout << "Add Amps: ";
            cin >> amps;
            obj.setAmps(amps);
            cout << "Power = " << obj.findPower() << "w\n";
            main();
            break;
        }
        else if (case1Choice == 2)
        {
            // Calculates Power using P=IR^2
            cout << "Add Volts: ";
            cin >> volts;
            obj.setVolts(volts);
            cout << "Add Amps: ";
            cin >> amps;
            obj.setAmps(amps);
            cout << "Power = " << obj.findPower() << "w\n";
            main();
            break;
        }
        else
        {
            alert();
            break;
        }

    case 2:
        // I've given two options to the user because there are other
        // ways to reach Volts in a DC Circuit.
        cout << "Would you like to calculate by using the V = IR formula or the P = IV formula?\n\n=====>";
        cin >> case2Choice;

        if (case2Choice == 1)
        {
            // Calculates Volts using V = IR
            cout << "Add Amps: ";
            cin >> amps;
            obj.setAmps(amps);
            cout << "Add Resistance: ";
            cin >> resistance;
            obj.setVolts(amps);
            cout << "Volts = " << obj.findVolts() << "v\n";
            main();
            break;
        }
        else if (case2Choice == 2)
        {
            // Calculates Volts using P = IV
            cout << "Add Amps: ";
            cin >> amps;
            obj.setAmps(amps);
            cout << "Add Power: ";
            cin >> power;
            obj.setVolts(amps);
            cout << "Volts = " << obj.findVolts() << "v\n";
            main();
            break;
        }
        else
        {
            cout << "Please use one of the provided options...";
            main();
            break;
        }

    case 3:
        // Calculates Amps from Power Calculation
        cout << "Add Volts: ";
        cin >> volts;
        obj.setVolts(volts);
        cout << "Add Power: ";
        cin >> power;
        obj.setAmps(power);
        cout << "Amps = " << obj.findAmps() << "A\n";
        main();
        break;
    case 4:
        // Calculates Resistance with v=ir
        cout << "Add Volts: ";
        cin >> volts;
        obj.setVolts(volts);
        cout << "Add Amps: ";
        cin >> amps;
        obj.setAmps(amps);
        cout << "Power = " << obj.findResistance() << "w\n";
        main();
        break;
    case 5:
        // Calculates Watts per Panel
        cout << "Add Total System Watts: ";
        cin >> totalWatts;
        cout << "How many Panels are there?: ";
        cin >> countPanels;
        cout << "Power = " << obj.findWattsPerPanel(totalWatts, countPanels) << "w\n";
        main();
        break;
    case 6:
        // Calculates Number of Panels
        cout << "Add Total System Watts: ";
        cin >> totalWatts;
        obj.setVolts(volts);
        cout << "Add Panel Watts: ";
        cin >> totalWattsPerPanel;
        obj.setAmps(amps);
        cout << "Num of Panels = " << totalWatts / totalWattsPerPanel << " panels\n";
        main();
        break;
    case 7:
        // Calculates some stats
        cout << "Add Volts: ";
        cin >> volts;
        obj.setVolts(volts);
        cout << "Add Amps: ";
        cin >> amps;
        obj.setAmps(amps);
        cout << "Power = " << obj.findPower() << "w\n";
        main();
        break;
    default:
        // Recursive function
        main();
        break;
    }
}

int main()
{
    circuitMath solar;
    // Step 1: give user options to choose from
    string user_choice;
    cout << "Solar Calculations:\n\nConinue? (y/n): ";
    cin >> user_choice;
    if (user_choice == "yes" || user_choice == "y")
    {
        menu(solar);
    }
    else
    {
        cout << "See you Later :)";
    }
    // Step 4: return to the menu
    return 0;
}