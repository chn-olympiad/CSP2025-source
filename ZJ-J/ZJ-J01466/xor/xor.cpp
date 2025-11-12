#include<bits/stdc++.h>
using namespace std;
#define LL long long
LL read() {
	LL x=0;
	char ch=getchar();
	bool flag=true;
	for(;ch<'0'||ch>'9';ch=getchar()) (ch=='-')&&(flag=false);
	for(;ch>='0'&&ch<='9';ch=getchar()) x=(x<<1)+(x<<3)+(ch^'0');
	return flag? x:-x;
}
bool kkksc03;
int n,k;
int maxr[3000000];
int a[500005];
int sum[500005];
struct node{
	int l,r;
	node(){}
	node(int a,int b):l(a),r(b){}
}ans[500005];
int top,last_r,tot;
bool cmp(node a,node b) {
	return a.r<b.r;
}
bool soha;
int main() {
//	printf("%lf",(&kkksc03-&soha)/1024.0/1024.0);
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	n=read();
	k=read();
	memset(maxr,-1,sizeof maxr);
	for(int i=1;i<=n;i++) {
		a[i]=read();
		sum[i]=sum[i-1]^a[i];
	}
	maxr[0]=0;
	for(int i=1;i<=n;i++) {
		if(maxr[sum[i]^k]>-1) {
			ans[++top]=node(maxr[sum[i]^k]+1,i);
		}
		maxr[sum[i]]=i;
	}
	if(top<1) {
		cout<<0<<'\n';
		return 0;
	}
	sort(ans+1,ans+top+1,cmp);
	last_r=ans[1].r;
	tot=1;
//	cout<<ans[1].l<<','<<ans[1].r<<'\n';
	for(int i=2;i<=top;i++) {
//		cout<<ans[i].l<<','<<ans[i].r<<'\n';
		if(ans[i].l>last_r) {
			last_r=ans[i].r;
			tot++;
		}
	}
	cout<<tot<<'\n';
	return 0;
}
