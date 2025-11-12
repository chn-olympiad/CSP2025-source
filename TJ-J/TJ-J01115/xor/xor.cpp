#include <bits/stdc++.h>
using namespace std;
int n,k;
int a[500005];
int x[500005];
int f[500005];
map<int,queue<int> > m;
int ans;
int o = 0,cur;
//priority_queue<pair<int,pair<int,int> > ,vector<pair<int,pair<int,int> > >,greater<pair<int,pair<int,int> > > > q;

int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin >> n >> k;
	for(int i = 1;i <= n;i++) cin >> a[i],x[i] = x[i-1]^a[i],m[x[i]].push(i);
	for(int i = 1;i <= n;i++){
		int j = k^x[i-1];
		if(a[i]==k) {
//			v.push_back({i,i});
			ans++;
			continue;
		}
		
		while(m[j].size() && m[j].front() < i){
			m[j].pop();
		}
		if(m[j].size()){
			int t = i;
			i = m[j].front();
			m[j].pop();
			ans++;
//			v.push_back({i,m[j].front()});
		}
	}

	cout << ans;
	return 0;
}
