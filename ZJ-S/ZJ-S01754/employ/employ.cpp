#include <iostream>
#include <string>

#define int long long

using std::cin;
using std::string;
using std::cout;

const int mod=998244353;

int n,m,ans;
string str;
int x[510];
bool used[510];
int p[510];

void dfs(int s){
    if(s==n+1){
        int cnt=0,ls=0;
        for(int i=1;i<=n;i++){
            if(ls>=x[p[i]]){
                ls++;
                continue;
            }
            if(str[i-1]-'0'){
                ls=0;
                cnt++;
            }
            else{
                ls++;
            }
        }
        if(cnt>=m){
            ans++;
        }
    }
    else{
        for(int i=1;i<=n;i++){
            if(used[i])continue;
            used[i]=true;
            p[s]=i;
            dfs(s+1);
            p[s]=0;
            used[i]=false;
        }
    }
}

signed main()
{
    freopen("employ.in","r",stdin);
    freopen("employ.out","w",stdout);
    cin>>n>>m;
    cin>>str;
    for(int i=1; i<=n; i++)
    {
        cin>>x[i];
    }
    dfs(1);
    cout<<ans<<'\n';
    return 0;
}
