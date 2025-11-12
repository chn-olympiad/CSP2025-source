#include<bits/stdc++.h>
using namespace std;
#define int long long
#define inf 1e18+10
inline int read(){
	int f=1,x=0;
	char ch=getchar();
	while(ch>'9'||ch<'0'){
		if(ch=='-')	f=-f;
		ch=getchar();
	}
	while(ch>='0'&&ch<='9')	x=x*10+ch-'0',ch=getchar();
	return x*f;
}
inline void write(int x){
	if(x<0)	x=-x,putchar('-');
	if(x>9)	write(x/10);
	putchar(x%10+'0');
	return;
}
int n;
struct Murasame{
	int a,b,c;
	int maxx,mid;
}e[100001];
int num[4],ans;
bool cmp(Murasame x,Murasame y){return x.maxx-x.mid>y.maxx-y.mid;}
void solve(int t,int i){
	if(t==1){
		if(num[3]==n/2)	ans+=e[i].a,num[1]++;
		else	ans+=e[i].c,num[3]++;
	}
	if(t==2){
		if(num[1]==n/2)	ans+=e[i].c,num[3]++;
		else	ans+=e[i].a,num[1]++;
	}
	if(t==3){
		if(num[1]==n/2)	ans+=e[i].b,num[2]++;
		else	ans+=e[i].a,num[1]++;
	}
	if(t==4){
		if(num[2]==n/2)	ans+=e[i].a,num[1]++;
		else	ans+=e[i].b,num[2]++;
	}
	if(t==5){
		if(num[2]==n/2)	ans+=e[i].c,num[3]++;
		else	ans+=e[i].b,num[2]++;
	}
	if(t==6){
		if(num[3]==n/2)	ans+=e[i].b,num[2]++;
		else	ans+=e[i].c,num[3]++;
	}
}
signed main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int T=read();
	while(T--){
		n=read();
		memset(num,0,sizeof(num));
		for(int i=1;i<=n;i++){
			e[i].a=read(),e[i].b=read(),e[i].c=read();
			int x=max(max(e[i].a,e[i].b),e[i].c),z;
			if(e[i].a>e[i].b){
				if(e[i].c>e[i].a)	z=e[i].a;
				else{
					if(e[i].c>e[i].b)	z=e[i].c;
					else	z=e[i].b;
				}
			}
			else{
				if(e[i].c<e[i].a)	z=e[i].a;
				else{
					if(e[i].c<e[i].b)	z=e[i].c;
					else	z=e[i].b;
				}
			}
			e[i].maxx=x,e[i].mid=z;
		}	
		sort(e+1,e+1+n,cmp);
//		for(int i=1;i<=n;i++)	cout<<e[i].a<<" "<<e[i].b<<" "<<e[i].c<<endl;
		ans=0;
		for(int i=1;i<=n;i++){
			int flag;
			if(e[i].a>e[i].b){
				if(e[i].c>e[i].a)	flag=1;//c>a>b
				else{
					if(e[i].c>e[i].b)	flag=2;//a>c>b
					else	flag=3;//a>b>c
				}               
			}     
			else{
				if(e[i].c<e[i].a)	flag=4;//b>a>c
				else{
					if(e[i].c<e[i].b)flag=5;//b>c>a
					else	flag=6;//c>b>a
				} 
			} 
			solve(flag,i);
		}
		write(ans),puts("");
	}
}