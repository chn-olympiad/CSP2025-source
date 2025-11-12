#include<iostream>
#include<string>
using namespace std;
string s[200005][2];
int s2[200005][2];
string t1,t2;
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	int n, q, ans, bt1, bt2;
	cin >> n >> q;
	for(int i=1;i<=n;i++){
		cin >> s[i][0] >> s[i][1];
		for(int j=0;j<s[i][0].size();j++){
			if(s[i][0][j]=='b'){
				s2[i][0] = j;
			}
			if(s[i][1][j]=='b'){
				s2[i][1] = j;
			}
		}
	}
	for(int i=1;i<=q;i++){
		cin >> t1 >> t2;
		ans = 0;
		if(t1.size() != t2.size()){
			cout << 0 << endl;
			continue;
		}
		for(int j=0;j<t1.size();j++){
			if(t1[j]=='b'){
				bt1 = j;
			}
			if(t2[j]=='b'){
				bt2 = j;
			}
		}
		for(int j=1;j<=n;j++){
			if(bt2-bt1 == s2[j][1]-s2[j][0] && bt1 >= s2[j][0] && t1.size()-bt1 >= s[j][0].size()-s2[j][0]){
				ans++;
			}
		}
		cout << ans << endl;
	}
	return 0;
}
