#include <bits/stdc++.h>
using namespace std;
int a[1000005];
bool cmp(int a,int b)
{
	return a>b;
}
int main()
{
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	string n;
	cin>>n;
	int cnt=0;
	for(int i=0;i<=n.size()-1;i++)
	{
		if('0'<=n[i]&&n[i]<='9')
		{
			a[cnt]=n[i]-48;
			cnt++;
		}
	}
	sort(a,a+cnt,cmp);
	for(int i=0;i<=cnt-1;i++)	cout<<a[i];
	fclose(stdin);
	fclose(stdout);
	return 0;
}