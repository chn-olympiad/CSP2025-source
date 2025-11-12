#include<bits/stdc++.h>
using namespace std;
int num[10][10];
int c[100];
int n,m,a,a1,b,d,n1,m1;
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for (int i=1;i<=n*m;i++){
		cin>>a;
		if(i==1){
			a1=a;
		}
		c[i]=a;
	}
	for (int i=1;i<=n*m;i++){
		int ma=0,p;
		for(int j=i;j<=n*m;j++){
			if(c[j]>ma){
				ma=c[j];
				p=j;
			}
		}
		c[p]=c[i];
		c[i]=ma;
	}
	for(int i=1;i<=n*m;i++){
		if(c[i]==a1){
			break;
		}
		d+=1;
	}
	m1=d/n+1;
	if(m1%2==0){
		n1=n-d%n;	
	} 
	else{
		n1=d%n+1;
	}
	cout<<m1<<" "<<n1;
	return 0;
}
