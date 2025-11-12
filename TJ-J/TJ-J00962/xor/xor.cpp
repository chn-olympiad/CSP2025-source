#include<bits\stdc++.h>
using namespace std;
const int N=1e6+10;
long long n,k,ans;
int a[N];
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(a[i]==k) ans++,a[i]=-1;
	}
	for(int i=1;i<n;i++){
		int cnt;
		for(int j=i;j<n;j++){
			if(a[j]!=-1) cnt=a[j];
			else continue;
			if(a[j-1]!=-1) cnt^=a[j-1];
			else break;
			if(cnt==k){
				ans++;
				for(int k=i;k<j;k++) a[k]=-1;
				i=j-2;
				break;
			}
		}
	} 
	cout<<ans;
	return 0;
}
