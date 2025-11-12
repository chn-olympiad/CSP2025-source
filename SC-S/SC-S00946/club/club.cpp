#include<bits/stdc++.h>
using namespace std;
int read(){
	int x=0,f=1;
	char ch=getchar();
	while(ch<'0'||ch>'9'){
		if(ch=='-') f=-1;
		ch=getchar();
	}
	while(ch>='0'&&ch<='9'){
		x=x*10+ch-'0';
		ch=getchar();
	}
	return x*f;
}
int t,n;
struct op{
	int a,b,c;
}m[100100];
int mxx(int o){
	if(m[o].a>=m[o].b&&m[o].a>=m[o].c) return 0;
	if(m[o].b>=m[o].a&&m[o].b>=m[o].c) return 1;
	return 2;
}
int rmx(int o){
	int x=mxx(o);
	if(x==0){
		if(m[o].b>=m[o].c) return 1;
		return 2;
	}
	if(x==1){
		if(m[o].a>=m[o].c) return 0;
		return 2;
	}
	if(x==2){
		if(m[o].a>=m[o].b) return 0;
		return 1;
	}
}
int get(int o,int wei){
	if(wei==0) return m[o].a;
	if(wei==1) return m[o].b;
	if(wei==2) return m[o].c;
}
int cnt[5];
int li[100100],len;
long long ans=0;
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	t=read();
	while(t--){
		n=read();
		cnt[0]=cnt[1]=cnt[2]=0;
		int cu=-1;
		ans=0,len=0;
		for(int i=1;i<=n;i++){
			m[i].a=read(),m[i].b=read(),m[i].c=read();
			int ji=mxx(i);
			cnt[ji]++;
			if(cnt[ji]>(n/2)) cu=ji;
			if(ji==0) ans+=m[i].a;
			else if(ji==1) ans+=m[i].b;
			else if(ji==2) ans+=m[i].c;
		}
		if(cu==-1){
			printf("%lld\n",ans);
		}
		else{
			for(int i=1;i<=n;i++){
				int ji=mxx(i),jo=rmx(i);
				if(ji==cu){
					li[++len]=get(i,ji)-get(i,jo);
				}
			}
			sort(li+1,li+len+1);
			for(int i=1;i<=(len-(n/2));i++) ans-=li[i];
			printf("%lld\n",ans);
		}
	}
	return 0;
}