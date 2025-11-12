//王苗亦 SN-S00521 西安市曲江第一学校 
#include<bits/stdc++.h>
using namespace std;
const int N=1E5+10;
int main()
{
	//freopen("club.in","r",stdin);
	//freopen("club.out","w",stdout);
	int n;
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		int rs;
		int zh=0;
		int a[N],b[N],c[N],pg[N];
		cin>>rs;
		for(int i=0;i<rs;rs++)
		{
			cin>>a[i]>>b[i]>>c[i];
			a[i]=a[i]*10+i;
			b[i]=b[i]*10+i;
			c[i]=c[i]*10+i;
		} 
		sort(a,a+rs);
		sort(b,b+rs);
		sort(c,c+rs);
		for(int i=0;i<rs;rs++)
		{
			zh+=a[i]/10;
		    pg[a[i]%10]=a[i]/10;
		}	
		for(int i=0;i<rs;rs++)
		{
			if(pg[b[i]%10]<b[i]/10)
			{
				zh=zh-pg[b[i]%10]+b[i]/10;
				pg[b[i]%10]=b[i]/10;
			}
		}		
		for(int i=0;i<rs;rs++)
		{
			if(pg[c[i]%10]<c[i]/10)
			{
				zh=zh-pg[c[i]%10]+c[i]/10;
				pg[c[i]%10]=c[i]/10;
			}
		}
		cout<<zh<<endl;				
	}
	return 0;
}
