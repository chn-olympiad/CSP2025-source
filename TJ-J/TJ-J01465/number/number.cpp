#include <bits/stdc++.h>
using namespace std;
int main(){
    freopen("number.in","r",stdin);
    freopen("number.ans","w",stdout);
    string s[100010];
    getline(cin,s);
    int a[100010];
    int ans;
    for (int i = 1;i <= 100010;i++){
        if (s[i] == '1')  a[i] = 1;
        if (s[i] == '2')  a[i] = 2;
        if (s[i] == '3')  a[i] = 3;
        if (s[i] == '4')  a[i] = 4;
        if (s[i] == '5')  a[i] = 5;
        if (s[i] == '6')  a[i] = 6;
        if (s[i] == '7')  a[i] = 7;
        if (s[i] == '8')  a[i] = 8;
        if (s[i] == '9')  a[i] = 9;
        if (s[i] == '0')  a[i] = 0;

    }
    for (int i = 1; i <= 100010;i++){
        if (a[i] < a[i-1]){
            swap(a[i],a[i-1]);
        }
    }
    for (int i = 1;i <= n;i++){
        ans = (string)a[i] + (string)a[i-1];
    }
    cout << ans;
    fclose(stdin);
    fclose(stdout);
    return 0;
}
