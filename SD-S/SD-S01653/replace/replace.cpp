#include<bits/stdc++.h>
using namespace std;
int n,q,ans,l1,r1,l2,r2,len[200009],at1[200009],bt1[200009],at2[200009],bt2[200009];
string s1[200009],s2[200009],t,j;
bool b;
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	cin.tie(0)->ios::sync_with_stdio(0);
	cin >> n >> q;
	for(int i = 1;i <= n;i++){
		cin >> s1[i] >> s2[i];
		len[i] = s1[i].size();
		for(int j = 0;j < len[i];j++){
			if(s1[i][j] == 'b'){
				at1[i] = j;
				bt1[i] = len[i] - j - 1;
				break;
			} 
		}
		for(int j = 0;j < len[i];j++){
			if(s2[i][j] == 'b'){
				at2[i] = j;
				bt2[i] = len[i] - j - 1;
				break;
			} 
		}
//		cout << at1[i] << ' ' << bt1[i] << ' ' << at2[i] << ' ' << bt2[i] << '\n';
	}
	while(q--){
		cin >> t >> j;
		int n = t.size();
		if(t.size() != j.size()){
			cout << "0\n";
			continue;
		}
		for(int i = 0;i < n;i++){
			if(t[i] == 'b'){
				l1 = i,r1 = n - i - 1;
			} 
		}
		for(int i = 0;i < n;i++){
			if(j[i] == 'b'){
				l2 = i,r2 = n - i - 1;
			} 
		}
		for(int i = 1;i <= n;i++){
			if(bt1[i] + r2 == bt2[i] + r1 && l1 >= at1[i] && r1 >= bt1[i]){
				ans++;
			}
		}
		cout << ans << '\n';
		ans = 0;
	}
	return 0;
}
