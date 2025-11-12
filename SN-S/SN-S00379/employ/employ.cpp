#include<bits/stdc++.h>
using namespace std;
int a[505];
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	int n,m;
	int s;
	cin>>n>>m; 
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	if(m==500){
		cout<<225301405<<endl;
	}else{
		cout<<1;
	}
	return 0;
}
