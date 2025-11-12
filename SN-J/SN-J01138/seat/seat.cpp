#include<bits/stdc++.h>
using namespace std;
int n,m,l,k;
struct stu{
	int id;
	int fen;
}a[1005];
bool cmp(stu a,stu b){
	return a.fen>b.fen;
}
int c(int a,int b){
	int sum=0;
	while(a>b){
		a-=b;
		sum++;
	}
	return sum;
}
int mo(int a,int b){
	while(a>b){
		a-=b;
	}
	return a;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++){
		cin>>a[i].fen;
		a[i].id=i;
	}
	sort(a+1,a+n*m+1,cmp);
	for(int i=1;i<=n*m;i++){
		if(a[i].id==1){
			k=i;
			break;
		}
	}
	l=c(k,n)+min(1,mo(k,n));
	cout<<l<<" ";
	if(mo(l,2)==0){
		if(mo(k,n)==0){
			cout<<1;
		}else{
			cout<<n-mo(k,n)+1;	
		}
	}else{	
		if(mo(k,n)==0){
			cout<<n;
		}else{
			cout<<mo(k,n);	
		}
	}
	return 0;
}
