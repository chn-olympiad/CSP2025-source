#include<bits/stdc++.h>
using namespace std;
int t[10];
int main()
{
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	int l;
	char a;
	while((a=getchar())!=10)
	if(a<='9'&&a>='0')
	t[a-'0']++;
	for(int i=9;i>=0;i--)
	if(t[i])
	for(int j=0;j<t[i];j++)
	printf("%d",i);
	return 0;
}