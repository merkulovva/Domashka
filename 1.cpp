#include <iostream>
#include <cmath>
#include <cstdlib>
#include <ctime>
using namespace std;

float GetRandomNumber(float min, float max)
{
    return ((float)(rand()) / RAND_MAX) * (max - min) + min;
}

int main()
{
    int seed = time(NULL);
    srand(seed);

    int score = 0;
    float Xi, Yi;
    int sector;
    int a = 1;

    int i = 0;
    while (i < 5)
    {
        i = i + (a&a);

        cout << i << " shot" << ")" << endl;
        cout << "enter the coordinates of the shot Xi=" << endl;
        cin >> Xi;
        cout << "enter the coordinates of the shot Yi=" << endl;
        cin >> Yi;

        Xi = Xi + GetRandomNumber(-5, 5);
        Yi = Yi + GetRandomNumber(-5, 5);


        float rad = sqrt(Xi*Xi+Yi*Yi);

        if (rad < 1)
            sector = 1;

        if ((rad == 1) || ((rad > 1) && (rad < 2)))
            sector = 2;

        if ((rad == 2) || ((rad > 2) && (rad < 3)))
            sector = 3;

        if ((rad == 3) || ((rad > 3) && (rad < 4)))
            sector = 4;

        if ((rad == 4) || ((rad > 4) && (rad < 5)))
            sector = 5;

        switch(sector)
        {
            case 1:
                score = score + 5;
                break;
            case 2:
                score = score + 4;
                break;
            case 3:
                score = score + 3;
                break;
            case 4:
                score = score + 2;
                break;
            case 5:
                score = score + 1;
                break;

            default:
                score = score + 0;
                break;
        }
    }

    if (score < 10)
        cout << "you lose"<< endl;
    else cout << "well done ^_^";

    system("pause");
    return 0;
}
