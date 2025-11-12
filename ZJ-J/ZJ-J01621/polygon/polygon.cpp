#include <bits/stdc++.h>
using namespace std;
const int maxn=5010;
const long long int mod=998244353;
int len[maxn],vis[maxn];
long long int ans,n;
//void dfs(int m,int max_l){
//	for(int i=1;i<=)
//}
long long int add(long long int a,long long int b){
	if(a*2>b)a=b-a;
	long long int sum_a=1,sum_b=1;
	for(int i=1;i<=a;i++){
		sum_a*=i;
		sum_a%=mod;
	}
	for(int i=1;i<=b;i++){
		sum_a*=i;
		sum_a%=mod;
	}
	for(int i=1;i<=b-a;i++){
		sum_a*=i;
		sum_a%=mod;
	}
	return sum_a%=mod;
}
int main()
{
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	int is_one=1;
	cin >> n;
	for(int i=1;i<=n;i++){
		cin >> len[i];
		if(len[i]!=1&&is_one)is_one=0;
	}
	vis[1]=1;
	if(n==3){
		int max_l=max(max(len[1],len[2]),max(len[2],len[3]));
		if(max_l*2<len[1]+len[2]+len[3])cout << 1;
		else cout << 0;
		return 0;
	}
	if(is_one){
		ans++;
		for(long long int i=3;i<n;i++){
			ans+=add(i,n);
			ans%=mod;
		}
		cout << ans;
		return 0;
	}
}