#include<bits/stdc++.h>
using namespace std;
long long n,m,a[105],s = 1,x,y,b[15][15],c,a_1;
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	cin>>a[1];
	a_1 = a[1];
	for(long long i = 2;i<=n*m;++i){
		cin>>a[i];
		if(a[i]>a[1]){
			s++;
		}
	}
	sort(a,a+n*m+1);
	if(s%n == 0){
		x = s/n;
	}else{
		x = s/n+1;
	}
	for(long long i = 1;i<=m;++i){
		if(i%2 == 0){
			for(long long j = n;j>=1;--j){
				c++;
				b[i][j] = a[m*n-c+1];
				if(b[i][j] == a_1){
					y = j;
					break;
				}
				
			}
		}
		if(i%2 == 1){
			for(long long j = 1;j<=n;++j){
				c++;
				b[i][j] = a[m*n-c+1];
				if(b[i][j] == a_1){
					y = j;
					break;
				}
				
			}
		}
		
	} 
	cout<<x<<" "<<y;
	return 0;
}
