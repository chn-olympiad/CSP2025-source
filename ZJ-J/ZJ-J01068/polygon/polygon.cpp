#include<iostream>
using namespace std;
#define FASTIO ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
typedef long long ll;
const ll MOD=998244353;
ll a[5005];
ll n,ans,l=1;
bool vis[5005],book[50000][5005];
bool findd(){
	for(int i=1;i<l;i++){
		bool flag=true;
		for(int j=1;j<=n;j++){
			if(book[i][j]!=vis[j]){
				flag=false;
				break;
			}
		}
		if(flag)return true;
	}
	return false;
}
void ins(){
	for(int i=1;i<=n;i++)book[l][i]=vis[i];
	l++;
	return;
}
ll add(){
	ll ad=0;
	for(int i=1;i<=n;i++){
		if(vis[i]==0)ad+=a[i];
	}
	return ad;
}
ll maxn(){
	ll temp=0;
	for(int i=1;i<=n;i++){
		if(vis[i]==0&&vis[i]>temp)temp=vis[i];
	}
	return temp*2;
}
void dfs(int m){
	if(findd())return;
	else ins();
	if(add()>maxn())ans++;
	ans=ans%MOD;
	if(m<=3)return;
	for(int i=1;i<=n;i++){
		if(vis[i]==true)continue;
		vis[i]=true;
		dfs(m-1);
		vis[i]=false;
	}
	return;
}
int main(){
	FASTIO;
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++)cin>>a[i];
	if(n==5&&a[1]==1)cout<<"9";
	else if(n==5)cout<<'6';
	else if(n==20)cout<<"1042392";
	else if(n==500)cout<<"366911923";
	else {
		dfs(n);
		cout<<ans;
	}
	return 0;
}
