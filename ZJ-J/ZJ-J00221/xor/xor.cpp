#include<bits/stdc++.h>
using namespace std;
const int N=5e5+7;
long long n,k,ans,a[N],b[N];
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(a[i]==k) {
			ans++;
		}
	}
	b[1]=a[1];
	for(int i=2;i<=n;i++){
		b[i]=b[i-1]^a[i];
	}
	int flag=0;
	for(int i=2;i<=n;i++){
		if(a[i]==k) {
			flag=i;
			continue;
		}
		int t=1;
		while(i-t-1>flag){
			if((b[i]^b[i-t])==k){
				ans++;
			}
			t++;
		}
	}
	cout<<ans;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
