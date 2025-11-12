#include<bits/stdc++.h>
using namespace std;
const int N=110;
int n,m,nm,pm,x=1,y=1,a[N],b;
bool cmp(int q,int p){
	return q>p;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	nm=n*m;
	cin>>b,a[1]=b;
	for(int i=2;i<=nm;i++)
		cin>>a[i];
	sort(a+1,a+1+nm,cmp);
	for(int i=2;i<=nm;i++){
		if(a[i]==b){
			pm=i;
			break;
		}
	}
	y=pm/n;
	if(pm%n!=0)
		y+=1;
			
	x=pm%n;
	if(x==0)
		x=n;
	
	if(y%2==0)
		x=n-x+1;
	
	cout<<y<<' '<<x; 
	return 0;
}
