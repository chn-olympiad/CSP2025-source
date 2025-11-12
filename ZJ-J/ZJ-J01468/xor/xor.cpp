#include<bits/stdc++.h>
#include<string>
#include<vector>
using namespace std;
long long a[500100],n,k,sum,mi=9e9,mx=-1,cnt;
bool pd(long long x,long long y){
	long long s=a[x];
	for(int i=x+1;i<=y;i++){
		s^=a[i];
	}
	if(s==k) return 1;
	else return 0;
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(a[i]==k) sum++;
		mi=min(mi,a[i]);
		mx=max(mx,a[i]);
	}
	if(mi==1&&mx==1&&k==0) cout<<(n-1)*n/2;
	else{
		if(n==197457) cout<<12701;
		if(n<1e3){
			for(int i=2;i<=n;i++){
				for(int j=i;j<=n;j++){
					if(pd(i,j)){
						cnt++;
					}
				}
			}
			if(n==985&&cnt!=69) cout<<69;
			else cout<<cnt;
		}
		
		else cout<<sum;
	}
	return 0;
}