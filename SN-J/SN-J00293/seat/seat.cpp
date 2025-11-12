#include<bits/stdc++.h>
using namespace std;
int n,m,a[105],s=1;
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++){
		cin>>a[i];
	    for(int j=a[1];j<a[i];s++){
	    	if(s<=n)cout<<"1"<<s;
		}
	}
	return 0;
}
