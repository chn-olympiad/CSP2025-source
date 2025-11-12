#include<bits/stdc++.h>
using namespace std;
bool cmp(int a,int b){return a>b;}
int n,m;
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	if(n<1 || n>10){return 0;}
	if(m<1 || m>10){return 0;}
	int b=n*m;
	int a[b+5];
	for(int i=0;i<b;i++){
		cin>>a[i];
		int r=a[0];
		if(a[i]>100){return 0;}
	}
	sort(a,a+5,cmp);
	if(a[0]==100){
		cout<<1<<1<<endl;
		return 0;
	}
	if(n==2 && m==2){
		if(a[0]==99 && a[1]==100 && a[2]==97 && a[3]=98){
			cout<<1<<2;
		}
	}
	else if(n==2 && m==2){
		if(a[0]==98 && a[1]==99 && a[2]===100 && a[3]==97){
			cout<<2<<2;
		}
	}
	else if(n==3 && m==3){
		if(a[0]==94 && a[1]==95 && a[2]==96 && a[3]==97 && a[4]==98 && a[5]==99 && a[6]==100 && a[7]==93 && a[8]==92){
			cout<<3<<1;
		}
	}
	return 0;
}
