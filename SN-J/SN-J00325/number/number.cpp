//SN-J00325 张奕晨 西安市建筑科技大学附属中学 
#include<bits/stdc++.h>
using namespace std;
int main()
{
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	string a;
	char b[1000001];
	int f=0;
	cin>>a;
	for(int i=0;i<a.size();i++)
	{
		if(a[i]>='0' && a[i]<='9')
		{
			b[f]=a[i];
			f++;
		} 
	}
	sort(b,b+f);
	for(int i=f-1;i>=0;i--)
	{
		cout<<b[i];
	}
	return 0;
}
