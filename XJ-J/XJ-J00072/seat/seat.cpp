#include<bits/stdc++.h>
using namespace std;
const int maxn=200;
int af[maxn],a[maxn];
int n,m,o=1;
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++){
		cin>>af[i];
	}
	int k=af[1]; 
	sort(af+1,af+n*m+1);
	for(int i=n*m,j=1;i>=1,j<=n*m;i--,j++){
		a[i]=af[j];
	}
	for(int i=1;i<=n;i++){
		if(i%2==1){
			for(int j=1;j<=m;j++){
				if(a[o]==k){
					cout<<i<<" "<<j;
					return 0;
				}
				o++;
			}
		}else if(i%2==0){
			for(int j=m;j>=1;j--){
				if(a[o]==k){
					cout<<i<<" "<<j;
					return 0;
				}
				o++;
			}
	    }
	}
	return 0;
}


