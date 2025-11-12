#include<bits/stdc++.h> 
using namespace std;
int m,n,num,zuo;
int a[111],b[111];
bool cmp(int a,int b){
	return a>b;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=m*n;i++){
		cin>>a[i];
		b[i]=a[i];
	}sort(b+1,b+n*m+1,cmp);
	for(int i=1;i<=m*n;i++){
		if(b[i]==a[1]){
			num=i;
			break;
		}
	}
	int m1=(num-1)/n+1,n1=0;
	if(m1%2==1){
		n1=num%n;
		if(n1==0) n1=n;
	}else{
		n1=n+1-num%n;
	}cout<<m1<<' '<<n1;
	return 0;
}
