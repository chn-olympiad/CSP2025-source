#include <bits/stdc++.h>
using namespace std;

const int N = 1e6+5;
int num[10];
string s;
int i = 0;

int main(){
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);

    cin >> s;
    int len = s.length();

    for(int i=0 ; i<len ; i++){
        int n = s[i]-'0';
        if(n>=0 && n<=9) num[n] ++;
    }

    for(int i = 9 ; i>=0 ; i--){
        while(num[i]-- > 0) cout << i;
    }


    fclose(stdin);
    fclose(stdout);
    return 0;
}


