#include<bits/stdc++.h>
using namespace std;
int score[101];
bool cmp(int x,int y){
	return x>y;
}
int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=(n*m);i++)
	{
		cin>>score[i];
	}
	int R=score[1],Paiming=0;
	sort(score+1,score+(n*m)+1,cmp);
	for(int i=1;i<=(n*m);i++)
	{
		if(score[i]==R)
		{
			Paiming=i;
			break;
		}
	}
	int q=0;
	for(int i=1;i<=m;i++)
	{
		if(i%2)
		{
			for(int j=1;j<=n;j++)
			{
				q++;
				if(q==Paiming)
				{
					cout<<i<<" "<<j;
					fclose(stdin);
					fclose(stdout);
					return 0;
				}
			}
		}
		else
		{
			for(int j=n;j>=1;--j)
			{
				q++;
				if(q==Paiming)
				{
					cout<<i<<" "<<j;
					fclose(stdin);
					fclose(stdout);
					return 0;
				}
			}
		}
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}