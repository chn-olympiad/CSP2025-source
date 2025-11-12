#include<bits/stdc++.h>
using namespace std;
int n,k;
int a;
int l[500005]={0};
bool b[500005]={0};
int cnt=0;
int main(){
	
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdin);
	
	cin>>n>>k;
	l[0]=0;
	for(int i=1;i<=n;i++){
		cin>>a;
		if(a==k){
			cnt++;
			b[i]=1;
		}
		l[i]=l[i-1]^a;
	}
	if(cnt==n){
		cout<<cnt;
		return 0;
	}
	for(int i=1;i<=n;i++){
		if(b[i]) continue;
		for(int j=i+1;j<=n;j++){
			if(b[j]) break;
			int xor_l=l[i-1]^l[j];
			if(xor_l==k){
				cnt++;
				for(int k_i=i;k_i<=j;k_i++){
					b[k_i]=1;
				}
				break;
			}
		}
	}
	cout<<cnt;
	return 0;
} 
