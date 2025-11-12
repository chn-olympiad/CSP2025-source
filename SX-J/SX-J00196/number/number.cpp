#include<bits/stdc++.h>
using namespace std;

int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	int n[500000];
	string s,w="";
	cin>>s;
	for(int i=0;i<=s.size();i++){
		if(s[i]<='9'&&s[i]>='0')
			w+=s[i];
	}
	int m=0;
	for(m=0;m<=w.size();m++){
		n[m]=w[m]-'0';
	}
	m--;
	sort(n,n+m);
	for(int i=m-1;i>=0;i--)
	{
		cout<<n[i];
	}
	return 0;
}