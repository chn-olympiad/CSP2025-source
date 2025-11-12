#include<bits/stdc++.h>
using namespace std;
int a[105],b[105];
bool cmp(int x,int y)//105*105=11000+
{
	if(x>y) return true;
	return false;
}
int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int i,j,n,m,Rseat,Rscore,o,blen=0;
	cin>>n>>m;//n行,m列 
	for(i=1;i<=n*m;i++)//m*n-105
	{
		cin>>a[i];
	}
	
	Rscore=a[1];
	sort(a+1,a+n*m+1,cmp);
	for(i=1;i<=m;i++)//m*n-105 原本复杂度只有O(n*m)的。。。 
	{
		//cout<<i<<endl<<endl;
		if(i%2==1)
		{
			for(j=(i-1)*n+1;j<=i*n;j++)
			{
				b[++blen]=a[j]; 
				//cout<<i<<" "<<j<<"1"<<endl;
			}
		}
		if(i%2==0)
		{
			for(j=i*n;j>=(i-1)*n+1;j--)
			{
				b[++blen]=a[j]; 
				//cout<<i<<" "<<j<<"2"<<endl;
			}	
		}
	}
	
	for(i=1;i<=n*m;i++)//m*n-105
	{
		if(b[i]==Rscore)
		{
			Rseat=i; break;
		}
	}
	if(Rseat%n==0)//列 
	{
		o=Rseat/n;
	} else
	{
		o=Rseat/n+1;
	}
	
	/*cout<<endl<<"o:"<<o<<" Rscore:"<<Rscore<<" Rseat:"<<Rseat<<" blen:"<<blen<<endl;
	for(i=1;i<=blen;i++)//max-105
	{
		cout<<b[i]<<" "<<a[i]<<"-";
	}
	cout<<endl;*/
	cout<<o<<" "<<Rseat-(o-1)*n;
	return 0;//<20000
}
