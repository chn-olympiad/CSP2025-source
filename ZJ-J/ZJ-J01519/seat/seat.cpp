#include<bits/stdc++.h>
using namespace std;
const int N=105;
int a[N*N];
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n*m;i++)cin>>a[i];
	int k=a[1];
	sort(a+1,a+n*m+1);
	int ii=1,jj=1;
	for(int i=n*m;i>=1;i--){
		if(a[i]==k)break;
		if(jj%2==1){
			if(ii==n){
				jj++;
			}
			else ii++;
		}
		else{
			if(ii==1){
				jj++;
			}
			else ii--;
		}
	}
	cout<<jj<<" "<<ii;
	return 0;
}
