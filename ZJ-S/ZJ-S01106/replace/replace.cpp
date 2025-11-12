#include<bits/stdc++.h>
using namespace std;
map<pair<int, int>, int> v;
int main(){
	freopen("replace.in", "r", stdin);
	freopen("replace.out", "w", stdout);
	
	int n, q;
	cin >> n >> q;
	for(int i=1;i<=n;i++){
		string a, b;
		cin >> a >> b;
		
		int w1 = 0, w2=0;
		for(int i=0;i < a.length();i++) if(a[i] == 'b') w1 = i;
		for(int i=0;i < b.length();i++) if(b[i] == 'b') w2 = i;
//		cout << w1-w2 << endl;
		v[{w1-w2, a.length()}]++;
	}
	while(q--){
		string a, b;
		cin >> a >> b;
		int w1 = -1, w2=-1;
		if(a.length() != b.length()) cout << 0 << endl;
		else{
			for(int i=0;i < a.length();i++) if(a[i] == 'b') w1 = i;
			for(int i=0;i < b.length();i++) if(b[i] == 'b') w2 = i;
			int s = w1-w2;
			if(w1 == -1 or w2 == -1) {
				cout << 0 << endl;
				continue;
			}
			int ans = 0;
			for(int k=1;k<=a.length();k++)
				ans += v[{s, k}];
			cout << ans << endl;
			
		}
	}
	return 0;
}