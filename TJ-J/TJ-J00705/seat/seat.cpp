#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m;
	int a[105];
	cin>>m>>n;
	for(int i=0;i<n*m;i++){
		cin>>a[i];
	}
	sort(a+1,a+m*n);
	for(int i=0;i<n*m;i++){
		if(a[1]<a[i]){
			int x=i%(2*m),y=i/n;
			if(x>m) x-=m;
			cout<<x+1<<y+1;
			return 0;
		}
	}
}
