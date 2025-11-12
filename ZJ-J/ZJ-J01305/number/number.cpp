#include<bits/stdc++.h>
using namespace std;
const int N=1e6+10;
unsigned long long numbers[N],n,maxn=0,nn;
bool cmp(unsigned long long a,unsigned long long b)
{
	return a>b;
}
int main()
{
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	string s;
	cin>>s;
	n=s.length();
	//cout<<int('0');
	int idx=1;
	for(int i=0;i<n;i++)
	{
		if(s[i]>='0'&&s[i]<='9')
		{
			numbers[idx]=int(s[i])-48;
			idx++;
		}
	}
	nn=idx-1;
	sort(numbers+1,numbers+nn+1,cmp);
	for(int i=1;i<=nn;i++)
	{
		cout<<numbers[i];
	}
	return 0;
}
