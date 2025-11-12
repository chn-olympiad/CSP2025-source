#include<bits/stdc++.h>
using namespace std;
const int N = 2e5 + 12;
int n,q;
string s1[N],s2[N];
string sp,sq;
int ans,k;
int main()
{
	cin>>n>>q;
	for(int i = 1;i <= n;i++)
	{
		cin>>s1[i]>>s2[i];
	}
	cin>>sp>>sq;
	string sl = sp,sr = sq;
	for(int i = 1;i <= n;i++)
	{
		sq = sr;
		sp = sl;
		string skp,skq;
		skp = s1[i];
		skq = s2[i];
		k = sp.find(skp);
		for(int j = k;j < skp.size();j++)
		{
			sp[j] = skq[j];
		}
		cout<<sq<<" "<<sp<<endl;
		if(sq == sp)
			ans++;
	}
	cout<<ans;
	return 0;
}
