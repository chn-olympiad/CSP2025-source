#include <bits/stdc++.h>
using namespace std;
struct node{
	long long data;
	long long want;
	long long per;
}a[300005];
bool cmp(node q,node h){
	return q.data>h.data;
}

int main(){
	ios::sync_with_stdio(0);
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	long long t;
	cin >> t;
	
	while(t--){
		long long n;
		cin >> n;
		long long len = 0;
		for(long long i = 1;i<=n;i++){
			long long q,w,e;
			cin >> q >> w >> e;
			a[++len] = {q,1,i};
			a[++len] = {w,2,i};
			a[++len] = {e,3,i};
		}
		long long ans = 0;
		sort(a+1,a+1+len,cmp);
		bool vis[100005] = {0};
		long long sum[10] = {0};
		for(long long i = 1;i<=len;i++){
			node to = a[i];
			if(vis[to.per]==0 && sum[to.want]<n/2){
				ans+=to.data;
				vis[to.per]++;
				sum[to.want]++;
			}
		}
		cout << ans << endl;
	}
	
	return 0;
}
