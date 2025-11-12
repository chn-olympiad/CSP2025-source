#include<bits/stdc++.h>
using namespace std;
const int N=1e6+80;
string s;
int sz[N],m;
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	for(int i=0;i<s.size();i++){
		if(s[i]>='0'&&s[i]<='9'){
			m++;
			sz[m]=s[i]-'0';
		}
	}
	sort(sz+1,sz+m+1);
	for(int i=m;i>=1;i--) cout<<sz[i];
	return 0;
}
