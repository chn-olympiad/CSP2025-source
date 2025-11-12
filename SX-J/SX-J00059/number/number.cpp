#include<bits/stdc++.h>
using namespace std;
#define int long long
#define endl '\n'
int cmp(int x,int y)
{
	if(x<=y) return x>y;
}
signed main()
{
	freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    string s;
	cin>>s;
    int n=s.size(),sum=0;
    vector<int> a;
    for(int i=0;i<n;i++)
	{
		if(s[i]>='0'&&s[i]<='9')
		{
			a.push_back((int)s[i]-48);
			sum++;
		}
	}
	sort(a.begin(),a.end(),cmp);
	for(int i=0;i<sum;i++)
	{
		cout<<a[i];
	}
	return 0;
}
