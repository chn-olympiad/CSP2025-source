#include <bits/stdc++.h>
using namespace std;
//100+100+30+40 270? maybe 1= in SN
//T4 is easier than T3,why? 
//oh no choice can be no-linked
//s[5005] couldn't be used, so it died.
//                  ___
//                _|  |_
//               |_    _|
//          _______|  |_______
//         |    s[5005]      |
//       _|                  |_
//     _|      qianzhuihe     |_
//    |           R.I.P        |
//40 score, polygon3.in can run
const int md= 998244353;
int a[5005];
int n,ans=0;
void dfs(int cur,int maxa,int sum,int times) {
//fucking with O(n!) dfs
	if(times>=3&&maxa*2<sum) {
		ans++;
		ans%=md;
	}
	if(cur==n)return ;
	for(int i=cur+1;i<=n;i++) {
		dfs(i,max(a[i],maxa),sum+a[i],times+1);
	}
} 
int main() {
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	scanf("%d",&n);
	for(int i=1;i<=n;i++) {
		scanf("%d",&a[i]);
	} 
	for(int i=1;i<=n-2;i++) {
		dfs(i,a[i],a[i],1);
	}
	printf("%d",ans);
	return 0;
} 
 
