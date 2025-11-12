#include<bits/stdc++.h>
using namespace std;
long long int n,k,a[500005],ans;
vector<long long int>vec;
inline void cLean()
{
	while(vec.size()>0)
	    vec.pop_back();
	return ;
}
int main()
{
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
		vec.push_back(0);
		for(int j=0;j<vec.size();j++)
		{
			vec[j]^=a[i];
			if(vec[j]==k)
			{
				ans++;
				cLean();
				break;
			}
		}
	}
	cout<<ans<<"\n";
	return 0;
}