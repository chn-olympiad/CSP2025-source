#include<bits/stdc++.h>
using namespace std;
struct club
{
	int o,t,h; //每位学生对不同部门的满意度 
};
int main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int t;
	cin>>t;
	for(int k=0;k<t;k++)
	{
		int n;
		cin>>n;
		club st[100005];
		int a[50002],b[50002],c[50002];  //存放部门满意度最高的学生的编号
		int na=0,nb=0,nc=0;  //部门学生数量 
		int ma=0,mb=0,mc=0;  //部门满意度 
		int ans;  //答案 
		for(int i=0;i<n;i++)
		{
			cin>>st[i].o>>st[i].t>>st[i].h;
			if(max(max(st[i].o,st[i].t),st[i].h)==st[i].o)
			{
				a[na]=i;
				na++;
				ma+=st[i].o;
			}
			if(max(max(st[i].o,st[i].t),st[i].h)==st[i].t)
			{
				b[nb]=i;
				nb++;
				mb+=st[i].t;
			}
			if(max(max(st[i].o,st[i].t),st[i].h)==st[i].h)
			{
				c[nc]=i;
				nc++;
				mc+=st[i].h;
			}
		}
		int y;  //部门中多余的学生 
		int mu=n/2;  //部门最多学生数量
		ans=ma+mb+mc;
		if(na<=mu && nb<=mu && nc<=mu)
		{
			cout<<ans<<endl;
			continue;
		}
		int az=0,bz=0,cz=0;  //判断1，2，3组是否满员，满员为1，否则为0
		if(na>mu) az=1;
		if(nb>mu) bz=1;
		if(nc>mu) cz=1;
		if(na>mu)
		{
			y=na-mu;
			for(int j=0;j<y;j++)
			{
				int mi=st[a[0]].o;  //部门中最小的满意度 
				int lbmi=st[a[0]].o-st[a[0]].t,lcmi=st[a[0]].o-st[a[0]].h;  //本部门学生与2部门和3部门差值最小的部门的满意度 
				int xua=0,xub=0,xuc=0;  //记录上面三个满意度的学生编号 
				for(int p=1;p<na;p++)
				{
					if(st[a[p]].o<mi)
					{
						mi=st[a[p]].o;
						xua=p;
					}
					if(st[a[p]].o-st[a[p]].t<lbmi)
					{
						lbmi=st[a[p]].o-st[a[p]].t;
						xub=p;
					}
					if(st[a[p]].o-st[a[p]].h<lcmi)
					{
						lcmi=st[a[p]].o-st[a[p]].h;
						xuc=p;
					}
				}
				int linans,jia;
				if(st[a[xua]].h>st[a[xua]].t && cz!=1)
				{
					linans=ans-mi+st[a[xua]].h;
					jia=3;
				}
				else
				{
					linans=ans-mi+st[a[xua]].t;
					jia=2;
				}
				if(linans<ans-st[a[xub]].o+st[a[xub]].t && bz!=1)
				{
					linans=ans-st[a[xub]].o+st[a[xub]].t;
					jia=2;
				}
				if(linans<ans-st[a[xuc]].o+st[a[xuc]].h && cz!=1)
				{
					linans=ans-st[a[xuc]].o+st[a[xuc]].h;
					jia=3;
				}
				ans=linans;
				na--;
				if(jia==2)
				{
					nb++;
					b[nb]=a[xub];
					a[xub]=0;
				}
				if(jia==3)
				{
					nc++;
					c[nc]=a[xuc];
					a[xuc]=0;
				}
			}
		}
		
		
		if(nb>mu)
		{
			y=nb-mu;
			for(int j=0;j<y;j++)
			{
				int mi=st[b[0]].t;  //部门中最小的满意度 
				int lami=st[b[0]].t-st[b[0]].o,lcmi=st[b[0]].t-st[b[0]].h;  //本部门学生与1部门和3部门差值最小的部门的满意度 
				int xua=0,xub=0,xuc=0;  //记录上面三个满意度的学生编号 
				for(int p=1;p<nb;p++)
				{
					if(st[b[p]].t<mi)
					{
						mi=st[b[p]].t;
						xub=p;
					}
					if(st[b[p]].t-st[b[p]].o<lami)
					{
						lami=st[b[p]].t-st[b[p]].o;
						xua=p;
					}
					if(st[b[p]].t-st[b[p]].h<lcmi)
					{
						lcmi=st[b[p]].t-st[b[p]].h;
						xuc=p;
					}
				}
				int linans,jia;
				if(st[b[xub]].h>st[b[xub]].o && cz!=1)
				{
					linans=ans-mi+st[b[xub]].h;
					jia=3;
				}
				else
				{
					linans=ans-mi+st[b[xub]].o;
					jia=1;
				}
				if(linans<ans-st[b[xua]].t+st[b[xua]].o && az!=1)
				{
					linans=ans-st[b[xua]].t+st[b[xua]].o;
					jia=1;
				}
				if(linans<ans-st[b[xuc]].t+st[b[xuc]].h && cz!=1)
				{
					linans=ans-st[b[xuc]].t+st[b[xuc]].h;
					jia=3;
				}
				ans=linans;
				nb--;
				if(jia==1)
				{
					na++;
					a[na]=b[xua];
					b[xua]=0;
				}
				if(jia==3)
				{
					nc++;
					c[nc]=b[xuc];
					b[xuc]=0;
				}
			}
		}
		
		
		if(nc>mu)
		{
			y=nc-mu;
			for(int j=0;j<y;j++)
			{
				int mi=st[c[0]].h;  //部门中最小的满意度 
				int lami=st[c[0]].h-st[c[0]].o,lbmi=st[c[0]].h-st[c[0]].t;  //本部门学生与1部门和2部门差值最小的部门的满意度 
				int xua=0,xub=0,xuc=0;  //记录上面三个满意度的学生编号 
				for(int p=1;p<nc;p++)
				{
					if(st[c[p]].h<mi)
					{
						mi=st[c[p]].h;
						xuc=p;
					}
					if(st[c[p]].h-st[c[p]].o<lami)
					{
						lami=st[c[p]].h-st[c[p]].o;
						xua=p;
					}
					if(st[c[p]].h-st[c[p]].t<lbmi)
					{
						lbmi=st[c[p]].h-st[c[p]].t;
						xub=p;
					}
				}
				int linans,jia;
				if(st[c[xuc]].t>st[c[xuc]].o)
				{
					linans=ans-mi+st[c[xuc]].t;
					jia=2;
				}
				else
				{
					linans=ans-mi+st[c[xuc]].o;
					jia=1;
				}
				if(linans<ans-st[c[xua]].h+st[c[xua]].o && az!=1)
				{
					linans=ans-st[c[xua]].h+st[c[xua]].o;
					jia=1;
				}
				if(linans<ans-st[c[xub]].h+st[c[xub]].t && bz!=1)
				{
					linans=ans-st[c[xub]].h+st[c[xub]].t;
					jia=2;
				}
				ans=linans;
				nb--;
				if(jia==1)
				{
					na++;
					a[na]=c[xua];
					c[xua]=0;
				}
				if(jia==2)
				{
					nb++;
					b[nb]=c[xub];
					c[xub]=0;
				}
			}
		}
		cout<<ans<<endl;
	}
	return 0;
}
