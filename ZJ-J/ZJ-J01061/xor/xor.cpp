#include<bits/stdc++.h>
using namespace std;
int w[500005];
int a[500005]; 
map<int, vector<int> > mp;
int main(){
	freopen("xor.in", "r", stdin);
	freopen("xor.out", "w", stdout);
	 
	int n, k;
	cin >> n >> k;
	mp[0].push_back(0);
	for(int i=1;i<=n;i++){
		cin >> a[i];
		w[i] = w[i-1] ^ a[i];
		mp[w[i]].push_back(i);
	}
	int last = 1, cnt = 0;
	int start_less = 1;
	while(last<=n){// O(n) 
		int val = w[last] ^ k;
		int s = *lower_bound(mp[val].begin(), mp[val].end(), start_less);
		if(s > last) continue;
		start_less = last+1;
		++cnt;
		++last;
	}
	cout << cnt << endl;
	return 0;
}
/*
4 2
2 1 0 3
*/
