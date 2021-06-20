#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;
void Mood(int s)
{
    if(s<0)
    {
        cout<<"\n\n_______________________\n";
        cout<<"|  Jerry is very sad. |\n";
        cout<<"|        *****        |\n";
        cout<<"|        *~ ~*        |\n";
        cout<<"|        * ^ *        |\n";
        cout<<"|        *****        |\n";
        cout<<"|_____________________|\n\n";
    }
    if(s==0)
    {
        cout<<"\n\n__________________\n";
        cout<<"|  Jerry is sad. |\n";
        cout<<"|     *****      |\n";
        cout<<"|     *o o*      |\n";
        cout<<"|     * ^ *      |\n";
        cout<<"|     *****      |\n";
        cout<<"|________________|\n\n";
    }
    if(s==1)
    {
        cout<<"\n\n__________________________\n";
        cout<<"| Jerry is not that sad. |\n";
        cout<<"|         *****          |\n";
        cout<<"|         *. .*          |\n";
        cout<<"|         * ^ *          |\n";
        cout<<"|         *****          |\n";
        cout<<"|________________________|\n\n";
    }
    if(s==2 || s==3 || s==4)
    {
        cout<<"\n\n______________________________________\n";
        cout<<"| Jerry is fine but he is not happy. |\n";
        cout<<"|               *****                |\n";
        cout<<"|               *. .*                |\n";
        cout<<"|               * - *                |\n";
        cout<<"|               *****                |\n";
        cout<<"|____________________________________|\n\n";
    }
    if(s==5)
    {
        cout<<"_________________________________\n";
        cout<<"|   Jerry is happy! YOU WON!!!  |\n";
        cout<<"|             *****             |\n";
        cout<<"|             *^ ^*             |\n";
        cout<<"|             * - *             |\n";
        cout<<"|             *****             |\n";
        cout<<"|_______________________________|\n\n";
        cout<<"Thanks for playing!\n";
    }
}

