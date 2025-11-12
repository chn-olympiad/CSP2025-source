#include<bits/stdc++.h>
using namespace std;
int t, n;
struct node {
	int ma, x, l, ll;
} a[100010];
int cnt[4];
bool cmp(node a,node b)
{
	return a.ma>b.ma;
}
int main() {
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin >> t;
	while (t--) {
		cin >> n;
		long long ans=0;
		priority_queue<int> qa,qb,qc;
		cnt[1]=cnt[2]=cnt[3]=0;
		for (int i = 1; i <= n; i++) {
			
			int x, y, z;
			cin >> x >> y >> z;
			a[i].ma = max(max(x, y), z);
			if (a[i].ma == x) {
				a[i].l = 1;
				if (y > z) {
                 a[i].x=y-x;
				 a[i].ll=2;
				}
				else{
					a[i].x=z-x;
					a[i].ll=3;
				}
			}
			else{
				if (a[i].ma == y) {
					a[i].l = 2;
					if (x > z) {
						a[i].x=x-y;
						a[i].ll=1;
					}
					else{
						a[i].x=z-y;
						a[i].ll=3;
					}
				}
				else{
						a[i].l = 3;
						if (x > y) {
							a[i].x=x-z;
							a[i].ll=1;
						}
						else{
							a[i].x=y-z;
							a[i].ll=2;
						}
				}
			}	
		}
		sort(a+1,a+1+n,cmp);
		for(int i=1;i<=n;i++)
		{
			if(cnt[a[i].l]<(n>>1)) 
			{
				ans+=a[i].ma;
				cnt[a[i].l]++;
				if(a[i].l==1) qa.push(a[i].x);
				if(a[i].l==2) qb.push(a[i].x);
				if(a[i].l==3) qc.push(a[i].x);
			}
			else
			{
				int m;
				if(a[i].l==1) m=qa.top();
				if(a[i].l==2) m=qb.top();
				if(a[i].l==3) m=qc.top();
				if(m>a[i].x)
				{
					if(a[i].l==1) qa.pop(),qa.push(a[i].x);
					if(a[i].l==2) qb.pop(),qb.push(a[i].x);
					if(a[i].l==3) qc.pop(),qc.push(a[i].x);
					ans+=m+a[i].ma;
				}
				else
				{
					ans+=a[i].ma+a[i].x;
				}
			}
		}
		cout<<ans<<endl;
	}
	return 0;
}