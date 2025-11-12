#include<bits/stdc++.h>
using namespace std;
int a[5009];
int cnt=0,ans=0;
int n;
void dfs(int x,int sum,int maxn){
	if(x==n+1){
		if(sum>2*maxn&&maxn!=-1&&cnt>=3){
			ans++;	
		} 
		return ;
	}
	//ัก
	cnt++;
	dfs(x+1,sum+a[x],max(maxn,a[x]));
	cnt--;
	//ฒปัก
	dfs(x+1,sum,maxn); 
}
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	dfs(1,0,-1);
	cout<<ans;
	return 0;
} 
