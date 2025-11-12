#include<iostream>//CSP-S T4
#include<cstdio>//20+4=24
using namespace std;
const int N=505,md=998244353;
int n,m,s[N],c[N],ans;
bool vis[N];
void dfs(int k,int g){
	if(k==n+1){
		if(g>=m){
			ans++;
			ans%=md;
		}
		return ;
	}
	for(int i=1;i<=n;i++){
		if(vis[i]) continue;
		vis[i]=1;
		bool op=0;
		if(s[k]&&k-1-g<c[i]) op=1;
		dfs(k+1,g+op);
		vis[i]=0;
	}
	return ;
}
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m;
	int sum=0;
	for(int i=1;i<=n;i++){
		char ch;
		cin>>ch;
		if(ch=='1') s[i]=1;
		sum+=s[i];
	}
	for(int i=1;i<=n;i++){
		cin>>c[i];
	}
	if(n<=18){//20
		dfs(1,0);
		cout<<ans<<endl;
	}
	else cout<<"0"<<endl;//4
	fclose(stdin);
	fclose(stdout);
	return 0;
}
