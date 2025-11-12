#include<bits/stdc++.h>
using namespace std;
long long n,m,cnt[5000008];
string a1[5000005],a2[5000005],a3[5000005],a4[5000005];
int main()
{
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		cin>>a1[i]>>a2[i];
	}
	
		for(int j=1;j<=m;j++)
		{
			cin>>a3[j]>>a4[j];	
			for(int i=1;i<=n;i++)
			{
				if(a1[i]==a3[j]&&a2[i]==a4[j]) cnt[j]++; 
				if(a3[i]==a4[j]&&a2[i]==a1[j]) cnt[j]++;
			}
			
		}
	for(int i=1;i<=m;i++) cout<<cnt[i]<<endl;
	return 0;
}






