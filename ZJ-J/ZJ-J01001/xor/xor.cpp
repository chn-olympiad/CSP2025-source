#include<bits/stdc++.h>
using namespace std;
int n,k,a[500005],vis[500005],sum,p[100000],p1[100000],p2[100000],f1,f2,m;
int pan(int x,int y){
	if(x==1&&y==1){
		return 0;
	}
	if(x==0&&y==0){
		return 0;
	}
	if(x==1&&y==0){
		return 1;
	}
	if(x==0&&y==1){
		return 1;
	}
}
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(a[i]==k){
			vis[i]=1;
			sum++;
		}
	}
	if(n==1){
		if(a[1]==k){
			cout<<1;
			return 0;
		}else{
			cout<<0;
			return 0;
		}
	}
	if(n==2){
		if(a[1]==k&&a[2]==k){
			cout<<2;
			return 0;
		}
		if(a[1]==k&&a[2]!=k){
			cout<<1;
			return 0;
		}
		if(a[1]!=k&&a[2]==k){
			cout<<1;
			return 0;
		}
		if(a[1]!=k&&a[2]!=k){
			for(int i=1;a[1]!=0;i++){
				p1[i]=a[1]%2;
				a[1]/=2;
				f1++;
			}
			for(int i=1;a[2]!=0;i++){
				p2[i]=a[2]%2;
				a[2]/=2;
				f2++;
			}
			f1=max(f1,f2);
			for(int i=1;i<=f1;i++){
				p[i]=pan(p1[i],p2[i]);
			}
			for(int i=1;i<=f1;i++){
				for(int j=1;j<=i-1;j++){
					m+=p[i];
				}
			}
			cout<<0;
			return 0;
		}
	}
	cout<<sum;
	return 0;
}
