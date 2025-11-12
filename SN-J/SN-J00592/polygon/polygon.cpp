#include<bits/stdc++.h>
using namespace std;

int n,a[5005],ans,he[5],hee;
bool b[5005];
void dfs(int ii,int maxn,int i){
	if(ii>=3&&hee>2*maxn){
		ans++;
		return;
	}
	for(int i;i<=n;i++){
		if(!b[i]){
			b[i]=true;
			he[ii]=a[i];
			hee+=a[i];
			dfs(ii+1,max(maxn,a[i]),i);
			b[i]=false;
			hee-=a[i];
		}
	}
	return;
}

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	dfs(1,0,1);
	cout<<ans;
	return 0;
}
