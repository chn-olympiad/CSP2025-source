#include<bits/stdc++.h>
using namespace std;
vector<int> l;

int he(int le,int r)
{
	if(le == r)
	{
		return l[le];
	}
	int ans = l[le];
	for(int i = le+1;i<=r;i++)
	{
	//	cout<<l[i]<<"^"<<ans<<"=";
		ans = ans ^ l[i];
	//	cout<<ans<<endl;
	}
	return ans;
}
int main()
{
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	
	int anss = 0;
	long long n,k;
	cin>>n>>k;
	l.push_back(-1);
	for(int i = 1;i<=n;i++)
	{
		int a;
		cin>>a;
		l.push_back(a);
	}
	int i = 1;
//	int a = 1,b = 2;
//	int c = a^b;
//	cout<<c;
	for(;i<=n;i++)
	{
		for(int j = i;j<=n;j++)
		{
		//	cout<<i<<" "<<j<<endl;
			if(he(i,j) == k)
			{
				anss++;
				i = j;
				break;
			}
		}
	}
	cout<<anss;
	
	return 0;
}
