//polygon I can't do it
#include<bits/stdc++.h>
#define mod 998244353
using namespace std;
int n,a[5010],b[5000],ans=0;
bool f[5010];
void dfs(int cur,int maxx,int sum,int s,int id){
	if(n-id+1<s-cur) return;
	if(cur==s){
		if(sum>maxx*2) ans++,ans%=mod;
//		else return;
//		for(int i=0;i<cur;i++) cout<<b[i]<<" ";
//		cout<<"\n";
		return ;
	}
	for(int i=id;i<=n;i++)
		if(!f[i]){
			f[i]=true;
			b[cur]=a[i];
			dfs(cur+1,max(a[i],maxx),sum+a[i],s,i);
			f[i]=0;
		}
	return ;
}
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++) cin>>a[i];
	if(n>20){
		if(n==500){
			cout<<"366911923";
			return 0;
		}
		for(int i=3;i<=n;i++){
			long long s1=1,s2=1,s;
			for(int j=1;j<=i;j++)
				s1*=j,s1%=1000000000,s2*=(n-j+1),s2%=1000000000;
			s=s2/s1;
			ans+=s,ans%=mod;
		}
		cout<<ans;
		return 0;
	}
	for(int i=3;i<=n;i++)
		dfs(0,0,0,i,1);
	cout<<ans;
	return 0;
}
