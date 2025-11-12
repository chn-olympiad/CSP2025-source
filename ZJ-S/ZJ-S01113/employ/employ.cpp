#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=5e2+10, MOD=998244353;
int n,m,k;
int ans=0,c[N],cnt=0;
char s[N];
bool f[N]; 
int cheng(int x){
	if(x==0)return 1;
	int y=x-1;
	while(y>0){
		x=x*y%MOD;
		y--;
	} 
	return x;
}
void dfs(int step,int lu){
	if(lu==m){
//		cout<<step<<" "<<lu<<" "<<cheng(n-lu)<<endl;
		ans=(ans+cheng(n-step+1))%MOD;
		return ;
	}
	if(step>n){
		return ;
	}
	for(int i=1;i<=n;i++){
		if(!f[i]){
			f[i]=1;
			dfs(step+1,lu+!(((step-lu-1)>=c[i])||!(s[step]-'0')));
			f[i]=0;
		}
	}
}
signed main(){
	ios::sync_with_stdio(0);
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m>>s+1;
	if(n<=100){
		for(int i=1;i<=n;i++)cin>>c[i];
		dfs(1,0);
		cout<<ans<<endl;
	}
	else if(m==1){
		
		for(int i=1;i<=n;i++){
			cin>>c[i];
			if(c[i])cnt++;
		}
		cout<<cnt*cheng(n-1)%MOD<<endl;
	}
	else{
	}
	return 0;
}
