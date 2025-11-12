#include <bits/stdc++.h>
using namespace std;
int main()
{
	
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int t,a1[10000],a2[10000],a3[10000],ax[11];
	cin>>t;
	int n[11];
	for(int i=0;i<t;i++)
	{
		int maxa=0,maxb=0,maxc=0;
		cin>>n[i];
		for(int j=0;j<n[i];j++)
		{
			cin>>a1[j]>>a2[j]>>a3[j];
			if(max(max(a1[j],a2[j]),a3[j])==a1[j])
			{
				maxa++;
			}
			else if(max(max(a1[j],a2[j]),a3[j])==a2[j])
			{
				maxb++;
			}
			else
			{
				maxc++;
			}
			
			ax[i]+=max(max(a1[j],a2[j]),a3[j]);
			
			
		}
	}
	for(int i=0;i<t;i++)
	{
		cout<<ax[i]<<"\n";
	}
	
	fclose(stdin);
	fclose(stdout);
	return 0;
} 



