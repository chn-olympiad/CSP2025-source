#include<bits/stdc++.h>
using namespace std;
int score[105],m,n,c,r,k,cnt=1,ord;
bool cmp(int x,int y)
{
	return x>y;
}
int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	scanf("%d %d",&n,&m);
	for(int i=1;i<=n*m;i++)
	{
		cin>>score[i];
	}
	ord=score[1];
	c=1;
	r=1;
	k=1;
	sort(score+1,score+n*m+1,cmp);
	while(score[cnt]!=ord)
	{
		if(c==n&&r%2==1||c==1&&r%2==0)
		{
			r++;
			k*=-1;
		}
		else c+=k;
		cnt++;
	}
	printf("%d %d",r,c);
	return 0;
}
