#include<bits/stdc++.h>
using namespace std;
string s1[1000010];
int x=0;
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	string s;
	cin>>s;
	for(int i=0;i<s.size();i++){
		if(s[i]=='1' || s[i]=='2' || s[i]=='3' || s[i]=='4' || s[i]=='5' || s[i]=='6' || s[i]=='7' || s[i]=='8' || s[i]=='9' || s[i]=='0'){
			s1[x]=s[i];
			x++;
		}
	}
	sort(s1,s1+x);
	for(int i=x;i>=0;i--) cout<<s1[i];
	return 0;
}
