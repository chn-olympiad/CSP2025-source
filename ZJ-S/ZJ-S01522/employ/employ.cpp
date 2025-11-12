#include<bits/stdc++.h>
using namespace std;
const int mod = 998244353;
long long cnt[600],mode[600],n,m,x,ans=0;
bool vis[600];
string uuu;
void dfs(int l){
    if(l>n){
        int kill = 0, man = 0;
        for (int i = 1; i <= n;i++){
        	//cout<<mode[i]<<" ";
            if(uuu[i-1]=='0'||kill>=mode[i]){
                kill++;
            }else if(uuu[i-1]=='1'){
                man++;
            }
        }
        //cout<<"\n";
        if(man>=m) ans++;
        return;
    }
    for (int i = 1; i <= n;i++){
        if(!vis[i]){
            vis[i] = true, mode[l] = cnt[i];
            dfs(l + 1);
            vis[i] = false;
        }
    }
}
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    cin >> n >> m >> uuu;
    for (int i = 1; i <= n;i++){
        cin >> cnt[i];
    }
    dfs(1);
    cout << ans << "\n";
    return 0;
}
