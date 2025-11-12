#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll N=1e5+5,M=(1<<20)+5;
ll n,k,a[N],pro[N],rmin,ans;
int maxn;
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(int i=1;i<=n;i++){
		int x;
		cin>>x;
		maxn=max(maxn,x);
		if(i==1) pro[i]=x;
		else pro[i]=pro[i-1]^x;
		a[i]=x;
	}
	if(k<=1&&maxn<=1){
		int x=0;
		for(int i=1;i<=n;i++){
			x^=a[i];
			if(a[i]==k||x==k) ans++,x=0;
		}
	}else{
		for(int l=1;l<=n;l++){
			for(int len=1;len<=n&&len+l-1<=n;len++){
				int r=len+l-1;
				if((pro[r]^pro[l-1])==k){
					if(l>rmin){
						rmin=r;
						ans++;
					}
					if(r<rmin) rmin=r;
					break;
				}
			}
		}
	}
	cout<<ans<<'\n';
	return 0;
}
