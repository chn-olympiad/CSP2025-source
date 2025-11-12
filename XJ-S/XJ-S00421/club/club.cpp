#include<bits/stdc++.h>
using namespace std;
int ans,mp[2020][4],n,f[2020],nm;
void dfs(int z,int a,int b,int c,int an){
	if(z>n){
		ans = max(ans,an);
	}
	if(f[z]==1||a>nm||b>nm||c>nm){
		return ;
	}
	
	f[z]=1;
	if(a+1<=nm) dfs(z+1,a+1,b,c,an+mp[z][1]);
	if(b+1<=nm) dfs(z+1,a,b+1,c,an+mp[z][2]);
	if(c+1<=nm) dfs(z+1,a,b,c+1,an+mp[z][3]);
	f[z]=0;	
}


int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int t;
	cin >>t;
	while(t--){
		cin >> n;
		nm = n/2;
		memset(f,0,sizeof(f));
		ans=0;
		memset(mp,0,sizeof(mp));
		for(int i = 1;i<=n;i++){
			cin >>mp[i][1] >>mp[i][2] >>mp[i][3];
		}
		dfs(1,0,0,0,0);
		cout << ans <<endl;
		
		
	}
	return 0;
}
