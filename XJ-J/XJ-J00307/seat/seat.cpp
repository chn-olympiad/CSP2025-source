#include<bits/stdc++.h>
using namespace std;
int n,m,k=1;
int a[101][101];
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	int s[n*m],c[n*m];
	for(int i=1;i<=n*m;i++){
		cin>>s[i];
	} 
	c[1]=s[1];
	for(int i=1;i<=n*m;i++){
		for(int j=i+1;j<=n*m;j++){
			if(s[i]<s[j]){
				swap(s[i],s[j]);
			}
			
		}
	}
	for(int i=1;i<=n*m;i++){
		if(s[i]==c[1]){
			if(m==2||i%m==0){
				cout<<(i/m)<<" "<<m;
			}
			else{
				cout<<(i/m)+1<<" "<<i-((i/m)*m);
			}
			
		}
	}
} 

