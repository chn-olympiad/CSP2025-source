#include <bits/stdc++.h>
#define int long long

using namespace std;
string dict[10000][2];
signed main(){
	cin.tie(0);cout.tie(0);ios::sync_with_stdio(false);
	freopen("replace.in","r",stdin);
	//freopen("replace.out","w",stdout);
	
	int n,q;
	cin >> n >> q;
	for(int i=0;i<n;i++)  cin >> dict[i][0] >> dict[i][1];
	string v, w;
	for(int i=0;i<q;i++){
		int cnt=0;
		cin >> v >> w;
		string v0(v);
		for(int j=0;j<n;j++){
			int p=v.find(dict[j][0]);
			int s=dict[j][0].size();
			for(int k=0;k<s;k++){
				v0[p+k]=dict[j][1][k];
			}
			cout << v << v0 << endl;
			if(v0==w)  cnt++;
		}
		cout << cnt << endl;
	}
	return 0;
}


