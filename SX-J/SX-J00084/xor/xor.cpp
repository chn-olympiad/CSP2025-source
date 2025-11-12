#include<bits/stdc++.h>
using namespace std;
int n,x,a[500005],c,s,f[500005],top;
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>x;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=1;i<=n;i++){
		for(int j=i;j<=n;j++){
			for(int k=i;k<=j;k++){
				c=int(c^a[k]);
			}
			if(c==x){
				//cout<<i<<'-'<<j<<endl;
				if(top==0){
					f[++top]=j;
				}
				if(j<f[top]){
					top--;
					f[++top]=j;
				}else{
					if(i>f[top]){
						f[++top]=j;
					}
				}
			}
			c=0;
		}

	}
	cout<<top;
	return 0;
}