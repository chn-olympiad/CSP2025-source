#include <bits/stdc++.h>
using namespace std;
#define int long long
#define LYT ios::sync_with_stdio(0),cin.tie(0)
#define N 5000010
int p[N],vis[N];
int findd(int x){
	return x == p[x] ? x : p[x] == findd(p[x]);
}
signed main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	int n,q;
	cin >> n >> q;
	for(int i =1;i <= n;i++) p[i] = i;
	for(int t = 1;t <= n;t++){
		string s,s1;
		cin >> s >> s1;
		int u = 0,v = 0;
		for(int i = 0;i < s.size();i++){
			if(s[i] == 'b'){
				u = i;
				break;
			}
		}
		for(int i = 0;i < s1.size();i++){
			if(s1[i] == 'b'){
				v = i;
				break;
			}
		}
		if(findd(u)!=findd(v)){
			p[findd(u)] = findd(v);
			vis[findd(v)] = 1;
		}
		else{
			vis[findd(v)]++;
		}
	}
	while(q--){
		string s,s1;
		cin >> s >> s1;
		int u = 0,v = 0;
		for(int i = 0;i < s.size();i++){
			if(s[i] == 'b'){
				u = i;
				break;
			}
		}
		for(int i = 0;i < s1.size();i++){
			if(s1[i] == 'b'){
				v = i;
				break;
			}
		}
		if(findd(u) == findd(v)){
			cout << vis[findd(v)] << "\n";
		}else{
			cout << 0 << "\n";
		}
	}
	return 0;
}
