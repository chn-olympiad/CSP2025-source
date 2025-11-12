#include<iostream>
#include<algorithm>
using namespace std;
const int N=5005,M=N*2,Mod=998244353;
int A[N],F[N*N],Sub[N*N];
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int n,Sum=0,Ans=0;
	cin>>n;
	for(int i=1;i<=n;i++)
		cin>>A[i];
	sort(A+1,A+1+n);
	for(int i=1;i<n;i++){
		for(int j=M;j>=0;j--){
			if(j>=A[i])
				F[j]+=F[j-A[i]],F[j]%=Mod;
			else
				F[j]+=F[0]+1,F[j]%=Mod;
		}
		if(i<2)	continue;
		Ans+=F[A[i+1]],Ans%=Mod;
	}
	cout<<Ans<<endl;
	return 0;
}
