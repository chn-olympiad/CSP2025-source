#include<bits/stdc++.h>
using namespace std;
int n,m,p,t,c,i,a[105];
bool cmp(int a,int b){
	return a>b;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m>>a[0];
	p=a[0];
	for(i=1;i<n*m;i++){
		cin>>a[i];
	}
	sort(a,a+n*m,cmp);
	for(i=0;i<n*m;i++){
		if(a[i]==p){
			t=i+1;
			break;
		}
	}
	c=t/(2*n)*2;
	if(t%(2*n)==0){
		cout<<c<<" "<<1;
	}
	else if(t%(2*n)>n){
		cout<<c+2<<" "<<2*n+1-t%(2*n);
	}
	else{
		cout<<c+1<<" "<<t%(2*n);
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
