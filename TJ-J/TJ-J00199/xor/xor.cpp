#include<iostream>
#include<algorithm>
using namespace std;
const int N=5e5+10;
int a[N];
int b[N];
struct node{
	int l;
	int r;
}c[N];
bool cmp(node a,node b){
	return a.r<b.r;
}
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	int n,k,p=0;
	bool is_all_one=1;
	scanf("%d%d",&n,&k);
	for(int i=1;i<=n;i++){
		scanf("%d",&a[i]);
		b[i]=b[i-1]^a[i];
		if(a[i]!=1) is_all_one=0;
	}if(is_all_one){
		printf("%d",n/2);
		return 0;
	}
	for(int i=0;i<=n;i++){
		for(int j=i+1;j<=n;j++){
			int t=b[j]^b[i];
			if(t==k){
				++p;
				c[p].l=i;
				c[p].r=j;
			}
		}
	}int ans;
	sort(c+1,c+1+p,cmp);
	int end=c[1].r;
	ans=1;
	for(int i=2;i<=p;i++){
		if(c[i].l>=end){
			ans++;
			end=c[i].r;
		}
	}printf("%d",ans);
	return 0;
}
