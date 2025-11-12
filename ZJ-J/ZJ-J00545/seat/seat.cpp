#include<bits/stdc++.h>
using namespace std;
int m,n,a[105],s,jl;
int v[15][15];
bool cmp(int aa,int aaa){
	return aa>aaa;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	
	cin>>m>>n;
	for(int i=1;i<=m*n;i++)cin>>a[i];
	s=a[1];
	sort(a+1,a+1+n*m,cmp);
	
	
	for(int i=1;i<=n;i++){
		if(i%2==1){
			
			for(int j=1;j<=m;j++){
				jl++;
				if(a[jl]==s){
					cout<<i<<" "<<j;
					return 0;
				}
//				v[j][i]=a[jl];
			}
			
		}
		else{
			
			for(int j=m;j>=1;j--){
				jl++;
				if(a[jl]==s){
					cout<<i<<" "<<j;
					return 0;
				}
//				v[j][i]=a[jl];
			}
			
		}
	}
	
//	for(int i=1;i<=m;i++){
//		for(int j=1;j<=n;j++)cout<<v[i][j]<<" ";
//		cout<<'\n';
//	}
	return 0;
}