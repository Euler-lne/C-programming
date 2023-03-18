#include "game.h"
#include <bits/stdc++.h>
using namespace std;
Game::Game()
{
    
}
Game::~Game()
{
    cout << "Delet Game" << endl;
}
void Game::Init()
{
    srand(time(nullptr)); // 用当前时间作为种子
    int min = 1, max = 1000;
    this->answer = (rand() % (max - min + 1)) + min; // 范围[min,max]

    char temp;
    cout << "Welcome to the game of guessing the price of goods, enter a integer from the range of 1-1000." << endl;
    cout << "Enter y/Y to start the game, enter other characters to exit the game." << endl;
    cin >> temp;
    if (temp == 'y' || temp == 'Y')
        this->Start();
    else
        this->End();
}
void Game::Start()
{
    cout << "The game starts, enter n/N during the game to end the game." << endl;
    int input = this->Input();
    while (input != -1 && input != this->answer)
    {
        if(input < this->answer)
        {
            cout << "This number is smaller than the number to be guessed." << endl
                 << "Enter a larger one: ";
            input = this->Input();
        }
        else
        {
            cout << "This number is larger than the number to be guessed." << endl
                 << "Enter a smaller one: ";
            input = this->Input();
        }
    }
    if(input == -1)
        this->End();
    else
        this->Win();
}
void Game::End()
{
    cout << "Thank for your play." << endl;
}
void Game::Win()
{
    char temp;
    cout << "Congratulations! " << endl
         << "Enter y/Y to exit the game, enter other characters to start a new game." << endl;
    cin >> temp;
    if(temp == 'y' || temp == 'Y')
        this->End();
    else
        this->Init();
}
/// @brief 检查输入函数
/// @return 返回-1代表输入n/N
int Game::Input()
{
    string temp;
    cin >> temp;
    int len = temp.length();
    if ((temp[0] == 'n' || temp[0] == 'N') && len == 1)
        return -1;
    else if (len > 4)
    {
        cout << "Enter a integer from the range of 1-1000. Re-enter!" << endl;
        return this->Input();
    }
    else
    {
        for (int i = 0; i < len; i++)
        {
            //如果有一个位置不是整数，那就在此调用这个函数
            if(!isdigit(temp[i]))
            {
                cout << "Enter a integer from the range of 1-1000. Re-enter!" << endl;
                return this->Input();
            }
        }
        //先将string类型转换为char * 然后再将char * 转换为int
        return atoi(temp.c_str());
    }
}