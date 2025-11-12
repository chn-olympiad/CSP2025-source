//SN-J01169 马歆玥 西安滨河学校 
#include <bits/stdc++.h>
using namespace std;

int n,m,cnt;
int a[105];
int b[15][15]; 

bool cmp(int num1,int num2)
{
	return num1 > num2;
}

int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	cin >> n >> m;
	for(int i=1;i<=n*m;i++)
		cin >> a[i];
	int r = a[1];
	sort(a+1,a+n*m+1,cmp);
	int hang = 1,lie = 1;
	while(hang >= 1 && lie <= m && cnt <= n*m)
	{
		b[hang][lie] = a[++cnt];
		if(lie % 2 == 1)
		{
			if(hang == n)
				lie++;
			else
				hang++;
		}
		else if(lie % 2 == 0)
		{
			if(hang == 1)
				lie++;
			else
				hang--;
		}
		if(hang == 1 && lie == m && cnt == n*m)
			break;
	}	
	for(int i=1;i<=n;i++)
		for(int j=1;j<=m;j++)
			if(b[i][j] == r)
			{
				cout <<j << " " << i;
				return 0;
			}
	return 0;
}
