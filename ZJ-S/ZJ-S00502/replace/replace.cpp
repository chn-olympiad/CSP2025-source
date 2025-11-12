#include <bits/stdc++.h>
using namespace std;
int n,q,cnt;
struct node{
	string st1,st2;
}s[200005];
string sss;
bool dy(string x,string y){
	if(x.size() != y.size()){
		return 0;
	}
	for(int i = 0;i < x.size();i++){
		if(x[i] != y[i]){
			return 0;
		}
	}
	return 1;
}
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	cin >> n >> q;
	for(int i = 1;i <= n;i++){
		cin >> s[i].st1 >> s[i].st2;
		s[i].st1 = ' ' + s[i].st1;
		s[i].st2 = ' ' + s[i].st2;
	}
	while(q--){
		string a,b;
		cin >> a >> b;
		cnt = 0;
		for(int i = 1;i <= n;i++){
			int len = s[i].st1.size() - 1;
			int lens = s[i].st2.size() - 1;
			for(int i = 0;i+len-1 < min(a.size(),b.size());i++){
				int j = i + len - 1;
				string c = sss,d = sss;
				int js = i+lens-1;
				for(int k = i;k <= j;k++){
					c += a[k];
				}
//				cout << c << " ";
				for(int k = i;k <= js;k++){
					d += b[k];
				}
//				cout << d << endl;
				if(dy(c,s[i].st1) && dy(d,s[i].st2)){
					cnt++;
				}
			}
		}
		cout << cnt << endl;
	}
	return 0;
}