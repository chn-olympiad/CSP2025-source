#include<bits/stdc++.h>
using namespace std;
char a[1000005];
int b[20],c[20],w,f;
int main()
{
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	while(cin>>a[++w])
	{
		if(a[w]>='0' && a[w]<='9')
		{
			b[a[w]-'0']++;
			if(b[a[w]-'0']==1)
				c[++f]=a[w]-'0';
		}
	}
	sort(c+1,c+f+1);
	for(int i=f;i>=1;i--)
	{
		for(int j=1;j<=b[c[i]];j++)
			cout<<c[i];
	}
	return 0;
}
