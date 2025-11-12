#include<bits/stdc++.h>
using namespace std; 
int m[5010];
int n,t=0; 
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>m[i];
	}
	if(n>=3){
		if(m[1]+m[2]+m[3]>max(m[1],max(m[2],m[3]))*2){
			t++;
		}
	} 
	cout<<t;
	return 0;
}
