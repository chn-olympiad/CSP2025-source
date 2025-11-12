#include<bits/stdc++.h>
using namespace std;
const int N=1e5+10;
struct member
{
	int a1;
	int a2;
	int a3;
}a[N];
int a1[N];
int a2[N];
int a3[N];
bool cmp(member A,member B)
{
	return A.a1>B.a1; 
}
bool cmp1(member A,member B)
{
	return A.a2>B.a2; 
}
bool cmp2(member A,member B)
{
	return A.a3>B.a3; 
}
int main()
{
	(stdin,"club.in","r");
	(stdout,"club.out","w");
	int t;
	cin>>t;
	while(t--)
	{
		int n;
		cin>>n;
		int ans=0;
		int m=n/2;
		int p1=m,p2=m,p3=m;
		for(int i=0;i<n;i++) cin>>a[i].a1>>a[i].a2>>a[i].a3;
		sort(a,a+n,cmp);
		ans+=a[i].a1;
		sort(a,a+n,cmp1);
		ans+=a[i].a2;
		sort(a,a+n,cmp2);
		ans+=a[i].a3;
		cout<<ans;	
	}	
} 