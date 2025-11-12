#include<bits/stdc++.h>
#define ll long long 
using namespace std;
ll n ,m ;
ll a[101];
ll s;
ll c,r,x=1,y=1;
bool flag=0;
bool cmp(int a,int b){
	return a>b;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	int p=n*m;
	for(int i=1;i<=p;i++) cin>>a[i];
	s=a[1];
	sort(a+1,a+1+p,cmp);
	
	for(int i=1;i<=p;i++){
		if(s==a[i]){
			c=x;
			r=y;
			break;
		}
		else{
			if(y<n&&flag==0){
				y++;
			}
			else if(y>1&&flag==1){
				y--;
			}
			else if(y==n ||y==1){
				x++;
				flag=!flag;
			}
		}
	} 
	cout<<c<<' '<<r<<endl;
	return 0;
}
