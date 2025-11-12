#include<bits/stdc++.h>
using namespace std;
int n,q;
string a[200005],b[200005];
string x,y;
int ans;
	
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	
	cin >> n >> q;
	for(int i = 1;i <= n;i++) cin >> a[i] >> b[i];
	while(q--){
		cin >> x >> y;
		ans = 0;
		if(x.size()!=y.size()){
			cout << 0;
			continue;
		}
		for(int i = 1;i <= n;i++){
			if(x.find(a[i]) != string::npos){
				string t = "";
				bool flag = 0;
				for(int k = 0;k < x.size();k++){
					if(flag == 0 && x.substr(k,a[i].size()) == a[i]){
						flag = 1;
						t+=b[i];
						k+=a[i].size()-1;
					}
					else t+=x[k];
				}
				if(t == y){
					ans++;
				}
			}
		}
		cout << ans << endl;
	}
	return 0;
}
