//Ren5Jie4Di4Ling5%
#include <bits/stdc++.h>
using namespace std;

const int N = 1e5+10;
struct nnn
{
	int zz,yy;
};
nnn aaz[N],bbz[N],ccz[N];
int a[N][5],c[N];
bool cmp(int xx,int yy)
{
	return xx > yy;
}
bool cmpc(nnn xx,nnn yy)
{
	return xx.zz>yy.zz;
}
//bool ch(int mid)
//{
//	
//}

int main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int T;cin>>T;
	while (T--)
	{
		int n;cin>>n;
		bool kkk=0;
		for (int i = 1;i <= n;i++)
		{
			scanf("%d%d%d",&a[i][1],&a[i][2],&a[i][3]);
			if(a[i][2] != 0 || a[i][3] != 0) kkk = 1;
		}
		
		if (!kkk)
		{
			for (int i = 1;i <= n;i++) c[i] = a[i][1];
			sort(c+1,c+n+1,cmp);
			long long sum = 0;
			for (int i = 1;i <= n/2;i++)
			{
				sum+=c[i];
			}
			cout<<sum<<'\n';
			continue;
		}
		long long sum = 0;
		map<int,pair<int,int>> ac,bc,cc;
		for (int i = 1;i <= n;i++)
		{
			if (a[i][1] >= a[i][2] && a[i][1] >= a[i][3]) sum+=(long long)a[i][1],ac[a[i][1]].first++,ac[a[i][1]].second=i;
			else if (a[i][2] >= a[i][1] && a[i][2] >= a[i][3]) sum+=(long long)a[i][2],bc[a[i][2]].first++,bc[a[i][2]].second=i;
			else sum+=(long long)a[i][3],cc[a[i][3]].first++,cc[a[i][3]].second=i;
		}
		int y = 0;
		for (auto i:ac) y+=i.second.first;
		int t = 0;
		for (auto i:bc) t+=i.second.first;
		int z = 0;
		for (auto i:cc) z+=i.second.first;
	//	cout<<ac.size()<<' '<<bc.size()<<' '<<cc.size()<<'\n';
	int hhh = 0;
		if (y > n/2)
		{
			for (auto i:ac)
			{
//				bool flag = 0;
				for (int j = 1;j <= ac[i.first].first;j++)
				{
//					if (y <= n/2)
//					{
//						flag = 1;
//						break;
//					}
				//	y--;
				//	ac[i.first].first--;
					//sum-=i.first;
					if (a[i.second.second][2] >= a[i.second.second][3]) hhh++,aaz[hhh].zz = (long long)a[i.second.second][2]-i.first,aaz[hhh].yy = 2;
					if (a[i.second.second][3] >= a[i.second.second][2])hhh++,aaz[hhh].zz = (long long)a[i.second.second][3]-i.first,aaz[hhh].yy = 3;
//					elsehhh++,aaz[hhh] = (long long)a[i.second.second][2]-i.first;
//					else if ((int)z+1 <= n/2) hhh++,aaz[hhh] = (long long)a[i.second.second][3]-i.first;
				}
			//	if (flag) break;
			}
		}
		sort(aaz+1,aaz+1+hhh,cmpc);
		for (int i = 1;i <= hhh;i++)
		{
			if (y <= n/2) break;
			if (aaz[i].yy==2)
			{
				if ((int)t+1 <= n/2) t++,sum+=aaz[i].zz,y--;
			}
			else
			{
				if ((int)z+1 <= n/2) z++,sum+=aaz[i].zz,y--;
			}
		}
	//	cout<<bc.size()<<"\n";
		int ppp = 0;
		if ((int)t > n/2)
		{
			for (auto i:bc)
			{
//				bool flag = 0;
				for (int j = 1;j <= bc[i.first].first;j++)
				{
//					if (t <= n/2)
//					{
//						flag = 1;
//						break;
//					}
				//	t--;
			//		bc[i.first].first--;
				//	sum-=i.first;
				//	cout<<sum<<'\n';
					if (a[i.second.second][1] >= a[i.second.second][3]) ppp++,bbz[ppp].zz=(long long)a[i.second.second][1]-i.first,bbz[ppp].yy = 1;
					if (a[i.second.second][3] >= a[i.second.second][1]) ppp++,bbz[ppp].zz=(long long)a[i.second.second][3]-i.first,bbz[ppp].yy = 3;
//					else if ((int)y+1 <= n/2) sum+=(long long)a[i.second.second][1],y++;
//					else if ((int)z+1 <= n/2) sum+=(long long)a[i.second.second][3],z++;
				}
//				if (flag) break;	
			}
		}
		sort(bbz+1,bbz+1+ppp,cmpc);
		for (int i = 1;i <= ppp;i++)
		{
			if (t <= n/2) break;
			if (bbz[i].yy == 1)
			{
				if ((int)y+1 <= n/2) y++,sum+=bbz[i].zz,t--;
			}
			else
			{
				if ((int)z+1 <= n/2) z++,sum+=bbz[i].zz,t--;
			}
			//cout<<bbz[i]<<' '<<i<<'\n';
		}
		int ooo = 0;
		if ((int)z > n/2)
		{
			for (auto i:cc)
			{
//				bool flag = 0;
				for (int j = 1;j <= cc[i.first].first;j++)
				{
//					if (z <= n/2)
//					{
//						flag = 1;
//						break;
//					}
//					z--;
				//	cc[i.first].first--;
//					sum-=i.first;
					if (a[i.second.second][2] >= a[i.second.second][1]) ooo++,ccz[ooo].zz=(long long)a[i.second.second][2]-i.first,ccz[ooo].yy = 2;
					if (a[i.second.second][1] >= a[i.second.second][2])ooo++,ccz[ooo].zz=(long long)a[i.second.second][1]-i.first,ccz[ooo].yy = 1;
//					else if ((int)y+1 <= n/2) sum+=(long long)a[i.second.second][1],y++;
//					else if ((int)t+1 <= n/2) sum+=(long long)a[i.second.second][2],t++;
				}
//				if (flag) break;
			}
		}
		sort(ccz+1,ccz+1+ooo,cmpc);
		for (int i = 1;i <= ooo;i++)
		{
			if (z <= n/2) break;
			if (ccz[i].yy == 1)
			{
				if ((int)y+1 <= n/2) y++,sum+=ccz[i].zz,z--;
			}
			else
			{
				if ((int)t+1 <= n/2) t++,sum+=ccz[i].zz,z--;
			}
		}
		cout<<sum<<'\n';
//		sort(a+1,a+n+1,cmp);
//		sort(b+1,b+n+1,cmp);
//		sort(c+1,c+n+1,cmp);
		
//		int l = 0,r = 2e9;
//		while (l <= r)
//		{
//			int mid = (l+r)>>1;
//			if (ch(mid)) l = mid+1;
//			else r = mid-1;
//		}
	}
	return 0;
}
