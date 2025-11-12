#include<bits/stdc++.h>
using namespace std;
int n,m,c[505],cnm,ns[505];
long long ans;
bool fa=true,use[505];
string s;
void dfs(int d){
	if(d>=n){int lm=0,nm=0;
		for(int i=0;i<d;i++){
		if(s[i]=='1'&&c[ns[i]]>nm)lm++;
		else nm++;
		if(nm>n-m)break;	
		}
		
		if(lm>=m){
			ans++;
			ans=ans%998244353;
			
		} 
		return ;
	}
	for(int i=1;i<=n;i++)
	if(use[i]==false){
		use[i]=true;ns[d]=i;
		dfs(d+1);
		use[i]=false;
		ns[d]=0;
	}
}
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m>>s;
	for(int i=1;i<=n;i++){
		cin>>c[i];
	}
		dfs(0);
		cout<<ans;
	
	return 0;
}