#include<bits/stdc++.h>
using namespace std;
char a[1000005],b[1000005];
long long int i,j,t,k;
int main()
{
	freopen("number.in"."r",stdin);
	freopen("number.out"."w",stdout);
	cin>>a;
	t=strlen(a);
	for(i=0;i<t;i++)
	{
		if(a[i]>='0'&&a[i]<='9')
		b[k++]=a[i];
	}
	sort(b,b+k,greater<char>());
	cout<<b;
	return 0; 
}
