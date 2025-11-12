#include<bits/stdc++.h>
using namespace std;
int n,m,c[40];
string s;
bool b1[40],b2[40];
long long ans,a[20];
void dfs(int x,int cnt){
	if(cnt==m){
		ans+=a[n-x+1];
		ans%=998244353;
		return ;
	}
	if(x>n){
		return ;
	}
	
	for(int i=1;i<=n;i++){
		if(!b2[i]){
			b2[i]=true;
			if(x-cnt-1>=c[i]||!b1[x]){
				dfs(x+1,cnt);
			}
			else{
				dfs(x+1,cnt+1);
			}
			b2[i]=false;
		}
	}
	return ;
}
int main()
{
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m;
	cin>>s;
	s=" "+s;
	a[0]=1;
	for(int i=1;i<=20;i++){
		a[i]=a[i-1]*i;
		a[i]%=998244353;
	}
	for(int i=1;i<=n;i++){
		cin>>c[i];
		if(s[i]=='1'){
			b1[i]=true;
		}
	}
	dfs(1,0);
	cout<<ans<<"\n";
	fclose(stdin);
	fclose(stdout);
	return 0;
}
