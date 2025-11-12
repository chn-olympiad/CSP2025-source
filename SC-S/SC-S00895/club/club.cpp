#include<bits/stdc++.h>
#define int long long 
using namespace std;
inline int read(){
	int x=0,f=1;char ch=getchar();
	while(ch<'0'||ch>'9'){if(ch=='-'){f=-1;}ch=getchar();}
	while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
	return x*f;
}
inline void write(int x){
	if(x<0){putchar('-');x=-x;}
	if(x>=10){
		write(x/10);
	}
	putchar(x%10+'0');
}
int t,n,ans;
struct node1{
	int a,b,c,js;
}A[100010];
struct node2{
	int a,b,c,js;	
}B[100010];
struct node3{
	int a,b,c,js;
}C[100010];
int cnt1,cnt2,cnt3,sumA,sumB,sumC;
bool cmp1(node1 x,node1 y){
	return x.js>y.js;	
}
bool cmp2(node2 x,node2 y){
	return x.js>y.js;	
}
bool cmp3(node3 x,node3 y){
	return x.js>y.js;	
}
signed main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	t=read();
	while(t--){
		sumA=sumB=sumC=0;
		cnt1=cnt2=cnt3=0;
		n=read();
		for(int i=1;i<=n;i++){
			int a,b,c;
			a=read();b=read();c=read();
			if(a>=b&&a>=c){
				A[++cnt1].a=a;A[cnt1].b=b;A[cnt1].c=c;
				A[cnt1].js=a-max(b,c);
				sumA+=a;
			}else if(b>=a&&b>=c){
				B[++cnt2].a=a;B[cnt2].b=b;B[cnt2].c=c;
				sumB+=b;
				B[cnt2].js=b-max(a,c);
			}else if(c>=a&&c>=b){
				C[++cnt3].a=a;C[cnt3].b=b;C[cnt3].c=c;
				sumC+=c;
				C[cnt3].js=c-max(b,a);
			}
		}
		ans=sumA+sumB+sumC;
		if(cnt1>n/2){
			sort(A+1,A+cnt1+1,cmp1);
			for(int i=n/2+1;i<=cnt1;i++){
				ans-=A[i].js;
			}
		}else if(cnt2>n/2){
			sort(B+1,B+cnt2+1,cmp2);
			for(int i=n/2+1;i<=cnt2;i++){
				ans-=B[i].js;
			}
		}else if(cnt3>n/2){
			sort(C+1,C+cnt3+1,cmp3);
			for(int i=n/2+1;i<=cnt3;i++){
				ans-=C[i].js;
			}
		}
		write(ans);
		putchar('\n');
	}
	return 0;
}