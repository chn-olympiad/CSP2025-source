#include<bits/stdc++.h>
#define ull unsigned long long 
using namespace std;
int n,q;
//struct s_a_m_e_{
//	int len;
//	ull hs;
//}sm[550001];
struct d_i_f_f_{
	int l,r;
	ull hs1,hs2,hsall;
	int hslen,len;
};
vector<d_i_f_f_>df[1550001]; 
int totdf=0,totsm=0;
string s1,s2;
ull pr[5550001],p=13331;
ull hsp[2550001];
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout); 
	int i,j;
	cin>>n>>q;
	pr[0]=1;
	for(i=1;i<=5000000;i++)pr[i]=pr[i-1]*p;
	for(i=1;i<=n;i++)
	{
		int len=0;
		cin>>s1>>s2;
		len=s1.size();
		int l=0,r=0;
		for(l=1;l<=len;l++)
		{
			if(s1[l-1]!=s2[l-1])
			{
				l--;
				break;
			}
		}
		for(r=len;r>=1;r--)
		{
			if(s1[r-1]!=s2[r-1])
			{
				r++;
				break;
			}
		}
		ull hs1=0,hs2=0,hsall=0;
		int hslen=r-l-1;
		for(j=l+1;j<=r-1;++j)
		{
			hs1=hs1*p+s1[j-1];
			hs2=hs2*p+s2[j-1];
		}
		for(j=1;j<=len;++j)
		{
			hsall=hsall*p+s1[j-1];
		}
		d_i_f_f_ kkk;
		kkk.l=l;
		kkk.r=r;
		kkk.hs1=hs1;
		kkk.hs2=hs2;
		kkk.hslen=hslen;
		kkk.hsall=hsall;
		kkk.len=len;
		df[hslen+2].push_back(kkk);
	}
	string t1,t2; 
	while(q--)
	{
		cin>>t1>>t2; 
		int len=t1.size(),ans=0,l,r;
		if(t1.size()!=t2.size())
		{
			cout<<0<<"\n";
			continue;
		}
		for(l=1;l<=len;l++)
		{
			if(t1[l-1]!=t2[l-1])
			{
				l--;
				break; 
			}
		}
		for(r=len;r>=1;r--)
		{
			if(t1[r-1]!=t2[r-1])
			{
				r++;
				break;
			}
		}
		int hslen=r-l-1;
		for(i=1;i<=len;++i)
		{
			hsp[i]=hsp[i-1]*p+t1[i-1];
		}
		ull hsx=0,hsy=0;
		for(i=l+1;i<=r-1;++i)
		{
			hsx=hsx*p+t1[i-1];
			hsy=hsy*p+t2[i-1];
		}
		for(i=0;i<df[hslen+2].size();++i)
		{
			if(df[hslen+2][i].hs1!=hsx||df[hslen+2][i].hs2!=hsy)continue;
			if(df[hslen+2][i].l>l||df[hslen+2][i].len-df[hslen+2][i].r>len-r)continue;
			int rr=l-df[hslen+2][i].l+df[hslen+2][i].len,ll=l-df[hslen+2][i].l+1;
			ull hsk=hsp[rr]-hsp[ll-1]*pr[rr-ll+1];
			if(hsk!=df[hslen+2][i].hsall)continue;
			ans++;
		}
		cout<<ans<<"\n";
	} 
	return 0;
}
/*
15:24"子串y的位置不同"这个性质真的有用吗
哦，有用的 aaaa aaaa 用 aa aa替换有3种可能
上hash 
16:01暴力思路大概是nq+l1+l2的，应该好写吧 
16:03 O，NO！t_j1!=t_j2,第一条到底有什么用！ 
16:33 耗时30min，过了全部大样例，好耶！ 骗到50
16:35 突然有个绝妙的剪枝，让我试试 
16:44 样例3从2.2s到0.38s了，显著提升！ 
*/
