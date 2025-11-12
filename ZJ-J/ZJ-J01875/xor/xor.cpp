#include<iostream>
#include<cstring>
#include<algorithm>
#include<cmath>
using namespace std;
const int N=1e5+5;
long long ans,numlst[N],n,k,dp[N],llst[N],rlst[N],cont=0;
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	dp[0]=0;
	for(int i=1;i<=n;i++){
		cin>>numlst[i];
		dp[i]=numlst[i]^dp[i-1];
	}
	for(int i=1;i<=n;i++){
		for(int j=i;j<=n;j++){
			if((dp[j] ^ dp[i-1])==k){
				llst[cont]=i;
				rlst[cont]=j;
				cont++;
			}
		}
	}
	cout<<cont;
	fclose(stdin);
	fclose(stdout);
}

