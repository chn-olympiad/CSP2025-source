#include<bits/stdc++.h>
#define int long long
using namespace std;
int n,k,a[1000010],f1,f10,g=1;
signed main(){
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(a[i]!=1)f1=1;
		if(a[i]!=0&&a[i]!=1)f10=1;
	}
	if(!f1){
		cout<<n/2;
	}else if(!f10){
		if(k==1){
			int s=0;
			for(int i=1;i<=n;i++){
				s+=a[i];
			}cout<<s;
		}else{
			int s=0;
			for(int i=1;i<=n;i++){
				s+=(a[i]==0);
				if(a[i]==1&&a[i-1]==1){
					a[i]=a[i-1]=0;
					s++;
				}
			}cout<<s;
		}
	}else{
		int sum=0;
		for(int i=1;i<=n;i++){
			int s=0;
			for(int j=g;j<=i;j++){
				s^=a[j];
				if(s==k){
					sum++;
					g=j+1;
					break;
				}
			}
		}
		cout<<sum;
	}
	return 0;
}
