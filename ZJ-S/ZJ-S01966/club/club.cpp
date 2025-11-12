#include<bits/stdc++.h>
using namespace std;
struct o{
long long d1;
long long d2;
long long d3;	
bool k;
}a[100005];
bool cmp1(o x,o y){
int a1=x.d1;
int a2=x.d2;
int a3=x.d3;
int b1=y.d1;
int b2=y.d2;
int b3=y.d3;
int a4=max(a1,max(a2,a3));
int b4=max(b1,max(b2,b3));
return a4>b4;
}
bool cmp2(o x,o y){
int a1=x.d1;
int a2=x.d2;
int a3=x.d3;
int b1=y.d1;
int b2=y.d2;
int b3=y.d3;
int a4=max(a1,max(a2,a3));
int b4=max(b1,max(b2,b3));
return a4<b4;
}
bool cmp(o x,o y){
int a1=x.d1;
int a2=x.d2;
int a3=x.d3;
int b1=y.d1;
int b2=y.d2;
int b3=y.d3;
if(a1>b1){
return true;	
}
if(a1<b1){
return false;	
}
if(a2>b2){
return true;	
}
if(a2<b2){
return false;	
}
return a3>=b3;
}
bool cmp3(o x,o y){
int a1=x.d1;
int a2=x.d2;
int a3=x.d3;
int b1=y.d1;
int b2=y.d2;
int b3=y.d3;
if(a1<b1){
return true;	
}
if(a1>b1){
return false;	
}
if(a2<b2){
return true;	
}
if(a2>b2){
return false;	
}
return a3<=b3;
}
bool cmp4(o x,o y){
int a1=x.d1;
int a2=x.d2;
int a3=x.d3;
int b1=y.d1;
int b2=y.d2;
int b3=y.d3;
if(a1<b1){
return true;	
}
if(a1>b1){
return false;	
}
if(a2>b2){
return true;	
}
if(a2<b2){
return false;	
}
return a3>=b3;
}
bool cmp5(o x,o y){
int a1=x.d1;
int a2=x.d2;
int a3=x.d3;
int b1=y.d1;
int b2=y.d2;
int b3=y.d3;
int a4=min(a1,min(a2,a3));
int b4=min(b1,min(b2,b3));
return a4<=b4;
}
bool cmp6(o x,o y){
int a1=x.d1;
int a2=x.d2;
int a3=x.d3;
int b1=y.d1;
int b2=y.d2;
int b3=y.d3;
int a4=min(a1,min(a2,a3));
int b4=min(b1,min(b2,b3));
return a4>=b4;
}
bool cmp7(o x,o y){
int a1=x.d1;
int a2=x.d2;
int a3=x.d3;
int b1=y.d1;
int b2=y.d2;
int b3=y.d3;
int a4=max(a1,min(a2,a3));
int b4=min(b1,max(b2,b3));
return a4>=b4;
}
bool cmp8(o x,o y){
int a1=x.d1;
int a2=x.d2;
int a3=x.d3;
int b1=y.d1;
int b2=y.d2;
int b3=y.d3;
int a4=max(a1,max(a2,a3));
int b4=min(b1,min(b2,b3));
return a4>b4;//
}
bool cmp9(o x,o y){
int a1=x.d1;
int a2=x.d2;
int a3=x.d3;
int b1=y.d1;
int b2=y.d2;
int b3=y.d3;
int a4=max(b1,max(a2,a3));
int b4=max(a1,max(b2,b3));
return a4==b4;
}
bool cmp10(o x,o y){
int a1=x.d1;
int a2=x.d2;
int a3=x.d3;
int b1=y.d1;
int b2=y.d2;
int b3=y.d3;
int a4=max(a1,max(b2,a3))*2;
int b4=max(b1,max(a2,b3));
return a4==b4;
}
bool cmp11(o x,o y){
int a1=x.d1;
int a2=x.d2;
int a3=x.d3;
int b1=y.d1;
int b2=y.d2;
int b3=y.d3;
int a4=max(a1,min(b2,a3))+a1-b1;
int b4=max(b1,min(a2,b3))+a2-b2;
return a4>=b4;
}
bool cmp12(o x,o y){
int a1=x.d1;
int a2=x.d2;
int a3=x.d3;
int b1=y.d1;
int b2=y.d2;
int b3=y.d3;
int a4=max(a1,min(b2,a3))-b1;
int b4=max(b1,min(a2,b3))-b2;
return a4<=b4;
}
bool cmp13(o x,o y){
int a1=x.d1;
int a2=x.d2;
int a3=x.d3;
int b1=y.d1;
int b2=y.d2;
int b3=y.d3;
long long a4=max(a1,min(b2,a3))*a1;
long long b4=max(b1,min(a2,b3))*b1;
return a4<b4;
}
bool cmp14(o x,o y){
int a1=x.d1;
int a2=x.d2;
int a3=x.d3;
int b1=y.d1;
int b2=y.d2;
int b3=y.d3;
long long a4=max(a1,min(b2,a3))*a2+a3;
long long b4=max(b1,min(a2,b3))*b2+b3;
return a4>=b4;
}
bool cmp15(o x,o y){
int a1=x.d1;
int a2=x.d2;
int a3=x.d3;
int b1=y.d1;
int b2=y.d2;
int b3=y.d3;
long long a4=max(a1,max(b2,a3))*a2+a3;
long long b4=max(b1,max(a2,b3))*b2+b3;
return a4>b4;
}
long long dp[100005];
int main(){
    freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int t;
	cin>>t;
	for(int w=0;w<t;w++){
	long long ans=-1;
	int n;
	cin>>n;	
	bool ta=1;
	for(int i=0;i<n;i++){
	dp[i]=0;
	cin>>a[i].d1>>a[i].d2>>a[i].d3;
	if(a[i].d2!=0 or a[i].d3!=0){
	ta=0;	
	}
	}
	long long cnt=-1;
	if(ta==1){
		long long ans=0; 
	for(int i=0;i<n/2;i++){
	ans+=a[i].d1;
	}
	cnt=ans;	
	}
	int r1=0;
	int r2=0;
	int r3=0;
	for(int j=0;j<16;j++){
    for(int i=0;i<n;i++){
    int r=0;
    if(i==0) r=0;
    else r=dp[i-1];
    if(r1+1<=n/2) dp[i]=r+a[i].d1;
	if(r2+1<=n/2) dp[i]=max(dp[i],r+a[i].d2);
	if(r3+1<=n/2) dp[i]=max(dp[i],r+a[i].d3);
	int cnt=dp[i]-r;
	if(cnt==a[i].d1 && cnt!=a[i].d2 && cnt!=a[i].d3){
	r1++;	
	}
	if(cnt!=a[i].d1 && cnt==a[i].d2 && cnt!=a[i].d3){
	r2++;	
	}
	if(cnt!=a[i].d1 && cnt!=a[i].d2 && cnt==a[i].d3){
	r3++;	
	}
	//
	if(cnt==a[i].d1 && cnt==a[i].d2 && cnt!=a[i].d3){
	if(r1>r2){
	r2++;	
	}
	else r1++;	
	}
	if(cnt==a[i].d1 && cnt!=a[i].d2 && cnt==a[i].d3){
	if(r1>r3){
	r3++;	
	}
	else r1++;	
	}
	if(cnt!=a[i].d1 && cnt==a[i].d2 && cnt==a[i].d3){
	if(r3>r2){
	r2++;	
	}
	else r3++;	
	}
	}
	ans=max(ans,dp[n-1]); 
	for(int i=0;i<n;i++){
	dp[i]=0;	
	}
	if(j==0) sort(a,a+n,cmp);
	if(j==1) sort(a,a+n,cmp2);
	if(j==2) sort(a,a+n,cmp3);
	if(j==3) sort(a,a+n,cmp4);
	if(j==4) sort(a,a+n,cmp5);
	if(j==5) sort(a,a+n,cmp6);
	if(j==6) sort(a,a+n,cmp7);
	if(j==7) sort(a,a+n,cmp8);
	if(j==8) sort(a,a+n,cmp9);
	if(j==9) sort(a,a+n,cmp10);
	if(j==10) sort(a,a+n,cmp1);
	if(j==11) sort(a,a+n,cmp11);
	if(j==12) sort(a,a+n,cmp12);
	if(j==13) sort(a,a+n,cmp13);
	if(j==14) sort(a,a+n,cmp14);
	if(j==15) sort(a,a+n,cmp15);
	r1=0;
	r2=0;
	r3=0;
	
}
	cout<<max(cnt,ans)<<endl;
	}
	
	
	
return 0;	
} 
