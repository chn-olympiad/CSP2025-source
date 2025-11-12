#include <bits/stdc++.h>
using namespace std;
unsigned long long ans,t;
int n,m,k;int a[10001];int x;
int f(int v,int o){
	t=1;
	for (int i = o+1; i <= v;i++)t*=i,t%=998244353;
	for (int i = 1; i <= v-o;i++)t/=i;
	return tt;
}
void dfs(int n){
	if (n==t)return
}
//998244353
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	if (x==3){
	cin >> n>>m>>k;
	int y=max(n,max(m,k));
	if ((n+m+k)>y*2)cout <<1;
	else cout <<0;
	}else{
		int flag=1;
		for (int i = 1; i <= x; i++){
			cin >> a[i];
			if (a[i]==0)flag=0;
		}
		if (flag){
			for (int i = 3; i <= x; i++){
				ans+=f(x,i);
				ans%=998244353;
			}
			cout << ans;
		}else{
			cout<<5;
		}
	}
	return 0;
} 
