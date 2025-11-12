#include<bits/stdc++.h>
using namespace std;
int v[500005],n,m,h[500005],e;
struct node{
	int x,y;
};
int cmp(node s,node v)
{
	if(s.x!=v.x)
		return s.x<v.x;
	else
	    return s.y<v.y;
}
node o[1000000];
int main()
{
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
    cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		cin>>v[i];
		h[i]=h[i-1]^v[i];
	}
	int ans=0;
	for(int i=1;i<n;i++)
	{
		for(int j=i+1;j<=n;j++)
		{
			if((h[j]^h[i-1])==m)
			{
				o[e].x=i,o[e].y=j;
				e++;
			}
		}
	}
	for(int i=1;i<n;i++)
	{
		if(v[i]==m)
			o[e].x=i,o[e].y=i,e++;
	}
	sort(o,o+e,cmp);
	int t=-1,amin=1e9,l=0; 
	for(int i=0;i<e;i++)
	{
		amin=1e9;
		for(int j=l;j<e;j++)
		{
			if(o[j].x>t&&o[j].y<amin)
				amin=o[j].y,l=j+1;
		}
		if(amin!=1e9)
			t=amin,ans++;
		else
		    break;
	}
	cout<<ans;
}
