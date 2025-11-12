#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=1e2+10;
string s;
int a[N];
signed main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	for(int i=0;i<s.size();i++){
		if(s[i]>='0'&&s[i]<='9') a[s[i]-'0']++;
	}
	for(int i=9;i>=0;i--){
		if(a[i]){
			for(int j=1;j<=a[i];j++) cout<<i;
		}
	}
	cout<<'\n';
	return 0;
}