#include<iostream>
using namespace std;
const int N=1e3+5;
int n,K,f[N][N];
int a[N],S[N];

int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>K;
	for(int i=1;i<=n;i++)
	    cin>>a[i],S[i]=S[i-1]^a[i];
	for(int i=1;i<=n;i++){
		f[i][i]=(a[i]==K?1:0);
	}
	for(int cd=2;cd<=n;cd++){
		for(int l=1;l<=n-cd+1;l++){
			int r=l+cd-1;
			f[l][r]=((S[r]^S[l-1])==K?1:0);
			for(int kk=l;kk<=r-1;kk++){
				f[l][r]=max(f[l][r],f[l][kk]+f[kk+1][r]);
			}
		}
	}
	cout<<f[1][n];
	return 0;
}
