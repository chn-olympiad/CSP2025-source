#include<bits/stdc++.h>
using namespace std;
char s[1000010];
int a[1000010],x,l;
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	l=strlen(s);
	for(int i=0;i<l;i++){
		if(s[i]>='0' and s[i]<='9') a[++x]=s[i]-'0';
	}
	sort(a+1,a+1+x);
	for(int i=x;i>=1;i--) cout<<a[i];
	return 0;
} 
