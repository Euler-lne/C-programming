# I/O流实验
编写一个C++程序完成猜价格游戏的一下功能
* 假定有一件商品，程序用随机数指定商品的价格（1-1000的整数）
* 提示用户猜价格，并输入：若用户猜的价格比商品价格高或者低，对用户做出提示
* 直到到猜对为止，并给出提示。（提示及要求：1.要求使用C++的输入输出方式（cin，cout），不能使用C语言的printf等；2.注意检查输入的合法性）

## 笔记
* string 类型转换为 int
```CPP
#include <iostream>
#include <string>
 
using namespace std;
 
int main()
{
    char* s = "1234";
    string str("5678");
 
    int intS = atoi(s);
 
    //此写法会报错
    //int intStr = atoi(str);
    //需先将string转成char*
    int intStr = atoi(str.c_str());
 
    cout << "char* 转int:    " << intS << endl;
    cout << "string 转int:    " << intStr << endl;
 
    system("pause");
    return 0;
}
```
* 判断输入是否正确
```CPP
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
```