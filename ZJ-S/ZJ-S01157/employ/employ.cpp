#include<bits/stdc++.h>
#define maxn (int)(1005)
#define maxm (int)(2e6+5)
using namespace std;
int n,m,a[maxn],c[maxn],ans,vis[maxn];
void dfs(int now,int now_run){
	if(now==n+1&&(n-now_run)>=m){
		ans++;
		return;
	}
	for(int i=1;i<=n;i++){
		if(!vis[i]){
			vis[i]=true;
			int temp=0;
			if((now_run>=a[i])||(c[now]==0))temp=1;
			//cout << now << " " << i << " " << now_run+temp << endl;
			dfs(now+1,now_run+temp);
			vis[i]=false;
		}	
	}
}
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0),cout.tie(0);
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin >> n >> m;
	for(int i=1;i<=n;i++){
		char ch;
		cin >> ch;
		c[i]=ch-48;
	}
	for(int i=1;i<=n;i++){
		cin >> a[i];
	}
	if(n<=10){
		dfs(1,0);
		cout << ans;
	}
	else {cout << 0;}
	//system("employ.out");
}

//freopen("road3.in","w",stdin);
//froepen("road.out","r",stdout);
//luogu-??????
//ZJ-S??????
//probably AFO
//ÓÐ2=Âð£¿ºÜÀ¶µÄÀ²
