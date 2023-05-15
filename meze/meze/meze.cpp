// meze.cpp : 此檔案包含 'main' 函式。程式會於該處開始執行及結束執行。
//

#include <iostream>
#include<stack>
using namespace std;
#define maxX 20
#define maxY 20
struct location {
    int x;
    int y;
};
int main()
{
    stack<location> n;
    bool pass[maxX][maxY] = { false };
    int  map[maxX][maxY];
    for (int i = 0; i < maxY; i++) {
        for (int t = 0; t < maxX; t++) {
            cin>>map[t][i] ;
        }
    }
    //假設從(0,0)開始,(19,19)是終點
    location now;
    now.x = 0;
    now.y = 0;
    n.push(now);
    while (true) {
        bool success = false;
        if (n.top().x+1<20&&pass[n.top().x + 1][n.top().y]==false &&map[n.top().x + 1][n.top().y] == 0) {
            pass[n.top().x + 1][n.top().y] = true;
            now.x = n.top().x + 1;
            now.y = n.top().y;
            n.push(now);
            success = true;
        }
        else if (n.top().x - 1 >=0 && pass[n.top().x - 1][n.top().y] == false && map[n.top().x - 1][n.top().y] == 0) {
            pass[n.top().x - 1][n.top().y] = true;
            now.x = n.top().x - 1;
            now.y = n.top().y;
            n.push(now);
            success = true;
        }
        else if (n.top().y - 1>=0&&pass[n.top().x][n.top().y-1] == false && map[n.top().x][n.top().y-1] == 0) {
            pass[n.top().x][n.top().y-1] = true;
            now.x = n.top().x;
            now.y = n.top().y-1;
            n.push(now);
            success = true;
        }
        else if (n.top().y+1<20&&pass[n.top().x][n.top().y+1] == false && map[n.top().x][n.top().y+1] == 0) {
            pass[n.top().x][n.top().y+1] = true;
            now.x = n.top().x;
            now.y = n.top().y+1;
            n.push(now);
            success = true;
        }
        else if (!success) {
            n.pop();
        }
        if (n.top().x == 19 && n.top().y == 19) {
            break;
        }
    }
    while (!n.empty()) {
        cout << n.top().x<< n.top().y<<endl;
        n.pop();
    }
    system("pause");
    return 0;
}

// 執行程式: Ctrl + F5 或 [偵錯] > [啟動但不偵錯] 功能表
// 偵錯程式: F5 或 [偵錯] > [啟動偵錯] 功能表

// 開始使用的提示: 
//   1. 使用 [方案總管] 視窗，新增/管理檔案
//   2. 使用 [Team Explorer] 視窗，連線到原始檔控制
//   3. 使用 [輸出] 視窗，參閱組建輸出與其他訊息
//   4. 使用 [錯誤清單] 視窗，檢視錯誤
//   5. 前往 [專案] > [新增項目]，建立新的程式碼檔案，或是前往 [專案] > [新增現有項目]，將現有程式碼檔案新增至專案
//   6. 之後要再次開啟此專案時，請前往 [檔案] > [開啟] > [專案]，然後選取 .sln 檔案
