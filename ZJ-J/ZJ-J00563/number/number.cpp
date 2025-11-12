#include<bits/stdc++.h>
using namespace std;
#define int long long 
string s,a;
signed main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	sort(s.begin(),s.end());
	for(int i=0;i<s.size();i++){
		if(s[i]>='0'&&s[i]<='9') a+=s[i];
		else break;
	}for(int i=a.size()-1;i>=0;i--){
		cout<<a[i];
	}
	return 0;
}//#Shang4Shan3Ruo6Shui4


