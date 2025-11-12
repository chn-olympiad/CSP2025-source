#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	int n;
	cin>>n;
	int t[5005];
	for(int i=1;i<=n;i++){
		cin>>t[i];
	}
	if(t[1]+t[2]>t[3]&&t[1]+t[3]>t[2]&&t[3]+t[2]>=t[1]) cout<<1;
	else cout<<0;
	return 0;
} 
