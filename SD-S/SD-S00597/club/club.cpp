#include<bits/stdc++.h>
using namespace std;
struct xinxi
{
	int my[4];
	int kkk[3];//神奇空间重叠，不写会出错 
	int mobiao;
	int kkk01[3];
	int shiji;
	int kkk02[3];
	int xhdu;
	int kkk03[3];
	int tidai;
};
xinxi ppl[100005];
int t,n,shangx,ren[3],man[100005][3],cheng=0;
long long answ=0;
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	for(int q=0;q<t;q++)
	{
		answ=0;
		cin>>n;
		shangx=n/2;
		ren[1]=0;
		ren[2]=0;
		ren[3]=0;
		for(int i=0;i<100005;i++)
		{
			for(int j=1;j<=3;j++)
			{
				man[i][j]=0;
			}
		}
		for(int i=0;i<n;i++)
		{
			cin>>ppl[i].my[1]>>ppl[i].my[2]>>ppl[i].my[3];
			if(ppl[i].my[1]>=ppl[i].my[2] && ppl[i].my[1]>=ppl[i].my[3])
			{
				ppl[i].mobiao=1;
				if(ppl[i].my[2]>=ppl[i].my[3])
				{
					ppl[i].xhdu=ppl[i].my[1]-ppl[i].my[2];
					ppl[i].tidai=2;
				}
				else
				{
					ppl[i].xhdu=ppl[i].my[1]-ppl[i].my[3];
					ppl[i].tidai=3;
				}
			}
			else if(ppl[i].my[2]>=ppl[i].my[1] && ppl[i].my[2]>=ppl[i].my[3])
			{
				
				ppl[i].mobiao=2;
				if(ppl[i].my[1]>=ppl[i].my[3])
				{
					ppl[i].xhdu=ppl[i].my[2]-ppl[i].my[1];
					ppl[i].tidai=1;
				}
				else
				{
					ppl[i].xhdu=ppl[i].my[2]-ppl[i].my[3];
					ppl[i].tidai=3;
				}
				
			}
			else
			{
				ppl[i].mobiao=3;
				if(ppl[i].my[2]>=ppl[i].my[1])
				{
					ppl[i].xhdu=ppl[i].my[3]-ppl[i].my[2];
					ppl[i].tidai=2;
				}
				else
				{
					ppl[i].xhdu=ppl[i].my[3]-ppl[i].my[1];
					ppl[i].tidai=1;
				}
			}	
		}
		for(int i=0;i<n;i++)
		{
			
			if(ren[ppl[i].mobiao]<shangx)
			{
				ppl[i].shiji=ppl[i].mobiao;
				ren[ppl[i].mobiao]++;
				if(ppl[i].xhdu!=0)
				{
					man[i][ppl[i].mobiao]=ppl[i].xhdu;
				}
				else
				{
					man[i][ppl[i].mobiao]=-1;
				}
			}
			else
			{
				
				if(ppl[i].xhdu!=0)
				{
					cheng=0;
					int hh=ppl[i].xhdu,xixi=ppl[i].mobiao,yud=1000000,yd=-1;
					for(int j=0;j<n;j++)
					{
						if(man[j][xixi]!=0 && man[j][xixi]<hh && man[j][xixi]<yud)
						{
							cheng=1;
							yud=man[j][xixi];
							yd=j;
						}
					}
					
					if(!cheng)
					{
						ppl[i].shiji=ppl[i].tidai;
					}
					else
					{
						ppl[i].shiji=xixi;
						ppl[yd].shiji=ppl[yd].tidai;
						man[yd][xixi]=0;
						man[i][xixi]=hh;
					}
				}
				else
				{
					ppl[i].shiji=ppl[i].tidai;
				}
			}
		}
		for(int i=0;i<n;i++)
		{
			answ+=ppl[i].my[ppl[i].shiji];
		}
		cout<<answ<<endl;
	}
	return 0;
}

