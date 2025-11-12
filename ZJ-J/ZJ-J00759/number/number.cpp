#include<bits/stdc++.h>
using namespace std;
int n,a[1000005];
string s;
int read(){
	int ret=0,f=1;char ch=getchar();
	while(!isdigit(ch)){if(ch=='-')f=-f;ch=getchar();}
	while(isdigit(ch))ret=(ret<<3)+(ret<<1)+(ch&15),ch=getchar();
	return ret*f;
}
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;n=s.length();
	for(int i=0;i<n;i++)
		if(isdigit(s[i]))a[++a[0]]=(s[i]&15);
	sort(a+1,a+1+a[0]);reverse(a+1,a+1+a[0]);
	for(int i=1;i<=a[0];i++)printf("%d",a[i]);
	return 0;
}