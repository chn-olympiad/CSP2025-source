#include<bits/stdc++.h>
using namespace std;
int n,m,len,a[1000010],s=1,i;
void sc(int x,int y,int z){
	if(z==s){
		cout<<y<<" "<<x;
		return ;
	}
	if(y%2==1){
		if(x==n) sc(x,y+1,z+1);
		else sc(x+1,y,z+1);
	}
	else{
		if(x==1) sc(x,y+1,z+1);
		else sc(x-1,y,z+1);
	}
	
}
int main(){
	ios::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	len=n*m;
	for(i=1;i<=len;i++){
		cin>>a[i];
		if(a[i]>a[1]) s++;
	}
	sc(1,1,1);
	return 0;
}
