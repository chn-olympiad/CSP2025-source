#include<bits/stdc++.h>
using namespace std;
int n,k,ix=1,l,r,ans=0,xz=0,sk=0;
int a[100005];
int fk(int l,int r){
	int sum=0;
	for(int i=l;i<=r;i++){
		sum=sum^a[i-xz];
	}
	return sum;
}
struct qj{
	int l;
	int r;
}q;
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(r=1;r<=n;r++){
		cin>>a[r-xz];
		sk=0;
		for(l=r;l>xz;l--){
			q.l=l;q.r=r;
			sk=fk(l,r);
			if(sk==k){
				ans++;
				xz=r;
				break;
			}
			
		}
	}	
	cout<<ans;
}

