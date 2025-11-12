#include<bits/stdc++.h>
using namespace std;
string s;
int a[1000005],cnt;
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	for(int i=0;i<s.size();i++)
	if(isdigit(s[i]))a[++cnt]=s[i]-'0';
	sort(a+1,a+1+cnt);
	for(int i=cnt;i;i--)putchar((char)(a[i]+'0'));
	printf("\n");
	return 0;
}
