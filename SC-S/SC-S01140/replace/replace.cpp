#include<bits/stdc++.h>
#define int long long
using namespace std;
const int maxn=100000+5;
int T;
bool vis[maxn];
struct node{
	int a1,a2,a3;
	int x1,x2,x3; // 被需要程度
}a[maxn];
bool cmp1(node n1,node n2){
	if(n1.a1==n2.a1){
		if(n1.a2==n2.a2) return n1.a3>n2.a3;
		return n1.a2>n2.a2;
	}return n1.a1>n2.a1;
}
bool cmp2(node n1,node n2){
	if(n1.a2==n2.a2){
		if(n1.a1==n2.a1) return n1.a3>n2.a3;
		return n1.a1>n2.a1;
	}return n1.a2>n2.a2;
}
bool cmp3(node n1,node n2){
	if(n1.a3==n2.a3){
		if(n1.a1==n2.a1) return n1.a2>n2.a2;
		return n1.a1>n2.a1;
	}return n1.a3>n2.a3;
}
signed main(){
//	freopen("club.in","r",stdin);
//	freopen("club.out","w",stdout);
	ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	cin>>T;
	while(T--){
		memset(vis,0,sizeof(vis));
		int n; cin>>n;
		int maxr=n/2,ans1=0;//ans1按需要度答案
		for(int i=1;i<=n;i++) 
		cin>>a[i].a1>>a[i].a2>>a[i].a3;
		
		sort(a+1,a+n+1,cmp1);
		for(int i=1;i<=n;i++) a[i].x1=i;
		sort(a+1,a+n+1,cmp2);
		for(int i=1;i<=n;i++) a[i].x2=i;
		sort(a+1,a+n+1,cmp3);
		for(int i=1;i<=n;i++) a[i].x3=i;
		
		int cnt1=0,cnt2=0,cnt3=0;
		for(int i=1;i<=n;i++){
			if(cnt3==maxr) break;
			if(vis[i]) continue;
			if(a[i].x1==a[i].x2&&a[i].x2==a[i].x3){
				if(a[i].a3==max(a[i].a1,max(a[i].a2,a[i].a3))){
					cnt3++; ans1+=a[i].a3; vis[i]=1;
				}
			}else if(a[i].x3==a[i].x1){
				if(a[i].a3==max(a[i].a1,a[i].a3)){
					cnt3++; ans1+=a[i].a3; vis[i]=1;
				}
			}else if(a[i].x3==a[i].x2){
				if(a[i].a3==max(a[i].a2,a[i].a3)){
					cnt3++; ans1+=a[i].a3; vis[i]=1;
				}
			}else{ans1+=a[i].a3; cnt3++; vis[i]=1;}
		}
		
		sort(a+1,a+n+1,cmp2);
		for(int i=1;i<=n;i++){
			if(cnt2==maxr) break;
			if(vis[i]) continue;
			if(a[i].x1==a[i].x2&&a[i].x2==a[i].x3){
				if(a[i].a2==max(a[i].a1,max(a[i].a2,a[i].a3))){
					cnt2++; ans1+=a[i].a2; vis[i]=1;
				}
			}else if(a[i].x2==a[i].x1){
				if(a[i].a2==max(a[i].a2,a[i].a1)){
					cnt2++; ans1+=a[i].a2; vis[i]=1;
				}
			}else if(a[i].x2==a[i].x3){
				if(a[i].a2==max(a[i].a2,a[i].a3)){
					cnt2++; ans1+=a[i].a2; vis[i]=1;
				}
			}else{ans1+=a[i].a2; cnt2++; vis[i]=1;}
		}

	return 0;
}//rp++