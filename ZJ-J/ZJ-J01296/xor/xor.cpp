#include<bits/stdc++.h>
using namespace std;
int n,k,a[600000],num,p,yf;
bool vis[600000],bxz;
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	bxz=true;
	cin>>n>>k;
	for(int i=1;i<=n;i++){
		vis[i]=true;
	}
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(a[i]==k){
			vis[i]=false;
			yf++;
			num++;
		}
		if(a[i]>1){
			bxz=false;
		}
	}
	if(bxz==true){
		if(k>1){
			cout<<0;
			return 0;
		}
		if(k==1){
			num=0;
			for(int i=1;i<=n;i++){
				if(a[i]==1){
					num++;
				}
			}
			cout<<num;
			return 0;
		}
		if(k==0){
			num=0;
			for(int i=1;i<=n;i++){
				if(a[i]==0){
					num++;
				}
				if(a[i]==1&&a[i+1]==1){
					num++;
					a[i+1]=2;
				}
			}
			cout<<num;
			return 0;
		}
	}
	for(int len=2;len<=n;len++){
		if(n-yf<len){
			cout<<num;
			return 0;
		}
		for(int i=1;i<=n-len+1;i++){
			int j=i+len-1;
			bool flag=true;
			p=a[i];
			for(int l=i;l<=j;l++){
				if(vis[l]==false){
					p=2e9;
					flag=false;
					break;
				}
				if(l>i){
					p=p^a[l];
				}
			}
			if(p==k){
				num++;
				yf+=len;
				for(int l=i;l<=j;l++){
					vis[l]=false;
				}
			}
		}
	}
	cout<<num;
	return 0;
}
