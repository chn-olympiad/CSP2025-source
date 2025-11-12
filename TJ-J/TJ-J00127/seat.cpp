#include<bits/stdc++.h>
using namespace std;
bool cmp(int x,int y)
{
	return x>y;
}
int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m,r;
	cin>>n>>m;
	int score[(n*m)];
	for(int i=0;i<n*m;i++)
	{
		cin>>score[i];
	}
	r=score[0];
	int mingci;
	sort(score,score+n*m,cmp);
	for(int i=0;i<n*m;i++)
	{
		if(score[i]==r)
		{
			mingci=i;
			break;
		}
	}
	int hang=1,lie=1;
	bool zhuan=false;
	for(int i=1;i<=mingci;i++)
	{
		if(zhuan==false)
		{
			if(hang==n)
			{
				lie++;
				zhuan=true;
			}else{
				hang++;
			}
		}else{
			if(hang==1)
			{
				lie++;
				zhuan=false;
			}else{
				hang--;
			}
		}
	}
	cout<<lie<<" "<<hang;
	return 0;
}
