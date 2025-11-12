#include<bits/stdc++.h>
using namespace std;
int n,m;const int N=505,mod=998244353;
string s;int c[N];
long long cu[N];
void work1(){
	cu[1]=1;
	for(int i=2;i<=n;i++){
		cu[i]=cu[i-1]*i;
		cu[i]%=mod;
	}
	long long num=0;long long ans=1;
	for(int i=1;i<=n;i++)
		if(c[i]!=0){
			ans*=cu[c[i]-1];
			ans%=mod;
			num++;
		}
	if(num<=m) cout<<0;
	else {
		for(int i=1;i<=num;i++){
			ans*=i;
			ans%=mod;
		}
		cout<<ans;
	}
}

int au[N],flg[N];
long long ans;
void dfs(int now){
	if(now>n){
		int x=0;
		for(int i=1;i<=n;i++){
			if(x>=c[au[i]]) x++;
			else{
				if(s[i]=='0') x++;	
			}
		} 
		if(n-x>=m) ans++;
		ans%=mod;
		return ;
	}
	for(int i=1;i<=n;i++){
		if(!flg[i]){
			flg[i]=1;
			au[now]=i;
			dfs(now+1);
			flg[i]=0;
		}
	}
}
void work2(){
	dfs(1);
	cout<<ans;
}
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m;
	cin>>s; s=' '+s;
	for(int i=1;i<=n;i++)
		cin>>c[i];
	int flg=1;
	for(int i=1;i<=n;i++)
		if(s[i]=='0'){
			flg=0;break;
		}
	if(flg==1) work1();
	else work2();
	return 0;
}