#include<bits/stdc++.h> 
using namespace std;
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	int n,m;
	cin>>n>>m;
	int t=n*m;
	int b[t];
	int sb;
	cin>>sb;
	for(int i=2;i<=t;i++){
		cin>>b[i];
	}
	b[1]=sb;
	sort(b+1,b+1+n);
	int a[t];
	for(int i=1;i<=t;i++){
		a[t-i+1]=b[i];
	}
	for(int i=1;i<=m;i++){
		if(i%2==1){
			for(int j=1;j<=n;j++){
				if(a[i]==sb){
					cout<<i<<" "<<j;
					return 0;
				}
			}
		}
		if(i%2==0){
			for(int j=n;j>=1;j--){
				if(a[i]==sb){
					cout<<j<<" "<<i;
					return 0;
				}
			}
		}
	} 
	return 0;
}
