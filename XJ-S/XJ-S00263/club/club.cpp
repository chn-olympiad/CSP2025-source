#include <bits/stdc++.h>
using namespace std;
bool cmp(int x,int y){return x>y;}
//struct toge
//{
//	int id,num;
//};
int main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int T;
	cin >> T;
	while (T--)
	{
		int n,a[3][10010];
		cin >> n;
		int isA=1,isB=1;
		for (int i=0;i<n;i++)
		{
			cin >> a[0][i] >> a[1][i] >> a[2][i];
			if (a[2][i] != 0 || a[1][i] != 0)
			{
				if (a[2][i] != 0)
				{
					isB=0;
				}
				isA=0;
			}
		}
		if (isA)
		{
			sort(a[0]+0,a[0]+n,cmp);
			int sum=0;
			for (int i=0;i<n/2;i++)
			{
				sum += a[0][i];
			}
			cout << sum << endl;
		}
		else if (isB)
		{
			int all[2][n],cnt[2]={0,0},sum=0;
			int w_move[n];
			for (int i=0;i<n;i++)
			{
				if (a[0][i] > a[1][i])
				{
					all[0][cnt[0]++] = i;
					sum += a[0][i];
				}
				else if (a[0][i] <= a[1][i])
				{
					all[1][cnt[1]++] = i;
					sum += a[1][i];
				}
			}
			//a[0][x] 0社团对x的价值 
			if (cnt[0] > (n/2))
			{
				for (int i=0;i<cnt[0];i++)
				{
					w_move[i] = a[1][all[0][i]]-a[0][all[0][i]];
				}
				sort(w_move+0,w_move+cnt[0],cmp);
				int needless = cnt[0]-(n/2);
				for (int i=0;i<needless;i++)
				{
					//cout << sum << " and " << w_move[i] << endl;
					sum += w_move[i];
				}
			}
			else if (cnt[1] > (n/2))
			{
				for (int i=0;i<cnt[1];i++)
				{
					w_move[i] = a[0][all[1][i]]-a[1][all[1][i]];
					//cout << w_move[i] << ",";
				}
				sort(w_move+0,w_move+cnt[1],cmp);
				int needless = cnt[1]-(n/2);
				for (int i=0;i<needless;i++)
				{
					//cout << sum << " and " << w_move[i] << endl;
					sum += w_move[i];
				}
			}
			cout << sum << endl;
		}
		else
		{
			;
		}
		
	} 
	return 0;
} 

