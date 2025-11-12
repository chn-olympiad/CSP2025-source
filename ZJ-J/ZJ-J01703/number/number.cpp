#include<bits/stdc++.h>
using namespace std;
const int N=310;
string stra;
int f[N],len;
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>stra;
	len=stra.size();
	for(int i=0;i<len;i++)
	{
		if(stra[i]>='0'&&stra[i]<='9')
		{
			f[stra[i]-'0']++;
		}
	}
	for(int i=9;i>=0;i--)
	{
		for(int j=1;j<=f[i];j++)
		{
			cout<<i;
		}
	}
	return 0;
}
