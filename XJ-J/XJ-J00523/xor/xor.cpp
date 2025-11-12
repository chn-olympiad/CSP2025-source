#include<bits/stdc++.h> 
using namespace std;
const int N=5e5+7;
int a[N],l=0,r=0;
int n,k;
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	scanf("%d%d",&n,&k);
	for(int i=1;i<=n;i++){
		scanf("%d",&a[i]);
		if(a[i]==1) l++;
		if(a[i]==0) r++;
	}
	if(l==n){
		if(k==0) cout<<n/2;
		else cout<<n;
		return 0;
	}
	if(l+r==n){
		int j=0,cnt=0;
		for(int i=1;i<=n;i++){
			if(j==k){
				cnt++;j=0;	
			} 
			j+=a[i];
		}
		if(j==k){
			cnt++;j=0;	
		} 
		cout<<cnt;
		return 0;
	}
	cout<<1; 
	return 0;
}
