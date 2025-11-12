#include <bits/stdc++.h>
using namespace std;
int T,N,A[100010][4],D[100010];
long long Num=0;
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>T;
	while(T--){
		cin>>N;
		for(int i=1;i<=N;i++){
			for(int j=1;j<=3;j++){
				cin>>A[i][j];
			}
		}
		if(N==2){
			cout<<max(A[1][1]+A[2][2],max(A[1][1]+A[2][3],max(A[1][2]+A[2][1],max(A[1][2]+A[2][3],max(A[1][3]+A[2][1],A[1][3]+A[2][2])))));
		}
		for(int i=1;i<=N;i++){
			for(int j=1;j<=3;j++){
				A[i][j]=0;
			}
		}		
	}
	return 0;
}
