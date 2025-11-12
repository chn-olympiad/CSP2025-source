#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("xor.in","r",stdin);
    freopen("xor.out","w",stdout);
    int n,k;
    cin>>n>>k;
    int a[n];
    for (int i=0;i<n;i++){
    	cin>>a[i];
	}
	//A
	if (n<=2){
		cout<<n;
		return 0;
	}
	//k=0
	if (k==0){
		int cnt=0;
		int sg=-1;
		for (int i=0;i<n;i++){
			if (a[i]==0){
				cnt+=1;
			} else if (a[i]==sg) {
				cnt+=1;
				sg=-1;
			} else sg=a[i];
		}
		cout<<cnt;
		return 0;
	}
	//xor yunsuanfu
	//int c=a[1] xor a[2] xor a[3];
	//cout<<c<<endl;
    //for (int i=0;i<n;i++){
    //	cout<<a[i]<<" ";
	//}
	// bao li qiu jie
	int sj=-1,cnt=0;
	for (int i=0;i<n;i++){
		for (int j=0;j<i-sj;j++){
			int xorres=a[i];
			for (int k=i-1;k>=i-j;k--){
				xorres=(xorres xor a[k]);
			}
			if (xorres==k){
				//cout<<xorres<<endl;
				cnt+=1;
				sj=i;
			}
		}
	}
	cout<<cnt;
    return 0;
}

