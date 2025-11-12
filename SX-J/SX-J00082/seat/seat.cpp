#include<bits/stdc++.h>
using namespace std;
int main(){
freopen("seat.in","r",stdin);
freopen("seat.out","w",stdout);

int n,m,y=1;
cin>>n>>m;
int x;
x=n*m;
int a[x];
for(int i=0;i<x;i++){
cin>>a[i];
}
for(int num=1;num<x;num++){
	if(a[0]<a[num]){
		y++;
	}
}
if(y%n==0){
cout<<y/n<<" ";
if(y/n%2==0){
    cout<<1;
}
else{
cout<<n;
}
}
else{
cout<<y/n+1<<" ";
if(y/n%2==0){
    cout<<y%n;
}
else{
cout<<m-y%n+1;
}
}


fclose(stdin);
fclose(stdout);
return 0;
}