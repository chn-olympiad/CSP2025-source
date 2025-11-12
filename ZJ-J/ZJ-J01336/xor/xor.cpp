#include<bits/stdc++.h>
using namespace std;
const int maxn = 5e5+5;
int n,k,a[maxn],flag1,cnt,flag2;
int main(){
	
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin.tie(0)->sync_with_stdio(0);
	cin>>n>>k;
	for(int i=1;i<=n;++i){
		cin>>a[i];
		if(a[i]!=1)	flag1=1;
		if(a[i]>1)	flag2=1;
	}
	if(!flag1){
		if(k==0){
			cnt=n/2;
			cout<<cnt;
			return 0;
		}else if(k==1){
			cout<<n;
			return 0;
		}
	}
	if(!flag2){
		if(k==1){
			for(int i=1;i<=n;++i)
				if(a[i]==1)	cnt++;
			cout<<cnt;
			return 0;
		}else if(k==0){
			for(int i=1;i<=n;++i)
				if(a[i]==0)	cnt++;
			for(int i=0,j=1;j<=n+1;j++){
				if(a[j]==0){
					cnt+=(j-i-1)/2;
					i=j;
				}
			}
			cout<<cnt;
			return 0;
		}
	}
	
	return 0;
}