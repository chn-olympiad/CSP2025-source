#include<bits/stdc++.h>
using namespace std;
long long n,a,b,c,x,f;
string s,m;
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	for(int i=0;i<s.size();i++){
		if(s[i]>='0'&&s[i]<='9'){
			m+=s[i];
		}
	}
	sort(m.begin(),m.end());
	reverse(m.begin(),m.end());
	cout<<m;
	return 0;
} 
