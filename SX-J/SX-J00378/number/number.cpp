#include<bits/stdc++.h>
using namespace std;
const int N=1e5+5;
int main()
{
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	string s;
	int a[N],sum=0;
    getline(cin,s);
    for(int i=0;i<s.size();i++)
    {
    	int temp=s[i];
    	if(temp>=48&&temp<=57)
    	{
    	a[i]=s[i]-48;
        sum++;
		}
	}
	sort(a,a+sum);
	for(int i=sum-1;i>=0;i--)
	{
		cout<<a[i];
	}
	return 0;
}