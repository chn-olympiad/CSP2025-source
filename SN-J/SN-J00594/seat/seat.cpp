//姓名：杜悦菲
//考号：SN-J00594
//学校：西安市曲江第一学校 

#include<bits/stdc++.h>
using namespace std;
int a[10010];
bool f(int a,int b){
	return a>b;
}
void sol(int nn,int loc){
	int c,r;
	if(loc%nn==0){
		c=loc/nn;
	}else{
		c=loc/nn+1;
	}
	if(c%2==1){
		r=loc-(c-1)*nn;
	}else{
		r=nn+1-loc+(c-1)*nn;
	}
	cout<<c<<" "<<r;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m;
	cin>>n>>m;
	int seatsize=n*m;
	for(int i=1;i<=seatsize;i++){
		cin>>a[i];
	}
	int ts=a[1];
	sort(a+1,a+seatsize+1,f);
	for(int i=1;i<=seatsize;i++){
		if(a[i]==ts){
			sol(n,i);
			return 0;
		}
	}
}
