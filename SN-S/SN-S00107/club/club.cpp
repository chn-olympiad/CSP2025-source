#include<bits/stdc++.h>
using namespace std;
struct stu{
	int m;
	int a,b,c;
	int i;
}u[190000];
bool cmp(stu x,stu y)
{
	return x.m > y.m;
}
int main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int t;
	cin>>t;
	while (t--)
	{
		int n;
		cin>>n;
		int sa = 0,sb = 0,sc = 0;
		for (int i = 0;i < n;i++)
		{
			cin>>u[i].a>>u[i].b>>u[i].c;
			u[i].m = max(u[i].a,max(u[i].b,u[i].c));
			if (u[i].m = u[i].a) u[i].i = 1;
			else if (u[i].m = u[i].b) u[i].i = 2;
			else if (u[i].m = u[i].c) u[i].i = 3;
			
		}
		sort(u,u + n,cmp);
		int s = 0;
		for (int i = 0;i < n;i++)
		{
			if (u[i].i == 1 and sa < n / 2) {sa++;s += u[i].a;
			}else if (u[i].i == 2 and sb < n / 2) {sb++;s += u[i].b;
			}else if (u[i].i == 3 and sc < n / 2) {sc++;s += u[i].c;
			}else{
				if (u[i].i == 1){
					if (u[i].b > u[i].c and sb < n / 2) {sb++;s += u[i].b;
					}else{sc++;s += u[i].c;}
				}else if (u[i].i == 2)
				{
					if (u[i].a > u[i].c and sa < n / 2) {sa++;s += u[i].a;
					}else{sc++;s += u[i].c;}
				}
				else if (u[i].i == 3)
				{
					if (u[i].a > u[i].b and sa < n / 2) {sa++;s += u[i].a;
					}else{sb++;s += u[i].b;}
				}
			}
			
		}
		cout<<s<<endl;
	 } 
	 return 0;
}
