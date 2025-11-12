#include<bits/stdc++.h>
using namespace std;
int sa=1,sb=1,n,k,x,a[500055];
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr),cout.tie(nullptr);
	cin>>n>>k;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		sa=sa&(a[i]==1);
		sb=sb&(a[i]<=1);
	}
	if(sa){
		cout<<n/2<<"\n";
		return 0;
	}
	if(sb){
		int cnt=0,cntt=0;
		if(k==1){
			for(int i=1;i<=n;i++){
				if(a[i]==1){
					cnt++;
				}
			}
		}
		else{
			for(int i=1;i<=n;i++){
				if(a[i]==0){
					cnt++;
					cnt+=cntt/2;
					cntt=0;
				}
				else{
					cntt++;
				}
			}
		}
		cout<<cnt<<"\n";
		return 0;
	}
	return 0;
}
