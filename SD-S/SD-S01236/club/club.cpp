#include<bits/stdc++.h>
using namespace std;
const int N=1e5+10;
inline int read(){
	int f=1,x=0;char c=getchar();
	while(c<'0'||c>'9'){
		if(c=='-') f=-1;
		c=getchar();
	}
	while(c>='0'&&c<='9'){
		x=(x<<1)+(x<<3)+c-'0';
		c=getchar();
	}
	return f*x;
}
int a[N][10],n,cnt[10],sum,sur;
bool fl=true;
struct nd{
	int d1,d2,max,mid,min,id,bel;
	bool okk=false;
};
nd b[N];
void dval(int h,int hh,int hhh,int x){
	b[x].d1=a[x][h]-a[x][hh];
	b[x].d2=a[x][hh]-a[x][hhh];
	b[x].id=x;
	b[x].max=h;b[x].mid=hh;b[x].min=hhh;b[x].bel=h;
	cnt[h]++; sum+=a[x][h]; 
	if(cnt[h]*2>n){
		fl=false; sur=h;
	} 
}
void init(int x){
	if(a[x][1]>=a[x][2]){
		if(a[x][2]>=a[x][3]){
			dval(1,2,3,x);
		}
		else{
			if(a[x][1]>=a[x][3]){
				dval(1,3,2,x);
			}
			else{
				dval(3,1,2,x);
			}
		
		}
	}
	else{
		if(a[x][2]>=a[x][3]){
			if(a[x][1]>=a[x][3]){
				dval(2,1,3,x);
			}
			else{
				dval(2,3,1,x);
			}
		}
		else{
			dval(3,2,1,x);
		}
	}
}
bool cmp1(nd x,nd y){
	return x.d1<y.d1;
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int T=read();
	while(T--){
		n=read();
		sum=0;
		cnt[1]=0;cnt[2]=0;cnt[3]=0;
		fl=true;
		for(int i=1;i<=n;i++){
			a[i][1]=read();a[i][2]=read();a[i][3]=read();
			init(i);
		}
		if(!fl){
			sort(b+1,b+n+1,cmp1);
			int cnt0=0;
			for(int i=1;i<=n;i++){
				if(b[i].bel==sur){
					cnt[b[i].bel]--;
					cnt[b[i].mid]++;
					cnt0++; sum-=b[i].d1;
					if(cnt[b[i].bel]*2==n){
						break;
					}
				} 
			}
		}
		printf("%d\n",sum);
	}
	return 0;
}
