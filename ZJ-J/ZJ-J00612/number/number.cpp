#include<bits/stdc++.h>
using namespace std;
long long i,l,t,a[1000010];
string s;
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;l=s.size();
	for(i=0;i<l;i++)
		if(s[i]>='0'&&s[i]<='9') a[++t]=s[i]-48;
	sort(a+1,a+1+t);
	for(i=t;i>=1;i--) cout<<a[i];
	return 0;
}

