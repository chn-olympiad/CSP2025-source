#include<bits/stdc++.h>
using namespace std;
int n,m,b[101],q=0,w=0;
string a;
int main(){
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>b[i];
	}for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=0;i<n;i++){
		if(a[i]==1){
			q+=1;
		}else{
			w+=1;
		}
	}	for(int i=1;i<=n;i++){
		if(w>b[i]){
			w+=1;
		}
	}
	
	cout<<q%998244353;
	return 0;
}
