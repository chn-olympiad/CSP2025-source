#include<bits/stdc++.h>
using namespace std;
int n,k,p,xb,ans1;
int a[500909];
int main(){
    freopen("xor.in","r",stdin);
    freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=1;i<=n;i++){
		for(int kp=0;kp<=n-i;kp++){
			p=0;
			for(int j=i;j<=i+kp;j++){
				p=p^a[j];	
		//		cout<<p<<" ";
			}
		//	cout<<endl;
			if(p==k){
				xb++;
			}
		}
	}
	cout<<xb;
    return 0;
}
