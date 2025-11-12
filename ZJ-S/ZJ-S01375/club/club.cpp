#include<bits/stdc++.h>
#define int long long
using namespace std;
int T,n,a[100005][4],t[5],id[100005];
int read(){
	char c=getchar();int x=0;bool f=0;
	while(c>'9'||c<'0'){
		if(c=='-')f=1;
		c=getchar();
	}
	while(c>='0'&&c<='9')x=(x<<3)+(x<<1)+(c^48),c=getchar();
	if(f)return -x;
	return x;
}
priority_queue<int> q;
int midnum(int x){
	int tmp[5];
	tmp[0]=a[x][0],tmp[1]=a[x][1],tmp[2]=a[x][2];
	sort(tmp,tmp+3);
	return tmp[1];
}
signed main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	T=read();
	while(T--){
		n=read();
		int ans=0;
		while(!q.empty())q.pop();
		t[0]=t[1]=t[2]=0;
		for(int i=1;i<=n;i++){
			a[i][0]=read(),a[i][1]=read(),a[i][2]=read();
			int ma=max(a[i][0],max(a[i][1],a[i][2]));
			ans+=ma;
			if(ma==a[i][0])t[0]++,id[i]=0;
			else if(ma==a[i][1])t[1]++,id[i]=1;
			else if(ma==a[i][2])t[2]++,id[i]=2;
		}
		int w=0,ma=0;
		for(int i=0;i<3;i++)if(t[i]>ma)ma=t[i],w=i;
		for(int i=1;i<=n;i++){
			if(id[i]==w)q.push(midnum(i)-a[i][w]);
		}
		while(t[w]>n/2)ans+=q.top(),t[w]--,q.pop();
		printf("%lld\n",ans);
	}
	return 0;
}
