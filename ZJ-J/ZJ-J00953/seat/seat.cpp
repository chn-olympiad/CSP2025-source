#include<bits/stdc++.h>
using namespace std;
int n,m,len,r,R,x,y;
int a[105];
bool cmp(int s,int t){
	return s>t;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	len=n*m;
	for(int i=1;i<=len;i++){
		cin>>a[i];
	}r=a[1];
	sort(a+1,a+len+1,cmp);
	for(int i=1;i<=len;i++){
		if(a[i]==r){
			R=i;
			break;
		}
	}x=R/n+(R%n>0);
	if(x%2){
		y=(R-1)%n+1;
	}else{
		y=n-(R-1)%n;
	}cout<<x<<" "<<y;
	return 0;
}
