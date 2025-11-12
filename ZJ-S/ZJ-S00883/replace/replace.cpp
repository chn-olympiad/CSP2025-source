#include<bits/stdc++.h>
using namespace std;
#define ull unsigned long long 
const int N = 2e5+10;
const int base = 31;
int n,q;
ull p[N];
string str[2][N];
vector<ull>s[2][N];
string now[2];
vector<ull>nows[2];
ull geth(vector<ull> &s,int l,int r){
    if(l == 0) return s[r];
    if(l > r) return 0;
    return s[r] - s[l-1] * p[r-l+1];
}
int main(){
    ios::sync_with_stdio(false);
    freopen("replace.in","r",stdin);
    //freopen("replace.out","w",stdout);
    cin >> n >> q;
    for(int i = 1;i <= n;i++){
        cin >> str[0][i] >> str[1][i];
        int l = str[0][i].length();
        for(int j = 0;j <= 1;j++){
            s[j][i].resize(l);
            s[j][i][0] = str[j][i][0] - 'a';
            for(int k = 1;k < l;k++){
                s[j][i][k] = s[j][i][k-1] * base + (str[j][i][k] - 'a');
            }
        }
    }
    p[0] = 1;
    for(int i = 1;i <= n;i++)
        p[i] = p[i-1] * base;
    while(q--){
        cin >> now[0] >> now[1];
        int l = now[0].length();
        if(l != now[1].length()){
            puts("0");
            continue;
        }
        int be = 0,ls = 0;
        for(int i = 0;i < l;i++){
            if(now[0][i] != now[1][i]){
                be = i;
                break;
            }
        }
        for(int i = l-1;i >= 0;i--){
            if(now[0][i] != now[1][i]){
                ls = i;
                break;
            }
        }
        int ll = ls - be + 1;
        for(int j = 0;j <= 1;j++){
            nows[j].resize(l);
            nows[j][0] = now[j][0] - 'a';
            for(int k = 1;k < l;k++)
                nows[j][k] = nows[j][k-1] * base + (now[j][k] - 'a');
        }

        int ans = 0;
        for(int i = 1;i <= n;i++){
            int nlen = str[0][i].length();
            for(int j = 0;j <= nlen - ll;j++){
                //cout << nlen << ' ';
                if(geth(s[0][i],j,j+ll-1) == geth(nows[0],be,ls) && geth(s[1][i],j,j+ll-1) == geth(nows[1],be,ls)){
                    cout << "orz\n";
                    if(be < j || geth(s[0][i],0,j-1) != geth(nows[0],be-j,be-1) || geth(s[1][i],0,j-1) != geth(nows[1],be-j,be-1)){
                        cout << "orz3\n";
                        cout << str[0][i] << ' ' << str[1][i] << '\n';
                        cout << j-1 <<' ' <<  be-j <<' ' << be-1 << '\n';
                        cout << geth(s[0][i],0,j-1) << ' ' << geth(nows[0],be-j,be-1) << '\n';
                        continue;
                    }
                    if(l - ls < nlen - (j+ll-1) || geth(s[0][i],j+ll,nlen-1) != geth(nows[0],ls+1,ls+nlen-j-ll) || geth(s[1][i],j+ll,nlen-1) != geth(nows[1],ls+1,ls+nlen-j-ll)){
                        //cout << "orz3\n";
                        continue;
                    }
                    ans += 1;
                }
            }
        }
        cout << ans << '\n';
    }
    return 0;
}