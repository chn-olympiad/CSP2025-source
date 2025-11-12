#include<bits/stdc++.h>
using namespace std;
int n,m,mp[101][101],sp[1001],l,p,y;
bool cmp(int rt,int kt)
{
	return rt>kt;
}
int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	l=n*m;
	for(int i=1;i<=l;i++)
	{
		cin>>sp[i];
	}
	p=sp[1];
	sort(sp+1,sp+l+1,cmp);
	for(int i=1;i<=l;i++)if(sp[i]==p)y=i;
	int r=(y+n-1)/n;
	cout<<r;
	if(r%2==1)
	{
		cout<<" "<<(y-1)%n+1;
	}
	else
	{
		int w=(y-1)%n+1;
		cout<<" "<<n-w+1;	
	}
	return 0;
}//#Shang4Shan3Ruo6Shui4
