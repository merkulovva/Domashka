#include <iostream>
#include <cmath>
#include <cstdlib>
#include <ctime>
using namespace std;

int GetRandomNumber(int min, int max)
{
    return ((int)(rand()) / RAND_MAX) * (max - min) + min;
}

int main()
{
    int score = 0;
    int Xi, Yi, sector;
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
        
        if (((Xi*Xi)+(Yi*Yi)) < 1)
            sector = 1;
        
        if ((((Xi*Xi)+(Yi*Yi)) == 1) || ((((Xi*Xi)+(Yi*Yi)) > 1) && (((Xi*Xi)+(Yi*Yi)) < 2)))
            sector = 2;
            
        if ((((Xi*Xi)+(Yi*Yi)) == 2) || ((((Xi*Xi)+(Yi*Yi)) > 2) && (((Xi*Xi)+(Yi*Yi)) < 3)))
            sector = 3;
            
        if ((((Xi*Xi)+(Yi*Yi)) == 3) || ((((Xi*Xi)+(Yi*Yi)) > 3) && (((Xi*Xi)+(Yi*Yi)) < 4)))
            sector = 4;
            
        if ((((Xi*Xi)+(Yi*Yi)) == 4) || ((((Xi*Xi)+(Yi*Yi)) > 4) && (((Xi*Xi)+(Yi*Yi)) < 5)))
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
    
    return 0;
}