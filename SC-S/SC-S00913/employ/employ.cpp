#include <bits/stdc++.h>
using namespace std;
const int N = 1e5+15;
int n,m,ans,a[N],sta[N];
char s[N];
bool vis[N];
bool check(){
	int cnt = 0 , sum = 0;
	for(int i = 1 ; i<=n ; i++){
		if(cnt<a[sta[i]]&&s[i]=='1') ++sum;
		else ++cnt;
		if(sum>=m) return 1;
	}
	return 0;
}
void dfs(int step){
	if(step>n){
		if(check()) ++ans;
//		for(int i = 1 ; i<=n ; i++) cout<<s[i]<<" ";
//		cout<<"\n";
		return ;
	}
	for(int i = 1 ; i<=n ; i++){
		if(!vis[i]){
			vis[i] = 1 , sta[step] = i;
			dfs(step+1);
			vis[i] = 0;
		}
	}
	return ;
}
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	scanf("%d%d",&n,&m);
	for(int i = 1 ; i<=n ; i++){
		while(s[i]!='0'&&s[i]!='1') s[i] = getchar();
	}
	for(int i = 1 ; i<=n ; i++) scanf("%d",&a[i]);
	dfs(1);
	cout<<ans;
	return 0;
}