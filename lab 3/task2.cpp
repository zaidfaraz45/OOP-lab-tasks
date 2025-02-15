#include <iostream>
#include <string>
using namespace std;

class FitnessTracker
{
    string userName;
    int dailyStepGoal = 0;
    int stepsTaken = 0;
    double caloriesBurned = 0.0;

    public:
        void inputName()
        {
            cout << "Enter your username: ";
            getline(cin, userName);
        }

        void setDailyStepGoal(int steps)
        {
            dailyStepGoal = steps;
        }

        void logSteps(int steps)
        {
            stepsTaken += steps;
            caloriesBurned += steps * 0.4;
        }

        void displayProgress()
        {
            if (stepsTaken >= dailyStepGoal)
                {cout << "You achieved your daily step goals and burned " << caloriesBurned << " calories." << endl << endl;}
            else
                {cout << "You could not achieve your daily step goals and burned only " << caloriesBurned << " calories." << endl << endl;}
        }
};

int main()
{
    FitnessTracker ft1;
    ft1.inputName();
    ft1.setDailyStepGoal(5000);
    ft1.logSteps(3000);
    ft1.logSteps(4600);
    ft1.displayProgress();

    FitnessTracker ft2;
    ft2.inputName();
    ft2.setDailyStepGoal(5000);
    ft2.logSteps(3000);
    ft2.displayProgress();

    return 0;
}