#include <bits/stdc++.h>
using namespace std;
const int N=105;
int n,m,a[N];
bool cmp(int x,int y) {return x>y;}
int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	int p=n*m;
	for(int i=1;i<=p;i++) cin>>a[i];
	int cnt=a[1],bnt=0;
	sort(a+1,a+p+1,cmp);
	for(int i=1;i<=n*m;i++)
	{
		if(a[i]==cnt)
		{
			bnt=i; 
			break;
		}
	}
	int c=0,r=0;
    if(bnt%m==0) c=bnt/(m+1)+1;
    else c=bnt/m+1;
    if(c%2==0) 
    	if(bnt%m==0) r++;
		else r=(m+1)-bnt%m;
    else 
    	if(bnt%m==0) r=((c+1)%2 ? 1 : m);
    	else r=bnt%m;
	cout<<c<<' '<<r;
	return 0;
}
