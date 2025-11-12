#include<bits/stdc++.h>
using namespace std;
const int N=1e5+10;
struct node{int ly,yx,wz;}a[N];
int T,n,ans=-1; 
void dfs(int step,int i,int j,int k,int sum)
{
	if(step==n+1) {
		ans=max(ans,sum);
		return;
	}
	if(i<n/2) dfs(step+1,i+1,j,k,sum+a[step].ly);
	if(j<n/2) dfs(step+1,i,j+1,k,sum+a[step].yx);
	if(k<n/2) dfs(step+1,i,j,k+1,sum+a[step].wz); 
}
void work1()
{
	ans=-1;
	dfs(1,0,0,0,0);
	cout<<ans<<'\n';
}
bool cmp(node x,node y)
{
	return x.ly-x.yx>y.ly-y.yx;
}
bool cmd(node x,node y)
{
	return x.ly>y.ly;
}
void work0()
{
	sort(a+1,a+n+1,cmp);
	ans=0;
	for(int i=1;i<=n/2;i++)
	ans+=a[i].ly;
	for(int i=n/2+1;i<=n;i++)
	ans+=a[i].yx;
	cout<<ans<<'\n';
}
void work00()
{
	sort(a+1,a+n+1,cmd);
	ans=0;
	for(int i=1;i<=n/2;i++)
	ans+=a[i].ly;
	cout<<ans<<'\n';
}
bool twz1(node x,node y)
{
	return x.ly-max(x.yx,x.wz)>y.ly-max(y.yx,y.wz);
}
bool twz2(node x,node y)
{
	return x.yx-max(x.ly,x.wz)>y.yx-max(y.ly,y.wz);
}
bool twz3(node x,node y)
{
	return x.wz-max(x.ly,x.yx)>y.wz-max(y.ly,y.yx);
}
int main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>T;
	while(T--)
	{
		int flag=0,flag1=0,res1=0,res2=0,res3=0;
		cin>>n;
		for(int i=1;i<=n;i++)
		{
			cin>>a[i].ly>>a[i].yx>>a[i].wz;
			if(a[i].ly>=a[i].yx&&a[i].ly>=a[i].wz) res1++;
			else if(a[i].yx>=a[i].ly&&a[i].yx>=a[i].wz) res2++;
			else res3++;
			if(a[i].wz) flag=1;
			if(a[i].yx||a[i].wz) flag1=1;
		}
		if(!flag1) {
			work00();
			continue;
		}
		if(!flag) {
			work0();
			continue;
		}
		if(n<=10) {
			work1();
			continue;
		}
		ans=0;
		if(res1>n/2) {
			sort(a+1,a+n+1,twz1);
			for(int i=1;i<=n/2;i++)
			ans+=a[i].ly;
			for(int i=n/2+1;i<=n;i++)
			ans+=max(a[i].yx,a[i].wz);
			cout<<ans<<'\n';
			continue;
		}
		else if(res2>n/2) {
			sort(a+1,a+n+1,twz2);
			for(int i=1;i<=n/2;i++)
			ans+=a[i].yx;
			for(int i=n/2+1;i<=n;i++)
			ans+=max(a[i].ly,a[i].wz);
			cout<<ans<<'\n';
			continue;
		}
		else if(res3>n/2) {
			sort(a+1,a+n+1,twz3);
			for(int i=1;i<=n/2;i++)
			ans+=a[i].wz;
			for(int i=n/2+1;i<=n;i++)
			ans+=max(a[i].ly,a[i].yx); 
			cout<<ans<<'\n';
			continue;
		}
		else {
			for(int i=1;i<=n;i++)
			ans+=max(a[i].yx,max(a[i].ly,a[i].wz));
			cout<<ans<<'\n';
			continue;
		}
	}
	return 0;
 } 
 /*
Ren5Jie4Di4Ling5%
 */
 /*
 3
 4
 4 2 1
 3 2 4
 5 3 4
 3 5 1
 4
 0 1 0
 0 1 0
 0 2 0
 0 2 0
 2
 10 9 8
 4 0 0
 */
