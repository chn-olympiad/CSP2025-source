#include<bits/stdc++.h>
using namespace std;
int a[500005],cnt,b[500005],c[500005];
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	int n,k;
	cin >> n >> k;
	for(int i=1;i<=n;i++){
		cin >> a[i];
		if(a[i]==k){
			cnt++;
		}
	}
	b[0]=n;
	c[0]=1;
	if(n==1){
		if(n==k){
			cout << 1;
			return 0;
		}else{
			cout << 0;
			return 0;
		}
	}
	int x=1,y=1,ii=0;
	for(int i=2;i<=n;i++){
		for(int j=1;j<=n-i+1;j++){
			int o=0;
			for(int q=j;q<=j+i-1;q++){
				if(a[q]==k){
					continue;
				}else{
					o=a[q]^o;
				}
			}
			if(o==k){
				if(b[x-1]<=j||c[j-1]>=j+i-1){
					continue;
				}
				if(ii!=i||ii==0){
					b[x]=j;
					c[y]=j+i-1;
					x++;
					y++;
				}
				cnt++;
				ii=i;
				j+=i;
			}
		}
	}
	cout << cnt;
	return 0;
}
