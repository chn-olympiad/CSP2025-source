#include<bits/stdc++.h>
using namespace std;
int n,m,rs,x,bao,lie,hang,a[1005];
bool cmp(int a,int b){
	return a>b;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w".stdout);
	cin>>n>>m;rs=n*m;
	for(int i=1;i<=rs;i++)cin>>a[i];
	x=a[1];
	sort(a+1,a+1+rs,cmp);
	for(int i=1;i<=rs;i++)
		if(a[i]==x){bao=i;break;}
	lie=bao/n;
	if(bao%n!=0)lie++;
	bao=bao%n;
	if(bao==0){
		if(lie%2==0)hang=1;
		else hang=n;
	}
	else{
		if(lie%2==0)hang=n-bao+1;
		else hang=bao;
	}
	cout<<lie<<" "<<hang;
	return 0;
}

