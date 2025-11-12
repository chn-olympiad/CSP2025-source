#include <bits/stdc++.h>
using namespace std;
#define pii pair<int,int>
#define fir first
#define sec second
#define pb push_back
void Ios(){ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);}
pii a[1001];
int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	Ios();
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n*m;i++) cin>>a[i].fir,a[i].sec=i;
	sort(a+1,a+n*m+1);
	reverse(a+1,a+n*m+1);
	int pos;
	for(int i=1;i<=n*m;i++)
	if(a[i].sec==1)
	{
		pos=i;
		break;
	}
	int x=1,y=1,o=0;
	pos--;
	while(pos--)
	{
		if(o==0)
		{
			if(x==n) y++,o^=1;
			else x++;
		}
		else
		{
			if(x==1) y++,o^=1;
			else x--;
		}
	}
	cout<<y<<" "<<x<<"\n";
	return 0;
}
//8:49 pretest passed(3)