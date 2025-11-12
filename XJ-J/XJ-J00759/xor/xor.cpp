#include <bits/stdc++.h>
using namespace std;
int n,m,a[500001],ans;
int yh(int a,int b){
	int e=1,cnt=0;
	while (a||b){
		if (a%2!=b%2){
		cnt+=e;
		}
		a/=2;
		b/=2;
		e*=2;
	}
	return cnt;
}
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>m;
	for (int i=1;i<=n;i++){
		cin>>a[i];
		if (a[i]==m) ans++;
	}
	int q=0,st=1;
	for (int i=1;i<=n;i++){
		if (a[i]==m){
			for (int j=st;j<i;j++){
				if (q==m){
					ans++;
					q=0;
					break;
				}
				q=yh(q,a[j]);
			}
			st=i+1;
			q=0;
		}
		else{
			q=yh(q,a[i]);
			if (q==m){
				ans++;
				q=0;
				st=i+1;
			}
		}
	}
	cout<<ans;
	return 0;
}
