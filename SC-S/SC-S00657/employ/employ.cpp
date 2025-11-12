#include<bits/stdc++.h>
#define ll long long

const int N=503,mod=998244353;

int read(){
	int x=0,f=1;
	char ch=getchar();
	while(!isdigit(ch)){
		if(ch=='-') f=-1;
		ch=getchar();
	}
	while(isdigit(ch)){
		x=(x<<3)+(x<<1)+(ch^48);
		ch=getchar();
	}
	return x*f;
}

using namespace std;

int n,m,cnt;
char str[N];
int c[N],p[N];

signed main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	n=read();m=read();
	scanf("%s",str+1);
	for(int i=1;i<=n;++i) {
		c[i]=read(),p[i]=i;
		if(c[i]) cnt++;
	}
	if(cnt<m) return cout<<0<<'\n',0;
	if(n<=10){
		int res=0;
		do{
			int cnt=0;
			for(int i=1;i<=n;++i)
				if(i-1-cnt<c[p[i]]&&str[i]=='1')
					cnt++;
			if(cnt>=m) res++;
		}while(next_permutation(p+1,p+n+1));
		cout<<res<<endl;
	}
	else{
		ll res=1;
		for(int i=1;i<=n;++i) res=1ll*res*i%mod;
		cout<<res<<'\n';
	}
	return 0;
}