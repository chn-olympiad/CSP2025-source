#include <bits/stdc++.h>
#define ll long long
using namespace std;
const int maxn=1e5+5;
int t,n;
ll ans,tt;
struct f{
	int num1,num2,num3;
}a[maxn];
bool cmp(f xx,f yy){
	return xx.num1>yy.num1;
}
int dfs(int i,ll sum,int x,int y,int z){
	if(i==n) return sum;
	++i;
	if(x<(n/2)){
		tt=dfs(i,sum+a[i].num1,++x,y,z);
		x--;
		ans=max(ans,tt);
	}
	if(y<(n/2)){
		tt=dfs(i,sum+a[i].num2,x,++y,z);
		y--;
		ans=max(ans,tt);
	}
	if(z<(n/2)){
		tt=dfs(i,sum+a[i].num3,x,y,++z);
		z--;
		ans=max(ans,tt);
	}
	return ans;
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	while(t--){
		bool flag=true;
		cin>>n;
		for(int i=1;i<=n;i++){
			cin>>a[i].num1>>a[i].num2>>a[i].num3;
			if(a[i].num2!=0 || a[i].num3!=0) flag=false;
		}
		if(flag==true){
			sort(a+1,a+1+n,cmp);
			for(int i=1;i<=(n/2);i++) ans+=a[i].num1;
			cout<<ans<<"\n";
			ans=0;
			continue;
		}
		ll s=dfs(0,0,0,0,0);
		cout<<s<<"\n";
		ans=0;
	}
	return 0;
}
