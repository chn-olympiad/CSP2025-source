#include<bits/stdc++.h>
using namespace std;
const int MOD=998244353;
int n,m,a[510],cnt[510],ans;
bool c[510],vis[510];

void dfs(int k){
	if(k==n){
		int win=0,lose=0;
		for(int i=1;i<=n;i++){
			if(a[cnt[i]]>lose&&c[i]==1) win++;
			else lose++;
		}
		if(win>=m) ans=(ans+1)%MOD;
		return ;
	}
	for(int i=1;i<=n;i++){
		if(!vis[i]){
			vis[i]=1;
			cnt[k+1]=i;
			dfs(k+1);
			vis[i]=0;
		}
	}
}

__int128 jie(int x){
	__int128 cnt=1;
	for(int i=2;i<=x;i++){
		cnt=cnt*i%MOD;
	}
	return cnt;
}

void fun(){
	dfs(0);
	printf("%d",ans);
}

void funm(){
	
	for(int i=1;i<=n;i++){
		if(a[i]){
			ans=(ans+(jie(n-1)%MOD))%MOD;
//			cout<<ans<<endl;
		}
	}
	printf("%lld",ans);
}
/*
20 1
11111111111111111111
3 0 1 2 5 2 4 5 3 3 5 0 7 3 2 9 8 6 0 0
*/

int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
//	srand(time(0));
//	cout<<int(jie(500)%MOD);
	scanf("%d%d",&n,&m);
	int flag=0;
	for(int i=1;i<=n;i++){
		char s;
		cin>>s; 
		c[i]=s-'0';
		flag+=c[i];
//		cout<<i<<':'<<flag<<endl;
	}
	for(int i=1;i<=n;i++){
		scanf("%d",&a[i]);
	}
	/*
	3 2
	101
	1 1 2
	*/
	if(flag<m){
		printf("0");
		return 0;
	}
	if(m==1){
		funm();
		return 0;
	}
	if(n<=18){
		fun();
		return 0;
	}
	printf("0");
	return 0;
}
