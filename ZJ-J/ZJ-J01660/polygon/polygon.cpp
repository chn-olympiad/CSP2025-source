#include <bits/stdc++.h>
using namespace std;
const int M=998244353;
int n,a[5005],bj[5005],ans=0;
void dg(int x,int Max,int sum,int cnt){
	if(x==n+1){
		if(sum>2*Max&&cnt>=3){
			ans++;
			ans%=M;
		}
		return ;
	}
	if(bj[x]==0){
		bj[x]=1;
		dg(x+1,max(Max,a[x]),sum+a[x],cnt+1);
		bj[x]=0;
		dg(x+1,Max,sum,cnt);
	}
}
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++)scanf("%d",&a[i]);	
	dg(1,-1e9,0,0);
	cout<<ans%M;
	return 0;
}
