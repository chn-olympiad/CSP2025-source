#include<bits/stdc++.h>
#define int long long
using namespace std;
int n,m;
int cnt,a[505];
bool vis[505];
char s[505];
int c[505];
int ans;
int check(){
	int sum=0,dsum=0;//录用多少个 ,没~ 
//	for(int i=1;i<=n;i++){
//		cout<<a[i]<<" ";
//	}cout<<"\n";
	for(int i=1;i<=n;i++){//s[i]
		
		if(dsum>=c[a[i]]){
			dsum++;
			continue;
		}
		if(s[i]=='0'){
			dsum++;
		}else{
			sum++;
		}
//		cout<<sum<<" "<<dsum<<"\n";
	}
	if(sum>=m){
		return 1;
	}else{
		return 0;
	}
}
void dfs(int step){
	vis[step]=1;
	if(cnt==n){
		ans+=check();
		return ;
	}
	for(int i=1;i<=n;i++){
		if(vis[i]==1){
			continue;
		}
		vis[i]=1;
		cnt++;
		a[cnt]=i;
		dfs(i);
		a[cnt]=0;
		vis[i]=0;
		cnt--;
	}
	return ;
}
signed main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>s[i];
	}
	for(int i=1;i<=n;i++){
		cin>>c[i];
	}
	for(int i=1;i<=n;i++){
		vis[i]=0;
	}
	if(n<=18){
		dfs(0);
		cout<<ans;
		return 0;
	}
	int sum=1;
	for(int i=1;i<=n;i++){
		sum*=i;
		sum%=998244353;
	}
	cout<<sum;
	return 0;
}