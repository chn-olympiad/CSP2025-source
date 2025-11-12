#include<bits/stdc++.h>
using namespace std;
int l,i,cnt,a[1000010];
char s[1000010];
bool cmp(int t,int w){return t>w;}
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	cin>>s+1;
	l=strlen(s+1);
	for(i=1;i<=l;i++)
		if(isdigit(s[i]))a[++cnt]=s[i]-'0';
	sort(a+1,a+1+cnt,cmp);
	for(i=1;i<=cnt;i++)cout<<a[i];
	return 0;
}