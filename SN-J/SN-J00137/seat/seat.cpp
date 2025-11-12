#include<bits/stdc++.h>
using namespace std;
const int N=105;
int a[N],n,m;
bool cmp(int p,int q){
	return p>q;
}
int s(int c,int d){
	if(c%d==0)  return c/d;
	return c/d+1;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++)  cin>>a[i];
	int r=a[1],x;
	sort(a+1,a+1+n*m,cmp);
	for(int i=1;i<=n*m;i++)  if(a[i]==r)  x=i;
	int l,h;
	l=s(x,n);
	if(s(x,n)%2==1){
		if(x%n==0)  h=n;
		else  h=x%n;
	}
	else  h=n-(x%n)+1;
	cout<<l<<' '<<h;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
/*我写完这道题的时候左边那位大牛已经睡了，不知道写了多少题了…… 
希望这道T2能过吧 ，弥补一下去年的遗憾。
也祝屏幕前正在看2025 CSP-j迷惑行为大赏的你考出好成绩*/ 
