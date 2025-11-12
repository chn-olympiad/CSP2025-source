#include<bits/stdc++.h>
using namespace std;
long long n,m,v,p,q,t,a[50001],sum;
bool cmp(int x,int y){
	return x>y;
}
int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	t=n*m;
	for(int i=1;i<=t;i++)cin>>a[i];
	sum=a[1];
	sort(a+1,a+t+1,cmp);
	p=0;
	q=1;
	v=0;
	for(int i=1;i<=t;i++){
		if(v==0){
			p++;
			if(p>n){
				p=n;
				q++;
				v=1;
			}
		}
		else{
			p--;
			if(p<=0){
				p=1;
				q++;
				v=0;
			}
		}
		if(a[i]==sum)break;
	}
	cout<<q<<' '<<p;
	return 0;
}
