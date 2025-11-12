#include <bits/stdc++.h>
using namespace std;
string s;
int a[1000005],cnt;
bool cmp(int a,int b){
    return a>b;
}
int main(){
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    cin >> s;
    for (int i=0;i<s.size();i++){
        if (s[i] >= '0' && s[i] <= '9'){
            a[cnt++] = s[i]-'0';
        }
    }
    sort(a,a+cnt+1,cmp);
    if (a[1] == 0){
        cout << 0;
        fclose(stdin);
        fclose(stdout);
        return 0;
    }
    for (int i=0;i<=cnt-1;i++){
        cout << a[i];
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}
