#include<bits/stdc++.h>
using namespace std;
int n,p,m,a1,a2,a3,sum,f1,f2,f3,danan=0,f11,f22,sb[10001];
int dp[3][10000];
struct kk{
	int a,b,c,ping;
}a[10001];
bool se(kk x,kk y){
	return x.c>y.c;
}
void f(int k,int f1,int f2,int f3){
	if(k-1==m){
		danan=max(danan,sum);
		return;
	}
	if(f1<p){
		a1=a[k].a;
		sum+=a1;
		f(k+1,f1+1,f2,f3);
		sum-=a[k].a;
	}
	if(f2<p){
		a2=a[k].b;
		sum+=a2;
		f(k+1,f1,f2+1,f3);
		sum-=a[k].b;
	}
	if(f3<p){
		a3=a[k].c;
		sum+=a3;
		f(k+1,f1,f2,f3+1);
		sum-=a[k].c;
	}
	return;
}
void ff(){
	for(int i=1;i<=m;i++){
		a[i].c=a[i].a-a[i].b;
		if(a[i].c<0){
			a[i].c=-a[i].c;
			a[i].ping=1;
		}
	}
	sort(a+1,a+1+m,se);
	for(int i=1;i<=m;i++){
		if(a[i].ping==0 && f11!=p){
			danan+=a[i].a;
			sb[i]=1;
			f11++;
		}else{
			if(f22!=p){
				danan+=a[i].b;
				sb[i]=1;
				f22++;
			}
		}
	}
	for(int i=1;i<=m;i++){
		if(f11==p && sb[i]!=1){
			danan+=a[i].b;
		}else if(f22==p && sb[i]!=1){
			danan+=a[i].a;
		}
	}
	for(int i=1;i<=m;i++){
		sb[i]=0;
		a[i].ping=0;
	}
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>m;
		p=m/2;
		for(int j=1;j<=m;j++){
			cin>>a[j].a>>a[j].b>>a[j].c;
		}
		if (m<190){
			f(1,0,0,0);
		}else{
			ff();
			f11=0;
			f22=0;
		}
		
		cout<<danan<<endl;
		danan=0;
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
} 
