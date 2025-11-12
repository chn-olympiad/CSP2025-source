#include<bits/stdc++.h>
using namespace std;
int a,b,c;
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>a>>b>>c;
	c=0;
	for(int i=1;i<=b;i++){
		cin>>a>>a>>a;
		c+=a;
	}
	cout<<c;
	return 0;
}