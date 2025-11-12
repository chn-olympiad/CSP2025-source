#include<bits/stdc++.h>
using namespace std;
const int N=15;
int n,m;
struct student{
	int s,t;
}a[N*N];
bool cmp(student x,student y){
	return (x.s>y.s);
}
int main(){
	freopen("seat.in","r",stdin);freopen("seat.out","w",stdout);
	cin>>n>>m;
	for (int i=1;i<=n*m;i++)
		cin>>a[i].s,a[i].t=i;
	sort(a+1,a+1+n*m,cmp);
	for (int i=1;i<=n*m;i++)
		if (a[i].t==1){
			if ((i/n+1)%2==0)
				cout<<i%n+1<<' ';
			else
				cout<<m-(i%n)<<' ';
			cout<<i/n+1;
			break;
		}
	return 0;
}
