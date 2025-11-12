#include<iostream>
#include<algorithm>
#define int long long
#define MOD 998244353
using namespace std;
int n;
int a[5005];
int ans;
bool flag=true;
void dfs(int num,int maxn,int total,int choose,bool judge){
	if(total>maxn*2&&choose>=3&&judge)ans++,ans%=MOD;
	if(num>=n)return;
	dfs(num+1,max(maxn,a[num+1]),total+a[num+1],choose+1,true);
	dfs(num+1,maxn,total,choose,false);
}
signed main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	if(n<3){
		cout<<0;
		return 0;
	}
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(a[i]!=1)flag=false;
	}
	if(!flag){
		dfs(0,0,0,0,false);
		cout<<ans;
	}else{
		int c=1;
		for(int i=3;i<=n;i++){
			for(int j=n;j>=n-i+1;j--){
				c*=j;
				c%=MOD;
			}
			for(int j=1;j<=i;j++){
				c/=j;
				c%=MOD;
			}
			ans+=c;
			ans%=MOD;
			c=1;
		}
		cout<<ans%MOD;
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
// expect 64 pts
