#include <iostream>
#include <string>

using namespace std;

const int len = 4;

//draw the board
void draw(string(&arr)[len][len]);

//function for win
bool is_win(string(&arr)[len][len]);

//mixing the board
void mixing_the_board(string(&arr)[len][len]);

//start the game

void start_the_game(string(&arr)[len][len]);

void player_move(string move, string(&arr)[len][len]);

int main()
{
    
    string main_arr[4][4] = { " 1"," 2"," 3"," 4"," 5"," 6"," 7"," 8"," 9","10","11","12","13","14","15","  "};
    draw(main_arr);
    start_the_game(main_arr);
    return 0;
}

void draw(string(&arr)[len][len])
{
    for (int i = 0; i < len; i++)
    {
        for (int j = 0; j < len; j++) 
        {
            cout << "|" << arr[i][j];
        }
        cout << "|";
        cout << endl;
    }
}

bool is_win(string(&arr)[len][len])
{
    if (arr[0][0] == " 1" &&
        arr[0][1] == " 2" &&
        arr[0][2] == " 3" &&
        arr[0][3] == " 4" &&
        arr[1][0] == " 5" &&
        arr[1][1] == " 6" &&
        arr[1][2] == " 7" &&
        arr[1][3] == " 8" &&
        arr[2][0] == " 9" &&
        arr[2][1] == "10" &&
        arr[2][2] == "11" &&
        arr[2][3] == "12" &&
        arr[3][0] == "13" &&
        arr[3][1] == "14" &&
        arr[3][2] == "15" &&
        arr[3][3] == "  ") 
    {
        return true;
    }
    else 
    {
        return false;
    }
    
}

//void mixing_the_board(string(&arr)[len][len])
void mixing_the_board(string(&arr)[len][len])
{
    int array_for_mix[16] = {0};
    int temp;
    srand(time(NULL));
    
    for (int i = 0; i < 16; i++)
    {
        temp = (rand() % 16)+1;

        while (temp == array_for_mix[0] ||
            temp == array_for_mix[1] ||
            temp == array_for_mix[2] ||
            temp == array_for_mix[3] ||
            temp == array_for_mix[4] || 
            temp == array_for_mix[5] || 
            temp == array_for_mix[6] ||
            temp == array_for_mix[7] ||
            temp == array_for_mix[8] ||
            temp == array_for_mix[9] ||
            temp == array_for_mix[10] ||
            temp == array_for_mix[11] ||
            temp == array_for_mix[12] ||
            temp == array_for_mix[13] ||
            temp == array_for_mix[14] ||
            temp == array_for_mix[15])

        {
            temp = (rand() % 16)+1;
        }
        array_for_mix[i] = temp;
    }
    for (int i = 0; i < 16; i++)
    {
        array_for_mix[i]--;
    }
    for (int i = 0, j = 15; i <= 7; i++, j--)
    {
        string tmp = "";
        //random shuffle
        tmp = *(*arr + array_for_mix[i]);
        *(*arr + array_for_mix[i]) = *(*arr + array_for_mix[j]);
        *(*arr + array_for_mix[j]) = tmp;
    }
}

void start_the_game(string(&arr)[len][len])
{
    string start;
    string user_move;
    cout << endl;
    cout << "Press 's' for start:";
    getline(cin, start);
    if (start == "s")
    {
        system("cls");
        cout << "Starting game..." << endl;
        mixing_the_board(arr);
        while (is_win(arr) != true)
        {
            system("cls");
            draw(arr);
            cout << endl;
            cout << "Enter the number you want to move->";
            getline(cin, user_move);
            //convert "1" to " 1" etc
            if (user_move.length() == 1)
            {
                user_move = " " + user_move;
            }
            player_move(user_move, arr);
        }       
        if (is_win(arr) == true)
        {
            cout << "You win!" << endl;
        }
    }
    else
    {
        cout << "Exit...";
    }
}

void player_move(string move, string(&arr)[len][len])
{
    bool flag = false;
    for (int i = 0; i < len; i++) 
    {
        for (int j = 0; j < len; j++)
        {
            if (move == arr[i][j] && flag == false)
            {
                cout << "Found! i " << i << " j " << j << endl;
                //trying to move
                if (arr[i][j - 1] == "  " && j != 0)
                {
                    string temp;
                    temp = arr[i][j];
                    arr[i][j] = arr[i][j - 1];
                    arr[i][j - 1] = temp;
                    flag = true;
                    break;
                }
                if (arr[i - 1][j] == "  " && i != 0)
                {
                    string temp;
                    temp = arr[i][j];
                    arr[i][j] = arr[i-1][j];
                    arr[i - 1][j] = temp;
                    flag = true;
                    break;

                }
                if (arr[i + 1][j] == "  " && i != 3) 
                {
                    string temp;
                    temp = arr[i][j];
                    arr[i][j] = "  ";
                    arr[i + 1][j] = temp;
                    flag = true;
                    break;
                }
                if (arr[i][j + 1] == "  " && j != 3)
                {
                    string temp;
                    temp = arr[i][j];
                    arr[i][j] = "  ";
                    arr[i][j+1] = temp;
                    flag = true;
                    break;
                }
            }
        }
    }
}
