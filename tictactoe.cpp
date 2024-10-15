// in this program i have tried to manipulate the tic tac toe game 

#include <iostream>
#include <ctime>
void random1();
void user();

char m;
int s;
char opt[3][3];


using namespace std;
int main()
{
    srand(time(NULL));

    int i,j;
    for(int i  = 0;i<3;i++)
    {
        for(int j = 0;j<3;j++)
        {
            opt[i][j] = ' ';
        }
    }
    //just to display the empty grid so that a feel comes that where to place the symbol.

        cout<<" ________________________\n";
        cout<<"|       |        |      |\n";
        cout<<"|   "<<opt[0][0]<<"   |   "<<opt[0][1]<<"    |   "<<opt[0][2]<<"  |\n";
        cout<<"|_______|________|______|\n";
        cout<<"|       |        |      |\n";
        cout<<"|   "<<opt[1][0]<<"   |   "<<opt[1][1]<<"    |   "<<opt[1][2]<<"  |\n";
        cout<<"|_______|________|______|\n";
        cout<<"|       |        |      |\n";
        cout<<"|   "<<opt[2][0]<<"   |   "<<opt[2][1]<<"    |   "<<opt[2][2]<<"  |\n";
        cout<<"|_______|________|______|\n"; 

        
    cout<<"What character do you choose to play with: ";
    cin>> m; 
    
    for(int k = 0;k<9;)
    {
        
        user();
        random1();
        

        cout<<" ________________________\n";
        cout<<"|       |        |      |\n";
        cout<<"|   "<<opt[0][0]<<"   |   "<<opt[0][1]<<"    |   "<<opt[0][2]<<"  |\n";
        cout<<"|_______|________|______|\n";
        cout<<"|       |        |      |\n";
        cout<<"|   "<<opt[1][0]<<"   |   "<<opt[1][1]<<"    |   "<<opt[1][2]<<"  |\n";
        cout<<"|_______|________|______|\n";
        cout<<"|       |        |      |\n";
        cout<<"|   "<<opt[2][0]<<"   |   "<<opt[2][1]<<"    |   "<<opt[2][2]<<"  |\n";
        cout<<"|_______|________|______|\n"; 

        if(opt[0][0] ==  m && opt[0][1] == m && opt[0][2] ==m)
        {
            cout<<"You are a winner"<<endl;
            break;

        }
        else if(opt[1][0] ==  m && opt[1][1] == m && opt[1][2] ==m)
        {
            cout<<"You are a winner"<<endl;
            break;
        }
        else if(opt[2][0] ==  m && opt[2][1] == m && opt[2][2] ==m)
        {
            cout<<"You are a winner"<<endl;
            break;
        }
        else if(opt[0][0] ==  m && opt[1][0] == m && opt[2][0] ==m)
        {
            cout<<"You are a winner"<<endl;
            break;

        }
        else if(opt[0][1] ==  m && opt[1][1] == m && opt[2][1] ==m)
        {
            cout<<"You are a winner"<<endl;
            break;
        }
        else if(opt[0][2] ==  m && opt[1][2] == m && opt[2][2] ==m)
        {
            cout<<"You are a winner"<<endl;
            break;
        }
        else if(opt[0][0] ==  m && opt[1][1] == m && opt[2][2] ==m)
        {
            cout<<"You are a winner"<<endl;
            break;

        }
        else if(opt[0][2] ==  m && opt[1][1] == m && opt[2][0] ==m)
        {
            cout<<"You are a winner"<<endl;
            break;
        }
        if(opt[0][0] ==  '+'& opt[0][1] == '+' && opt[0][2] =='+')
        {
            cout<<"Computer is a winner"<<endl;
            break;

        }
        else if(opt[1][0] ==  '+' && opt[1][1] == '+' && opt[1][2] =='+')
        {
            cout<<"Computer is a winner"<<endl;
            break;
        }
        else if(opt[2][0] ==  '+' && opt[2][1] == '+' && opt[2][2] =='+')
        {
            cout<<"Computer is a winner"<<endl;
            break;
        }
        else if(opt[0][0] ==  '+' && opt[1][0] == '+' && opt[2][0] =='+')
        {
            cout<<"Computer is a winner"<<endl;
            break;

        }
        else if(opt[0][1] ==  '+' && opt[1][1] == '+' && opt[2][1] =='+')
        {
            cout<<"Computer is a winner"<<endl;
            break;
        }
        else if(opt[0][2] ==  '+' && opt[1][2] == '+' && opt[2][2] =='+')
        {
            cout<<"Computer is a winner"<<endl;
            break;
        }
        else if(opt[0][0] ==  '+' && opt[1][1] == '+' && opt[2][2] =='+')
        {
            cout<<"Computer is a winner"<<endl;
            break;

        }
        else if(opt[0][2] ==  '+' && opt[1][1] == '+' && opt[2][0] =='+')
        {
            cout<<"Computer is a winner"<<endl;
            break;
        }
        else if(k == 8)
        {
            cout<<"It is a tie.";
        }
        else{
            k++;
        }
    
    
    }
}

