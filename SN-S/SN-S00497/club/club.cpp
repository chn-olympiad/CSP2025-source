// SN-S00497 王昭云 西安市曲江第一学校
#include <bits/stdc++.h>

using namespace std;

struct Min
{
	int num = 0x3f3f3f3f,id;
}ma,mb,mc;

int T,n,a[100005],b[100005],c[100005],aa,bb,cc,a_,b_,c_,manyi,ans = -0x3f3f3f3f;

int main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	scanf("%d",&T);
	while(T--)
	{
		scanf("%d",&n);
		aa = bb = cc = a_ = b_ = c_ = 0;
		ma.num = mb.num = mc.num = 0x3f3f3f3f;
		memset(a,0,sizeof(a));
		memset(b,0,sizeof(b));
		memset(c,0,sizeof(c));
		for(int i = 1;i <= n;i++)
		{
			scanf("%d%d%d",&a[i],&b[i],&c[i]);
			if(a[i] >= b[i] && a[i] >= c[i])
			{
				if(aa < (n / 2))
				{
					aa++;
					a_ += a[i];
					if(a[i] < ma.num)
					{
						ma.num = a[i];
						ma.id = i;
					}
				}
				else
				{
					if(a[i] > ma.num)
					{
						a_ = a_ - ma.num + a[i];
						if(b[ma.id] >= c[ma.id] && bb < (n / 2))
						{
							bb++;
							b_ += b[ma.id];
							if(b[ma.id] < mb.num)
							{
								mb.num = b[ma.id];
								mb.id = i;
							}
						}
						else if(c[ma.id] >= b[ma.id] && cc < (n / 2))
						{
							cc++;
							c_ += c[ma.id];
							if(c[ma.id] < mc.num)
							{
								mc.num = c[ma.id];
								mc.id = i;
							}
						}
					}
					else
					{
						if(b[ma.id] >= c[ma.id] && bb < (n / 2))
						{
							bb++;
							b_ += b[ma.id];
							if(b[ma.id] < mb.num)
							{
								mb.num = b[ma.id];
								mb.id = i;
							}
						}
						else if(c[ma.id] >= b[ma.id] && cc < (n / 2))
						{
							cc++;
							c_ += c[ma.id];
							if(c[ma.id] < mc.num)
							{
								mc.num = c[ma.id];
								mc.id = i;
							}
						}
					}
				}
			}
			else if(b[i] >= a[i] && b[i] >= c[i])
			{
				if(bb < (n / 2))
				{
					bb++;
					b_ += b[i];
					if(b[i] < mb.num)
					{
						mb.num = a[i];
						mb.id = i;
					}
				}
				else
				{
					if(b[i] > mb.num)
					{
						b_ = b_ - mb.num + b[i];
						if(a[mb.id] >= c[mb.id] && aa < (n / 2))
						{
							aa++;
							a_ += a[mb.id];
							if(a[mb.id] < ma.num)
							{
								ma.num = a[mb.id];
								ma.id = i;
							}
						}
						else if(c[mb.id] >= a[mb.id] && cc < (n / 2))
						{
							cc++;
							c_ += c[mb.id];
							if(c[mb.id] < mc.num)
							{
								mc.num = c[mb.id];
								mc.id = i;
							}
						}
					}
					else
					{
						if(a[mb.id] >= c[mb.id] && aa < (n / 2))
						{
							aa++;
							a_ += a[mb.id];
							if(a[mb.id] < ma.num)
							{
								ma.num = a[mb.id];
								ma.id = i;
							}
						}
						else if(c[mb.id] >= a[mb.id] && cc < (n / 2))
						{
							cc++;
							c_ += c[mb.id];
							if(c[mb.id] < mc.num)
							{
								mc.num = c[mb.id];
								mc.id = i;
							}
						}
					}
				}
			}
			else if(c[i] >= a[i] && c[i] >= b[i])
			{
				if(cc < (n / 2))
				{
					cc++;
					c_ += c[i];
					if(c[i] < mc.num)
					{
						mc.num = a[i];
						mc.id = i;
					}
				}
				else
				{
					if(c[i] > mc.num)
					{
						c_ = c_ - mc.num + c[i];
						if(a[mc.id] >= b[mc.id] && aa < (n / 2))
						{
							aa++;
							a_ += a[mc.id];
							if(a[mc.id] < ma.num)
							{
								ma.num = b[mc.id];
								ma.id = i;
							}
						}
						else if(b[mc.id] >= a[mc.id] && bb < (n / 2))
						{
							bb++;
							b_ += b[mc.id];
							if(b[mc.id] < mb.num)
							{
								mb.num = b[mc.id];
								mb.id = i;
							}
						}
					}
					else
					{
						if(a[mb.id] >= c[mb.id] && aa < (n / 2))
						{
							aa++;
							a_ += a[mb.id];
							if(a[mb.id] < ma.num)
							{
								ma.num = a[mb.id];
								ma.id = i;
							}
						}
						else if(c[mb.id] >= a[mb.id] && cc < (n / 2))
						{
							cc++;
							c_ += c[mb.id];
							if(c[mb.id] < mc.num)
							{
								mc.num = c[mb.id];
								mc.id = i;
							}
						}
					}
				}
			}
		}
		printf("%d\n",a_ + b_ + c_);
		
//		for(int i = 1;i <= n;i++)
//		{
//			scanf("%d%d%d",&a[i],&b[i],&c[i]);
//			if(a[i] >= b[i] && a[i] >= c[i] && aa < (n / 2))
//			{
//				aa++;
//				manyi += a[i];
//			}
//			else if(b[i] >= a[i] && b[i] >= c[i] && bb < (n / 2))
//			{
//				bb++;
//				manyi += b[i];
//			}
//			else if(c[i] >= a[i] && c[i] >= a[i] && cc < (n / 2))
//			{
//				cc++;
//				manyi += c[i];
//			}
//			ans = max(ans,manyi);
//		}
//		printf("%d\n",ans);
//		ans = -0x3f3f3f3f;
//		manyi = aa = bb = cc = 0;
	}
	return 0;
} 
