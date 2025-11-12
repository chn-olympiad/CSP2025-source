#include <bits/stdc++.h>
using namespace std;
int n,k,a[500005];
struct ab{
	int ll,rr;
};
ab b[500005];
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	int i=0;
	for(int l=1;l<=n;l++){
		int x=a[l];
		if(x==k){
			i++;
			b[i].ll=l;
			b[i].rr=l;
		}else{
			int p=1;
			int r=l+1;
			while(r<=n&&p==1){
				x=x^a[r];
				if(x==k){
					i++;
					b[i].ll=l;
					b[i].rr=r;
					p=0;
				}
				r++;
			}
		}

	}
	if(i==0||i==1){
		cout<<i;
	}else{
		int r=b[1].rr,k=1;
		for(int j=2;j<=i;j++){
			if(b[j].ll<r&&b[j].rr<r){
				r=b[j].rr;
			}else if(b[j].ll==r){
			}else if(b[j].ll>r){
				k++;
				r=b[j].rr;
			}
		}
		cout<<k;
	}
	return 0;
}
