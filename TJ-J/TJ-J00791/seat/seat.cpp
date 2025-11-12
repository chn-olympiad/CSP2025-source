#include <bits/stdc++.h>
using namespace std;
int n,m,a[105][105];
struct Student
{
	int id,sore;
}b[105];
int cmp(Student x,Student y)
{
	if(x.sore==y.sore) return x.id<y.id;
	else return x.sore>y.sore;
}
int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin >> n >> m;
	b[1].id=1;
	cin >> b[1].sore;
	for(int i=2;i<=n*m;i++)
	{
		b[i].id=i;
		cin >> b[i].sore;
	}
	sort(b+2,b+n*m+1,cmp);
	for(int i=2;i<=n*m;i++)
	{
		if(b[1].sore>b[i].sore)
		{
			if((i-1)%n!=0)
			{
				if(((i-1)%n+1)%n!=0)cout << (i-1)/n+1 << " " << (i-1)%n;
				else cout << (i-1)/n+1 << " " << n-(i-1)%n+1;
			}
			else
			{
				if((i-1)/n==1) cout << (i-1)/n << " " << n;
				else if(((i-1)%n+1)%n!=0) cout <<(i-1)/n+1 << " " << n;
				else cout << (i-1)/n+1 << " " << "1"; 
			}
			return 0;
		}
	}
	cout << n << " " << m;
	return 0;
}
