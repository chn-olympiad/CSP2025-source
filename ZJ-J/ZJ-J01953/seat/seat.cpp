#include<bits/stdc++.h>
using namespace std;
int n,m,R,a[101];
bool cmp(int x,int y)
{
	return x>y;
}
int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++)cin>>a[i];
	R=a[1];
	sort(a+1,a+n*m+1,cmp);
	for(int i=1;i<=n*m;i++)
		if(a[i]==R)
			if(i%n==0)
			{
				cout<<i/n<<" ";
				if(i/n%2==0)cout<<1<<endl;
				else cout<<n<<endl;
				break;
			}
			else
			{
				cout<<i/n+1<<" ";
				if((i/n+1)%2==0)cout<<n-i%n+1<<endl;
				else cout<<i%n<<endl;
				break;
			}
	return 0;
}
//#Shang4Shan3Ruo6Shui4