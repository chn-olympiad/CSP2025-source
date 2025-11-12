#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	int n;
	int g[10001];
	cin>>n;
	for(int i=0;i<n;i++){
		cin>>g[i];
	}
	if(n==3 and (g[0]+g[1]+g[2])>max(max(g[0],g[1]),g[2])*2){
		cout<<1;
	}
	else{
		cout<<0;
	}
	return 0;
}
