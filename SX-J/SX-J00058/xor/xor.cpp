#include<bits/stdc++.h>
using namespace std;
int a[500005];
int st[500005];
struct node{
	int l;
	int r;
};
node b[500005];
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	int n,k;
	cin>>n>>k;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		st[i]=st[i-1]+a[i];
	}int m=0;
	if(k!=1){
		for(int l=1;l<=n;l++){
			for(int r=l;r<=n;r++){
				if((st[r]-st[l-1])%2==0)m++,b[m].l=l,b[m].r=r;
			}
		}
	}else{
		for(int l=1;l<=n;l++){
			for(int r=l;r<=n;r++){
				if((st[r]-st[l-1])%2==1)m++,b[m].l=l,b[m].r=r;
			}
		}
	}long long ans=0;
	for(int i=1;i<=m;i++){
		for(int j=i+1;j<=m;j++){
			if(b[j].l>b[i].r){
				ans++;
			}
		}
	}
	cout<<ans<<endl;
	return 0;
}