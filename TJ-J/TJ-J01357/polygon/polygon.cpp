#include<bits/stdc++.h>
using namespace std;
int a,b[5];
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>a;
	cin>>b[1]>>b[2]>>b[3];	
	if(a<=2){
		cout<<0;
		return 0;
	}
	sort(b+1,b+4,greater<int>());
	if(b[1]*2<b[1]+b[2]+b[3]) cout<<1;
	else cout<<0;
	return 0;
} 
