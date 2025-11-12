#include<bits/stdc++.h>
#define ll long long
#define itn int
using namespace std;
ll n,k,a[500005],xh[500005];

bool ck(itn x){
	int s = 1;
	while(x>0){
		itn flag=0;
		if(s>n) return 0;
		for(itn i=s;i<=n;i++){            //qidian
			if(flag) break;
			for(itn j=i;j<=n;j++){     //zhongdian
			    itn w = xh[j]^xh[i-1] ;
				if(w==k) {
					s=j+1;
					flag=1;
					x--;
					break;
				}
			}
		}
	}
	return 1;
}

int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		xh[i] = xh[i-1]^a[i];
	}
	for(itn i=n;i>=0;i--){
		if(ck(i)) {
			cout<<i;
			return 0;
		}
	}
	return 0;
}
