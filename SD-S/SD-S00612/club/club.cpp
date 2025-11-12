#include <bits/stdc++.h> 
#define endl '\n'
using namespace std;
long long t,n,suma,sumb,sumc,numa,numb,numc;
struct node
{
	int a,b,c,cab,cac,cbc;
}m[100005],aa[100005],bb[100005],cc[100005];
bool cmpa(node x,node y)
{
	int maxx=min(x.cab,x.cac);
	int maxy=min(y.cab,y.cac);
	return maxx<=maxy;
}
bool cmpb(node x,node y)
{
	int maxx=min(x.cab,x.cbc);
	int maxy=min(y.cab,y.cbc);
	return maxx<=maxy;
}
bool cmpc(node x,node y)
{
	int maxx=min(x.cbc,x.cac);
	int maxy=min(y.cbc,y.cac);
	return maxx<=maxy;
}
int main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin >> t;
	while(t--)
	{
		cin >> n;
		suma=0,sumb=0,sumc=0,numa=0,numb=0,numc=0;
		for(int i=1;i<=n;i++)
		{
			cin >> m[i].a >> m[i].b >> m[i].c;
			if(m[i].a>=m[i].b && m[i].a>=m[i].c)
			{
				suma+=m[i].a;
				numa++;
				aa[numa].a=m[i].a;
				aa[numa].b=m[i].b;
				aa[numa].c=m[i].c;
				aa[numa].cab=abs(m[i].a-m[i].b);
				aa[numa].cac=abs(m[i].a-m[i].c);
				aa[numa].cbc=abs(m[i].c-m[i].b);
			}
			else if(m[i].b>m[i].a && m[i].b>=m[i].c)
			{
				sumb+=m[i].b;
				numb++;
				bb[numb].a=m[i].a;
				bb[numb].b=m[i].b;
				bb[numb].c=m[i].c;
				bb[numb].cab=abs(m[i].a-m[i].b);
				bb[numb].cac=abs(m[i].a-m[i].c);
				bb[numb].cbc=abs(m[i].c-m[i].b);
			}
			else//(m[i].c>m[i].a && m[i].c>m[i].b)
			{
				sumc+=m[i].c;
				numc++;
				cc[numc].a=m[i].a;
				cc[numc].b=m[i].b;
				cc[numc].c=m[i].c;
				cc[numc].cab=abs(m[i].a-m[i].b);
				cc[numc].cac=abs(m[i].a-m[i].c);
				cc[numc].cbc=abs(m[i].c-m[i].b);
			}
		}
		//cout << suma << " " << sumb << " " << sumc << endl;
		int nn=n/2;
		if(numa>nn){
			sort(aa+1,aa+numa+1,cmpa);	
			for (int j=1;j<=numa-nn;j++)
			{
				suma-=aa[j].a;
				if(aa[j].b>=aa[j].c)
				{
					sumb+=aa[j].b;
				}
				else
				{
					sumc+=aa[j].c;
				}
			}
		}
		if(numb>nn){
			sort(bb+1,bb+numb+1,cmpb);
			for (int j=1;j<=numb-nn;j++)
			{
				sumb-=bb[j].b;
				if(bb[j].a>=bb[j].c)
				{
					suma+=bb[j].a;
				}
				else
				{
					sumc+=bb[j].c;
				}
			}
		}
		//cout << numc;
		if(numc>nn){
			sort(cc+1,cc+numc+1,cmpc);	
			for (int j=1;j<=numc-nn;j++)
			{
				sumc-=cc[j].c;
				//cout << cc[j].a << " "<<cc[j].b<<endl;
				if(cc[j].b>=cc[j].a)
				{
					sumb+=cc[j].b;
					//cout << 1111111;
				}
				else
				{
					suma+=cc[j].a;
				}
			}
		}
		//cout << suma << " " << sumb << " " << sumc << endl;
		cout << suma+sumb+sumc << endl;
		for (int i=1;i<=n;i++)
			m[i].a=0,m[i].b=0,m[i].c=0;
	}
	return 0;
}
