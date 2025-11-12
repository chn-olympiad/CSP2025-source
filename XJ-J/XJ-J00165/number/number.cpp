#include <bits/stdc++.h> 
using namespace std;
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	int n = 0,maxx = 0,max_i = -1;
	string s,ans; cin >> s;
	cout << s.size() << endl;
	for(int i = 0;i<s.size();i++){
		if(s[i]-'0' <= 9){
			n++;
		}
	}
	char number[n];
	for(int j = n;j>=0;j--){
		for(int g = 0;g<=s.size()-1;g++){
			if((s[g]-'0' <= 9)&&(s[g]-'0'>= maxx)&&(g!=max_i)){
				number[j] = s[g];
				maxx = max(maxx,number[j]-'0');
				max_i = g;
			}
		}
	}
	for(int l = n;l>=0;l--){
		for(int y = l;y>0;y--){
			number[l] = (char)number[l]-'0' * 10;
		}
		ans += number[l];
	}
	cout << ans;
	return 0;
}
