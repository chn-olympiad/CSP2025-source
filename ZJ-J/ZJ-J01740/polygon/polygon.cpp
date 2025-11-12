#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
int n;
int a[5001],flagg[5001];
vector<int> ttp;
int cnt;
void pg(int sidee,int tm);
int main()
{
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	ttp.push_back(-1);
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	sort(a+1,a+n);
	for(int i=3;i<=n;i++)
	{
		pg(i,1);
	}
	cout<<cnt;
	return 0;
}
void pg(int sidee,int tm)
{
	if(tm>sidee)
	{
		int aaa=0,mxx=-1;
		for(int i=1;i<ttp.size();i++)
		{
			mxx=max(mxx,a[ttp[i]]);
			aaa+=a[ttp[i]];
		}
		if(aaa>mxx*2)
		{
			cnt++;
			cnt%=998*244*353;
		}
		return;
	}
	for(int i=1;i<=n;i++)
	{
		if(flagg[i]==1)continue;
		if(i<ttp[tm-1])continue;
		flagg[i]=1;
		ttp.push_back(i);
		pg(sidee,tm+1);
		ttp.pop_back();
		flagg[i]=0;
	}
	return;
}
