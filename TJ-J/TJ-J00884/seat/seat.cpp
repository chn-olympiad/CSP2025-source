#include<bits/stdc++.h>
using namespace std;
int x[200],a[200],b[20][20];
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m;
	cin>>n>>m;
	int ts=0;
	for(int i=1;i<=n*m;i++){
		cin>>x[i];
		if(i==1){
			ts=x[i];
		}
	}
	sort(x+1,x+1+n*m);
	int k=1;
	for(int i=n*m;i>=1;i--){
		a[k]=x[i];
		k++;
	}
	int lie=0;
	for(int i=1;i<=m;i++){
		if(i%2==1){
			for(int j=1;j<=n;j++){
				lie++;
				b[j][i]=a[lie];
				if(b[j][i]==ts){
					cout<<i<<' '<<j;
					return 0;	
				}
			}
		}
		else{
			for(int j=n;j>=1;j--){
				lie++;
				b[j][i]=a[lie];
				if(b[j][i]==ts){
					cout<<i<<' '<<j;
					return 0;	
				}
			}
		}
	}
	return 0;
} 
