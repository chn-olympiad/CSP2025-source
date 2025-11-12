#include<bits/stdc++.h>
using namespace std;

long long n,m;
long long b[225];
int cmp(int x,int y){
	return x>y;
}
long long a[15][15];
long long ans;
long long bi = 1;
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++){
		cin>>b[i];
	}
	ans = b[1];
	sort(b+1,b+(n*m)+1,cmp);
//	for(int i=1;i<=n*m;i++){
//		cout<<b[i];
//	}

//	cin>>n>>m;

//	for(int i=1;i<=n;i++){
//		for(int j=1;j<=m;j++){
//			
//			a[j][i] =b[i*j]; 
//		}
//		
//	}
	for(int i=1;i<=m;i++){
		if(i%2 ==1){
			for(int j=1;j<=n;j++){
				a[j][i] = b[bi];
				bi++;
			}
		}else{
			for(int j=n;j>=1;j--){
				a[j][i] = b[bi];
				bi++;
			}
		}
		
	}

	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
//			cout<<a[i][j];
			if(a[i][j] == ans){
				cout<<j<<' '<<i;
				break;
			}
		}
//		cout<<endl;
		
	}

	return 0;
} 
