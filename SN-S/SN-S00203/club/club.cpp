#include<bits/stdc++.h>
using namespace std;
struct s
{
	int club[4];
	int max;
	int mincha;
}S[200000];
int cmp(s x,s y)
{
	return x.mincha>y.mincha;
}

int main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int t;
	cin>>t;
	for(int i=0;i<t;i++)
	{
		int n;
		cin>>n;
		for(int j=0;j<n;j++)
		{
			cin>>S[j].club[1]>>S[j].club[2]>>S[j].club[3];	
			if(S[j].club[1]>S[j].club[2] && S[j].club[1]>S[j].club[3]) S[j].max=1;
			if(S[j].club[2]>S[j].club[1] && S[j].club[2]>S[j].club[3]) S[j].max=2;
			if(S[j].club[3]>S[j].club[1] && S[j].club[3]>S[j].club[2]) S[j].max=3;	
			S[j].mincha=(max(max(S[j].club[1],S[j].club[2]),max(S[j].club[2],S[j].club[3]))-max(max(min(S[j].club[1],S[j].club[2]),min(S[j].club[2],S[j].club[3])),min(S[j].club[1],S[j].club[3])));
		}
		sort(S,S+n,cmp);
		long long sum=0;
		int	club[4]={0,0,0,0};
		for(int j=0;j<n;j++)
		{
			if(club[S[j].max]+1<=n/2)
			{
				sum+=S[j].club[S[j].max];
				club[S[j].max]++;
			}
			else
			{
				if(S[j].max==1)
				{
					for(int k=j;k<n;k++)
					{
						if(S[k].club[2]>S[k].club[3]) S[k].max=2;
						else S[k].max=3;
						S[k].mincha=(max(S[k].club[2],S[k].club[3])-min(S[k].club[2],S[k].club[3]));
					}
				}
				else if(S[j].max==2)
				{
					for(int k=j;k<n;k++)
					{
						if(S[k].club[1]>S[k].club[3]) S[k].max=1;
						else S[k].max=3;
						S[k].mincha=(max(S[k].club[1],S[k].club[3])-min(S[k].club[1],S[k].club[3]));
					}
				}
				else if(S[j].max==3)
				{
					for(int k=j;k<n;k++)
					{
						if(S[k].club[1]>S[k].club[2]) S[k].max=1;
						else S[k].max=2;
						S[k].mincha=(max(S[k].club[2],S[k].club[1])-min(S[k].club[2],S[k].club[1]));
					}
				}
				sort(S+j,S+n,cmp);
				j--;
			}	
		}
		cout<<sum<<endl; 
	}
	fclose(stdin);
	fclose(stdout);	
	return 0;	
} 
