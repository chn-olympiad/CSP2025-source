#include <bits/stdc++.h>
#define ll long long
using namespace std;
int read(){
	int x=0,f=1;
	char c=getchar();
	while(c<'0'||c>'9'){
		if(c=='-'){
			f=-1;
		}
		c=getchar();
	}
	while(c>='0'&&c<='9'){
		x=x*10+(c-'0');
		c=getchar();
	}
	return x*f;
}
int cmp1(int a,int b){
	return a>b;
}
int a[101000][4],n;
int s[4];ll ss=-1;
bool f=1;//1表示该特殊性质满足 
void dfs(int x,ll manyi){
	ss=max(manyi,ss);
	if(x>n){
		return ;
	}
	for(int i=1;i<=3;i++){
		if(s[i]<n/2){
			s[i]++;
			dfs(x+1,manyi+a[x][i]);
			s[i]--;
		}
	}
	return ;
}
struct I_LOVE_CCF{
	int a,b,c,x;//x用来保存a比b优多少 
}ab[110000];
int cmp2(I_LOVE_CCF a,I_LOVE_CCF b){
	return a.x>b.x;
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int T=read();
	while(T>0){
		T--;
		ss=0;
		f=1;
		for(int i=1;i<=3;i++){
			s[i]=0;
		}
		n=read();
		for(int i=1;i<=n;i++){
			for(int j=1;j<=3;j++){
				a[i][j]=read();
				if(j==3&&a[i][j]!=0){
					f=0;
				} 

			}
		}
//		if(fa==1){
//			int b[100004];
//			for(int i=1;i<=n;i++){
//				b[i]=a[i][1];
//			}
//			sort(b+1,b+n+1,cmp1);
//			for(int i=1;i<=n/2;i++){
//				ss+=b[i];
//			}
//			cout<<ss<<endl;
//			continue;
//		}
		if(f==1){
			for(int i=1;i<=n;i++){
				ab[i].a=a[i][1];
				ab[i].b=a[i][2];
				ab[i].x=ab[i].a-ab[i].b;
			} 
			sort(ab+1,ab+1+n,cmp2);
			for(int i=1;i<=n;i++){
				if(i<=n/2){
					ss+=ab[i].a;
				}else{
					ss+=ab[i].b;
				}
			}
			cout<<ss<<endl;
			continue;
		}
		dfs(1,0);
		cout<<ss<<endl;
	}
	return 0;
}
//oh ccf I love you
//I hope you could let me go to NOIP 
//shuan Q
