#include<bits/stdc++.h>
using namespace std;
struct stu{
	int k,i;
}v[100000];
bool cmp(stu x,stu y)
{
	return x.k > y.k;
}
int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m;
	cin>>n>>m;
	for (int i = 0;i < n * m;i++)
	{
		cin>>v[i].k;
		v[i].i = i;
	}
//	int l = v[0].k;
//	sort(v,v + n*m,cmp);
	int s = 0;
	for (int i = 1;i < n * m;i++)
	{
		if (v[i].k > v[0].k) s++;
	}
	s++;
//	cout<<s;
	int c = ceil(s / (n * 1.0));
	int r = c % 2 == 1?s - max(0,c - 1) * n:n - (s - max(0,c - 1) * n) + 1;
	cout<<c<<" "<<r;

//	cout<<ceil(s / (n * 1.0));
	return 0;
}

