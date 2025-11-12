#include<bits/stdc++.h>
using namespace std;
int cnt[10],len;
char c[1000005],ch;
int main()
{
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	ch=getchar();
	while(!(ch>='0'&&ch<='9'||ch>='a'&&ch<='z'))ch=getchar();
	while(ch>='0'&&ch<='9'||ch>='a'&&ch<='z')c[len++]=ch,ch=getchar();
	for(int i=0;c[i];i++)if(isdigit(c[i]))cnt[c[i]-'0']++;
	for(int i=9;i>=0;i--)for(int j=1;j<=cnt[i];j++)printf("%d",i);
	return 0;
}
