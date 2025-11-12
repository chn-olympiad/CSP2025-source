#include<bits/stdc++.h>
using namespace std;
int n,m;
bool cmp(int a,int b){
	return a>b;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	int a[n*m+10],b;
	int x,y;
	for(int c=1;c<=n*m;c++){
		cin>>a[c];
	}
	b=a[1];
	sort(a+1,a+n*m+1,cmp);
	int i;
	for(i=1;i<=m;i++){
		for(int j=1;j<=n;j++){
			if(a[(i-1)*n+j]==b){
				if(i%2==1){
					x=i;
					y=j;
				}
				else{
					x=i;
					y=n-j+1;
				}
			}
		}
		
	}
	cout<<x<<' '<<y;
}
