#include<iostream>
#include<cstdio>
#include<string>
#include<algorithm>
using namespace std;
int score[111],n,m,setsx[111],setsy[111];
bool cmp(int y,int u)
{
	return y > u;
}
void setmp(int x)
{
	int ojk = 1;
	for(int j = 1;j <= m;j ++)
	{
		if(j % 2 == 1)
		{
			for(int i = 1;i <= n; i ++)
			{
				setsx[ojk] = i;
				setsy[ojk] = j;
				// cout << ojk << ' ' << i << ' ' << j << endl;
				ojk ++;
			}
		}
		else
		{
			for(int i = n;i >= 1; i --)
			{
				setsx[ojk] = i;
				setsy[ojk] = j;
				// cout << ojk << ' ' << i << ' ' << j << endl;
				ojk ++;
			}
		}
	}
}
string s;
int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin >> n >> m;
	int o = n * m;
	cin >> score[1];
	int mscore = score[1];
	for(int i = 2;i <= o;i ++)
	{
		cin >> score[i];
	}
	setmp(o);
	sort(score + 1,score + o + 1,cmp);
	int mbj = 0;
	for(int i = 1;i <= o; i ++)
	{
		if(score[i] == mscore)
		{
			mbj = i;
			break;
		}
	}
	cout << setsy[mbj] << ' ' << setsx[mbj];
	return 0;
}
