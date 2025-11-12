#include<bits/stdc++.h>
using namespace std;
int cmp(int x,int y){
	return x>y;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
long long n,m,a[105],d;
cin>>n>>m;
long long w=n*m;
for(int i=1;i<=w;i++){
	cin>>a[i]; 
}
long long c=a[1];
sort(a+1,a+w+1,cmp);
for(int i=1;i<=w;i++){
	if(c==a[i]){
		d=i;
	}
}

long long f=d/n,e=d%n;
if(f==0){
	cout<<1<<" "<<d; 
}else{
	if(e==0){
		if(f%2!=0){
			cout<<f<<" "<<n;
		}else{
			cout<<f<<" "<<1;
		}
	}else{
		if(f%2!=0){
			cout<<f+1<<" "<<n-e+1;
		}else{
			cout<<f+1<<" "<<e;
		}
	}
}

	return 0;
} 
