#include<bits/stdc++.h>
using namespace std;

const int N=1e5+10;

int T;

struct people{
	int a, b, c;
}p[N];

bool cmp(people wsq, people fyy){
	if(wsq.a>=fyy.a) return true;
	else if(wsq.b>=fyy.b) return true;
	else if(wsq.c>=fyy.c) return true;
	
	return false;
}

int main()
{
	freopen("club.in", "r", stdin);
	freopen("club.out", "w", stdout);
	
	scanf("%d", &T);
	
	while(T--)
	{
		int n;
		long long ans=0;
		int A=0, B=0, C=0;
		
		scanf("%d", &n);
		for(int i=1; i<=n; i++)	{
			cin>>p[i].a>>p[i].b>>p[i].c;
		}
		sort(p, p+n, cmp);
		for(int i=1; i<=n; i++)
		{
			int m=max(max(p[i].a, p[i].b), p[i].c);
			if(p[i].a+p[i+1].a>m+p[i+1].a&&A<n/2&&A+1<=n/2){
				A++;
				ans+=p[i].a;
				continue;
			}
			else if(p[i].a+p[i+1].b>m+p[i+1].a&&A<n/2&&B<=n/2){
				A++;
				ans+=p[i].a;
				continue;
			}
			else if(p[i].a+p[i+1].c>m+p[i+1].a&&A<n/2&&C<=n/2){
				A++;
				ans+=p[i].a;
				continue;
			}
			//
			else if(p[i].b+p[i+1].a>m+p[i+1].a&&B<n/2&&A<=n/2){
				B++;
				ans+=p[i].b;
				continue;
			}
			else if(p[i].b+p[i+1].b>m+p[i+1].a&&B<n/2&&B+1<=n/2){
				B++;
				ans+=p[i].b;
				continue;
			}
			else if(p[i].b+p[i+1].c>m+p[i+1].a&&B<n/2&&C<=n/2){
				B++;
				ans+=p[i].b;
				continue;
			} 
			//
			else if(p[i].c+p[i+1].a>m+p[i+1].a&&C<n/2&&A<=n/2){
				C++;
				ans+=p[i].c;
				continue;
			}
			else if(p[i].c+p[i+1].b>m+p[i+1].a&&C<n/2&&B<=n/2){
				C++;
				ans+=p[i].c;
				continue;
			}
			else if(p[i].c+p[i+1].c>m+p[i+1].a&&C<n/2&&C+1<=n/2){
				C++;
				ans+=p[i].c;
				continue;
			}
			//bbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbb
			else if(p[i].a+p[i+1].a>m+p[i+1].b&&A<n/2&&A+1<=n/2){
				A++;
				ans+=p[i].a;
				continue;
			}
			else if(p[i].a+p[i+1].b>m+p[i+1].b&&A<n/2&&B<=n/2){
				A++;
				ans+=p[i].a;
				continue;
			}
			else if(p[i].a+p[i+1].c>m+p[i+1].b&&A<n/2&&C<=n/2){
				A++;
				ans+=p[i].a;
				continue;
			}
			//
			else if(p[i].b+p[i+1].a>m+p[i+1].b&&B<n/2&&A<=n/2){
				B++;
				ans+=p[i].b;
				continue;
			}
			else if(p[i].b+p[i+1].b>m+p[i+1].b&&B<n/2&&B+1<=n/2){
				B++;
				ans+=p[i].b;
				continue;
			}
			else if(p[i].b+p[i+1].c>m+p[i+1].b&&B<n/2&&C<=n/2){
				B++;
				ans+=p[i].b;
				continue;
			} 
			//
			else if(p[i].c+p[i+1].a>m+p[i+1].b&&C<n/2&&A<=n/2){
				C++;
				ans+=p[i].c;
				continue;
			}
			else if(p[i].c+p[i+1].b>m+p[i+1].b&&C<n/2&&B<=n/2){
				C++;
				ans+=p[i].c;
				continue;
			}
			else if(p[i].c+p[i+1].c>m+p[i+1].b&&C<n/2&&C+1<=n/2){
				C++;
				ans+=p[i].c;
				continue;
			}
			//cccccccccccccccccccccccccccc
			else if(p[i].a+p[i+1].a>m+p[i+1].c&&A<n/2&&A+1<=n/2){
				A++;
				ans+=p[i].a;
				continue;
			}
			else if(p[i].a+p[i+1].b>m+p[i+1].c&&A<n/2&&B<=n/2){
				A++;
				ans+=p[i].a;
				continue;
			}
			else if(p[i].a+p[i+1].c>m+p[i+1].c&&A<n/2&&C<=n/2){
				A++;
				ans+=p[i].a;
				continue;
			}
			//
			else if(p[i].b+p[i+1].a>m+p[i+1].c&&B<n/2&&A<=n/2){
				B++;
				ans+=p[i].b;
				continue;
			}
			else if(p[i].b+p[i+1].b>m+p[i+1].c&&B<n/2&&B+1<=n/2){
				B++;
				ans+=p[i].b;
				continue;
			}
			else if(p[i].b+p[i+1].c>m+p[i+1].c&&B<n/2&&C<=n/2){
				B++;
				ans+=p[i].b;
				continue;
			} 
			//
			else if(p[i].c+p[i+1].a>m+p[i+1].c&&C<n/2&&A<=n/2){
				C++;
				ans+=p[i].c;
				continue;
			}
			else if(p[i].c+p[i+1].b>m+p[i+1].c&&C<n/2&&B<=n/2){
				C++;
				ans+=p[i].c;
				continue;
			}
			else if(p[i].c+p[i+1].c>m+p[i+1].c&&C<n/2&&C+1<=n/2){
				C++;
				ans+=p[i].c;
				continue;
			}		
//			if(k(max(max(p[i].a, p[i].b), p[i].c)))
//			{
//				ans+=max(max(p[i].a, p[i].b), p[i].c);
//				if((max(p[i].a, p[i].b), p[i].c)==p[i].a) A++;
//				else if(max(max(p[i].a, p[i].b), p[i].c)==p[i].b) B++;
//				else C++;
//				continue;
//			}
		}
		cout<<ans;
	}
	
	return 0;
}
