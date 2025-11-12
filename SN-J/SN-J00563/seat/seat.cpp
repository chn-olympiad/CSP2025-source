#include<bits/stdc++.h>
using namespace std;
bool cmp(int a,int b){
	return a>b;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m,ri,mind;
	int a[101]={0};
	cin>>n>>m;
	ri=m*n;
	for(int i=1;i<=ri;i++){
		cin>>a[i];
	}
	int xr=a[1];
	sort(a+1,a+ri+1,cmp);
	for(int i=1;i<=ri;i++){
		if(a[i]==xr){
			mind=i;
			break;
		}
	}
	int c,r,b,d;
	b=mind/(2*n)*2;
	d=mind%(2*n);
	if(d==0){
		d=1;
	}else if(d>n){
		b+=2;
		d=n-(d-n)+1;
	}else{
		b+=1;
	}
	cout<<b<<" "<<d;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
