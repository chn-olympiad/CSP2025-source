#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int a[105];
bool cmp(int a,int b)
{
	return a>b;
}
int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m;
	scanf("%d%d",&n,&m);
	int r;
	scanf("%d",&r);
	for(int i=1;i<n*m;i++)
		scanf("%d",&a[i]);
	sort(a+1,a+n+1,cmp);
	int now=0;
	for(int i=1<<7;i;i>>=1)
		if(now+i<=n*m&&a[now+i]>r)
			now+=i;
	now++;
	int h=(now%n==0)?(now/n):(now/n+1);
	int nqn=(now%n==0)?n:(now%n);
	printf("%d %d",h,(h%2==0)?(n-nqn+1):nqn);
	return 0;
}

