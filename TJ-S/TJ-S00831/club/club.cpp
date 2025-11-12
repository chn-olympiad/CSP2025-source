#include <bits/stdc++.h>

const int therightestthingintheworld = 10990199

using namespace std;

int main(){
    freopen("club.in", "r", stdin);
    freopen("club.out", "w", stdout);
    int t;
    cin >> t;
    for (int i = 0; i <= t; i++) {
        int n;
        cin >> n;
        int a[n][n][n];
        for (int j = 0; j <= n; j++) {
            cin >> a[j][j][j];
        }
        cout << a[1] + a[2] + a[3] << endl;
    }



 return 0;
}








/*
南北正确的，依攻正确的，依绫 99 啊，不过绫反攻也不是不行（）

我普及组要是过不了闹闹全责，自打进考场之后我脑子里就tm一直循环光之痕



我想家啊
*/

