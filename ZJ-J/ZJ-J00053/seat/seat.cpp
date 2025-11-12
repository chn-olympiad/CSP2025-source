#include <bits/stdc++.h>
using namespace std;
const int N=100+10;
int n,m,a[N];
bool cmp(int x,int y){
	return x>y;
}
int main()
{
  	freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++)cin>>a[i];
	int x=a[1],p;
	sort(a+1,a+n*m+1,cmp);
	for(int i=1;i<=n*m;i++)
		if(a[i]==x){p=i;break;}
	int t=p/n,s=p%n;
	if(s)t++;
	else s+=n;
	if(t%2==1)
		cout<<t<<" "<<s;
	else cout<<t<<" "<<n+1-s;
    return 0;
}

