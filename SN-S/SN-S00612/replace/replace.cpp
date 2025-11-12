#include <bits/stdc++.h>
using namespace std;
const unsigned long long P = 131;
unsigned long long n,q;
string s1[1005],s2[1005];
unsigned long long p1[1005][2005],p2[1005][2005],p[2005];
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	cin >> n >> q;
	p[0] = 1;
	for(int i = 1;i <= 2000;i++)
		p[i] = p[i-1]*P;
	for(int i = 1;i <= n;i++){
		cin >> s1[i] >> s2[i];
		for(int j = 0;j < s1[i].size();j++)
			p1[i][j+1] = p1[i][j] * P + (int)s1[i][j];
		for(int j = 0;j < s2[i].size();j++)
			p2[i][j+1] = p2[i][j] * P + (int)s2[i][j];
	}
	while(q--){
		string x,y;
		bool flag = false;
		int ans = 0;
		cin >> x >> y;
		unsigned long long px=0,py=0;
		for(int j = 0;j < x.size();j++)
			px = px * P + x[j];
		for(int j = 0;j < y.size();j++)
			py = py * P + y[j];
		for(int i = 1;i <= n;i++){
			if(s1[i].size() < x.size())
				continue;
			for(int j = 0;j < s1[i].size()-x.size()+1;j++){
				if(p1[i][j+x.size()]-p1[i][j]*p[x.size()] == px)
					if(py == p2[i][j+x.size()]-p2[i][j]*p[x.size()]){
						flag = true;
						ans++;
					}
			}
		}
		if(flag)
			cout << ans << '\n';
		else
			cout << 0 << '\n';
	}
	return 0;
}

