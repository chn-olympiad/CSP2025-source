#include <iostream>
#include <vector>
#include <string>
using namespace std;
vector<string> s1,s2;
int n,q,ans;
string replace(string x,string y,string z){
	for (int i = 1;i<=s1.size();i++){
		if (x == s1[i]) x = s2[i];
		if (y == s1[i]) y = s2[i];
		if (z == s1[i]) z = s2[i];
	}
	string res = x + y + z;
	return res;
}
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	cin >> n >> q;
	for (int i = 1;i<=n;i++){
		string a,b;
		cin >> a >> b;
		s1.push_back(a);
		s2.push_back(b);
	}
	while (q--){
		string a,b;
		cin >> a >> b;
		
		for (int i = 0;i<a.size();i++){
			for (int j = i;j<a.size();j++){
				if (replace(a.substr(0,i),a.substr(i,(j-i)),a.substr(j,(a.size()-j))) == b) ans++;
			}
		}
		cout << ans << " ";
	}
}