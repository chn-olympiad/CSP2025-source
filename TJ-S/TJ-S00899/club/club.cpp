#include<bits/stdc++.h>
using namespace std;
struct peo
{
	int one;
	int tow;
	int three;
}a[100050];
bool mysort11(peo a,peo b)
{
	return a.tow>b.tow;
}
bool mysort(peo a,peo b)
{
	return a.three>b.three;
}
int main()
{
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin>>t;
    while(t--)
    {
	
    int n;
    cin>>n;
    if(n==4)
    {
    	int a,b,c,maxx,d;
    	int a2,b2,c2,maxx2=-10,d2;
    	int a3,b3,c3,maxx3=-1,d3;
    	int a4,b4,c4,maxx4=-10,d4;
    	cin>>a>>b>>c>>a2>>b2>>c2>>a3>>b3>>c3>>a4>>b4>>c4;
    	if(a>maxx)
    	{
    		d=a;
    		maxx=1;
		}
		if(b>maxx)
    	{
    		d=b;
    		maxx=2;
		}
		if(c>maxx)
    	{
    		d=c;
    		maxx=3;
		}
		
		if(a2>maxx2)
    	{
    		d2=a2;
    		maxx2=1;
		}
		if(b2>maxx2)
    	{
    		d2=b2;
    		maxx2=2;
		}
		if(c2>maxx2)
    	{
    		d2=c2;
    		maxx2=3;
		}
		
		if(a3>maxx3)
    	{
    		d3=a3;
    		maxx3=1;
		}
		if(b3>maxx3)
    	{
    		d3=b3;
    		maxx3=2;
		}
		if(c3>maxx3)
    	{
    		d3=c3;
    		maxx3=3;
		}
		
		if(a4>maxx4)
    	{
    		d4=a4;
    		maxx4=1;
		}
		if(b4>maxx4)
    	{
    		d4=b4;
    		maxx4=2;
		}
		if(c4>maxx4)
    	{
    		d4=c4;
    		maxx4=3;
		}
		int zon=(a+b+c)-d-min(a,min(b,d)),xia=min(a,min(b,d));
		int zon3=(a3+b3+c3)-d3-min(a3,min(b3,d3)),xia3=min(a3,min(b3,d3));
		int zon2=(a2+b2+c2)-d2-min(a2,min(b2,d2)),xia2=min(a2,min(b2,d2));
		int zon4=(a4+b4+c4)-d4-min(a4,min(b4,d4)),xia4=min(a4,min(b4,d4));
		if(maxx==maxx2&&maxx==maxx3&&maxx==maxx4&&maxx2==maxx3&&maxx2==maxx4&&maxx3==maxx4)cout<<max(max(d+d2+zon3+zon4,d3+d2+zon+zon4),max(d3+d4+zon+zon2,d+d4+zon3+zon2))<<endl;
		else cout<<d+d2+d3+d4;
		
	}
    else if(n==2)
	{
		int a1,a2,a3;
		int b1,b2,b3;
		cin>>a1>>a2>>a3>>b1>>b2>>b3;
		if((a1==max(a1,max(a3,a2)) && b1==max(b1,max(b3,b2))) || (a2==max(a1,max(a3,a2)) && b2==max(b1,max(b3,b2))) || (a3==max(a1,max(a3,a2)) && b3==max(b1,max(b3,b2))))
		{
			cout<<max(max(a1,max(a3,a2))+b1+b2+b3-max(b1,max(b3,b2))-min(b1,min(b3,b2)),max(b1,max(b3,b2))+a1+a2+a3-max(a1,max(a3,a2))-min(a1,min(a3,a2)));
		}
		else
		{
			cout<<max(a1,max(a3,a2))+max(b1,max(b3,b2))<<endl;;
		}
	}
	else
	{
		int x;
		bool boo=1;;
		for(int i=1;i<=n;i++)
		{
			cin>>a[i].one>>a[i].tow>>x;
			a[i].three=a[i].tow-a[i].one;
			if(a[i].one!=0)boo=0;
		}
		if(boo)
		{
			sort(a+1,a+1+n,mysort11);
			long long sum=0;
			for(int i=1;i<=n/2;i++)sum+=a[i].tow;
			cout<<sum<<endl;
		}
		else
		{
			long long sum=0;
			sort(a+1,a+1+n,mysort);
			for(int i=1;i<=n;i++)
			{
				if(i<=n/2)sum+=a[i].one;
				else sum+=a[i].tow; 
			}
			cout<<sum<<endl;
		}
	}
	}
	return 0;
}
