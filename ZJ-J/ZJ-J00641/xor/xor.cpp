#include<bits/stdc++.h>
using namespace std;
const int N = 5e5+500;
struct Node{
	int l,r;
};
vector<Node> ways;
int a[N];
int sum[N]={0};
bool cmp(Node x,Node y){
	if(x.l==y.l){
		return x.r<y.r;
	}
	return x.l<y.l;
}
signed main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	int n,k; cin >> n >> k;
	for(int i = 1; i <= n; i++) cin >> a[i];
	for(int i = 1; i <= n; i++) sum[i]=sum[i-1]^a[i];
	for(int i = 1; i <= n; i++){
		for(int j = i; j <= n; j++){
			if(((sum[j]^sum[i-1])==k)){
//				cout << "t " << j << ' ' << i << ' ' << sum[j] << ' ' << sum[i] << ' ' << '\n';
				Node news;
				news.l=i;news.r=j;
				ways.push_back(news);
			}
		}
	}
	sort(ways.begin(),ways.end(),cmp);
//	for(int i = 0; i < ways.size(); i++){
//		cout << ways[i].l << ' ' << ways[i].r << '\n';
//	}
	int cnt=0,ans=0;
	for(int i = 0; i < ways.size(); i++){
		if(ways[i].l<=cnt) continue;
		else{
			ans++;
			cnt=ways[i].r;
		}
	}
	cout << ans;
}
