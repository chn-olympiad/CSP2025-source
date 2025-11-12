#include<bits/stdc++.h>

using namespace std;

int main()

{

	freopen("road.in","r",stdin);

	freopen("road.out","w",stdout);

	int n;
	int a,b,c,z,m,k;
	int g,v,h;

	cin>>n>>a>>b>>c>>z>>m>>k;
	if(a>b)
    {
        g=a-b;
    }
    else
    {
        g=b-a;
    }
    if(c>z)
    {
        v=c-z;
    }
    else
    {
        v=z-c;
    }
    if(g=v)
    {
        h=(a+g)*2-1;
    }
    else
    {
    	h=(a+g)*2+1;
	}
	
	cout<<h<<endl;

	return 0;

}


