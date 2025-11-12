#include<bits/stdc++.h>
using namespace std;
int g[109];
bool cmp(int a,int b){
	if(a>b) return true;
	return false;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n*m;i++){
	    cin>>g[i];
	}
	int a=g[1];
	sort(g+1,g+1+n*m,cmp);
	for(int i=1;i<=n*m;i++){
		if(g[i]==a){
			cout<<ceil(1.0*i/n)<<" ";
			if((int)ceil(1.0*i/n)%2==1){
				if(i%n==0) cout<<n;
				else cout<<i%n;
			}else{
				if(i%n==0) cout<<1;
				else cout<<n+1-i%n;
			}
		}
	}
	return 0;
} 
