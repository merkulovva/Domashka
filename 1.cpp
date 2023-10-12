#include <iostream>
#include <cmath>
#include <stdlib.h>
#include <time.h>
using namespace std;

int GetRandomNumber(int min, int max)
{
    srand(time(NULL));
    int num = min + rand() % (max - min + 1);
    return num;
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
        
        if ((((Xi*Xi)+(Yi*Yi)) == 1) || ((((Xi*Xi)+(Yi*Yi)) > 1) && (((Xi*Xi)+(Yi*Yi)) < sqrt(2))))
            sector = 2;
            
        if ((((Xi*Xi)+(Yi*Yi)) == sqrt(2)) || ((((Xi*Xi)+(Yi*Yi)) > sqrt(2)) && (((Xi*Xi)+(Yi*Yi)) < sqrt(3))))
            sector = 3;
            
        if ((((Xi*Xi)+(Yi*Yi)) == sqrt(3)) || ((((Xi*Xi)+(Yi*Yi)) > sqrt(3)) && (((Xi*Xi)+(Yi*Yi)) < sqrt(4))))
            sector = 4;
            
        if ((((Xi*Xi)+(Yi*Yi)) == sqrt(4)) || ((((Xi*Xi)+(Yi*Yi)) > sqrt(4)) && (((Xi*Xi)+(Yi*Yi)) < sqrt(5))))
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