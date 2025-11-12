#include <bits/stdc++.h>
using namespace std;
int n,k,a[500005],sum[500005],cnt;
struct node{
	int l,r;
};
vector <node> v;
bool cmp(node x,node y){
	if(x.r == y.r){
		return x.l > y.l;
	}else{
		return x.r < y.r;
	}
}
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin >> n >> k;
	for(int i = 1;i <= n;i++){
		cin >> a[i];
		sum[i] = sum[i - 1] ^ a[i];
	}
	for(int i = 1;i <= n;i++){
		for(int j = i;j <= n;j++){
			if((sum[j] ^ sum[i-1]) == k){
//				cout << i << " " << j << " " << sum[j] << " " << sum[i-1] << endl;
				v.push_back({i,j});
			}
		}
	}
	sort(v.begin(),v.end(),cmp);
	int left = 0,right = 0;
	for(auto [l,r]:v){
		if(right < l){
			cnt ++ ;
			left = l;
			right = r;
		}
	}
	cout << cnt;
	return 0;
}