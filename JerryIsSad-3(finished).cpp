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
    int height=rand()%20+1, heightguess, heightbr=0;
    int flower=rand()%3+1, flowermat=rand()%5+3, flowerc=0, flowerguess, flowerhint=0;
    int cat=rand()%3+1, catmat=rand()%5+3, catc=0, catguess, cathint=0;
    int flavor=rand()%5+1, flavormat=rand()%7+3, flavorc=0, flavorguess, flavorhint=0;
    int materials=flowermat+catmat+flavormat;

    SetConsoleTextAttribute(h, 14);
    cout<<"WELCOME TO JerryIsSad  1.0!\n";
    SetConsoleTextAttribute(h, 15);
    cout<<"(reach the score of 5 points before you run out of materials to win)\n\n";
    Mood(score);
    cout<<"\nHello! As you can see, Jerry is sad. Try to do anything to make him happy.\n";
    cout<<"\n(You have "<<materials<<" materials in total)\n\n";

    while(score<5)
    {
        if(materials==0 && score<5)
        {
          SetConsoleTextAttribute(h, 4);
          cout<<"\nWE'RE OUT OF MATERIALS AND JERRY ISN'T HAPPY.";
          cout<<"\nYOU LOSE.\n";
          SetConsoleTextAttribute(h, 15);
          return 0;
        }
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
                        cout<<"\nYou guessed Jerry's height correctly. He appreciates that you know how tall he is.\n";
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
                if(flowerc==flowermat)
                {
                  SetConsoleTextAttribute(h, 4);
                  cout<<"\nSorry, we're out of flowers.\n\n";
                  SetConsoleTextAttribute(h, 15);
                }
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
                        cout<<"\nJerry didn't like the flower and he didn't take it.\n";
                        score--;
                        SetConsoleTextAttribute(h, 4);
                        cout<<"\n-1 POINT\n";
                        SetConsoleTextAttribute(h, 15);
                        cout<<"score: "<<score<<"/5"<<endl;
                        Mood(score);
                    }
                    else
                    {
                        flowerhint++;
                        flowerc++;
                        cout<<"\nJerry liked the flower and he took it!\n";
                        score++;
                        SetConsoleTextAttribute(h, 2);
                        cout<<"\n+1 POINT\n";
                        SetConsoleTextAttribute(h, 15);
                        materials--;
                        cout<<"\n(-1 materials)\n";
                        cout<<"Materials Remaining: "<<materials<<"\n\n";
                        if(flowerhint==1) cout<<"HINT: Now you know what kind of flowers Jerry likes.\n\n";
                        cout<<"score: "<<score<<"/5"<<endl;
                        Mood(score);

                    }
                }
            }
            if(guess==3)
            {
                if(catc==catmat)
                {
                  SetConsoleTextAttribute(h, 4);
                  cout<<"\nSorry, we're out of cats.\n\n";
                  SetConsoleTextAttribute(h, 15);
                }
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
                        cout<<"\nJerry didn't like the cat and he didn't take it.\n";
                        score--;
                        SetConsoleTextAttribute(h, 4);
                        cout<<"\n-1 POINT\n";
                        SetConsoleTextAttribute(h, 15);
                        cout<<"score: "<<score<<"/5"<<endl;
                        Mood(score);
                    }
                    else
                    {
                        cathint++;
                        catc++;
                        cout<<"\nJerry liked the cat and he took it!\n";
                        score++;
                        SetConsoleTextAttribute(h, 2);
                        cout<<"\n+1 POINT\n";
                        SetConsoleTextAttribute(h, 15);
                        materials--;
                        cout<<"\n(-1 materials)\n";
                        cout<<"Materials Remaining: "<<materials<<"\n\n";
                        if(cathint==1) cout<<"HINT: Now you know what kind of cats Jerry likes.\n\n";
                        cout<<"score: "<<score<<"/5"<<endl;
                        Mood(score);
                    }
                }
            }
            if(guess==4)
            {
                if(flavorc==flavormat)
                {
                   SetConsoleTextAttribute(h, 4);
                   cout<<"\nSorry, we're out of ice-cream.\n\n";
                   SetConsoleTextAttribute(h, 15);
                }
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
                        cout<<"\nJerry didn't like the ice-cream and he didn't take it.\n";
                        score--;
                        SetConsoleTextAttribute(h, 4);
                        cout<<"\n-1 POINT\n";
                        SetConsoleTextAttribute(h, 15);
                        cout<<"score: "<<score<<"/5"<<endl;
                        Mood(score);
                    }
                    else
                    {
                        flavorhint++;
                        flavorc++;
                        cout<<"\nJerry liked the ice-cream and he took it!\n";
                        score++;
                        SetConsoleTextAttribute(h, 2);
                        cout<<"\n+1 POINT\n";
                        SetConsoleTextAttribute(h, 15);
                        materials--;
                        cout<<"\n(-1 materials)\n";
                        cout<<"Materials Remaining: "<<materials<<"\n\n";
                        if(flavorhint==1) cout<<"HINT: Now you know what kind of ice-cream Jerry likes.\n";
                        cout<<"score: "<<score<<"/5"<<endl;
                        Mood(score);
                    }
                }
            }
        }
    }

    return 0;
}
