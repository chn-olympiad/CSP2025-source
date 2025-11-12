#include <iostream>
#include <string>
using namespace std;
const int N = 200005;

int n, q;
string sa[N], sb[N];
int main(){
	freopen("replace.in", "r", stdin);
	freopen("replace.out", "w", stdout);
	cin>>n>>q;
	for(int i=1; i<=n; i++){
		cin>>sa[i]>>sb[i];
	}
	string a, b;
	for(int i=1; i<=q; i++){
		cin>>a>>b;
		int ans=0;
		for(int j=1; j<=n; j++){
			if(a.size()<sa[j].size())continue;
			int pos=-1;
			while((pos=a.find(sa[j], pos+1)) != string::npos){
				string ne = a.substr(0, pos) + sb[j] + a.substr(pos+sa[j].size(), a.size()-1);
				if(ne==b)ans++;
			}
		}
		cout << ans << endl;
	}
	return 0;
}