void random1()
{
    int n = (rand()%9)+1;
        switch(n)
        {
            case 1:
                if(opt[0][0] ==m || opt[0][0] =='+' )
                {
                    random1();
                }
                else
                {
                  opt[0][0] = '+' ;
                  break;
                }  
            case 2:
                if(opt[0][1] ==m || opt[0][1] =='+' )
                {
                    random1();
                }
                else
                {
                    opt[0][1] = '+';
                    break;
                }
            case 3:
                if(opt[0][2] ==m || opt[0][2] =='+')
                {
                    random1();
                }
                else
                {
                    opt[0][2] = '+';
                    break;
                }
            case 4:
                if(opt[1][0] ==m || opt[1][0] =='+')
                {
                    random1();
                }
                else
                {
                    opt[1][0] = '+';
                    break;
                }
            case 5:
                if(opt[1][1] ==m || opt[1][1] =='+')
                {
                    random1();
                }
                else
                {
                    opt[1][1] = '+';
                    break;
                }
            case 6:
                 if(opt[1][2] ==m || opt[1][2] =='+')
                {
                    random1();
                }
                else
                {
                    opt[1][2] = '+';
                    break;
                }
            case 7:
                if(opt[2][0] ==m || opt[2][0] =='+')
                {
                    random1();
                }
                else
                {
                    opt[2][0] = '+';
                    break;
                }
            case 8:
                if(opt[2][1] ==m || opt[2][1] =='+')
                {
                    random1();
                }
                else
                {
                    opt[2][1] = '+';
                    break;
                }
            case 9:
                if(opt[2][2] ==m || opt[2][2] =='+')
                {
                    random1();
                }
                else
                {
                    opt[2][2] = '+'; 
                    break;       
                }  
        
        }
}

void user()
{
    cout<<"Choose the place you want to mark: \n";
        cout<<"1.[0][0]  2.[0][1]  3.[0][2]\n4.[1][0]  5.[1][1]  6.[1][2]\n7.[2][0]  8.[2][1]  9.[2][2]\n";
        cin>> s;
        switch(s)
        {
             case 1:
                if(opt[0][0] == '+' ||  opt[0][0] == m)
                {
                    cout<<"Choose a spot that is not occupied.\n";
                    user();
                }
                else
                {
                  opt[0][0] = m;
                  break;
                }  
            case 2:
                if(opt[0][1] =='+' ||  opt[0][1] == m)
                {
                   cout<<"Choose a spot that is not occupied.\n";
                    user();
                }
                else
                {
                    opt[0][1] = m;
                    break;
                }
            case 3:
                if(opt[0][2] =='+' ||  opt[0][2] == m)
                {
                    cout<<"Choose a spot that is not occupied.\n";
                    user();
                }
                else
                {
                    opt[0][2] = m ;
                    break;
                }
            case 4:
                if(opt[1][0] =='+' ||  opt[1][0] == m)
                {
                    cout<<"Choose a spot that is not occupied.\n";
                    user();
                }
                else
                {
                    opt[1][0] = m;
                    break;
                }
            case 5:
                if(opt[1][1] =='+' ||  opt[1][1] == m)
                {
                    cout<<"Choose a spot that is not occupied.\n";
                    user();
                }
                else
                {
                    opt[1][1] = m;
                    break;
                }
            case 6:
                 if(opt[1][2] =='+' ||  opt[1][2] == m)
                {
                    cout<<"Choose a spot that is not occupied.\n";
                    user();
                }
                else
                {
                    opt[1][2] = m;
                    break;
                }
            case 7:
                if(opt[2][0] =='+' ||  opt[2][0] == m)
                {
                    cout<<"Choose a spot that is not occupied.\n";
                    user();
                }
                else
                {
                    opt[2][0] = m;
                    break;
                }
            case 8:
                if(opt[2][1] =='+' ||  opt[2][1] == m)
                {
                    cout<<"Choose a spot that is not occupied.\n";
                    user();
                }
                else
                {
                    opt[2][1] = m;
                    break;
                }
            case 9:
                if(opt[2][2] =='+' ||  opt[2][2] == m)
                {
                    cout<<"Choose a spot that is not occupied.\n";
                    user();
                }
                else
                {
                    opt[2][2] = m; 
                    break;       
                }      
        }
}
        
    
    
             