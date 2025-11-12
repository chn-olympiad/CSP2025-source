#include<bits/stdc++.h>
using namespace std;
const int mod=998244353;
int n,m,s[1000],ans,fl[100009],c[100009],tmp=0;
void dfs(int i,int cnt){
	if(i>n&&cnt>=m){
		ans++;
		return;
	}
	if(n-i+cnt+1<m)return;
	for(int j=1;j<=n;j++){
		if(fl[j])continue;
		if(s[i]==0){
			fl[j]=1;
			dfs(i+1,cnt);
			fl[j]=0;
		}else{
		
		if(c[j]<=i-1-cnt){
			fl[j]=1;
			dfs(i+1,cnt);
			fl[j]=0;
		}else{
			fl[j]=1;
			dfs(i+1,cnt+1);
			fl[j]=0;
		}
		tmp/=10;
	}
	}
}
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m;
	char wwww;
	for(int i=1;i<=n;i++){
		cin>>wwww;
		s[i]=wwww-'0';
	}
	for(int i=1;i<=n;i++)cin>>c[i];
		dfs(1,0);
		cout<<ans%mod<<endl;
return 0;}
