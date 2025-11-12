#include<bits/stdc++.h>
using namespace std;
const int N=1e5+5;
int T,n,a[N][4],dp[N][4],flag;
long long ans;
struct num{
	int x,y,id;
}b[N];
bool cmp(num p,num q){
	if(p.x==q.x)return p.y>q.y;
	return p.x>q.x;
}
inline void dfs(int x,int num1,int num2,int num3,int sum){
	if(num1>n/2||num2>n/2||num3>n/2)return;
	if(x>n){
		ans=max(ans,1ll*sum);
		return;
	}
	dfs(x+1,num1+1,num2,num3,sum+a[x][1]);
	dfs(x+1,num1,num2+1,num3,sum+a[x][2]);
	dfs(x+1,num1,num2,num3+1,sum+a[x][3]);
}
int main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin>>T;
	while(T--){
		cin>>n;
		ans=0,flag=1;
		for(int i=1;i<=n;i++){
			for(int j=1;j<=3;j++)
				cin>>a[i][j];
			if(a[i][3]!=0)flag=0;
		}
		if(n<=16){
			dfs(1,0,0,0,0);
			cout<<ans<<'\n';
			continue;
		}
		if(flag){
			for(int i=1;i<=n;i++)
				b[i].x=max(a[i][1],a[i][2]),b[i].y=min(a[i][1],a[i][2]),b[i].id=i;
			sort(b+1,b+n+1,cmp);
			int num1=0,num2=0;
			for(int i=1;i<=n;i++){
				if(a[i][1]>a[i][2]){
					if(num1<=n/2)ans+=a[i][1],num1++;
					else ans+=a[i][2],num2++;
				}
				else{
					if(num2<=n/2)ans+=a[i][2],num2++;
					else ans+=a[i][1],num1++;
				}
			}
			cout<<ans<<'\n';
		}
		else{
			for(int i=1;i<=n;i++)
				ans+=max(a[i][1],max(a[i][2],a[i][3]));
			cout<<ans<<'\n';
		}
	}
	return 0;
}