//SN-J00787  ÍõìÏÂü 
#include<bits/stdc++.h>
using namespace std;
int n,m,x,wei,c,r;
struct nod{
	int shu,hao;
}a[105];
bool cmp(nod a,nod b)
{
	if(a.shu!=b.shu) return a.shu>b.shu;
	else return a.hao<b.hao;
}
int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout); 
	scanf("%d",&n);
	scanf("%d",&m);
	x=n*m;
	for(int i=1;i<=x;i++){
		scanf("%d",&a[i].shu);
		a[i].hao=i;
	} 
	sort(a+1,a+x+1,cmp);
	for(int i=1;i<=x;i++) if(a[i].hao==1){
		wei=i;
		break;
	}
	if(wei%n==0){
		c=wei/n;
		if((wei/n)%2==0) r=1;
		else r=n;
	}
	else if((wei+1)%n==0)
	{
		c=wei/n+1;
		r=n;
	}
	else{
		c=wei/n+1;
		if(((wei/n)+1)%2==0) r=(n-(wei%n)) ;
		else{
			r=(wei%n);
		}
	}
	printf("%d %d",c,r);
	return 0;
}
/*
2 2
98 100 97 99
3 3
94 95 96 97 98 99 100 93 92
*/
