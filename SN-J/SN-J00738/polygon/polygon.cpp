//SN-J00738 王子铭 西安市曲江第一中学 
#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N = 5e3+5;
const int mod = 998244353;
int a[N],n,b[N],vis[N],ans = 0,v[N];
void dfs(int last,int l,int num,int end){
	if(num==end+1){
		int sum = 0,mx = 0;
		for(int i = 1;i <= end;i ++){
			sum = sum+b[i]%mod;
			mx = max(mx,b[i]);
		}
		if(sum>2*mx){
			ans = ans+1%mod;
		}
		return;
	}
	for(int i = 1;i <= n;i ++){
		if(a[i]>=last&&v[i]==0&&l<i){
			b[num] = a[i];
			v[i] = 1;
			last = a[i];
			l = i;
			dfs(last,l,num+1,end);
			b[num] = 0;
			last = 0;
			v[i] = 0;
			l = 0;
		}
	} 
}
signed main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> n;
	for(int i = 1;i <= n;i ++){
		cin >> a[i];
		vis[a[i]]++;
	}
	sort(a+1,a+n+1);
	for(int i = 3;i <= n;i ++){
		dfs(0,0,1,i);
	}
	cout << ans;
	return 0; 
}
