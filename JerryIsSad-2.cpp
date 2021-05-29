#include <iostream>
#include <cstdlib>
#include <windows.h>
#include <ctime>
using namespace std;
void Mood(int s)
{
    HANDLE h=GetStdHandle(STD_OUTPUT_HANDLE);
    if(s<0)
    {
        SetConsoleTextAttribute(h, 4);
        cout<<"\nJerry is very sad.\n";
        cout<<"*****\n";
        cout<<"*~ ~*\n";
        cout<<"* ^ *\n";
        cout<<"*****\n\n";
        SetConsoleTextAttribute(h, 15);
    }
    if(s==0)
    {
        SetConsoleTextAttribute(h, 12);
        cout<<"\nJerry is sad.\n";
        cout<<"*****\n";
        cout<<"*o o*\n";
        cout<<"* ^ *\n";
        cout<<"*****\n\n";
        SetConsoleTextAttribute(h, 15);
    }
    if(s==1)
    {
        SetConsoleTextAttribute(h, 14);
        cout<<"\nJerry is not that sad.\n";
        cout<<"*****\n";
        cout<<"*. .*\n";
        cout<<"* ^ *\n";
        cout<<"*****\n\n";
        SetConsoleTextAttribute(h, 15);
    }

    if(s==2 || s==3 || s==4)
    {
        SetConsoleTextAttribute(h, 6);
        cout<<"\nJerry is fine, but he isn't happy.\n";
        cout<<"*****\n";
        cout<<"*. .*\n";
        cout<<"* - *\n";
        cout<<"*****\n\n";
        SetConsoleTextAttribute(h, 15);
    }
    if(s==5)
    {
        SetConsoleTextAttribute(h, 10);
        cout<<"\nJerry is happy!!! You won!\n\n";
        cout<<"*****\n";
        cout<<"*^ ^*\n";
        cout<<"* - *\n";
        cout<<"*****\n\n";
        cout<<"Thanks for playing!\n";
        SetConsoleTextAttribute(h, 15);
    }
}

