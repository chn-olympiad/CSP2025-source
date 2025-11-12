#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("employ.in", "r", stdin);
	freopen("employ.out", "w", stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int n, m;
	cin >> n >> m;
	string s;
	cin >> s;
	s=" " + s;
	vector<int>c(n+1),p(n+1);
	for(int i=1; i<=n; ++i){
		cin >> c[i];
		p[i]=i;
	}
	int ans=0;
	do{
		int past=0;
		for(int i=1; i<=n; ++i){
			if(s[i] == '0'){past++;continue;}
			if(past >= c[p[i]]){past++;continue;}
		}
		if(n-past>=m){
			ans++;
		}
	}while(next_permutation(p.begin()+1,p.end()));
	cout << ans;
	return 0;
}
/*
This may be my last csp-s,so please let me have a good grade
I can't promise whether i can still be an oier.
*/