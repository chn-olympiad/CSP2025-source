//SN-J00110 刘思辰 西安高新一中沣东中学初中校区 
#include<bits/stdc++.h> 
using namespace std;
int f(int);
int f(int n)
{
	if(n==1) return 1;
	else return f(n-1)*n;
}
int main()
{
	freopen("polygon.in","r",stdin)
	freopen("polygon.out","w",stdout)
	int n,a[5001],t;
	cin>>n;
	for(int i=1;i<=n;i++) cin>>a[i];
	 for(int i=3;i<=n;i++)  t+=f(n)/(f(i)+f(n-i));
	 cout<<a;
}
