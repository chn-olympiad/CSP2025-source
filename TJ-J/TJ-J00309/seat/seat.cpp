#include<bits/stdc++.h>
using namespace std;
cmp(int c,int b){
	c>b;}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m,x,y;
	int a[10005];
	cin>>n>>m;
	int s=n*m;
	for(int i=1;i<=s;i++){
		cin>>a[i];
	}
	int w=a[1];
	sort(a+1,a+1+s,cmp);
	for(int i=1;i<=s;i++){
		if(a[i]==w){
			if(n>=i){
				x=1;
				y=i;
			}
			else{
				x=i/n;
				if(x%2==1){
					y=i%n;
				}
				else{
					y=n-i%n;
				}
				
			}
		}
	}
	cout<<x<<" "<<y;
	return 0;
}






