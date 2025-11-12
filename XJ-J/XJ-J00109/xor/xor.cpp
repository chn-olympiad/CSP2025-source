#include <bits/stdc++.h>
using namespace std;

const int N=500005; 
int a[N],b[N],ans; 
bool f[N];
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	int n,k;
	cin >> n >> k;
	for(int i=1;i<=n;i++){
		cin >> a[i];
		b[i]=a[i];
		for(int j=1;j<i;j++){
			b[i]^=a[j];
		}
		if(a[i]==k) ans++,f[i]=1;
	}
	for(int i=1;i<=n;i++){
		for(int j=i+1;j<=n;j++){
			bool flag=0;
			for(int z=i;z<=j;z++){
				if(f[z]){
					flag=1;
					break;
				}
			}
			if(flag) break;
			int sum=b[j];
			for(int z=1;z<i;z++){
				sum^=a[z];
			}
			if(sum==k){
				ans++;
				for(int z=i;z<=j;z++) f[z]=1;
			}
		}
	}
	cout<<ans;
	return 0;
}
