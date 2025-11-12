#include<bits/stdc++.h>
using namespace std;
#define rep1(i,x,y) for(int i=(x);i<=(y);++i)
#define rep2(i,x,y) for(int i=(x);i>=(y);--i)
#define sp putchar(' ')
#define ln putchar('\n')
#define int long long
int read(){
	int x=0;
	char c=getchar();
	bool p=0;
	while(c<'0'||c>'9'){
		p=(c=='-'?1:p);
		c=getchar();
	}while(c>='0'&&c<='9'){
		x=(x<<3)+(x<<1)+(c^48);
		c=getchar();
	}return (p?~(x-1):x);
}void write(int x){
	if(x<0){
		putchar('-');
		x=~(x-1);
	}if(x>9)write(x/10);
	putchar(x%10|48);
}struct edge{
	int u,v,w;
	bool operator<(const edge&t)const{return w<t.w;}
}ee[1000010],e[2000010];
int n,m,k,f[20010],a[20][10010],c[20],minn=LLONG_MAX;
bool fl;
int fd(int x){return x==f[x]?x:f[x]=fd(f[x]);}
void ad(int x,int y){f[fd(y)]=fd(x);}
signed main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	n=read();m=read();k=read();
	if(n<=1000&&m<=100000&&k<=5)fl=1;
	rep1(i,1,m)ee[i]={read(),read(),read()};
	rep1(i,1,k){
		c[i]=read();
		if(!fl){
			if(c[i])fl=1;
			int s=0;
			rep1(j,1,n){
				a[i][j]=read();
				s+=(!a[i][j]);
			}if(!s)fl=1;
			continue;
		}rep1(j,1,n)a[i][j]=read();
	}if(!fl){
		rep1(i,1,m)e[i]=ee[i];
		int sum=0,s=0,ll=m;
		rep1(i,1,k){
			int p=0;
			rep1(j,1,n)
				if(!a[i][j]){
					p=j;
					break;
				}
			rep1(j,1,n)
				if(p!=j)e[++ll]={p,j,a[i][j]};
		}rep1(i,1,n)f[i]=i;
		sort(e+1,e+ll+1);
		rep1(i,1,ll){
			if(fd(e[i].u)==fd(e[i].v))continue;
			ad(e[i].u,e[i].v);
			sum+=e[i].w;
			s++;
			if(s==n)break;
		}write(sum);
		return 0;
	}rep1(tt,0,(1<<k)-1){
		int l=n,sum=0,ll=m,s=0;
		rep1(i,1,m)e[i]=ee[i];
		rep1(i,1,k)
			if(tt&(1<<i-1)){
				l++;
				sum+=c[i];
				rep1(j,1,n)e[++ll]={j,l,a[i][j]};
			}
		rep1(i,1,l)f[i]=i;
		sort(e+1,e+ll+1);
		rep1(i,1,ll){
			if(fd(e[i].u)==fd(e[i].v))continue;
			ad(e[i].u,e[i].v);
			sum+=e[i].w;
			s++;
			if(s==n)break;
		}minn=min(minn,sum);
	}write(minn);
	return 0;
}/*
期望 AC :1~10,13~14,17~18
期望得分:56pts
保守得分:16pts
但rp高一点没准能艹过11&12 ovo
4 4 2
1 4 6
2 3 7
4 2 5
4 3 4
1 1 8 2 4
100 1 3 2 4
*/
