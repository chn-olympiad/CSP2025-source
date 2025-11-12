#include<bits/stdc++.h>
using namespace std;
int a2[200],a1[200],b2[200],c2[200],b1[200],c1[200];
int main()
{
	int m,n;
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>m;
	for(int i=1;i<=m;i++)
	{
		cin>>n;
		int r=0,aa=0,bb=0,cc=0;
		if(n>=1000000){
			for(int j=1;j<=n;j++)
			{
				cin>>a1[i]>>b1[i]>>c2[i];
			}
			sort(a1+1,a1+n+1);
			for(int j=n;j>=n/2;j--)r+=a1[j];
			cout<<r;
			
		}
		for(int j=1;j<=n;j++)
		{
			cin>>a1[i]>>b1[i]>>c1[i];
			if(a1[i]>=b1[i]&&a1[i]>=c1[i])
			{
				if(aa<=n/2)
				{
					aa++;
					a2[aa]=a1[i];
				}else{
					sort(a2+1,a2+aa+1);
					if(a2[1]<a1[i])a2[1]=a2[i];
				}
				
			}else if(b1[i]>a1[i]&&b1[i]>=c1[i])
			{
				if(bb<=n/2)
				{
					bb++;
					b2[bb]=b1[i];
				}else{
					sort(b2+1,b2+bb+1);
					if(b2[1]<b1[i])b2[1]=b2[i];
				}
				
			}else if(c1[i]>a1[i]&&c1[i]>b1[i])
			{
				if(cc<=n/2)
				{
					cc++;
					c2[cc]=c1[i];
				}else{
					sort(c2+1,c2+cc+1);
					if(c2[1]<c1[i])c2[1]=c2[i];
				}
			}
		}
		for(int j=1;j<=aa;j++)r+=a2[j];
		for(int j=1;j<=bb;j++)r+=b2[j];
		for(int j=1;j<=cc;j++)r+=c2[j];
		cout<<r<<endl;
	}
	
	return 0;
}