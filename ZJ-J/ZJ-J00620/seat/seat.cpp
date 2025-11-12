#include<bits/stdc++.h>
using namespace std;
int m,n,ma;
int na,a[10010],nu;
bool comp(int a1,int a2){
	return a1> a2;
}
int red(){
	char cc=getchar();int x=0;
	while(cc<'0'||cc>'9')cc=getchar();
	while(cc>='0'&&cc<='9'){
		x*=10;x+=cc-'0';cc=getchar();
	}
	return x;
}
int main(){
	freopen("seat.in","r",stdin);freopen("seat.out","w",stdout);
	cin>>n>>m;
	ma=n*m;
	for(int i=1;i<=ma;i++)a[i]=red();
	na=a[1];nu=0;
	sort(a+1,a+ma+1,comp);
	for(int i=1;i<=ma;i++){
		if(a[i]==na){
			nu=i;break;
		}
	}
	int l=ceil(nu/(1.00000000*n));int c=nu%m;
	cout<<l<<' ';
	if(l%2==1){
		if(c==0){
			cout<<n;
		}else{
			cout<<c;
		}
	}else{
		if(c==0){
			cout<<1;
		}else{
			cout<<n-c+1;
		}
	}
	return 0;
}
