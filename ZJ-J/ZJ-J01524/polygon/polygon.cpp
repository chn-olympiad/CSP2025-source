#include <bits/stdc++.h>
using namespace std;
const int mod = 998244353;
int n,a[5005];
long long ans=0;
void dfs(int num,int i,int he,int maxv,bool vis){
	if(i>n+1) return;
	//cout<<num<<" "<<i<<" "<<he<<" "<<maxv<<"\n";
	if(num<3){
		dfs(num+1,i+1,he+a[i],max(maxv,a[i]),false);
		dfs(num,i+1,he,maxv,false);
	}
	else{
		if(he>2*maxv&&vis==false){
			//cout<<he<<" "<<maxv;
			ans++;
			ans%=mod;
			vis=true;
		}
		dfs(num+1,i+1,he+a[i],max(maxv,a[i]),false);
		dfs(num,i+1,he,maxv,vis);
	}
	return;
}
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	scanf("%d",&n);
	bool flag=true;
	for(int i=1;i<=n;i++){
		scanf("%d",&a[i]);
		if(a[i]!=1) flag = false;
	}
	if(n<=20){
		dfs(0,1,0,0,false);
		printf("%ld",ans);
		return 0;
	}
	if(flag==true){
		for(int i=3;i<=n;i++){
			long long x=1,y=1;
			for(int j=1;j<=i;j++){
				y*=j;
			}
			for(int j=n;n-j<=i;j--){
				x*=j;
			}
			long long cmp=x/y;
			ans+=cmp;
			ans%=mod;
		}
		printf("%ld",ans);
	}
	return 0;
}
