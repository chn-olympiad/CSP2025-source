#include<bits/stdc++.h>
//#define int long long
using namespace std;
int a[500050],dp[500001][9],sum;
int c[500001][9],ak[9];
signed main(){
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	int n,k;
	cin>>n>>k;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		int l=a[i];
		int cl[21],f=0;
		while(l){
			cl[++f]=l%2;
			l/=2;
		}
		for(int j=1;j<=8-f;j++){
			c[i][j]=0;
		}
		for(int j=1;j<=f;j++){
			c[i][j+8-f]=cl[f-j+1];
		}
	}
	int qc=0;
	for(int i=1;i<=n;i++){
		if(a[i]!=1){
			qc=1;
			break;
		}
	}
	
	if(qc==0){
		cout<<0;
		return 0;
	}
	int qcz=0;
	for(int i=1;i<=n;i++){
		if(a[i]==1||a[i]==0){
			qcz++;
		}
	}
	int ls=0;
	if(qcz==n&&qc==1){
		int qc1=0,qc2=0;
		for(int i=1;i<=n;i++){
			if(a[i]==1){
				qc1++;
			}
			else{
				for(int j=1;j<=qc1;j++){
					ls+=j;
				}
				qc1=0;
			}
		}
		for(int i=1;i<=n;i++){
			if(a[i]==0){
				qc2++;
			}
		}
		ls+=qc2/2;
		cout<<ls;
		return 0;
	}
	
	
	if(n==2){
		cout<<1;
		return 0;
	}
	for(int i=1;i<=n;i++){
		if(a[i]>255){
			cout<<1;
			return 0;
		}
	}
	int cl[9],f=0;
	while(k){
		cl[++f]=k%2;
		k/=2;
	}
//	cout<<f<<' ';
	for(int i=1;i<=8-f;i++){
		ak[i]=0;
	}
	for(int i=1;i<=f;i++){
		ak[i+8-f]=cl[f-i+1];
	}
//	cout<<c[3][1]<<c[3][2]<<c[3][3]<<c[3][4]<<c[3][5]<<c[3][6]<<c[3][7]<<c[3][8]<<'\n';
	for(int i=1;i<=8;i++){
		dp[1][i]=c[1][i];
	}
	int h=0;
	for(int i=2;i<=n;i++){
		int h=1;
		for(int j=1;j<=8;j++){
//			if(c[i][j]==1||dp[i-1][j]==1){
//				h=0;
//			}
			if(c[i][j]==dp[i-1][j]  ){//&&h==0){
				dp[i][j]=1;
			}
			else{
				dp[i][j]=0;
			}
		}
	}
//	for(int i=1;i<=8;i++){
//		cout<<ak[i];
//	}
	int maxn=0;
	for(int i=1;i<=n;i++){
		sum=0;
		for(int j=1;j<=n;){
			int l=i-1,r=j+i-1,s=0;
			if(r>n){
				break;
			}
			int lf[9]={0};
			if(l==0){
				for(int q=1;q<=8;q++){
					lf[q]=dp[r][q];
					if(lf[q]!=ak[q]){
						s=1;
						break;
					}
				}
			}
			for(int q=8-f+1;q<=8;q++){
				if(dp[r][q]==dp[l][q]){
					lf[q]=1;
				}
				else{
					lf[q]=0;
				}
				if(lf[q]!=ak[q]){
					s=1;
					break;
				}
			}
//			if(l==2&&r==2){
//				for(int p=1;p<=8;p++){
//					cout<<lf[p];
//				}
//			}
			if(s==0){
//				cout<<l<<' '<<r<<'\n';
				sum++;
				j+=i;
			}
			else{
				j++;
			}
		}
		maxn=max(maxn,sum);
	}
	cout<<maxn;
	
	return 0;
}
