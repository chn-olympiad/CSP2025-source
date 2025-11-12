#include<bits/stdc++.h>
using namespace std;
const int N=1e5+10; 
struct lr{
	int l,r,x;
}p[N];
int a[N],s[N],cnt=1;
bool cmp(lr x,lr y){
	return x.r<y.r;
}
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	int n,k;
	cin>>n>>k;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=1;i<=n;i++){
		s[i]=(s[i-1] xor a[i]);
	}
	for(int i=1;i<=n;i++){
		for(int j=i;j<=n;j++){
			if((s[j] xor s[i-1])==k||(j==i&&a[j]==k)){
				p[cnt++].l=i;
				p[cnt-1].r=j;
				p[cnt-1].x=(s[j] xor s[i-1]);
			}
		}
	}
	sort(p+1,p+n+1,cmp);
	int ans=0,kl=p[1].l;
	for(int i=2;i<=cnt-1;i++){
		if(p[i].l>=kl){
			ans++;
			kl=p[i].l;
		} 
	} 
	cout<<ans; 
	return 0;
}
