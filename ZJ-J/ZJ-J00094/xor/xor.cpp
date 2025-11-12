#include<bits/stdc++.h>
using namespace std;
int a[100001],n,k,s=0,b[100000],l[10001],r[10001],top=1,sum=0,zb[10000],yb[10000],op=1;
int main(){
	freopen("xor.in","r",stdin);
    freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(a[i]==k){
			l[top]=i;
			r[top++]=i;
		}
	}
	for(int z=1;z<=n;z++){
		b[z]=a[z];
		for(int i=z+1;i<=n;i++){
			b[z]=b[z]^a[i];
			if(b[z]==k){
				r[top]=i;
				l[top++]=z;
			}
		}
	}if(top==1){
		cout<<0;
		return 0;
	}
	for(int i=1;i<top;i++){
		for(int j=1;j<=top;j++){
			if(j!=i && (l[i]>r[j] || l[j]>r[i])){
				int yuo=0;
				for(int z=1;z<op;z++){
					if(r[j]<zb[z] || yb[z]<l[j]){
						yuo=1;
						break;
					}
				}
				if(yuo==0){
					s++;
					zb[op]=l[j];
					yb[op++]=r[j];
				}
				
			}
		}
		if(s>sum)sum=s;
		s=0;
		op=0;
	}
	if(sum>1)cout<<sum;
	else cout<<sum+1;
	return 0;
}
