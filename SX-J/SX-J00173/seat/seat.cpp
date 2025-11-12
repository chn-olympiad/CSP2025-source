#include<bits/stdc++.h>
using namespace std;
long long a[10000001];
bool cmp(int x,int y)
{
	if(y>x)
	return x>y;
}
int main()
{
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    int n,m,i,j,s=0,c,r,w,h,r1;
    cin>>n>>m;
    for(i=1;i<=n*m;i++)
    {
    	cin>>a[i];
	}
    w=a[1];
	sort(a+1,a+n*m+1,cmp);
 for(i=1;i<=n*m;i++){
		if(a[i]==w)
		{
        h=i;
        break;
		}

	}

    if(h==n)
    c=1;
    else if(h>n){
    	if(h/n==0)
    	{
        c=n;
		}
    	else
    	{
        c=h/n+1;
		}

	}
    else if(h<n)
 	{
		c=h;
	}
	r=h/m;
	r1=h%m;
	if(h==m)
	r=m;
	else
	  if(r1==0)
      r=h/m;
      else
      {
      	if(m==2)
      	r=r%m+1;
        else
        r=r/m+1;
	  }


cout<<c<<" "<<r;
return 0;
}