int main ()
{
    HANDLE h=GetStdHandle(STD_OUTPUT_HANDLE);

    int score=0;

    srand(time(0));
    int guess;
    int height = rand()%20+1, heightguess, heightbr=0;
    int flower = rand()%3+1, flowercount = rand()%5+3, flowerc=0, flowerguess, flowerbr=0;
    int cat = rand()%3+1, catcount = rand()%5+3, catc=0, catguess, catbr=0;
    int flavor = rand()%5+1, flavourcount = rand()%5+3, flavourc=0, flavorguess, flavorbr=0;

    SetConsoleTextAttribute(h, 14);
    cout<<"WELCOME TO JerryIsSad  1.0!\n";
    SetConsoleTextAttribute(h, 15);
    cout<<"(reach the score of 5 points to win)\n\n";
    Mood(score);
    cout<<"\nHello! As you can see, Jerry is sad. Try to do anything to make him happy.\n\n";

    while(score<5)
    {
        if(flowerc==flowercount && catc==catcount && flavorc==flavorcount && score<5) cout<<"\nWe're out of materials. You lose.\n";
        else
        {
            cout<<"- Give Up(0)\n- Guess his height(1)\n- Give him a flower(2)\n- Give him a cat(3)\n- Give him an ice-cream(4)\n\nWhat do you try: ";
            cin>>guess;
            while(guess<0||guess>4)
            {
                cout<<"What do you try: ";
                cin>>guess;
            }
            if(guess==0)
            {
                cout<<"\nYou gave up. Jerry is disappointed with you.";
                return 0;
            }
            if(guess==1)
            {
                if(heightbr==1) cout<<"\nYou already guessed his height correctly.\n\n";
                else
                {
                    heightguess=0;
                    while(heightguess<1 || heightguess>20)
                    {
                        cout<<"\nYour Guess (1-20): ";
                        cin>>heightguess;
                    }
                    if(heightguess!=height)
                    {
                        cout<<"\nYou didn't guess Jerry's height correctly.\n";
                        score--;
                        SetConsoleTextAttribute(h, 4);
                        cout<<"\n-1 POINT\n";
                        SetConsoleTextAttribute(h, 15);
                        cout<<"score: "<<score<<"/5"<<endl;
                        Mood(score);
                    }
                    else
                    {
                        cout<<"\nYou guessed Jerry's height correctly. He appreciated that you know how tall he is.\n";
                        score=score+3;
                        SetConsoleTextAttribute(h, 2);
                        cout<<"\n+3 POINTS\n";
                        SetConsoleTextAttribute(h, 15);
                        cout<<"score: "<<score<<"/5"<<endl;
                        Mood(score);
                        heightbr++;
                    }
                }

            }
            if(guess==2)
            {
                if(flowerc==flowercount) cout<<"\nSorry, we're out of flowers.\n";
                else
                {
                    flowerguess=0;
                    while(flowerguess<1 || flowerguess>3)
                    {
                        SetConsoleTextAttribute(h, 1);
                        cout<<"\nBlue flower(1)";
                        SetConsoleTextAttribute(h, 15);
                        cout<<"/";
                        SetConsoleTextAttribute(h, 13);
                        cout<<"Pink flower(2)";
                        SetConsoleTextAttribute(h, 15);
                        cout<<"/";
                        SetConsoleTextAttribute(h, 10);
                        cout<<"Green flower(3)";
                        SetConsoleTextAttribute(h, 15);
                        cout<<": ";
                        cin>>flowerguess;
                    }
                    if(flowerguess!=flower)
                    {
                        cout<<"\nJerry didn't like the flower you gave him.\n";
                        score--;
                        SetConsoleTextAttribute(h, 4);
                        cout<<"\n-1 POINT\n";
                        SetConsoleTextAttribute(h, 15);
                        cout<<"score: "<<score<<"/5"<<endl;
                        Mood(score);
                    }
                    else
                    {
                        flowerbr++;
                        flowerc++;
                        cout<<"\nJerry liked the flower!\n";
                        score++;
                        SetConsoleTextAttribute(h, 2);
                        cout<<"\n+1 POINT\n";
                        SetConsoleTextAttribute(h, 15);
                        if(flowerbr==1) cout<<"HINT: Now you know what kind of flowers Jerry likes.\n\n";
                        cout<<"score: "<<score<<"/5"<<endl;
                        Mood(score);

                    }
                }
            }
            if(guess==3)
            {
                if(catc==catcount) cout<<"\nSorry, we're out of cats.\n";
                else
                {
                    catguess=0;
                    while(catguess<1 || catguess>3)
                    {
                        SetConsoleTextAttribute(h, 7);
                        cout<<"Gray cat(1)";
                        SetConsoleTextAttribute(h, 15);
                        cout<<"/";
                        SetConsoleTextAttribute(h, 14);
                        cout<<"Yellow cat(2)";
                        SetConsoleTextAttribute(h, 15);
                        cout<<"/";
                        SetConsoleTextAttribute(h, 6);
                        cout<<"Brown cat(3)";
                        SetConsoleTextAttribute(h, 15);
                        cout<<": ";
                        cin>>catguess;
                    }
                    if(catguess!=cat)
                    {
                        cout<<"Jerry didn't like the cat you gave him.\n";
                        score--;
                        SetConsoleTextAttribute(h, 4);
                        cout<<"\n-1 POINT\n";
                        SetConsoleTextAttribute(h, 15);
                        cout<<"score: "<<score<<"/5"<<endl;
                        Mood(score);
                    }
                    else
                    {
                        catbr++;
                        catc++;
                        cout<<"Jerry liked the cat!\n";
                        score++;
                        SetConsoleTextAttribute(h, 2);
                        cout<<"\n+1 POINT\n";
                        SetConsoleTextAttribute(h, 15);
                        if(catbr==1) cout<<"HINT: Now you know what kind of cats Jerry likes.\n\n";
                        cout<<"score: "<<score<<"/5"<<endl;
                        Mood(score);
                    }
                }
            }
            if(guess==4)
            {
                if(flavorc==flavorcount) cout<<"Sorry, we're out of ice-cream.";
                else
                {
                    flavorguess=0;
                    while(flavorguess<1 || flavorguess>5)
                    {
                        SetConsoleTextAttribute(h, 6);
                        cout<<"\nChocolate(1)";
                        SetConsoleTextAttribute(h, 15);
                        cout<<"/";
                        SetConsoleTextAttribute(h, 1);
                        cout<<"Blueberry(2)";
                        SetConsoleTextAttribute(h, 15);
                        cout<<"/";
                        SetConsoleTextAttribute(h, 10);
                        cout<<"Mint(3)";
                        SetConsoleTextAttribute(h, 15);
                        cout<<"/";
                        SetConsoleTextAttribute(h, 12);
                        cout<<"Strawberry(4)";
                        SetConsoleTextAttribute(h, 15);
                        cout<<"/";
                        SetConsoleTextAttribute(h, 9);
                        cout<<"Bubble gum(5)";
                        SetConsoleTextAttribute(h, 15);
                        cout<<": ";
                        cin>>flavorguess;
                    }
                    if(flavorguess!=flavor)
                    {
                        cout<<"Jerry didn't like the ice-cream you gave him.\n";
                        score--;
                        SetConsoleTextAttribute(h, 4);
                        cout<<"\n-1 POINT\n";
                        SetConsoleTextAttribute(h, 15);
                        cout<<"score: "<<score<<"/5"<<endl;
                        Mood(score);
                    }
                    else
                    {
                        flavorbr++;
                        flavorc++;
                        cout<<"Jerry liked the ice-cream!\n";
                        score++;
                        SetConsoleTextAttribute(h, 2);
                        cout<<"\n+1 POINT\n";
                        SetConsoleTextAttribute(h, 15);
                        if(flavorbr==1) cout<<"HINT: Now you know what kind of ice-cream Jerry likes.\n";
                        cout<<"score: "<<score<<"/5"<<endl;
                        Mood(score);
                    }
                }
            }
        }
    }

    return 0;
}
