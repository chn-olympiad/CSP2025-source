#include<bits/stdc++.h>
using namespace std;
long long int n,i,a[1000005]={0},wow;
string s;
int main()
{
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	n=s.size();//·ÀÀ×Í¬`^v^`) 
	for(i=0;i<n;i++)
	{
		if(s[i]>='0'&&s[i]<='9')
		{
			a[wow]=s[i]-'0';
			wow++;		
		}
	}
	sort(a,a+wow);
	for(i=wow-1;i>=0;i--)
	cout<<a[i];
	return 0;
}
