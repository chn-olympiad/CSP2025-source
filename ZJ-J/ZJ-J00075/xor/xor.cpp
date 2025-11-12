#include<bits/stdc++.h>
using namespace std;
const int N=500005;
int n,k,a[N],ans=0;
inline int jcsy(int x,int y){
	return (x^y);
}
inline int Jcsy(int l,int r){
	int t=jcsy(a[l],a[l+1]);
	for(int i=l+1;i<r;i++){
		t=jcsy(t,a[i+1]);
	}
	return t;
}
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	cin>>n>>k;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(a[i]==k) ans++;
	}
	if(k==0){
		for(int i=1;i<n;i++){
			if(a[i]==1&&a[i+1]==1){
				ans++;
				a[i]=-1,a[i+1]=-1;
			}
		}
	}
	cout<<ans<<'\n';
	return 0;
}
