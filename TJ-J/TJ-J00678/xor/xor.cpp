#include<bits/stdc++.h>
using namespace std;
int n,k,flag=1,flagb=1;
int s[9000][9000];
int dp[600000];
int a[600000];
int jg(int x,int y){
	if(x==y) return 1;
	return 0;
}
int main(){
    freopen("xor.in","r",stdin);
    freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(a[i]!=1) flag=0;
		if(a[i]>1) flagb=0;
		s[i][i]=i;
	}
	for(int i=1;i<=n;i++){
		for(int j=i;j<=n;j++){
			s[i][j]=s[i][j-1]^a[j];
		}
	}
	if(n==2){
		int cnt=0;
		if(a[1]==k) cnt++;
		if(a[2]==k) cnt++;
		if(a[1]^a[2]==k) cnt++;
		cout<<cnt;
	}else if(flag==1){
		if(k==1) cout<<n;
		else if(k==0) cout<<n/2;
		else cout<<0;
	}else{
		for(int i=1;i<=n;i++){
			for(int j=0;j<i;j++){
				//cout<<i<<' '<<j<<' '<<dp[i]<<endl;
				dp[i]=max(dp[i],dp[j]+jg(s[j+1][i],k));
			}
		}
		cout<<dp[n];
	}

    fclose(stdin);
    fclose(stdout);
    return 0;
}
/*
4 2
2 1 0 3

2
*/
/*
4 3
2 1 0 3

2
*/
/*
4 0
2 1 0 3

1
*/
/*
100 1
1 0 1 1 0 0 0 1 1 1 1 1 1 0 0 1 1 1 1 1 0 0 1 1 1 0 0 1 1 1 1 0 1 0 1 1 1 0 1 1 1 1 0 1 0 0 1 1 1 0 1 1 1 0 1 0 0 1 0 1 0 1 1 1 0 1 0 1 0 1 0 1 1 1 0 1 0 1 1 0 1 1 0 1 1 1 1 0 1 1 0 1 0 1 1 0 0 0 0 1

63
*/
