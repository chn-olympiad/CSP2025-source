#include <bits/stdc++.h>
#define ll long long
using namespace std;

const int N = 1e6 + 3;
ll ans, a[N], i;
string s;
int main(){
    freopen("number.in", "r", stdin);
    freopen("number.out", "w", stdout);
    cin >> s;
    for (char ch : s){
        if (ch >= '0' && ch <= '9'){
            a[i] = ch - '0';
            i ++;
        }
    }
    sort(a, a + i);
    for (int x = i - 1; x >= 0; x --)
        printf("%d", a[x]);
    fclose(stdin);
    fclose(stdout);
    return 0;
}
