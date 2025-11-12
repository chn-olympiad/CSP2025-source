#include<iostream>
using namespace std;
int t,n;
int main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	for(int i=1;i<=t;i++)
	{
		cin>>n;
		int a1[100005]={},a2[100005]={},a3[100005]={};
		int s[100005]={},sum=0;
		for(int i=1;i<=n;i++)
		{
			cin>>a1[i]>>a2[i]>>a3[i];
			sum+=max(a1[i],max(a2[i],a3[i]));
		}
		cout<<sum<<endl;
	}
	return 0;
}
