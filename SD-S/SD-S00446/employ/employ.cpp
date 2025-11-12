//code by JuRuoOIer(Luogu 476093)
//problem:employ
//expected:
#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cmath>
#include<cstring>
#include<string>
#include<cctype>
#include<ctime>
#include<algorithm>
#include<vector>
#include<map>
#include<unordered_map>
#include<set>
#include<queue>
#include<deque>
#include<random>
#define ll long long
#define ull unsigned long long
#define lf double
#define ld long double
using namespace std;
void file(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
}
char ch;
ll n,m,a[510],c[510],p[510],vis[510],ans;
inline void dfs(ll dep){
	if(dep==n){
		ll t=0,s=0;
		for(int i=0;i<n;i++){
			if(a[i]==0||t>=c[p[i]]){
				t++;
			}
			else s++;
		}
		ans+=(s>=m);
		return ;
	}
	for(int i=0;i<n;i++){
		if(!vis[i]){
			vis[i]=1;
			p[dep]=i;
			dfs(dep+1);
			vis[i]=0;
		}
	}
}
int main(){
	file();
	ios::sync_with_stdio(0);
	cin>>n>>m;
	for(int i=0;i<n;i++){
		cin>>ch;
		a[i]=ch-'0';
	}
	for(int i=0;i<n;i++){
		cin>>c[i];
	}
	dfs(0);
	cout<<ans;
	return 0;
}
/*
船 摇啊摇
摇到陌生的远方 摇断了船桨
进土壤 长出了愿望和新故乡
我 的朋友
你在哪 是否凝望同一轮月光
有没有 成为期待的英雄模样 
*/
