#include<bits/stdc++.h>
using namespace std;
struct gh
{
	int h;
	int g;
	int y;
};
int main()
{
	freopen("clubin","r",stdin);
	freopen("clubout","w",stdout);
	int t;
	cin>>t;
	while(t>0)
	{
		t--;
		int p = 0;
		int u = 0;
		int m = 0;
		int n;
		int b;
		cin>>n;
		gh kl[10001];
		int a[100001][6];
		int l[100001];
		for(int i = 0;i<n;i++){
			cin>>kl[i].g>>kl[i].h>>kl[i].y;
			if(max(kl[i].g,max(kl[i].h,kl[i].y)) == kl[i].g)
			{
				p++;
				l[i] = 1;
				int o = max(kl[i].h,kl[i].y);
				a[i][1] = kl[i].g;
				a[i][2] = o;
				
				a[i][3] = (kl[i].h+kl[i].y-o);
			}
			if(max(kl[i].h,max(kl[i].g,kl[i].y)) == kl[i].h)
			{
				u++;
				int o = max(kl[i].g,kl[i].y);
				l[i] = 2;
				a[i][1] = kl[i].h;
				a[i][2] = o;
				
				a[i][3] = (kl[i].g+kl[i].y-o);
			}
			if(max(kl[i].y,max(kl[i].h,kl[i].g)) == kl[i].y)
			{
				m++;
				l[i] = 3;
				int o = max(kl[i].h,kl[i].g);
				a[i][1] = kl[i].y;
				a[i][2] = o;
				
				a[i][3] = (kl[i].h+kl[i].g-o);
			}
			a[i][4] = p;
			a[i][5] = u;
			a[i][6] = m;
		}
		int all = 0;
		for(int i = 0;i<n;i++)
		{
			if(l[i]==1&&a[i][4]>n/2)
			all+=a[i][2];
			else if(l[i]==2&&a[i][5]>n/2)
			all+=a[i][2];
			else if(l[i]==3&&a[i][6]>n/2)
			all+=a[i][2];
			else all+=a[i][1];
		}
		cout<<all;
	
}
return 0;
}
