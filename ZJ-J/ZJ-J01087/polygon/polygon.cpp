#include <bits/stdc++.h>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */
using namespace std;
#define ll long long
const int MAXN=5e3+5,p=998244353;
ll n,ma=0,num,anss=0,a[MAXN],b[MAXN];
ll dfs(ll x,ll dep,ll s){
	if(dep<3){
		return 0;
	}
	if(dep==3){
		return 1;
	}
	ll su=1;
	for(int i=x-1;i>0;i--){
		if(s-a[i]<=num){
			continue;
		}
		su=(su+dfs(i,dep-1,s-a[i]))%p;
	}
	return su;
}
int main() {
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		ma=max(ma,a[i]);
		b[i]=b[i-1]+a[i];
	}
	if(ma==1){
		anss=pow(2,n);
		anss%=p;
		anss=(anss-((n*(n-1))/2)-n-1+p)%p;
		cout<<anss;
		return 0;
	}
	sort(a+1,a+n+1);
	for(int i=3;i<=n;i++){
		if(b[i-1]<=a[i]){
			continue;
		}
		num=a[i]*2;
		anss=(anss+dfs(i,i,b[i]))%p;
	}
	cout<<anss%p;
	return 0;
}
