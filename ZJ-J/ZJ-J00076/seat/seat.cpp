#include<bits/stdc++.h>
using namespace std;
int n,m,lieshu,a[101],c=1;
void px(){
	for(int i=1;i<=n*m-1;i++){
		for(int j=n*m;j>=i+1;j--){
			if(a[j]>a[j-1]){	
				if(j==c)c--;
				else if(j-1==c)c++;
				swap(a[j-1],a[j]);
			}
		}
	}
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++){
		cin>>a[i];
	}
	px();
	int x=ceil(c*1.0/n);
	int y;
	if(x%2==1)y=(c-1)%n+1;
	else y=n-(c-1)%n;
	cout<<x<<" "<<y;
	return 0;
}
