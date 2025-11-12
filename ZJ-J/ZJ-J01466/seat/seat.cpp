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
int n,m;
struct node{
	int id,val;
}a[105];
bool cmp(node a,node b) {
	return a.val>b.val;
}
int ans_h,ans_l,si,tmp;
int main() {
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	n=read();
	m=read();
	for(int i=1;i<=(n*m);i++) {
		a[i].id=i;
		a[i].val=read();
	}
	sort(a+1,a+n*m+1,cmp);
	for(int i=1;i<=(n*m);i++) {
		if(a[i].id==1) {
			si=i;
			break;
		}
	}
//	cout<<si<<'\n';
	ans_l=(si-1)/n;
	tmp=si-ans_l*n;
	ans_l++;
	if((ans_l&1)>0) {
		ans_h=1+tmp-1;
	} else {
		ans_h=n-tmp+1;
	}
	cout<<ans_l<<' '<<ans_h<<'\n';
	return 0;
}