int main ()
{
    int score=0;
    srand(time(0));
    int guess;
    int height=rand()%10+1, flower=rand()%3+1, cat=rand()%3+1, toy=rand()%5+1;
    int heightguess, flowerguess, catguess, toyguess;
    int heightbr=0, flowerc=0, catc=0, toyc=0;
    int flowermat=rand()%3+3, catmat=rand()%3+3, toymat=rand()%5+3;
    int flowerhint=0, cathint=0, toyhint=0;
    int materials=flowermat+catmat+toymat;


    cout<<"WELCOME TO JerryIsSad  1.0!\n";
    cout<<"(reach the score of 5 points before you run out of materials to win)\n\n";
    Mood(score);
    cout<<"\nHello! As you can see, Jerry is sad. Try to do anything to make him happy.\n";
    cout<<"\n(You have "<<materials<<" materials in total)\n\n";

    while(score<5)
    {
        if(materials==0 && score<5)
        {
          cout<<"\nWE'RE OUT OF MATERIALS AND JERRY ISN'T HAPPY.";
          cout<<"\nYOU LOSE.\n";
          return 0;
        }
        else
        {
            cout<<"_____________________________\n";
            cout<<"|- Give Up(0)               |\n";
            cout<<"|- Guess his height(1)      |\n";
            cout<<"|- Give him a flower(2)     |\n";
            cout<<"|- Give him a cat(3)        |\n";
            cout<<"|- Give him a toy(4)        |\n";
            cout<<"--------------------------------> What do you try: ";
            cin>>guess;
            while(guess<0||guess>4)
            {
                cout<<"What do you try: ";
                cin>>guess;
            }
            if(guess==0)
            {
                cout<<"\nYou gave up. Jerry is disappointed with you.\n";
                return 0;
            }
            if(guess==1)
            {
                if(heightbr==1) cout<<"\nYou already guessed his height correctly.\n\n";
                else
                {
                    heightguess=0;
                    while(heightguess<1 || heightguess>10)
                    {
                        cout<<"\nYour Guess (1-10cm): ";
                        cin>>heightguess;
                    }
                    if(heightguess!=height)
                    {
                        cout<<"\n--------------------------------------------";
                        cout<<"\nYou didn't guess Jerry's height correctly.\n";
                        score--;
                        cout<<"--------------------------------------------";
                        cout<<"\n-1 POINT\n";
                        cout<<"score: "<<score<<"/5"<<endl;
                        cout<<"--------------------------------------------\n";
                        Mood(score);
                    }
                    else
                    {
                        cout<<"\n+++++++++++++++++++++++++++++++++++++++++";
                        cout<<"\nYou guessed Jerry's height correctly.\n";
                        score=score+3;
                        cout<<"+++++++++++++++++++++++++++++++++++++++++";
                        cout<<"\n+3 POINTS\n";
                        cout<<"score: "<<score<<"/5"<<endl;
                        cout<<"+++++++++++++++++++++++++++++++++++++++++\n";
                        Mood(score);
                        heightbr++;
                    }
                }
            }
            if(guess==2)
            {
                if(flowerc==flowermat)
                {
                  cout<<"\n______________________________";
                  cout<<"\nSorry, we're out of flowers.\n";
                  cout<<"------------------------------\n";
                }
                else
                {
                    flowerguess=0;
                    while(flowerguess<1 || flowerguess>3)
                    {
                        cout<<"__________________________________________________\n";
                        cout<<"| Blue flower(1)| Red flower(2)| Green flower(3)|\n";
                        cout<<"------------------------------------------------------> ";
                        cin>>flowerguess;
                    }
                    if(flowerguess!=flower)
                    {
                        cout<<"\n-----------------------------------------------------";
                        cout<<"\nJerry didn't like the flower and he didn't take it.\n";
                        score--;
                        cout<<"-----------------------------------------------------";
                        cout<<"\n-1 POINT\n";
                        cout<<"score: "<<score<<"/5"<<endl;
                        cout<<"-----------------------------------------------------\n";
                        Mood(score);
                    }
                    else
                    {
                        flowerhint++;
                        flowerc++;
                        cout<<"\n+++++++++++++++++++++++++++++++++++++++++";
                        cout<<"\nJerry liked the flower and he took it!\n";
                        score++;
                        cout<<"+++++++++++++++++++++++++++++++++++++++++";
                        cout<<"\n+1 POINT\n";
                        cout<<"score: "<<score<<"/5"<<endl;
                        cout<<"+++++++++++++++++++++++++++++++++++++++++\n";
                        materials--;
                        cout<<"\n(-1 materials)\n";
                        cout<<"Materials Remaining: "<<materials<<"\n\n";
                        if(flowerhint==1) cout<<"***HINT: Now you know what kind of flowers Jerry likes.***\n";
                        Mood(score);
                    }
                }
            }
            if(guess==3)
            {
                if(catc==catmat)
                {
                  cout<<"\n____________________________";
                  cout<<"\nSorry, we're out of cats.\n";
                  cout<<"----------------------------\n";
                }
                else
                {
                    catguess=0;
                    while(catguess<1 || catguess>3)
                    {
                        cout<<"___________________________________________\n";
                        cout<<"| Gray cat(1)| Yellow cat(2)| Brown cat(3)|\n";
                        cout<<"------------------------------------------------> ";
                        cin>>catguess;
                    }
                    if(catguess!=cat)
                    {
                        cout<<"\n--------------------------------------------------";
                        cout<<"\nJerry didn't like the cat and he didn't take it.\n";
                        cout<<"--------------------------------------------------";
                        score--;
                        cout<<"\n-1 POINT\n";
                        cout<<"score: "<<score<<"/5"<<endl;
                        cout<<"--------------------------------------------------\n";
                        Mood(score);
                    }
                    else
                    {
                        cathint++;
                        catc++;
                        cout<<"\n++++++++++++++++++++++++++++++++++++++";
                        cout<<"\nJerry liked the cat and he took it!\n";
                        score++;
                        cout<<"++++++++++++++++++++++++++++++++++++++";
                        cout<<"\n+1 POINT\n";
                        cout<<"score: "<<score<<"/5"<<endl;
                        cout<<"++++++++++++++++++++++++++++++++++++++\n";
                        materials--;
                        cout<<"\n(-1 materials)\n";
                        cout<<"Materials Remaining: "<<materials<<"\n\n";
                        if(cathint==1) cout<<"***HINT: Now you know what kind of cats Jerry likes.***\n";
                        cout<<"score: "<<score<<"/5"<<endl;
                        Mood(score);
                    }
                }
            }
            if(guess==4)
            {
                if(toyc==toymat)
                {
                   cout<<"\n_______________________________";
                   cout<<"\nSorry, we're out of toys.\n";
                   cout<<"-------------------------------\n";
                }
                else
                {
                    toyguess=0;
                    while(toyguess<1 || toyguess>5)
                    {
                        cout<<"____________________________________________________________________\n";
                        cout<<"| Yellow toy(1)| Orange toy(2)| Red toy(3)| Pink toy(4)| Blue toy(5)|\n";
                        cout<<"--------------------------------------------------------------------------> ";
                        cin>>toyguess;
                    }
                    if(toyguess!=toy)
                    {
                        cout<<"\n------------------------------------------------";
                        cout<<"\nJerry didn't like the toy and he didn't take it.\n";
                        score--;
                        cout<<"------------------------------------------------";
                        cout<<"\n-1 POINT\n";
                        cout<<"score: "<<score<<"/5"<<endl;
                        cout<<"------------------------------------------------\n";
                        Mood(score);
                    }
                    else
                    {
                        toyhint++;
                        toyc++;
                        cout<<"\n+++++++++++++++++++++++++++++++++++++";
                        cout<<"\nJerry liked the toy and he took it!\n";
                        cout<<"+++++++++++++++++++++++++++++++++++++";
                        score++;
                        cout<<"\n+1 POINT\n";
                        cout<<"+++++++++++++++++++++++++++++++++++++\n";
                        materials--;
                        cout<<"\n(-1 materials)\n";
                        cout<<"Materials Remaining: "<<materials<<"\n\n";
                        if(toyhint==1) cout<<"***HINT: Now you know what kind of toys Jerry likes.***\n";
                        cout<<"score: "<<score<<"/5"<<endl;
                        Mood(score);
                    }
                }
            }
        }
    }

    return 0;
}
