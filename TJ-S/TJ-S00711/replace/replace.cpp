#include <bits/stdc++.h>
using namespace std;
int n,q,k,p,f,c,v[200001];
string s1[200001],s2[200001],t1,t2;
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> n >> q;
	for(int i = 1;i <= n;i++){
		cin >> s1[i] >> s2[i];
	}
	while(q--){
		memset(v,0,sizeof(v));
		c = 0;
		cin >> t1 >> t2;
		for(int i = 1;i <= n;i++){
			k = 0;
			for(int j = 0;j < t1.size() && k < s1[i].size();j++){
				if(t1[j] == s1[i][k]){
					p = j - k;
					k++;
				}else k = 0;
			}
			if(k >= s1[i].size() && !v[p]){
				f = 1;
				for(int j = 0;j < s2[i].size();j++){
					if(t2[j + p] != s2[i][j]){
						f = 0;
					}
				}
				if(f){
					c++;
					v[p] = 1;
				}
			}
		}
		cout << c << "\n";
	}
	return 0;
}
