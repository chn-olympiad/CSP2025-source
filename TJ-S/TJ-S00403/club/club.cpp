#include <bits/stdc++.h>
#include <iostream>
#include <algorithm>
using namespace std;
int main(){
	//ios::sync_with_stdio(0);cin.tie(0);
	//freopen("club.in","r",stdin);
	//freopen("club.out","w",stdout);
	int n,t;
	int a[1005][1005]={};
	cin>>n;
	int maxn=0;	
	int d=0,e=0,f=0;	
	int g=0;
	int cnt=0;
	for(int i=1;i<=n;i++)
	{
		cin>>t;
		maxn=0;
		for(int i=1;i<=t;i++)
		{
			a[i][1]=0;
			a[i][2]=0;
			a[i][3]=0;
		}
		for(int i=1;i<=t;i++)
		{
			cin>>a[i][1]>>a[i][2]>>a[i][3];
		}
		for(int i=1;i<=t;i++)
		{

			if(a[i][1]>maxn)
			{
				maxn=a[i][1];
				g=1;
			}
			if(a[i][2]>maxn)
			{
				maxn=a[i][2];
				g=2;
			}
			if(a[i][3]>maxn)
			{
				maxn=a[i][3];
				g=3;
			}
			if(g==1&&cnt+1<=n/2)
			{
				d++;
			}
			if(g==2&&cnt+1<=n/2)
			{
				e++;
			}
			if(g==3&&cnt+1<=n/2)
			{
				f++;
			}
		}
	}
	cout<<d+e+f<<endl;
	
	return 0;
} 

/*shuru
3
4
4 2 1
3 2 4
5 3 4
3 5 1
4
0 1 0
0 1 0
0 2 0
0 2 0
2
10 9 8
4 0 0
*/
/*shuchu
18
4
13
*/
