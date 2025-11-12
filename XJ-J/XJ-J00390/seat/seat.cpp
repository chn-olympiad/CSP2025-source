#include<bits/stdc++.h>
using namespace std;
int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m,f,id=0;
	cin>>n>>m;
	vector<int> g(n*m,0);
	cin>>f;
	g[0]=f;
	for(int i=1;i<n*m;i++)
	{
		cin>>g[i];
	}
	sort(g.rbegin(),g.rend());
	for(int i=0;i<n*m;i++)
	{
		if(g[i]==f)
		{
			id=i;
			break;
		}
	}
	id++;
	int z=2*n,rn=id/z;
	rn=id-z*rn;
	if(rn>n)
	{
		rn=rn%n;
		if(rn==0)
		{
			rn=1;
		}
		else
		{
			rn=n+1-rn;
		}
	}
	else
	{
		rn=rn%n;
		if(rn==0) rn=n;
	}
	int rm=id/n;
	if(id%n!=0) rm++;
	cout<<rm<<" "<<rn;
	fclose(stdin);
	fclose(stdout);
	return 0; 
}

