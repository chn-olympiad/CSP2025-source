#include<bits/stdc++.h>
using namespace std;
int n,m,c[105],x,wd,wc,num=0,xs,p=0;
int main(){
freopen("seat.in","r",stdin);
freopen("seat.out","w",stdout);
bool flag=0;
cin>>n>>m;
x=n*m;
for(int i=1;i<=x;i++){
	cin>>c[i];
	if(i==1){
		wd=c[i];
	}
}
sort(c+1,c+x+1);
for(int i=x;i>=1;i--){
	p++;
	if(wd==c[i]){
		wc=p;
	}
}
for(int i=1;i<=m;i++){
   for(int j=1;j<=n;j++){
   	   num++; 
   	   if(i%2==0){
   	   	  xs=m+1-j;
		}else if(i%2!=0){
			xs=j;
		}
		if(num==wc){
			cout<<i<<" "<<xs;
			flag=1;
			break;
		}
   }
   	if(flag==1){
   		break;
	   }
}
return 0;
}
