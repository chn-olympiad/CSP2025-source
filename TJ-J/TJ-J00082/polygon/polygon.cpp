#include<iostream>
#define int long long
using namespace std;
int n,a[5005],ans;
const int mod=998244353;
void dfs(int he,int mxn,int xb,int c){
	if(c>=3&&he>2*mxn){
		ans++;
		ans%=mod;
	}
	for(int i=xb;i<=n;i++){
		if(a[i]>mxn){
			dfs(he+a[i],a[i],i+1,c+1);
		}
		else{
			dfs(he+a[i],mxn,i+1,c+1);
		}
	}
}
signed main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	scanf("%d",&n);
	if(n<3){
		printf("0");
		return 0;
	}
	for(int i=1;i<=n;i++){
		scanf("%d",&a[i]);
	}
	dfs(0,0,1,0);
	printf("%d",ans);
	return 0;
}
