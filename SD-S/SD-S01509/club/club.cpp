#include<iostream>
#include<algorithm>
#include<cstring>
using namespace std;
inline char gc(){
	static char BB[1<<20],*S=BB,*T=BB;
	return S==T&&(T=(S=BB)+fread(BB,1,1<<20,stdin),S==T)?EOF:*S++;
}
inline int read(){
	int x=0;char ch=gc();
	while(ch<48) ch=gc();
	while(ch>=48) x=(x<<3)+(x<<1)+(ch^48),ch=gc();
	return x;
}
const int N=1e5+10;
int n;
struct node{
	int a,b,c;
}a[N];
bool cmpa(node x,node y){return x.a>y.a;}
bool cmpb(node x,node y){return x.b>y.b;}
bool cmpc(node x,node y){return x.c>y.c;}
int check1(){
	int ans=0,ans1=0,ans2=0;
	for(int k=0;k<=n/2;k++){
		sort(a+1,a+1+n,cmpa);
		ans1=0;
		for(int i=1;i<=k;i++) ans1+=a[i].a;
		sort(a+k+1,a+1+n,cmpb);
		for(int j=0;j<=n/2;j++){
			if(j+k<n/2) continue;
			ans2=ans1;
			for(int i=k+1;i<=k+j;i++) ans2+=a[i].b;
			for(int i=k+j+1;i<=n;i++) ans2+=a[i].c;
			ans=max(ans,ans2);
		}
	}
	for(int k=0;k<=n/2;k++){
		sort(a+1,a+1+n,cmpa);
		ans1=0;
		for(int i=1;i<=k;i++) ans1+=a[i].a;
		sort(a+k+1,a+1+n,cmpc);
		for(int j=0;j<=n/2;j++){
			if(j+k<n/2) continue;
			ans2=ans1;
			for(int i=k+1;i<=k+j;i++) ans2+=a[i].c;
			for(int i=k+j+1;i<=n;i++) ans2+=a[i].b;
			ans=max(ans,ans2);
		}
	}
	for(int k=0;k<=n/2;k++){
		sort(a+1,a+1+n,cmpb);
		ans1=0;
		for(int i=1;i<=k;i++) ans1+=a[i].b;
		sort(a+k+1,a+1+n,cmpa);
		for(int j=0;j<=n/2;j++){
			if(j+k<n/2) continue;
			ans2=ans1;
			for(int i=k+1;i<=k+j;i++) ans2+=a[i].a;
			for(int i=k+j+1;i<=n;i++) ans2+=a[i].c;
			ans=max(ans,ans2);
		}
	}
	for(int k=0;k<=n/2;k++){
		sort(a+1,a+1+n,cmpb);
		ans1=0;
		for(int i=1;i<=k;i++) ans1+=a[i].b;
		sort(a+k+1,a+1+n,cmpc);
		for(int j=0;j<=n/2;j++){
			if(j+k<n/2) continue;
			ans2=ans1;
			for(int i=k+1;i<=k+j;i++) ans2+=a[i].c;
			for(int i=k+j+1;i<=n;i++) ans2+=a[i].a;
			ans=max(ans,ans2);
		}
	}
	for(int k=0;k<=n/2;k++){
		sort(a+1,a+1+n,cmpc);
		ans1=0;
		for(int i=1;i<=k;i++) ans1+=a[i].c;
		sort(a+k+1,a+1+n,cmpa);
		for(int j=0;j<=n/2;j++){
			if(j+k<n/2) continue;
			ans2=ans1;
			for(int i=k+1;i<=k+j;i++) ans2+=a[i].a;
			for(int i=k+j+1;i<=n;i++) ans2+=a[i].b;
			ans=max(ans,ans2);
		}
	}
	for(int k=0;k<=n/2;k++){
		sort(a+1,a+1+n,cmpc);
		ans1=0;
		for(int i=1;i<=k;i++) ans1+=a[i].c;
		sort(a+k+1,a+1+n,cmpb);
		for(int j=0;j<=n/2;j++){
			if(j+k<n/2) continue;
			ans2=ans1;
			for(int i=k+1;i<=k+j;i++) ans2+=a[i].b;
			for(int i=k+j+1;i<=n;i++) ans2+=a[i].a;
			ans=max(ans,ans2);
		}
	}
	return ans;
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int T=read();
	while(T--){
		n=read();
		for(int i=1;i<=n;i++) a[i].a=read(),a[i].b=read(),a[i].c=read();
		int ans=0,ans1;
		if(n<=200) ans=check1();
		sort(a+1,a+1+n,cmpa);ans1=0;
		for(int i=1;i<=n/2;i++) ans1+=a[i].a;
		for(int i=n/2+1;i<=n;i++) ans1+=max(a[i].b,a[i].c);
		ans=max(ans,ans1);ans1=0;
		sort(a+1,a+1+n,cmpb);
		for(int i=1;i<=n/2;i++) ans1+=a[i].b;
		for(int i=n/2+1;i<=n;i++) ans1+=max(a[i].a,a[i].c);
		ans=max(ans,ans1);ans1=0;
		sort(a+1,a+1+n,cmpc);
		for(int i=1;i<=n/2;i++) ans1+=a[i].c;
		for(int i=n/2+1;i<=n;i++) ans1+=max(a[i].a,a[i].b);
		ans=max(ans,ans1);
		cout<<ans<<"\n";
	} 
	return 0;
}

