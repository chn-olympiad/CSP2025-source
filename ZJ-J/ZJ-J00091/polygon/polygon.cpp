#include<bits/stdc++.h>
using namespace std;
const int mod=998244353;
int n,m,a[100100],cnt;
int c(int aa,int bb){
	int ss=1;
	int s1=aa,s2=1;
	for(int i=0;i<bb;i++){
		ss=(ss*(s1-i)/(s2+i))%mod;
	}
	return ss;
}
void dfs(int sheng,int shu){
	//cout<<sheng<<" ";
	if(shu>=0&&sheng<=0){
		cnt=(cnt+1)%mod;
		if(shu>0){
			int sum=0;
			for(int i=1;i<=shu;i++){
				sum=(sum+c(shu,i))%mod;
			}
			cnt=(cnt+sum)%mod;
		}
		//cout<<cnt<<"!\n";
		return;
	}
	for(int i=shu;i>=1;i--){
		//cout<<i<<' '<<sheng<<"\n";
		dfs(sheng-a[i],i-1);
	}
}
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	if(n<3){
		cout<<0;
		return 0;
	}
	if(n==3){
		if(a[1]+a[2]>a[3]) cout<<1;
		else cout<<0;
		return 0;
	}
	for(int i=3;i<=n;i++){
		dfs(a[i]+1,i-1);
		//cout<<cnt<<"#\n";
	}
	cout<<cnt;
	return 0;
}
