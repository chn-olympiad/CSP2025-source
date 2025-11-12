#include <iostream>
#include <algorithm>
using namespace std;
struct mb
{
	int a;
	bool *flagg;
	mb *nt;
};
int t,n,happiness;
mb b[100001];
int n11,n22,n33;
bool cmpp(mb c,mb b);
int main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	for(int i=1;i<=t;i++)
	{
		happiness=0;
		n11=0,n22=0,n33=0;
		cin>>n;
		for(int j=1;j<=n;j++)
		{
			cin>>b[j].a;
			b[j].nt=new mb;
			b[j].nt->nt=new mb;
			bool *tt=new bool;
			*tt=0;
			cin>>b[j].nt->a>>b[j].nt->nt->a;
			b[j].flagg=tt;
			b[j].nt->flagg=tt;
			b[j].nt->nt->flagg=tt;
		}
		for(int j=1;j<=n;j++)
		{
			mb q=b[j];
			if(*(q.flagg))continue;
			*(q.flagg)=1;
			int mxx=max(n11<=n/2?q.a:0,max(n22<=n/2?q.nt->a:0,n33<=n/2?q.nt->nt->a:0));
			if(mxx==q.a)n11++;
			if(mxx==q.nt->a)n22++;
			if(mxx==q.nt->nt->a)n33++;
			happiness+=mxx;
		}
		cout<<happiness<<endl;
	}
	return 0;
}
bool cmpp(mb c,mb b)
{
	return c.a>b.a;
}
