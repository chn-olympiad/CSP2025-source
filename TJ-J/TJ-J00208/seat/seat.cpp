#include<bits/stdc++.h>
using namespace std;
int n,m;
int a[110];
bool f=0;
int sum;
bool cmp(int x,int y){
	return x>y;
}
int main(){
	//freopen("seat,in","r",stdin);
	//freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=0;i<n*m;i++){
		cin>>a[i];
		if(i==0)  sum==a[i];
	}
	sort(a,a+n*m,cmp);
	int p;
	for(int i=0;i<n*m;i++){
		if(a[i]==sum){
			p=i;
			break;
		}
	}         
	int h=1;
	int l=1;     
	for(int i=0;i<p;i++){
		h=i/n;
		if(h%2==1){
			l=n-i;
		}
		else{
			l=i%n;
		}
		if(l<0)l=1;
	}                               
	cout<<h+1<<' '<<l;
	return 0;
}
