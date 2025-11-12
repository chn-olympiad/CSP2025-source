#include<bits/stdc++.h>
using namespace std;
const int MAXN=5e5;
int n,k;
int a[MAXN];
long long sum;

int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(int i=1;i<=n;i++) cin>>a[i];
	for(int len=1;len<=n;len++){
		for(int l=1;l+len-1<=n;l++){
			int r=l+len-1;
			long long ans=a[l];
			for(int i=l+1;i<=r;i++){
				ans^=a[i];
			}
			if(ans==k) sum++;
		}
	}
	cout<<sum;
	return 0;
}
