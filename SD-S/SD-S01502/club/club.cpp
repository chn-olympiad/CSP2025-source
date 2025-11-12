#include<bits/stdc++.h>
#define ll long long
using namespace std;
ll t,n;
const ll N=1e5;
struct cc{
	ll lv1,lv2,lv3;
}a[N];
struct xam{
	ll num,val;
};
bool cmp(cc x,cc y){
	return max(x.lv1,max(x.lv2,x.lv3))>max(y.lv1,max(y.lv2,y.lv3));
}
void solve2();
void solve4();
void solve(){
	cin>>n;
	if(n==2){
		solve2();
		return;
	}
	if(n==4){
		solve4();
		return;
	}
	ll m=n/2,fir=m,sec=m,tir=m,ans=0,f=0,nx,sc;
	for(ll i=1;i<=n;i++){
		cin>>a[i].lv1>>a[i].lv2>>a[i].lv3;
	}
	sort(a+1,a+n+1,cmp);
	for(ll i=1;i<=n;i++){
		xam ma;
		ma.val=max(a[i].lv1,max(a[i].lv2,a[i].lv3));
		if(ma.val==a[i].lv1) fir--;
		else if(ma.val==a[i].lv2) sec--;
		else tir--;
		if(fir<0||sec<0||tir<0) break;
		ans+=ma.val;
	}
	cout<<ans<<'\n';
	return;
}
int main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	while(t--){
		solve();	
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
} 
void solve2(){
	ll a1,a2,a3,a4,a5,a6;
	cin>>a1>>a2>>a3>>a4>>a5>>a6;
	ll t1=a1+a5;
	ll t2=a1+a6;
	ll t3=a2+a4;
	ll t4=a2+a6;
	ll t5=a3+a4;
	ll t6=a3+a5;
	cout<<max(max(max(max(max(t1,t2),t3),t4),t5),t6)<<'\n';
	return;
}
void solve4(){
	ll a1,a2,a3,a4,a5,a6,a7,a8,a9,a10,a11,a12,t[66];
	memset(t,0,sizeof(t));
	cin>>a1>>a2>>a3>>a4>>a5>>a6>>a7>>a8>>a9>>a10>>a11>>a12;
	t[1]=a1+a4+a8+a11;
	t[2]=a1+a4+a8+a12;
	t[3]=a1+a4+a9+a11;
	t[4]=a1+a4+a9+a12;
	t[5]=a1+a5+a7+a11;
	t[6]=a1+a5+a7+a12;
	t[7]=a1+a5+a8+a10;
	t[8]=a1+a5+a8+a12;
	t[9]=a1+a5+a9+a10;
	t[10]=a1+a5+a9+a11;
	t[11]=a1+a5+a9+a12;
	t[12]=a1+a6+a7+a11;
	t[13]=a1+a6+a7+a12;
	t[14]=a1+a6+a8+a10;
	t[15]=a1+a6+a8+a11;
	t[16]=a1+a6+a8+a12;
	t[17]=a1+a6+a9+a10;
	t[18]=a1+a6+a9+a11;
	t[19]=a2+a4+a7+a11;
	t[20]=a2+a4+a7+a12;
	t[21]=a2+a4+a8+a10;
	t[22]=a2+a4+a8+a12;
	t[23]=a2+a4+a9+a10;
	t[24]=a2+a4+a9+a11;
	t[25]=a2+a4+a9+a12;
	t[26]=a2+a5+a7+a10;
	t[27]=a2+a5+a7+a12;
	t[28]=a2+a5+a9+a10;
	t[29]=a2+a5+a9+a12;
	t[30]=a2+a6+a7+a10;
	t[31]=a2+a6+a7+a11;
	t[32]=a2+a6+a7+a12;
	t[33]=a2+a6+a8+a10;
	t[34]=a2+a6+a8+a12;
	t[35]=a2+a6+a9+a10;
	t[36]=a2+a6+a9+a11;
	t[37]=a3+a4+a7+a11;
	t[38]=a3+a4+a7+a12;
	t[39]=a3+a4+a8+a10;
	t[40]=a3+a4+a8+a11;
	t[41]=a3+a4+a8+a12;
	t[42]=a3+a4+a9+a10;
	t[43]=a3+a4+a9+a11;
	t[44]=a3+a5+a7+a10;
	t[45]=a3+a5+a7+a11;
	t[46]=a3+a5+a7+a12;
	t[47]=a3+a5+a8+a10;
	t[48]=a3+a5+a8+a12;
	t[49]=a3+a5+a9+a10;
	t[50]=a3+a5+a9+a11;
	t[51]=a3+a6+a7+a10;
	t[52]=a3+a6+a7+a11;
	t[53]=a3+a6+a8+a10;
	t[54]=a3+a6+a8+a11;
	sort(t+1,t+60,greater<ll>());
	cout<<t[1]<<'\n';
	return;
}
/*
我这辈子行善积德，扶老奶奶过马路，图灵爷爷在上，助我破鼎 
*/ 
