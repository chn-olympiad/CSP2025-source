#include<bits/stdc++.h>
using namespace std;
int n,k;
int a[500005];
int b[500005];
long long ll;
struct node{
	int l,r;
} x[500005];
bool cmp(node x,node y){
	return x.r <y.r ;
}
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>k;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		b[i]=b[i-1]^a[i];
	}
	for(int i=1;i<=n;i++){
		for(int j=i;j<=n;j++){
			if((b[i-1]^b[j])==k){
				ll++;
				x[ll].l=i;
				x[ll].r=j;
			}
		}
	}
	long long ans=ll;
	sort(x+1,x+ll+1,cmp);
	int xx=x[1].r;
	for(int i=2;i<=ll;i++){
		if(x[i].l<=xx){
			ans--;
		}
		else xx=x[i].r;
	}
	cout<<ans;
	return 0;
}
