#include<bits/stdc++.h>
using namespace std;

int num[500005], num1[500005], lr[50000005][2];
long long dp[5000005];
bool dd[25];

int d(int a, int b){
	int ans=0, k=0;
	for(int i=0;i<25;i++){
		dd[i]=0;
	}
	if(a<b){
		swap(a, b);
	}
	while(a){
		dd[k++]=((a%2)!=(b%2));
		a >>= 1;
		b >>= 1;
	}
	for(int i=k-1;i>=0;i--){
		ans += dd[i];
		ans <<= 1;
	}
	ans >>= 1;
	
	return ans;
}

int main(){
	freopen("xor.in", "r", stdin);
	freopen("xor.out", "w", stdout);
	
	int n, k, l=0;
	
	scanf("%d%d", &n, &k);
	
	for(int i=1;i<=n;i++){
		scanf("%d", &num[i]);
	}
	for(int i=1;i<=n;i++){
		num[i] = d(num[i], num[i-1]);
	}
	
	for(int j=1;j<=n;j++){
		for(int i=1;i<=j;i++){
			if(d(num[j], num[i-1])==k){
				lr[l][0]=i;
				lr[l++][1]=j;
			}
		}
	}
	
	int now=0;
	for(int i=1;i<=n;i++){
		dp[i] = dp[i-1];
		while(i==lr[now][1]){
			dp[i] = max(dp[i], dp[lr[now][0]-1]+1);
			now++;
		}
	}
	cout << dp[n];
		
	fclose(stdin);
	fclose(stdout);

	return 0;
	
}


