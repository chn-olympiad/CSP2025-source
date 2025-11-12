#include<bits/stdc++.h>
#define IOS ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);

#define endl '\n'

using namespace std;
using LL = long long;

int main(){

    freopen("number.in", "r", stdin);
    freopen("number.out", "w", stdout);

    IOS
    string s;
    int a[15] = {0};
    cin >> s;

    for(const auto & x : s){
        if(x >='0' && x <= '9'){
            a[x-'0']++;
        }
    }
    //至少包含一个1到9中的数字，无需考虑类似000的情况
    for(int i = 9; i >= 0; i --){
        while(a[i]){
            cout << i;
            a[i]--;
        }
    }
    cout << endl;
    

    return 0;
}