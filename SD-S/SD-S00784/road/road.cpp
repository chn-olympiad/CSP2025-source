#include <iostream>
#include <iomanip> 
#include <algorithm>
#include <cmath>
#include <string>
#include <cstdio>
using namespace std;
long long A[100000][100000],C[100000],U[100000],V[100000],W[100000];
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
    long long n,m,i,j,k;
    cin>>n>>m>>k;
    for(i = 1 ; i <= m ; i++) cin>>U[i]>>V[i]>>W[i];
    for(i = 1 ; i <= k ; i++){
    	cin>>C[i];
    	for(j = 1 ; j <= n ; j++) cin>>A[i][j];
	} 
	cout<<n;   
	fclose(stdin);
	fclose(stdout);
	return 0;
}
