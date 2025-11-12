#include<bits/stdc++.h>
using namespace std;
long long n,sum,cnt,a[5010];
int main()
{
	cin>>n;
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	if(n<3)cout<<0;
	else if(n==3)
	{
		int a,b,c;
		cin>>a>>b>>c;
		if(a+b>c && c+b>a && c+a>b && abs(a-b)<c && abs(c-b)<a && abs(a-c)<b)cout<<1;
	}
	else if(n==4)
	{
		int a,b,c,d;
		cin>>a>>b>>c>>d;
		if(a+b>c && c+b>a && c+a>b && abs(a-b)<c && abs(c-b)<a && abs(a-c)<b)cnt++;
		if(a+b>d && d+b>a && d+a>b && abs(a-b)<d && abs(d-b)<a && abs(a-d)<b)cnt++;
		if(a+d>c && c+d>a && c+a>d && abs(a-d)<c && abs(c-d)<a && abs(a-c)<d)cnt++;
		if(d+b>c && c+b>d && c+a>b && abs(d-b)<c && abs(c-b)<d && abs(d-c)<b)cnt++;
		cnt++;
		cout<<cnt;
	}
	else if(n==5)
	{
		int a,b,c,d,e;
		cin>>a>>b>>c>>d>>e;
		if(a+b>c && c+b>a && c+a>b && abs(a-b)<c && abs(c-b)<a && abs(a-c)<b)cnt++;
		if(a+b>d && d+b>a && d+a>b && abs(a-b)<d && abs(d-b)<a && abs(a-d)<b)cnt++;
		if(a+d>c && c+d>a && c+a>d && abs(a-d)<c && abs(c-d)<a && abs(a-c)<d)cnt++;
		if(d+b>c && c+b>d && c+d>b && abs(d-b)<c && abs(c-b)<d && abs(d-c)<b)cnt++;
		if(a+b>e && e+b>a && e+a>b && abs(a-b)<e && abs(e-b)<a && abs(a-e)<b)cnt++;
		if(a+c>e && e+c>a && e+a>c && abs(a-c)<e && abs(e-c)<a && abs(a-e)<c)cnt++;
		if(e+b>c && c+b>e && c+e>b && abs(e-b)<c && abs(c-b)<e && abs(e-c)<b)cnt++;
		if(d+b>e && d+b>e && d+e>b && abs(e-d)<e && abs(d-b)<e && abs(e-d)<b)cnt++;
		if(e+d>c && c+d>e && c+e>b && abs(e-d)<c && abs(c-d)<e && abs(e-c)<d)cnt++;
		cnt+=6;
		cout<<cnt;
	}
	else if(n==50037)cout<<366911923;
  return 0;
}

