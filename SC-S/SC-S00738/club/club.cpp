#include<bits/stdc++.h>
using namespace std;
const int MAXN=1e5+5;
int maxa,maxb,maxc,maxa2=-1e9,ai,bi,ci;
int a[MAXN];
int b[MAXN];
int c[MAXN];
void init(int n){
	for(int i=0;i<n;i++){
		a[i]=0;
		b[i]=0;
		c[i]=0;
	}
}
void MAXa(int n){
	int maxn=-1e9;
	for(int i=0;i<n;i++){
		if(a[i]>maxn){
			maxn=a[i];
			ai=i;
		}
	}
	maxa=maxn;
	return;
}
void MAXb(int n){
	int maxn=-1e9;
	for(int i=0;i<n;i++){
		if(b[i]>maxn){
			maxn=b[i];
			bi=i;
		}
	}
	maxb=maxn;
	return;
}
void MAXc(int n){
	int maxn=-1e9;
	for(int i=0;i<n;i++){
		if(c[i]>maxn){
			maxn=c[i];
			ci=i;
		}
	}
	maxc=maxn;
	return;
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int t,n,sum=0,suma=0,sumb=0,sumc=0,a2i=1;
	cin>>t;
	while(t--){
		init(n);
		cin>>n;
		for(int i=0;i<n;i++){
			scanf("%d %d %d",&a[i],&b[i],&c[i]);
		}
		for(int i=0;i<n;i++){
			MAXa(n);MAXb(n);MAXc(n);
			maxa2=-1e9;
			for(int j=0;j<n;j++){
				if(maxa2<a[j]&&a[j]<maxa){
					maxa2=a[j];a2i=j;
				}
			}
			if(suma>=n/2){
				for(int j=0;j<n;j++){
					a[j]=0;
				}
			}if(sumb>=n/2){
				for(int j=0;j<n;j++){
					b[j]=0;
				}
			}if(sumc>=n/2){
				for(int j=0;j<n;j++){
					c[j]=0;
				}
			}
			if(max(maxc,max(maxa,maxb))==maxc){
				MAXa(n);MAXb(n);
				sum+=maxc;sumc++;a[ci]=0;b[ci]=0;c[ci]=0;
				if(max(maxa,maxb)==maxa){
					sum+=maxa;suma++;
					a[ai]=0;b[ai]=0;c[ai]=0;
				}else{
					sum+=maxb;sumb++;
					a[bi]=0;b[bi]=0;c[bi]=0;	
				}
			}else if(max(maxc,max(maxa,maxb))==maxb){
				sum+=maxb;sumb++;
				a[bi]=0;b[bi]=0;c[bi]=0;
				MAXa(n);MAXc(n);
				if(max(maxa,maxb)==maxa){
					sum+=maxa;suma++;
					a[ai]=0;b[ai]=0;c[ai]=0;
				}else{
					sum+=maxc;sumc++;
					a[ci]=0;b[ci]=0;c[ci]=0;
				}
			}else{
				if(maxb+maxa2>maxa){
					sum+=maxb+maxa2;
					MAXb(n);MAXc(n);
					a[ai]=0;b[ai]=0;c[ai]=0;
					a[a2i]=0;b[a2i]=0;c[a2i]=0;					
					if(max(maxc,maxb)==maxb){
						sum+=maxb;sumb++;
						a[bi]=0;b[bi]=0;c[bi]=0;
					}else{
						sum+=maxc;sumc++;
						a[ci]=0;b[ci]=0;c[ci]=0;
					}
				}else{
					sum+=maxa;suma++;
					MAXb(n);MAXc(n);
					a[ai]=0;b[ai]=0;c[ai]=0;
					if(max(maxc,maxb)==maxb){
						sum+=maxb;sumb++;
						a[bi]=0;b[bi]=0;c[bi]=0;
					}else{
						sum+=maxc;sumc++;
						a[ci]=0;b[ci]=0;c[ci]=0;
					}
				}
			}
		}
		cout<<sum<<"\n";
		sum=0;
	}
	
	return 0;
}
