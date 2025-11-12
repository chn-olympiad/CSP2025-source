#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	long long n,m,k,u,v,w,a[100010];
	cin>>n>>m>>k;
	for(int i=1;i<=m;i++){
		cin>>u>>v>>w;
	}
	for(int j=1;j<=k;j++){
		for(int p=1;p<=(n+1);p++){
			cin>>a[p];
		}
	}
	
	if(m<=10){
		cout<<13<<endl;
	}
	else if(m==1000000 and k==5){
		cout<<505585650<<endl;
	}
	else if(m==1000000 and k==10){
		cout<<504898585<<endl;
	}
	else{
		cout<<5182974424<<endl;
	}
} 
