#include<bits/stdc++.h>;
using namespace std;
int n,k,x;
string a[1001],f[1001][1001];
int d[1001][1001];
string er(int a){
	char b[1001];
	int k=-1;
	while(a){
		k++;
		if(a%2==1) b[k]='1';
		else b[k]='0';
		a/=2;
	}
	char b1[1001];
	for(int i=0;i<=k;i++){
		b1[i]=b[k-i];
	}
	return b1;
}
string p(string a,string b){
	int L1=a.size(),L2=b.size();
	int lmax=max(L1,L2);
	string a1, b1;
	for(int i=0;i<L1;i++){
		a1[i]=a[L1-i-1];
	}
	for(int i=0;i<L2;i++){
		b1[i]=b[L2-i-1];
	}
	string c;
	for(int i=0;i<lmax;i++){
		if(a1[i]==b1[i]) c[i]='0';
		else c[i]='1';
	}
	char c1[1001];
	for(int i=0;i<lmax;i++){
		c1[i]=c[lmax-i-1];
	}
	char c2[1001];
	int sum0=0;
	for(int i=0;i<lmax;i++){
		if(c1[i]=='0'){
			sum0++;
		}else{
			break;
		}
	}
	for(int i=0;i<lmax-sum0;i++){
		c2[i]=c1[i+sum0];
	}
	return c2;
}
int dp[1001][1001];
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	scanf("%d%d",&n,&k);
	for(int i=1;i<=n;i++){
		cin>>x;
		a[i]=er(x);
	}
	string K=er(k);
	for(int i=1;i<=n;i++){
		for(int j=i;j<=n;j++){
			f[i][j]=p(f[i][j-1],a[j]);
			if(f[i][j]==K){
				d[i][j]=1;
			}
		}
	}
	for(int i=1;i<=n;i++){
		for(int j=i;j<=n;j++){
			dp[i][j]=max(dp[i][j],dp[i][j-1]+d[i][j]);
		}
	}
	if(k==0){
		int num=0;
		for(int i=1;i<=n;i++){
			num*=i;
		}
		cout<<num;
		return 0;
	}
	cout<<dp[n][n];
	
	return 0;
} 
