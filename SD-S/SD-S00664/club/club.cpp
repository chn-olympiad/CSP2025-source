#include<iostream>
#include<iomanip>
#include<cstring>
#include<cstdio>
#include<algorithm>
#include<cmath>
#include<vector>
using namespace std;
const int N=1e5+5;
int t,n,a1[N],a2[N],a3[N],cnt1,cnt2,cnt3;
struct node {
	int ft,num1,num2,num3;
	int sd;
} s[N];
bool cmp1(node hh,node mm){
	if(hh.num1==mm.num1&&hh.num1==1) return (hh.ft-hh.sd)<(mm.ft-mm.sd);
	return hh.num1>mm.num1;
}
bool cmp2(node hh,node mm){
	if(hh.num2==mm.num2&&hh.num2==1) return (hh.ft-hh.sd)<(mm.ft-mm.sd);
	return hh.num2>mm.num2;
}
bool cmp3(node hh,node mm){
	if(hh.num3==mm.num3&&hh.num3==1) return (hh.ft-hh.sd)<(mm.ft-mm.sd);
	return hh.num3>mm.num3;
}
int main() {
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	scanf("%d",&t);
	while(t--) {
		memset(s,0,sizeof(s));
		memset(a1,0,sizeof(a1));
		memset(a2,0,sizeof(a2));
		memset(a3,0,sizeof(a3));
		cnt1=cnt2=cnt3=0;
		scanf("%d",&n);
		for(int i=1; i<=n; i++) scanf("%d%d%d",&a1[i],&a2[i],&a3[i]);
		for(int i=1; i<=n; i++) {
			if(a1[i]>=a2[i]&&a1[i]>=a3[i]) {
				s[i].ft=a1[i],s[i].num1=1;
				cnt1++;
				s[i].sd=max(a2[i],a3[i]);
			}
			if(a2[i]>=a1[i]&&a2[i]>=a3[i]) {
				s[i].ft=a2[i],s[i].num2=1;
				cnt2++;
				s[i].sd=max(a1[i],a3[i]);
			}
			if(a3[i]>=a2[i]&&a3[i]>=a1[i]) {
				s[i].ft=a3[i],s[i].num3=1;
				cnt3++;
				s[i].sd=max(a2[i],a1[i]);
			}
		}
		int top=0;
		if(cnt1>n/2){
			sort(s+1,s+n+1,cmp1);
			while(cnt1>n/2){
				top++;
				s[top].ft=s[top].sd;
				cnt1--;
			}
		}
		if(cnt2>n/2){
			sort(s+1,s+n+1,cmp2);
			while(cnt2>n/2){
				top++;
				s[top].ft=s[top].sd;
				cnt2--;
			}
		}
		if(cnt3>n/2){
			sort(s+1,s+n+1,cmp3);
			while(cnt3>n/2){
				top++;
				s[top].ft=s[top].sd;
				cnt3--;
			}
		}
		long long ans=0;
		for(int i=1;i<=n;i++) ans+=s[i].ft;
		printf("%lld\n",ans);
	}
	return 0;
}
/*
3
4 
4 2 1
3 2 4
5 3 4
3 5 1
4
0 1 0
0 1 0
0 2 0
0 2 0
2
10 9 8
4 0 0
*/
