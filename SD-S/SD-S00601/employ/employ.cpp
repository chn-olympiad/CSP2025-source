#include<bits/stdc++.h>
using namespace std;
long long ans=0;
int n,m,tot,c[555],vis[22],a[555];
string s;
const int mod=998244353;
inline bool check(){
	int givup=0,los=0,cnt=0;
//	for(int i =1;i<=n;i++)cout<<a[i]<<" ";
//	cout<<endl;
	for(int i =1;i<=n;i++){
		if(c[a[i]]<=los+givup){
			givup++;
		}
		else if(s[i]=='0'){
			los++;
		}
		else{
			cnt++;
		}
	}
//	cout<<los<<" "<<givup<<endl;;
	return cnt>=m;
}
void dfs(int x){
	if(x>=n){
		if(check())ans++;
		ans=ans%mod;
	//	cout<<ans<<endl;
		return ;
	}
	for(int i =1;i<=n;i++){
		if(!vis[i]){
			a[++tot]=i,vis[i]=1;
			dfs(x+1);
			tot--;vis[i]=0;
		}
	}
}
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m;
	cin>>s;
	s=" "+s;
	if(m==n){
		int flag=1;
		for(int i =1;i<=n;i++){
			cin>>c[i];
		}
		for(int i =1;i<=n;i++){
			if(s[i]!='1'){
				flag=0;
				break;
			}
		}
		if(flag==0)cout<<0<<"\n";
		else{
			ans=1;
			for(int i =1;i<=n;i++)ans=1ll*ans*i%mod;
			cout<<ans;
		}
		return 0;
	}
	else if(m==1){
		for(int i =1;i<=n;i++){
			cin>>c[i];
		}
		int tm=-1;
		for(int i =1;i<=n;i++){
			if(s[i]=='1')tm=i;
		}
		if(tm==-1){
			cout<<0;
			return 0;
		}
		int countt=0;
		for(int i =1;i<=n;i++){
			if(c[i]>tm)countt++;
		}
		if(!countt){
			cout<<0;
			return 0;
		}
		return 0;
	}
	for(int i =1;i<=n;i++){
		cin>>c[i];
	}
	dfs(0);
	cout<<ans;
}



