#include<bits/stdc++.h>
using namespace std;
int n,m,c,r;
string a;
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	cin>>a;
	int x=a[1];
	sort(a.begin(),a.end());
	for(int i=0;i<m;i++){
		if(x>a[i*n]){
			continue;
		}
		c=i+1;
	}
	for(int i=0;i<n;i++){
		if(x!=a[i*m]){
			continue;
		}
		r=i+1;
	}
	cout<<c<<" "<<r;
	
	return 0;
}
