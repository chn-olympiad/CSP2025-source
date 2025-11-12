#include<bits/stdc++.h>
using namespace std;

string a[200010][2];

int main(){
	freopen("replace.in", "r", stdin);
	freopen("replace.out", "w", stdout);
	
	int n,q;cin>> n >> q;
	
	for(int i=1;i <=n; i++) cin >> a[i][0] >> a[i][1];
	while(q--){
		int cnt=0;
		string org, aft;
		cin >> org >> aft;
		for(int i = 1;i <=n; i++){
			string orgi = org;
			string aftr = aft;
			if(orgi.find(a[i][0])!=string::npos&&orgi.replace(orgi.find(a[i][0]), a[i][0].size(), a[i][1])==aftr) {
				cnt++;
			}
		}
		
		cout << cnt << '\n';
	}
	
	return 0;
}
