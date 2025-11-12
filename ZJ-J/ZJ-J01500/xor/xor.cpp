#include<bits/stdc++.h>
using namespace std;
int a[200005],sum,n,k,cnt,ans;
int read(){
	int ret=0,f=1;char ch=getchar();
	while(!isdigit(ch)){if(ch=='-') f=-f;ch=getchar();}
	while(isdigit(ch)){ret=ret*10+ch-'0';ch=getchar();}
	return ret*f;
}
struct jrt{
	int l,r;
	bool operator<(const jrt b)const{return l<b.l;}
}qj[200005];
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	n=read();k=read();
	if(n<=2&&k==0){
		if(n==1&&read()==0){printf("1");else printf("0");}
		else if(n==2){int f=read(),g=read();if(f^g==0||f==0||g==0) printf("1");else printf("0");}
		return 0; 
	}
	for(int i=1;i<=n;i++) a[i]=read();
	for(int i=1;i<=n;i++){
		for(int j=i;j<=n;j++){
			sum=a[i];
			for(int l=i+1;l<=j;l++) sum^=a[l];
			if(sum==k){qj[++cnt].l=i;qj[cnt].r=j;}
		}
	}
	sort(qj+1,qj+n+1);
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			if(!(qj[i-1].r<qj[i].l&&qj[i-1].r!=qj[i].r&&qj[i-1].l!=qj[i].l)&&qj[i-1].l!=-1&&qj[i].l!=-1&&qj[i-1].r!=-1&&qj[i].r!=-1){
				if(qj[i-1].l-qj[i-1].r<qj[i].l-qj[i].r){qj[i].l=-1;qj[i].r=-1;}
				else{qj[i-1].l=-1;qj[i-1].r=-1;}
			}
		}
	}
	for(int i=1;i<=n;i++) if(qj[i].l!=-1&&qj[i].r!=-1) ans++;
	printf("%d\n",ans);
	return 0;
}
