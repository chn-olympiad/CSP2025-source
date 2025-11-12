#include<bits/stdc++.h>
using namespace std;
bool cmp(char a,char b)
{
	return a>b;
}
char a[1000001];
char b[1000001];
int main()
{
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>a;
	int j=0;
	for(int i=0;i<=strlen(a);i++)
	{
		if(a[i]>='0'&&a[i]<='9')
		{
			b[j]=a[i];
			j++;
		}
	}
	sort(b,b+j,cmp);
	cout<<b;
	return 0;
	fclose(stdin);
	fclose(stdout);
} 
