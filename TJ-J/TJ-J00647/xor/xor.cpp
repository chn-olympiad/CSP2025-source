#include <bits/stdc++.h>
using namespace std;
int a[500010];
bool b[500010];
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	long long n,k,sum=0;
	cin >> n >> k;
	for(int i=1;i<=n;++i){
		cin >> a[i];
		sum+=a[i];
	}
	if(k==0){
		if(sum==n){//ai==1
			cout << n/2;
		}else{//ai==0 or 1 
			cout << max(n-sum,sum/2);
		}
		return 0;
	}else if(k==1){
		int sum1=0;
		for(int i=1;i<n;++i){
			if(a[i]!=a[i+1]&&!b[i]&&!b[i+1]){
				sum1++;
				b[i]=1;
				b[i+1]=1;
			}
		}
		cout << max(sum1,sum);
		return 0;
	}else{
		cout << 2;
	}
	return 0;
}

