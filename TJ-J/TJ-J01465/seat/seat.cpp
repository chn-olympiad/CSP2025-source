#include <bits/stdc++.h>
using namespace std;
int main(){
    freopen("seat.in","r",stdin);
    freopen("seat.ans","w",stdout);
    int n,m,s1,k,ansn,ansm;
    int s[110];
    cin >> n >> m;
    for(int i = 1; i <= n*m;i++){
        cin >> s[i];
    }
    s1 = s[1];
    for (int i = 1; i <= n*m;i++){
        for(int j = 1;j <= n*m ;j++){
            if(s[j] < s[j-1]){
                swap(s[j],s[j-1]);
            }
        }
    }
    for(int i = 1;i <= n*m ;i++){
        if (s[i] == s1){
            k  = i + 1;
        }
    }
    ansm = k/n + 1;
    int ansnb = k - (ansm - 1)*2;
    ansn = ansnb + 1;
    cout << ansm << " " << ansn;
    fclose(stdin);
    fclose(stdout);
    return 0;
}
