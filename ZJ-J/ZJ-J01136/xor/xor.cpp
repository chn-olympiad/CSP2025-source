#include<bits/stdc++.h>
using namespace std;
const int N = 5e5 + 10;
int n,k,a[N],cnt,ans,prv;
vector<pair<int,int> > res;
bool cmp(pair<int,int> x,pair<int,int> y){
	if(x.first != y.first){
		return x.first < y.first;
	}
	return x.second < y.second;
}
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin >> n >> k;
	for(int i = 1;i <= n;i++){
		cin >> a[i];
	}
	for(int i = 1;i <= n;i++){
		for(int j = i;j <= n;j++){
			int p = 0;
			for(int c = i;c <= j;c++){
				p ^= a[c];
			}
			if(p == k){
				res.push_back({i,j});
			}
		}
	}
	sort(res.begin(),res.end(),cmp);
	for(auto it:res){
		if(prv < it.first){
			ans++;
			prv = it.second;
		}
	}
	cout << ans;
	return 0;
}