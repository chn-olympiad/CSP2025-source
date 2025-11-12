#include<bits/stdc++.h>
using namespace std;
string s,r;
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
    cin>>s;
    r="";
    for(int i=0;i<s.size();i++){
    	if(s[i]>='0'&&s[i]<='9') r+=s[i];
	}
	sort(r.begin(),r.end());
	reverse(r.begin(),r.end());
	cout<<r;
	return 0;
}
