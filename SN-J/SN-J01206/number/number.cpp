//SN-J01206 黄梓沫 西安市曲江第一中学 
#include<bits/stdc++.h>
using namespace std;
int count[100005];
int main(){

	freopen("number.in","r",stdin)
	freopen("number.out","w",stdout)

	string s;
	cin >> s;
	for(int i=0;i <= s.size();i++){
		if((int)s[i] >= 0 && (int)s[i] <= 9){
			count += (int)s[i];
		}
	}
	count.sort();
	for(int j=0;j <= count.legth();j++){
		cout << count[j];
	}

	return 0;
}
