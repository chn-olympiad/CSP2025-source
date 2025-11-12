#include<bits/stdc++.h>
using namespace std;
const unsigned long long SELF = -1;
int n,k;
int a[500005],qian[500005];
pair<int,int> nxt[500005];
bool cmp(pair<int,int> a,pair<int,int> b) {
	return (a.second - a.first) < (b.second - b.first);
}
vector<pair<int,int> > vpii;
bool check(int ind){
	for(int i =0;i<vpii.size();i++){
		if(!(nxt[ind].second < vpii[i].first or nxt[ind].first > vpii[i].second)){
			return 0;
		}
	}
	return 1;
}
signed main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin >> n >> k;
	for(int i =1;i<=n;i++){
		cin >> a[i];
	}
	qian[0] = SELF;
	for(int i =1;i<=n;i++){
		qian[i] = qian[i-1] ^ a[i];
	}
	int l = n,indd = 0;
	for(int i =0;i<n;i++){
//		cout << i << " "<< ans << endl;
		int cur = i + 1,sv = i;
		while(cur <= n){
			if(k == (qian[cur]^qian[i]) ){
				break;
			}
			cur++;
		}
		if(cur == n + 1){
			continue;
		}
		nxt[indd++] = {sv + 1,cur};
//		cout << sv << " " << cur << endl; 
	}
	
	sort(nxt,nxt + indd,cmp); 
	int ans = 0;
	for(int i =0;i<indd;i++){
//		cout << nxt[i].first << " " << nxt[i].second << " " << check(i) << endl;
		if(check(i)){
			vpii.push_back(nxt[i]);
			ans++;
		}
	}
	cout << ans;
	return 0;
}
