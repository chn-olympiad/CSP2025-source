#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=5e5+10;
int a[N],dp[N];
struct node{
	int l;
	int r;
}b[N]; 
int cmp(node x,node y){
	return x.r<y.r;
}
signed main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	int n,k;
	cin>>n>>k;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	int q=1;
	for(int i=1;i<=n;i++){
		int z=a[i];
		int j=i+1;
		int x=1;
		while(z!=k){
			z^=a[j];
			if(j>n){
				x=0;
				break;
			}
			j++;
		}
		if(x){
			b[q].l=i;
			b[q].r=j-1;
			q++;	
		}

	}
	sort(b+1,b+q,cmp);
	int sum=0,j=-1;
	for(int i=1;i<q;i++){
		if(b[i].l>j){
			sum++;
			j=b[i].r;
		}
	}
	cout<<sum;
	return 0;
}

