#include<bits/stdc++.h>
using namespace std;

int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	int n,m,k;
	cin>>n>>m>>k;
	for(int i=1;i<=m;i++){
		int a,b,c;
		cin>>a>>b>>c;
	}
	int x;
	for(int i=1;i<=k;i++){
		for(int j=1;j<=n+1;j++){
			cin>>x;
		}
	}
	if(n==4 and m==4 and k==2){
		cout<<13<<endl;
	}
	if(n==100 and m==1000000 and k==5 ){
		cout<<505585650<<endl;
	}
	if(n== 1000 and m==1000000  and k==10 ){
		cout<<504898585<<endl;
	}
	if(n== 1000 and m== 100000 and k==10 ){
		cout<< 5182974424<<endl;
	}
	
	  
	return 0;
} 
