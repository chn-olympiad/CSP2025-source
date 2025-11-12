#include<bits/stdc++.h>
using namespace std;
#define int long long
int n,m,pa[505],d[505],qz[505];
bool tg[505],vis[505];
char a;
int jc(int a){
	int u=1;
	for(int i=2;i<=a;i++){
		u*=i;
		u%=998244353;
	}
	return u;
}
int dfs(int a,int de){
	if(a-de-1>=m) return jc(n-a+1);
	int ans=0;
	for(int i=1;i<=n;i++){
		if(!vis[i]){
			vis[i]=1;
			if(pa[i]<=de||tg[i]==0) ans+=dfs(a+1,de+1);
			else ans+=dfs(a+1,de);
			ans%=998244353;
			vis[i]=0;
		}
	}
	return ans;
}
signed main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin.tie(0);
	cout.tie(0);
	ios::sync_with_stdio(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a;
		tg[i]=a-'0';
		qz[i]=qz[i-1]+tg[i];
	}
	for(int i=1;i<=n;i++){
		cin>>pa[i];
	}
	sort(pa+1,pa+n+1);
	cout<<dfs(1,0);
	return 0;
} 
/*
复习时大脑是MLE的，考试时知识点是越界RE的，
题目思考时间是TLE的，思路是CE的，打好以后是证出来自己WA的， 
样例出错在自己脑子里是UKE的，交上是假装自己AC的。 
*/
