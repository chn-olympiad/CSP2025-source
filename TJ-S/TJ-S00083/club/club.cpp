#include <bits/stdc++.h>

using namespace std;

struct person
{
	int id,val;
	person(){id=val=0;}
	person(int a,int b){id=a,val=b;}
};

int v[100005][3],swi[100005];
vector<person> want[3];

int main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	
	int t;
	cin>>t;
	
	while(t--)
	{
		want[0].clear(),want[1].clear(),want[2].clear();
		
		int n;
		cin>>n;
	
		for(int i=0;i<n;i++)
			cin>>v[i][0]>>v[i][1]>>v[i][2];
		
		long long ans=0;
		for(int i=0;i<n;i++)
		{
			if(v[i][0]>=v[i][1]&&v[i][0]>=v[i][2])
				want[0].push_back(person(i,v[i][0])),ans+=1ll*v[i][0];
			else if(v[i][1]>=v[i][0]&&v[i][1]>=v[i][2])
				want[1].push_back(person(i,v[i][1])),ans+=1ll*v[i][1];
			else if(v[i][2]>=v[i][0]&&v[i][2]>=v[i][1])
				want[2].push_back(person(i,v[i][2])),ans+=1ll*v[i][2];
		}
		
		int fu=-1;
		for(int i=0;i<3;i++)
			if(want[i].size()>n/2)
				fu=i;
				
		//cout<<"------  "<<fu<<endl;
		
		if(fu!=-1)
		{
			for(int i=0;i<want[fu].size();i++)
			{
				int mx=-1,id=want[fu][i].id;
				for(int j=0;j<3;j++)
					if(j!=fu&&v[id][j]>mx)
						mx=v[id][j];
				swi[i]=want[fu][i].val-mx;
			}
			sort(swi,swi+want[fu].size());
			//cout<<"---------------------     "<<want[fu].size()<<endl;
			for(int i=0;i<want[fu].size()-n/2;i++)
				ans-=swi[i];
		}
				
		cout<<ans<<endl;
	}
	
	return 0;
}

