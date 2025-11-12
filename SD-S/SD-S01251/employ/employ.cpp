#include<iostream>
#include<cstdio>
using namespace std;
const int N=1e5+10;
int n,m,a[N],vis[N],tot,ans=0,c[N];
string s;
bool check(){
	int anss=0,cnt=0;
	for(int i=1;i<=n;i++){
		if(cnt>=c[a[i]]||s[i]=='0'){
			cnt++;
		}
		else{
			anss++;
		}
	}
	if(anss>=m){
		return 1;
	}
	return 0;
}
void dfs(int x,int cnt){
	if(cnt==n){
		if(check()){
			ans++;
		}
		return;
	}
	for(int i=1;i<=n;i++){
		if(!vis[i]){
			a[++tot]=i;
			vis[i]=1;
			dfs(i,cnt+1);
			vis[i]=0;
			tot--;
		}
	}
}
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m;
	cin>>s;
	s=' '+s;
	for(int i=1;i<=n;i++){
		cin>>c[i];
	}
	for(int i=1;i<=n;i++){
		a[++tot]=i;
		vis[i]=1;
		dfs(i,1);
		vis[i]=0;
		tot--;
	}
	cout<<ans<<'\n';
	return 0;
}
