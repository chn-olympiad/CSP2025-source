#include<bits/stdc++.h>
using namespace std;
#define int long long
struct node{
	int l,r;
};
bool cmp(node x,node y){
	return x.r<y.r;
}
int n,k,a[500001],s=0;
node p[500001];
signed main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(a[i]==k)s++,p[s].l=i,p[s].r=i;
	}
	for(int l=1;l<=n;l++){
		int x=a[l];
		for(int r=l+1;r<=n;r++){
			x=x^a[r];
			if(x==k){
				s++;
				p[s].l=l;
				p[s].r=r;	
				break;
			}
		}
	}
	sort(p+1,p+1+s,cmp);
	int jd=p[1].r,sum=1;
	for(int i=2;i<=s;i++){
		if(p[i].l>jd){
			jd=p[i].r;
			sum++;
		}
	}
	cout<<sum;
	return 0;
}
