#include<bits/stdc++.h>
using namespace std;
#define int long long
string s;
int len;
vector<char> v;
signed main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	len=s.size();
	for(int i=0;i<len;i++){
		if(s[i]>='0'&&s[i]<='9'){
			v.push_back(s[i]);
		}
	}
	sort(v.begin(),v.end());
	int len2=v.size();
	for(int i=len2-1;i>=0;i--){
		cout<<v[i];
	}
	return 0;
}
