#include<bits/stdc++.h>
using namespace std;

struct exam{
	int grade;
	int mine;
}a[105];
bool cmp(exam a,exam b)
{
	return a.grade>b.grade;
}
int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m;
	cin>>n>>m;
	if(n==0||m==0)
	{
		cout<<"0 0"<<endl;
		return 0;
	}
	for(int i=1;i<=n*m;i++)
	{
		cin>>a[i].grade;
		a[1].mine=1;
	}
	sort(a+1,a+1+n*m,cmp);
	int i=0;
	for(i+1;i<=n*m;i++)
	{
		if(a[i].mine==1) break;
	}
	int yu=i%n;
	int lie=0;
	if(yu==0)
		lie=i/n;
	else
		lie=i/n+1;
	int hang=0;
	if(yu!=0)
	{
		if(lie%2==0) hang=n-yu+1;
		else hang=yu;
	}
	if(yu==0)
	{
		if(lie%2==0) hang=1;
		else hang=n;
	}
	cout<<lie<<" "<<hang<<endl;
	return 0;
}
