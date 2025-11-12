//许明宇-SN-J00976-西安市高新第一学校
#include <bits/stdc++.h>
using namespace std;
int n,a[50005],b[50005],maxn,ans=0;
void dfs(int x,int sum,int len,int last){
	if(x>n){
		return;
	}
	if(sum>2*maxn&&len>=3){
//		for(int i=1;i<=cnt;i++){
//			cout<<num[i]<<' ';
//		}
//		cout<<endl;
		ans++;
	}
	for(int i=x;i<=n;i++){
		if(b[i]==0&&i>last){
			b[i]=1;
			int t=maxn;
			maxn=max(maxn,a[i]);
			dfs(x+1,sum+a[i],len+1,i);
			maxn=t;
			b[i]=0;
		}
	}
	return;
}
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	dfs(1,0,0,-1);
	cout<<ans+1;
	return 0;
}
