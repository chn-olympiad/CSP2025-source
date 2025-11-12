//SN-J01197  魏赫含  西安高新一中沣东中学初中校区
#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N=5005;
int n,a[N];
ll sum=0;
void dfs(int x,ll ans,int che,int ma){
	if(x==n){
		return;
	}
	if(che>=3&&ma*2<ans){
		sum++;
		return;
	}
	dfs(x+1,ans,che,ma);
	dfs(x++,ans+a[x],che++,max(ma,a[x]));
}
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	dfs(1,0,0,0);
	cout<<sum;
	return 0;
}
