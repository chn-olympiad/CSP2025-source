#include<bits/stdc++.h>
using namespace std;
int m,n,k,ans=1000000010,fe=0;
int str[1000010],en[1000010],mon[1000010];
int con[15],cr[10010];
int lu[1000010]={0};
void dfs(int x){
     int city=0;
    lu[x]=1;
	if(city==n){
		ans=min(ans,fe);
		return;
	}
	else{
	if(lu[x]==0)
	{
		city++;
		fe=fe+mon[x];
	    dfs(str[en[x]]);
	    return;
	}
	else if(lu[x]==1)
	{
		 dfs(str[en[x]]);
		 return;
	}
	}
}
int main(){
freopen("road.in","r",stdin);
freopen("road.out","w",stdout);
    cin>>n>>m>>k;
    for(int i=1;i<=m;i++)
    {
    	cin>>str[i]>>en[i]>>mon[i];
	}
	for(int j=1;j<=k;j++){
		cin>>con[j];
		for(int l=1;l<=n;l++){
		cin>>cr[l]	;
		}
	}
	dfs(str[1]);
	cout<<ans;
	return 0;
}
