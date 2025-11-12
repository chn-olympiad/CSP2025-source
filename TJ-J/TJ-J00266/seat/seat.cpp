#include<bits/stdc++.h>
using namespace std;

long long a[15][15];
long long b[105];
long long l,ind=1,n,m;
bool f,f2;

int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++){
		cin>>b[i];
	}
	l=b[1]; 
	sort(b+1,b+n*m+1);
	reverse(b+1,b+n*m+1);
	f=0;
	for(int i=1;i<=m;i++){
		f=!f;
		if(f){
			for(int j=1;j<=m;j++){
				a[j][i]=b[ind];
				ind++;
			}
		}
		else{
			for(int j=m;j>=1;j--){
				a[j][i]=b[ind];
				ind++;
			}
		}
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			if(a[i][j]==l){
				cout<<j<<' '<<i;
				f2=1;
				break;
			}
		}
		if(f2) break;
	}
	return 0;
}
