#include<bits/stdc++.h>
using namespace std;
int n,m;
struct z{
	int x;
	int c;
};

int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int t[100]={0};
	cin>>n>>m;
	z q[n*m];
	for(int a=0;a<n*m;a++)
	{
		cin>>q[a].c;
		q[a].x=a+1;
		t[q[a].c]++;
	}
	int w=q[0].c;
	int s=1;
	if(w==100)
	{
		cout<<1<<" "<<1;
		return 0;
	}
	for(int a=100;a>w;a--)
	{
		if(t!=0)
			s++;
	}
	if(s%n==0)//Ãÿ ‚ 
	{
		cout<<s/n<<" ";
		if((s%n)%2==1)//∆Ê ˝
		{
			cout<<n;
			return 0;
		} 
		else
		{
			if(s/n==1)
				cout<<2;
			else
				cout<<1;
			return 0;
		}
	}
	else
	{
		cout<<s/n+1<<" ";	
		if((s/n+1)%2==1)
		{
			cout<<s%n;
			return 0;
		}
		else
			cout<<n-s%n+1;
	}
	return 0;
}
