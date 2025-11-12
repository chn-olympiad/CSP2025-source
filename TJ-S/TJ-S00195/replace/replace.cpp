#include <bits/stdc++.h>
using namespace std;
const int N = 5e6+10;
string s1[N];
string s2[N];
int ans = 0;
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	int n,m;
	cin >> n >> m;
	for (int i = 1; i<=n; i++){
		cin >> s1[i] >> s2[i];
	}
	while(m--){
		string x,y;
		cin >> x >> y;
		for (int i = 1; i<=n; i++){
			for (int j = 0; j<x.size(); j++){
				if (x[j]==s1[i][0] && x.size()-j>=s1[i].size()){
					bool flag = true;
					for (int k = j+1; k<s1[i].size(); k++){
						if (s1[i][k-j]!=x[k]) flag=false;
					}
					if (flag==true){
						string k1 = x,k2 = y;
						for (int k = j; k-j<s1[i].size(); k++){
							k1[k]=s2[i][k-j];
						}
						if (k1==k2) ans++;
					}
				}
			}
		}
		cout << ans << endl;
		ans=0;
	}
	return 0;
}
