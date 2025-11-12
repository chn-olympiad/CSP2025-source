#include<bits/stdc++.h>
using namespace std;
int l,i,t,a[1000010];char s[1000010];
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;l=strlen(s);
	for(i=0;i<l;i++)
		if(s[i]>='0'&&s[i]<='9')a[++t]=s[i]-48;
	sort(a+1,a+1+t);
	if(a[t]==0)cout<<0;
	else for(i=t;i>=1;i--)cout<<a[i];
	return 0;
}