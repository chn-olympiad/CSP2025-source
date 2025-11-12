/*
我不会dp啊啊啊啊啊啊啊
*/ 
#include <bits/stdc++.h>
using namespace std;

#define MAXN (int)1e5+10

int t,n;
int lim;
int lima,limb,limc;
int dp[MAXN],dp1[MAXN],dp2[MAXN],dp3[MAXN];

struct STU{
	int a,b,c;
}meb[MAXN];

bool cmp1(STU x,STU y){
	return x.a+x.b+x.c>y.a+y.b+y.c;
} 

bool cmp2(STU x,STU y){
	return x.a>y.a;
} 

bool cmp3(STU x,STU y){
	return x.b>y.b;
} 

bool cmp4(STU x,STU y){
	return x.c>y.c;
} 

int main(){
	
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	
	cin>>t;
	while(t--){
		cin>>n;
		for(int i=1;i<=n;i++){
			cin>>meb[i].a>>meb[i].b>>meb[i].c;
		}
		sort(meb+1,meb+n+1,cmp1);
		lim=floor(n/2);
		lima=lim,limb=lim,limc=lim;
		memset(dp,0,sizeof(dp));
		dp[0]=0;
		dp1[0]=0;
		dp2[0]=0;
		dp3[0]=0;
		for(int i=1;i<=n;i++){
			if(meb[i].a>meb[i].b&&meb[i].a>meb[i].c){
				if(lima){
					dp[i]=meb[i].a+dp[i-1];
					lima--;
				}
				else if(meb[i].b>meb[i].c&&limb){
					dp[i]=meb[i].b+dp[i-1];
					limb--;
				}
				else{
					dp[i]=meb[i].c+dp[i-1];
					limc--;
				}
			}
			else if(meb[i].b>meb[i].a&&meb[i].b>meb[i].c){
				if(limb){
					dp[i]=meb[i].b+dp[i-1];
					limb--;
				}
				else if(meb[i].a>meb[i].c&&lima){
					dp[i]=meb[i].a+dp[i-1];
					lima--;
				}
				else{
					dp[i]=meb[i].c+dp[i-1];
					limc--;
				}
			}
			else if(meb[i].c>meb[i].b&&meb[i].c>meb[i].a){
				if(limc){
					dp[i]=meb[i].c+dp[i-1];
					limc--;
				}
				else if(meb[i].a>meb[i].b&&lima){
					dp[i]=meb[i].a+dp[i-1];
					lima--;
				}
				else{
					dp[i]=meb[i].b+dp[i-1];
					limb--;
				}
			}
		} 
		lim=floor(n/2);
		lima=lim,limb=lim,limc=lim;
		sort(meb+1,meb+n+1,cmp2);
		memset(dp1,0,sizeof(dp1));
		for(int i=1;i<=n;i++){
			if(meb[i].a>meb[i].b&&meb[i].a>meb[i].c){
				if(lima){
					dp1[i]=meb[i].a+dp1[i-1];
					lima--;
				}
				else if(meb[i].b>meb[i].c&&limb){
					dp1[i]=meb[i].b+dp1[i-1];
					limb--;
				}
				else{
					dp1[i]=meb[i].c+dp1[i-1];
					limc--;
				}
			}
			else if(meb[i].b>meb[i].a&&meb[i].b>meb[i].c){
				if(limb){
					dp1[i]=meb[i].b+dp1[i-1];
					limb--;
				}
				else if(meb[i].a>meb[i].c&&lima){
					dp1[i]=meb[i].a+dp1[i-1];
					lima--;
				}
				else{
					dp1[i]=meb[i].c+dp1[i-1];
					limc--;
				}
			}
			else if(meb[i].c>meb[i].b&&meb[i].c>meb[i].a){
				if(limc){
					dp1[i]=meb[i].c+dp1[i-1];
					limc--;
				}
				else if(meb[i].a>meb[i].b&&lima){
					dp1[i]=meb[i].a+dp1[i-1];
					lima--;
				}
				else{
					dp1[i]=meb[i].b+dp1[i-1];
					limb--;
				}
			}
		} 
		lim=floor(n/2);
		lima=lim,limb=lim,limc=lim;
		sort(meb+1,meb+n+1,cmp3);
		memset(dp2,0,sizeof(dp2));
		for(int i=1;i<=n;i++){
			if(meb[i].a>meb[i].b&&meb[i].a>meb[i].c){
				if(lima){
					dp2[i]=meb[i].a+dp2[i-1];
					lima--;
				}
				else if(meb[i].b>meb[i].c&&limb){
					dp2[i]=meb[i].b+dp2[i-1];
					limb--;
				}
				else{
					dp2[i]=meb[i].c+dp2[i-1];
					limc--;
				}
			}
			else if(meb[i].b>meb[i].a&&meb[i].b>meb[i].c){
				if(limb){
					dp2[i]=meb[i].b+dp2[i-1];
					limb--;
				}
				else if(meb[i].a>meb[i].c&&lima){
					dp2[i]=meb[i].a+dp2[i-1];
					lima--;
				}
				else{
					dp2[i]=meb[i].c+dp2[i-1];
					limc--;
				}
			}
			else if(meb[i].c>meb[i].b&&meb[i].c>meb[i].a){
				if(limc){
					dp2[i]=meb[i].c+dp2[i-1];
					limc--;
				}
				else if(meb[i].a>meb[i].b&&lima){
					dp2[i]=meb[i].a+dp2[i-1];
					lima--;
				}
				else{
					dp2[i]=meb[i].b+dp2[i-1];
					limb--;
				}
			}
		} 
		lim=floor(n/2);
		lima=lim,limb=lim,limc=lim;
		sort(meb+1,meb+n+1,cmp4);
		memset(dp3,0,sizeof(dp3));
		for(int i=1;i<=n;i++){
			if(meb[i].a>meb[i].b&&meb[i].a>meb[i].c){
				if(lima){
					dp3[i]=meb[i].a+dp3[i-1];
					lima--;
				}
				else if(meb[i].b>meb[i].c&&limb){
					dp3[i]=meb[i].b+dp3[i-1];
					limb--;
				}
				else{
					dp3[i]=meb[i].c+dp3[i-1];
					limc--;
				}
			}
			else if(meb[i].b>meb[i].a&&meb[i].b>meb[i].c){
				if(limb){
					dp3[i]=meb[i].b+dp3[i-1];
					limb--;
				}
				else if(meb[i].a>meb[i].c&&lima){
					dp3[i]=meb[i].a+dp3[i-1];
					lima--;
				}
				else{
					dp3[i]=meb[i].c+dp3[i-1];
					limc--;
				}
			}
			else if(meb[i].c>meb[i].b&&meb[i].c>meb[i].a){
				if(limc){
					dp3[i]=meb[i].c+dp3[i-1];
					limc--;
				}
				else if(meb[i].a>meb[i].b&&lima){
					dp3[i]=meb[i].a+dp3[i-1];
					lima--;
				}
				else{
					dp3[i]=meb[i].b+dp3[i-1];
					limb--;
				}
			}
		} 
		cout<<max(max(dp[n],dp1[n]),max(dp2[n],dp3[n]))<<'\n';
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
