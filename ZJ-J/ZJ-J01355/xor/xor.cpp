#include<bits/stdc++.h>
using namespace std;
const int N=5e5+10;
int n,k,p,r=1,cnt,a[N];
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin.tie(0);
	cin>>n>>k;
	for(int i=1;i<=n;i++) cin>>a[i];
	for(int i=1;i<=n;i++){
		p=a[i];
		if(p==k){
			cnt++;
			r=i+1;
			continue;
		}
		for(int j=i-1;j>=r;j--){
			p^=a[j];
			if(p==k){
				cnt++;
				r=i+1;
				break;
			}
		} 
	}
	cout<<cnt;
	return 0;
}

