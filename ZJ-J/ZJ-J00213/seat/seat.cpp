#include <bits/stdc++.h>
using namespace std;
int n,m,a[105],r,pos,o,p;
bool cmp(int a,int b){return a>b;}
int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++){cin>>a[i];}
	if (n==1&&m==1){
		cout<<1<<" "<<1;
		return 0;
	}
	r=a[1];
	sort(a+1,a+n*m+1,cmp);
	for(int i=1;i<=n*m;i++){
		if (a[i]==r){
			pos=i;
			break;
		}
	}
	if (pos%n==0) {o=pos/n;}
	else{o=pos/n+1;}
	if (o==1){p=pos;}
	else if (o%2==0){
		if (pos%n==0){p=n-(pos-((pos/n-1)*n+1));}
		else{p=n-(pos-(pos/n*n+1));}
	}
	else{
		if (pos%n==0){p=pos-((pos/n-1)*n);}
		else{p=pos-(pos/n*n);}
	}
	cout<<o<<" "<<p;
	return 0;
}
