#include<bits/stdc++.h>
using namespace std;
int y(int a,int b,int c,int d,int e){
	
	if(a>b&&a>c&&a>d&&a>e) return a;
	else if(b>c&&b>d&&b>e) return b;
	else if(c>d&&c>e) return c;
	else if(d>e ) return d;
	else return e;
}
int main(){
	freopen("polygon .in","r",stdin);
		freopen("polygon .out","w",stdout);
	int i,j;
	int s;
	int cnt=0,m=0;
	int x=0;
int n;
cin>>n;
int a[10000];
for(i=1;i<=n;i++){
	cin>>a[i];
}
for(j=0;j<=n;j++){
cnt=cnt+a[j];
} 
if(cnt%2!=0){
 
s=cnt/2.0+1;
} else{
s=cnt/2.0; 
} 


for(int i=0;i<=n;i++){

x=y(a[i],a[i+1],a[i+2],a[i+3],0);	
if(a[i]+a[i+1]+a[i+2]+a[i+3]>x*2)
	m++;
	x=y(a[i],a[i+1],a[i+2],0,0);	
if(a[i]+a[i+1]+a[i+2]>x*2)
	m++;

	x=y(a[i],a[i+1],a[i+2],a[i+3],a[i+4]);	
if(a[i]+a[i+1]+a[i+2]+a[i+3]+a[i+4]>x*2)
	m++;


}cout<<m;
	return 0;
}

