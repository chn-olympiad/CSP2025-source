#include<bits/stdc++.h>
using namespace std;
char s[510];
int c[510];
int a[510];
int n,m;
bool f[510];
int ans;
int cnt;
void dfs(int x){
	if(cnt>n-m)return;
	if(x==n+1){
		ans++;
		//for(int i=1;i<=n;i++)cout << a[i];
		
		//cout << cnt << endl;
		return;
	}
	for(int i=1;i<=n;i++){
		if(f[i])continue;
		f[i]=1;
		int wwh=((s[x]=='1' && cnt<c[i])?0:1);
		//cout << wwh << " " << x << endl;
		cnt+=wwh;
		a[x]=i;
		dfs(x+1);
		
		f[i]=0;
		cnt-=wwh;
	}
}
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin >> n >> m;
	for(int i=1;i<=n;i++)cin >> s[i];
	for(int i=1;i<=n;i++)cin >> c[i];
	
	dfs(1);
	
	cout << ans;
	return 0;
}
