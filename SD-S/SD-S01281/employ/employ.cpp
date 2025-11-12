#include<bits/stdc++.h>
#define ll long long
using namespace std;
int n,m,c[10005],ans;
string s;
bool vis[10005];
void dfs(int pos,int cnt){
	if(cnt>n-m) return ;
	if(pos>n||pos==n+1){
		ans++;
		return ;
	}
	for(int i=1;i<=n;i++){
		if(!vis[i]){
			vis[i]=1;
			if(s[pos-1]=='0'){
				dfs(pos+1,cnt+1);
			}
			else{
				if(cnt>=c[i]) dfs(pos+1,cnt+1);
				else dfs(pos+1,cnt);
			}
			vis[i]=0;
		}
	}
}
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	scanf("%d%d",&n,&m);
	cin>>s;
	for(int i=1;i<=n;i++) scanf("%d",&c[i]);
	dfs(1,0);
	printf("%d",ans);
	return 0;
}
