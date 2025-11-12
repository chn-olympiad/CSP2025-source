#include<bits/stdc++.h>
using namespace std;
const int N=1e5+5;
const int V=2e4;
int n,f[205][205][205];
int aa[N],bb[N],cc[N];
inline void text(){
	for(int i=1;i<=n;i++)cin>>aa[i]>>bb[i]>>cc[i];
	memset(f,-0x3f,sizeof(f));
	f[0][0][0]=0;
	for(int i=0;i<n;i++){
		for(int j=0;j<=n/2;j++){
			for(int k=0;k<=n/2;k++){
				f[i+1][j+1][k]=max(f[i+1][j+1][k],f[i][j][k]+aa[i+1]);
				f[i+1][j][k+1]=max(f[i+1][j][k+1],f[i][j][k]+bb[i+1]);
				f[i+1][j][k]=max(f[i+1][j][k],f[i][j][k]+cc[i+1]);
			}
		}
	}
	int ans=0; 
	for(int i=0;i<=n/2;i++){
		for(int j=0;j<=n/2;j++){
			int k=n-i-j;
			if(k>n/2)continue;
			ans=max(ans,f[n][i][j]);
		}
	}
	cout<<ans<<'\n';
}
struct node{
	int val,id;
}A[N],B[N],C[N];
inline bool cmp(node a,node b){
	return a.val>b.val;
}
inline bool check_A(){
	bool yet=0;
	for(int i=1;i<=n;i++)yet|=((B[i].val>0)|(C[i].val>0));
	return yet;
}
inline int getA(){
	int ans=0;
	for(int i=1;i<=n/2;i++)ans+=A[i].val;
	return ans;
}
bool used[N];
inline void solve(){
	cin>>n;
	if(n<=200){
		text();
		return ;
	}
	for(int i=1;i<=n;i++){
		int a,b,c;cin>>a>>b>>c;
		A[i]={a,i};
		B[i]={b,i};
		C[i]={c,i};
	}
	sort(A+1,A+n+1,cmp);
	sort(B+1,B+n+1,cmp);
	sort(C+1,C+n+1,cmp);
	if(!check_A()){
		cout<<getA()<<'\n';
		return ;
	}
	int ans=0,asd=0,cnta=0,cntb=0,cntc=0;
	
	asd=0;cnta=cntb=cntc=0;
	memset(used,0,sizeof(used));
	for(int i=1;i<=n;i++){
		if(!used[A[i].id]&&cnta<n/2)asd+=A[i].val,used[A[i].id]=1,cnta++;
		if(!used[B[i].id]&&cntb<n/2)asd+=B[i].val,used[B[i].id]=1,cntb++;
		if(!used[C[i].id]&&cntc<n/2)asd+=C[i].val,used[C[i].id]=1,cntc++;
	}
	ans=max(ans,asd);
	
	asd=0;cnta=cntb=cntc=0;
	memset(used,0,sizeof(used));
	for(int i=1;i<=n;i++){
		if(!used[B[i].id]&&cntb<n/2)asd+=B[i].val,used[B[i].id]=1,cntb++;
		if(!used[A[i].id]&&cnta<n/2)asd+=A[i].val,used[A[i].id]=1,cnta++;
		if(!used[C[i].id]&&cntc<n/2)asd+=C[i].val,used[C[i].id]=1,cntc++;
	}
	ans=max(ans,asd);
	
	asd=0;cnta=cntb=cntc=0;
	memset(used,0,sizeof(used));
	for(int i=1;i<=n;i++){
		if(!used[C[i].id]&&cntc<n/2)asd+=C[i].val,used[C[i].id]=1,cntc++;
		if(!used[A[i].id]&&cnta<n/2)asd+=A[i].val,used[A[i].id]=1,cnta++;
		if(!used[B[i].id]&&cntb<n/2)asd+=B[i].val,used[B[i].id]=1,cntb++;
	}
	ans=max(ans,asd);
	
	asd=0;cnta=cntb=cntc=0;
	memset(used,0,sizeof(used));
	for(int i=1;i<=n;i++){
		if(!used[A[i].id]&&cnta<n/2)asd+=A[i].val,used[A[i].id]=1,cnta++;
		if(!used[C[i].id]&&cntc<n/2)asd+=C[i].val,used[C[i].id]=1,cntc++;
		if(!used[B[i].id]&&cntb<n/2)asd+=B[i].val,used[B[i].id]=1,cntb++;
	}
	ans=max(ans,asd);
	
	asd=0;cnta=cntb=cntc=0;
	memset(used,0,sizeof(used));
	for(int i=1;i<=n;i++){
		if(!used[B[i].id]&&cntb<n/2)asd+=B[i].val,used[B[i].id]=1,cntb++;
		if(!used[C[i].id]&&cntc<n/2)asd+=C[i].val,used[C[i].id]=1,cntc++;
		if(!used[A[i].id]&&cnta<n/2)asd+=A[i].val,used[A[i].id]=1,cnta++;
	}
	ans=max(ans,asd);
	
	asd=0;cnta=cntb=cntc=0;
	memset(used,0,sizeof(used));
	for(int i=1;i<=n;i++){
		if(!used[C[i].id]&&cntc<n/2)asd+=C[i].val,used[C[i].id]=1,cntc++;
		if(!used[B[i].id]&&cntb<n/2)asd+=B[i].val,used[B[i].id]=1,cntb++;
		if(!used[A[i].id]&&cnta<n/2)asd+=A[i].val,used[A[i].id]=1,cnta++;
	}
	ans=max(ans,asd);
	
	cout<<ans<<'\n';
}
signed main (){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdin);
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	int T;cin>>T;
	while(T--)solve();
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
