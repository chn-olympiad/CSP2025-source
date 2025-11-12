#include<bits/stdc++.h>
using namespace std;
int sc[105],sx[105],sy[105];
bool cmp(int x,int y)
{
	return x>y;
}
int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m;
	cin>>n>>m;
	for(int i=1; i<=n*m; i++)
	{
		cin>>sc[i];
	}
	int rs=sc[1];
	sort(sc+1,sc+n*m+1,cmp);

	int lie=1; //列数
	int hang=1;//行数
	bool f=0,f1=0;
	for(int i=1,count=1; i<=n*m; i++,count++)
	{
		if(count==n+1&&f==0) //加到了n+1
		{
			lie++;
			f1=0;
			f=1;
		}
		else if((count-1)%n==0&&f==1)
		{
			lie++;
			f1=0;
		}
		//从n+1开始，每加一个n，就列数+1


		//当为奇数列时，行的变化：1加到n，为偶数列时，n减到1
		if(lie%2!=0)
		{
			if(f1==0)
			{
				hang=1;
				f1=1;
			}
			sx[i]=lie,sy[i]=hang;
			hang++;
		}
		if(lie%2==0)
		{
			if(f1==0)
			{
				hang=n;
				f1=1;
			}
			sx[i]=lie,sy[i]=hang;
			hang--;
		}
//		cout<<lie<<" "<<hang<<" "<<count<<endl;
	}
//	for(int i=1; i<=n*m; i++)
//	{
//		cout<<sc[i]<<" "<<endl;
//	}
	for(int i=1; i<=n*m; i++)
	{
		//寻找小r的分数
		if(sc[i]==rs)
		{
			cout<<sx[i]<<" "<<sy[i];
			return 0;
		}
	}
	return 0;
}

