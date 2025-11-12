#include<bits/stdc++.h>
#define int long long
using namespace std;

inline int read(){
	int x=0,f=1;char c=getchar();
	while(c<48){
		if(c=='-') f=-1;
		c=getchar();
	}
	while(c>47) x=(x<<1)+(x<<3)+(c^48),c=getchar();
	return x*f;
}

inline void write(int x){
	if(x<0) putchar('-'),x=-x;
	if(x<10) putchar(x+'0');
	else write(x/10),putchar(x%10+'0');
}

const int N=1e5+5;
int T,n,a[3][N],num[3],cha[3][2][N],sum,cho[N];
priority_queue<int,vector<int>,greater<int> > q; 

inline void cl(int id){
	if(a[0][id]>=a[1][id]&&a[0][id]>=a[2][id]){
		num[0]++;cho[id]=0;
	}
	else if(a[1][id]>=a[2][id]&&a[1][id]>=a[0][id]){
		num[1]++;cho[id]=1;
	}
	else if(a[2][id]>=a[1][id]&&a[2][id]>=a[0][id]){
		num[2]++;cho[id]=2;
	}
	cha[0][0][id]=a[0][id]-a[1][id];cha[0][1][id]=a[0][id]-a[2][id];
	cha[1][0][id]=a[1][id]-a[0][id];cha[1][1][id]=a[1][id]-a[2][id];
	cha[2][0][id]=a[2][id]-a[0][id];cha[2][1][id]=a[2][id]-a[1][id];
}

inline void solve(int id){
	int numb=0;
	for(int i=1;i<=n;i++){
		if(cho[i]==id){
			q.push(min(cha[id][0][i],cha[id][1][i]));numb++;
		}
	}
	while(numb>n/2){
		int s=q.top();q.pop();
		sum-=s;numb--;
	}
}

inline void INIT(){
	num[0]=num[1]=num[2]=0;sum=0;
	for(int i=1;i<=n;i++){
		cha[0][0][i]=cha[0][1][i]=cha[1][0][i]=0;
		cha[1][1][i]=cha[2][0][i]=cha[2][1][i]=0;
		cho[i]=-1;
	}
	while(!q.empty()) q.pop();
}

signed main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	T=read();
	while(T--){
		n=read();
		INIT();
		for(int i=1;i<=n;i++){
			a[0][i]=read(),a[1][i]=read(),a[2][i]=read();
			sum+=max(max(a[0][i],a[1][i]),a[2][i]);
			cl(i);
		}
		if(num[0]>n/2){
			solve(0);
		}
		else if(num[1]>n/2){
			solve(1);
		}
		else if(num[2]>n/2){
			solve(2);
		}
		printf("%lld\n",sum);
	}
	return 0;
} 
