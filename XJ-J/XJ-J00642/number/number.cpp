#include<bits/stdc++.h>
using namespace std;
bool cmp(int x,int y)
{
	return x>y;
} 
int main()
{
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	string nu;
	cin>>nu;
	int a[100050],j=1;
	for(int i=0;i<nu.length();i++)
	{
		if(nu[i]>='0'&&nu[i]<='9')
		{
			a[j]=nu[i]-'0';
			j++;
		}
	}
	sort(a+1,a+j+1,cmp);
	for(int i=1;i<=j-1;i++)cout<<a[i];
	return 0;
}
