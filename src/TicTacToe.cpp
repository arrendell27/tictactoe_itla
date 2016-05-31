
#include <iostream>
using namespace std;

void showTable();
void playerTurn();
bool gameOver();

char turn;
bool draw = false;
char table[3][3] = {{'1', '2', '3'},
                    {'4', '5', '6'},
                    {'7', '8', '9'}};


bool gameOver()
{
    for (int i = 0; i < 3; i++)//check if there is a winner
    {
        if (table[i][0] == table[i][1] && table[i][1] == table[i][2])
        {
            return true;
        }else if( (table[0][i] == table[1][i] && table[1][i] == table[2][i]))
        {
            return true;
        }else if(table[0][0] == table[1][1] && table[1][1] == table[2][2])
        {
            return true;
        }else if(table[0][2] == table[1][1] && table[1][1] == table[2][0])
        {
            return true;
        }
    }

    for (int i = 0; i < 3; i++)//check if  draw
    {
        for (int j = 0; j < 3; j++)
        {
            if (table[i][j] != 'X' && table[i][j] != 'O')
            {
                return false;
            }
        }
    }
    draw = true;
    return true;
}

int main()
{
    cout << "Game Tic - Tac - Toe\n";
    cout << endl<<endl ;

    char name1[17] = "first player";
    cout<<"player 1[X]: ";
    cin>> name1;

    char name2[17] = "second player";
    cout<<"player 2[O]: ";
    cin>> name2;

    cout << endl ;
    cout << name1<< "[X] VS "<<name2 <<  "[O]\n";
    turn = 'X';


    while (!gameOver())
    {
        showTable();
        playerTurn();
        gameOver();
    }

    if (turn == 'O' && !draw)
    {
        showTable();
        cout << endl << endl << name1<< " [X] wins!\n";
    }
    else if (turn == 'X' && !draw)
    {
        showTable();
        cout << endl << endl << name2<< " [O] wins!\n";
    }
    else
    {
        showTable();
        cout << endl << endl << "it's a  draw!\n";
    }
}

void playerTurn()
{
    int choice;
    int row = 0, column = 0;

    if (turn== 'X')
    {
        cout << "[X] choose the number where you want to play: ";
    }
    else if (turn == 'O')
    {
        cout << "[O] choose the number where you want to play: ";
    }
    cin >> choice;


    switch (choice)
    {
        case 1: row = 0; column = 0;
            break;
        case 2: row = 0; column = 1;
            break;
        case 3: row = 0; column = 2;
            break;
        case 4: row = 1; column = 0;
            break;
        case 5: row = 1; column = 1;
            break;
        case 6: row = 1; column = 2;
            break;
        case 7: row = 2; column = 0;
            break;
        case 8: row = 2; column = 1;
            break;
        case 9: row = 2; column = 2;
            break;

        default:
                cout << "that number isn't available, try 1-9\n";
                playerTurn();
    }


    if (turn == 'X' && table[row][column] != 'X' && table[row][column] != 'O')
    {
        table[row][column] = 'X';
        turn = 'O';
    }
    else if (turn == 'O' && table[row][column] != 'X' && table[row][column] != 'O')
    {
        table[row][column] = 'O';
        turn = 'X';
    }
    else
    {
        cout << "this number has been used, try another one\n";
        playerTurn();
    }
}

void showTable()
{

    cout<< endl;
    cout << "     |     |     " << endl;
    cout << "  " << table[0][0] << "  |  " << table[0][1] << "  |  " << table[0][2] << endl;
    cout << "_____|_____|_____" << endl;
    cout << "     |     |     " << endl;
    cout << "  " << table[1][0] << "  |  " << table[1][1] << "  |  " << table[1][2] << endl;
    cout << "_____|_____|_____" << endl;
    cout << "     |     |     " << endl;
    cout << "  " << table[2][0] << "  |  " << table[2][1] << "  |  " << table[2][2] << endl;
    cout << "     |     |     " << endl;
}
