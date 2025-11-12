//于硕-SN-J00019-西安滨河学校 
#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("mumber.in","r",stdin);
	freopen("mumber.out","w",stdout);
	int n,m,b[11*11],a[11*11],w[15][15],e,u=1;
	cin>>n>>m;
	for(int i=1;i<=n*m;i++){
			cin>>b[i];
	}
	int x=b[1];
	sort(b+1,b+n*m+1);
	for(int i=n*m;i>=1;i--){
		a[u]=b[i];
		u++;
	}
	for(int i=1;i<=n*m;i++){
		if(a[i]==x){
			e=i;
		}
	}
	int t;//lie
	if(e<m){
		t=1;
	}else{
		if(e%m==0){
			t=e/m;
		}else{
			t=e/m+1;
		}
	}
	if(e%m==0){
		if(t%2==0){
			w[t][1]=a[e];
		}else{
			w[t][n]=a[e];
		}
	}else{
		if(t%2==0){
			w[t][n-e%m+1]=a[e];
		}else if(t%2!=0){
			w[t][e%m]=a[e];
		}
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			if(w[i][j]==x){
				cout<<i<<" "<<j;
			}
		}
	}
	return 0;
}
