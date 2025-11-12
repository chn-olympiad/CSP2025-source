#include <bits/stdc++.h>
using namespace std;
string s;
int a[1000005],g;
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	for(int i=0;i<s.size();i++){
		if('0'<=s[i]&&s[i]<='9'){
			a[g]=int(s[i])-48;
			g++;
		}
	}
	sort(a,a+g,greater<int>());
	for(int i=0;i<g;i++){
		cout<<a[i];
	}
	return 0;
}

