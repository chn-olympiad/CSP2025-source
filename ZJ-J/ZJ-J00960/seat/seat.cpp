#include<bits/stdc++.h>
using namespace std;
int score[105];
bool cmp(int x,int y)
{
	return x>y;
}
int main()
{
	int n,m,scr;
	fstream file=fstream("seat.in",ios::in);
	fstream file2=fstream("seat.out",ios::out);
	file>>n>>m;
	for(int i=1;i<=n*m;i++)
	{
		file>>score[i];
	}
	scr=score[1];
	int nm=n*m;
	sort(score,score+nm+2,cmp);
	int x=1,y=1,force=0;
	//cout<<scr<<endl;
	for(int i=0;i<=n*m;i++)
	{
		//cout<<i<<" "<<score[i]<<" "<<x<<" "<<y<<endl;
		if(score[i]==scr)
		{
			file2<<x<<" "<<y;
			break;
		}
		if(y%m==0&&force==0)
		{
			x++;
			force=1;
			continue;
		}
		else if(y==1&&force==1)
		{
			x++;
			force=0;
			continue;
		}
		if(force==0)
		{
			y++;
		}
		else
			y--;
	}
	return 0;
}