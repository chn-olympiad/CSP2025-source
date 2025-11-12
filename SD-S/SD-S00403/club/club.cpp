#include<bits/stdc++.h>
using namespace std;
int main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int a,b;
	cin>>a;
	for(b=0;b<a;b++)
	{
		int c,d,e[100000][5]={0},f[5]={0},g,h=0,i,j,k,l,aa,bb,x,y,z;
		cin>>c;
		for(d=0;d<c;d++)
		{
			cin>>e[d][1]>>e[d][2]>>e[d][3];
			if(e[d][1]>=e[d][2]&&e[d][1]>=e[d][3]) e[d][4]=1;
			if(e[d][2]>=e[d][1]&&e[d][2]>=e[d][3]) e[d][4]=2;
			if(e[d][3]>=e[d][2]&&e[d][3]>=e[d][1]) e[d][4]=3;
			f[e[d][4]]++;
			h+=e[d][e[d][4]];
		}
		for(d=1;d<=3;d++) 
		    if(f[d]>c/2)
		       for(;f[d]>c/2;f[d]--)
		       {
		       	    i=-100000;
		       	    for(j=0;j<c;j++)
		       	    	if(e[j][4]==d)
		       	    	{
		       	    	    k=e[j][d%3+1]-e[j][d];
		       	    	    l=e[j][(d+1)%3+1]-e[j][d];
		       	    	    aa=f[d%3+1]>=c/2;
		       	    	    bb=f[(d+1)%3+1]>=c/2;
		       	    	    k=k*(100000*aa+1);
		       	    	    l=l*(100000*bb+1);
		       	    	    if(max(k,l)>i)
		       	    	    {
		       	    	    	i=max(k,l);
		       	    	    	x=j;
		       	    	    	if(k=max(k,l)) y=d%3+1;
		       	    	    	else y=(d+1)%3+1;
							}
						}
					h+=i;
                    e[x][4]=y;
                    f[y]++;
			   }
		cout<<h<<endl;
	}
	return 0;
}
