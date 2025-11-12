#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=1e5+6;
struct node{
	int st,nd,rd,mx,id,cd;
}a[N];
int n;
ll read()
{
	ll num=0,f=1;
	char c;
	c=getchar();
	while (c<'0'||c>'9')
	{
		if (c=='-')
		{
			f=-1;
		}
		c=getchar();
	}
	while (c>='0'&&c<='9')
	{
		num=num*10+(c-'0');
		c=getchar();
	}
	return num*f;
}
void write(ll h)
{
	if (h>9)
	{
		write(h/10);
		putchar(h%10+'0');
	}
	else
	{
		putchar(h+'0');
	}
	return ;
}
bool cmp1(node x,node y){
	if(x.mx-x.cd!=y.mx-y.cd)
	return x.mx-x.cd>y.mx-y.cd;
	else 
	return x.mx>y.mx;
}
int main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int t;
	t=read();
	int sum=0;
	int c[5]={0};
	while(t--){
		sum=0,c[1]=0,c[2]=0,c[3]=0;
		n=read();
		for(int i=1;i<=n;i++){
			cin>>a[i].st>>a[i].nd>>a[i].rd;
			a[i].mx=max({a[i].st,a[i].nd,a[i].rd});
			if(a[i].mx==a[i].st) a[i].id=1;
			else if(a[i].mx==a[i].nd) a[i].id=2;
			else if(a[i].mx==a[i].rd) a[i].id=3;
			if(a[i].id==1){
				a[i].cd=max(a[i].nd,a[i].rd);
			}
			if(a[i].id==2){
				a[i].cd=max(a[i].st,a[i].rd);
			}
			if(a[i].id==3){
				a[i].cd=max(a[i].nd,a[i].st);
			}
		}
		sort(a+1,a+n+1,cmp1);
		for(int i=1;i<=n;i++){
			if(c[a[i].id]<(n/2)){
				sum+=a[i].mx;
				c[a[i].id]++;
			}
			else{
				if(a[i].id==1){
					if(c[2]>=(n/2)){
						sum+=a[i].rd;
						c[a[i].id]++;
						continue;
					}
					if(c[3]>=(n/2)){
						sum+=a[i].nd;
						c[a[i].id]++;
						continue;
					}
					else{
						sum+=a[i].cd;
						c[a[i].rd>a[i].nd?3:2]++;
						continue;
					}
				}
				if(a[i].id==1){
					if(c[1]>=(n/2)){
						sum+=a[i].rd;
						c[a[i].id]++;
						continue;
					}
					if(c[3]>=(n/2)){
						sum+=a[i].st;
						c[a[i].id]++;
						continue;
					}
					else{
						sum+=a[i].cd;
						c[a[i].st>a[i].rd?1:3]++;
						continue;
					}
				}
				if(a[i].id==3){
					if(c[1]>=(n/2)){
						sum+=a[i].nd;
						c[2]++;
						continue;
					}
					if(c[2]>=(n/2)){
						sum+=a[i].st;
						c[1]++;
						continue;
					}
					else{
						sum+=a[i].cd;
						c[a[i].st>a[i].nd?1:2]++;
						continue;
					}
				}
			}
		}
		write(sum);
		printf("\n");
	}
	return 0;
}

