#include<bits/stdc++.h>
using namespace std;
const int N=5e3+5,mod=998244353;
long long ans=0;
int m,a[N],k;
void dfs(int now,int now_s,int now_max,int cnt,bool x)
{
    if(now>m+1)return ;
    if(now_s>2*now_max&&cnt>=3&&x)
    {
        ans++;
    }
    ans%=mod;
    dfs(now+1,now_s+a[now],max(now_max,a[now]),cnt+1,1);//选
    dfs(now+1,now_s,now_max,cnt,0);//不选
}
int main()
{
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin >>m;
    for(int i=1;i<=m;i++)
        cin >> a[i];
    sort(a+1,a+1+m);
    dfs(1,0,0,0,0);
    cout << ans;
	return 0;
}
 
