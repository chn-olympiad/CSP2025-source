#include<bits/stdc++.h>
using namespace std;
int main()
{
	freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    int a[11][11],n,m,i,c=0,r=0,s[101],x,y=0;
    cin>>n>>m;
    for(i=0;i<n*m;i++)
        cin>>s[i];
    x=s[0];
    for(i=1;i<n*m;i++)
    	if(s[i]>x)
    	    y++;
    y++;
    for(i=0;i<y;i++)
    {
        if(c<n&&r<m)
        {
        	if(r%2==0)
                c++;
            else c--;
	    }
	    else if(c==n&&r<m)
        	r++;
        else if(c<n&&r==m)
        {
        	if(r%2==0)
                c++;
            else c--;
	    }
	    else if(c==n&&r==m)
        {
        	cout<<m<<n;
        	return 0;
	    }
    }
    cout<<r+1<<" "<<c;
    return 0;
}