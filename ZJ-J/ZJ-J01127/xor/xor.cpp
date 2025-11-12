#include<bits/stdc++.h>
using namespace std;
struct node{
	int l;
	int r;
}b[1000010];
int a[500010];
bool cmp(node a,node b){
	if(a.r!=b.r){
		return a.r<b.r;
	}
	return a.l<b.l;
}
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	if(n<=10000){
		int d=0;
		int ans=0;
		for(int i=1;i<=n;i++){
			for(int j=i;j<=n;j++){
				int x=0;
				for(int k=i;k<=j;k++){
					x^=a[k];
				}
				if(x==m){
					b[++d].l=i;
					b[d].r=j;
				}
			}
		}
		sort(b+1,b+d+1,cmp);
		int r=b[1].r;
		ans++;
		for(int i=2;i<=d;i++){
			if(b[i].l>r){
				r=b[i].r;
				ans++;
			}
		}
		cout<<ans;
	}else{
		int ans=0;
		for(int i=1;i<=n;i++){
			if(a[i]==m){
				ans++;
			}
		}
		cout<<ans;
	}
	return 0;
}
