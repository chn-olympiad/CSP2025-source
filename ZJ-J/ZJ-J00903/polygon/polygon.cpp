#include<bits/stdc++.h>
using namespace std;
const int mod=998244353;
int n,a;
int s[5010];
long long ans;
void dfs(int sum,int mx,int now){
	if(sum>mx*2)ans=(ans+1)%mod;
	for(int i=now;i<=n;i++){
		dfs(sum+s[i],max(mx,s[i]),i+1);
	}
}
long long C(int x,int y){
	if(x*2>y)return C(y-x,y);
	long long mid=1;
	for(int i=y;i>=y-x+1;i--)mid*=i;
	for(int i=1;i<=x;i++)mid/=i;
	return mid; 
}
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	cin>>n;
	for(int i=1;i<=n;i++)cin>>s[i];
	if(n<=3){
		int x=max(max(s[1],s[2]),s[3]);
		int sum=s[1]+s[2]+s[3];
		if(sum>x*2)cout<<"1";
		else cout<<"0";
		return 0; 
	}
	for(int i=1;i<=n;i++)if(s[i]==1)a++;
	if(a==n){
		for(int i=3;i<=n;i++)ans=(ans+C(i,n))%mod;
		cout<<ans;
		return 0;
	} 
	dfs(0,0,1);
	cout<<ans;
	return 0;
} 
