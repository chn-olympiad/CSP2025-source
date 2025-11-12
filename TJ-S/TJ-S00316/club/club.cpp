#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout); 
	int t;
	cin >> t;
	
	for (int w=1;w<=t;w++)
	{
		int n,m=0,a[10][10],s,nt;
		cin >> n;
		nt = n/2;
		for(int i=1;i<=n;i++)
		{
			for(int j=1;j<=3;j++)
			{
				cin >> a[i][j];
			}
		}
		for(int j=1;j<=3;j++)
		{
			m = 0;
			for(int i=1;i<=n;i++)
			{
				if(a[i][j] > m)
				{
					m = a[i][j];
				}

				s+=m;
			}
		}
		
		
		
		
		cout << s;
	}
	return 0;
}

