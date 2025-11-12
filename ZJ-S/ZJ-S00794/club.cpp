#include<bits/stdc++.h>//teshuxingzhiweida
#define int long long
using namespace std;
const int N=1e6+5;
const int mod=1e9+7;
const int eps=1e-6;
struct node{
	int A,B,C;
}a[N];
bool cmp(node a1,node b1){
	if(a1.A==0){
		if(b1.A==0)return abs(a1.B-a1.C)>abs(b1.B-b1.C);
		if(b1.B==0)return abs(a1.B-a1.C)>abs(b1.A-b1.C);
		if(b1.C==0)return abs(a1.B-a1.C)>abs(b1.A-b1.B);
	}
	if(a1.B==0){
		if(b1.A==0)return abs(a1.A-a1.C)>abs(b1.B-b1.C);
		if(b1.B==0)return abs(a1.A-a1.C)>abs(b1.A-b1.C);
		if(b1.C==0)return abs(a1.A-a1.C)>abs(b1.A-b1.B);
	}
	if(a1.C==0){
		if(b1.A==0)return abs(a1.A-a1.B)>abs(b1.B-b1.C);
		if(b1.B==0)return abs(a1.A-a1.B)>abs(b1.A-b1.C);
		if(b1.C==0)return abs(a1.A-a1.B)>abs(b1.A-b1.B);
	}
	return max(a1.A,max(a1.B,a1.C))>max(b1.A,max(b1.B,b1.C));
}
bool cmp1(node a1,node b1){
	return a1.A>b1.A;
}
int read(){
	int k=0,f=1;
	char ch=getchar();
	while(ch<'0'||ch>'9'){
		if(ch=='-')f=-1;
		ch=getchar();
	}
	while(ch>='0'&&ch<='9'){
		k=k*10+ch-'0';
		ch=getchar();
	}
	return k*f;
}
int n,ans,acnt,bcnt,ccnt;
int Maxa,Maxb,Maxc;
void solve(){
	ans=acnt=bcnt=ccnt=Maxa=Maxb=Maxc=0;
	n=read();
	for(int i=1;i<=n;i++){
		a[i].A=read();a[i].B=read();a[i].C=read();
		int Min=min(a[i].A,min(a[i].B,a[i].C));
		a[i].A-=Min;a[i].B-=Min;a[i].C-=Min;
		Maxa=max(Maxa,a[i].A);
		Maxb=max(Maxb,a[i].B);
		Maxc=max(Maxc,a[i].C);
		ans+=Min;
	}
	if(Maxb==0&&Maxc==0){
		sort(a+1,a+1+n,cmp1);
		int ans=0;
		for(int i=1;i<=n/2;i++)
			ans+=a[i].A;
		cout<<ans<<'\n';
		return ;
	}
//	cout<<ans<<'\n';
	sort(a+1,a+1+n,cmp);
	for(int i=1;i<=n;i++){
		int Aa=a[i].A,Bb=a[i].B,Cc=a[i].C;
//		cout<<a[i].A<<' '<<a[i].B<<' '<<a[i].C<<'\n';
		int Acnt=acnt,Bcnt=bcnt,Ccnt=ccnt;
		if(Aa==0){
			if(Bb>=Cc){
				if(bcnt+1<=n/2)ans+=Bb,bcnt++;
				else if(ccnt+1<=n/2)ans+=Cc,ccnt++;
				else ans+=Aa,acnt++;
			}
			else{
				if(ccnt+1<=n/2)ans+=Cc,ccnt++;
				else if(bcnt+1<=n/2)ans+=Bb,bcnt++;
				else ans+=Aa,acnt++;
			}
		}
		else if(Bb==0){
			if(Aa>=Cc){
				if(acnt+1<=n/2)ans+=Aa,acnt++;
				else if(ccnt+1<=n/2)ans+=Cc,ccnt++;
				else ans+=Bb,bcnt++;
			}
			else{
				if(ccnt+1<=n/2)ans+=Cc,ccnt++;
				else if(acnt+1<=n/2)ans+=Aa,acnt++;
				else ans+=Bb,bcnt++;
			}
		}
		else if(Cc==0){
			if(Aa>=Bb){
				if(acnt+1<=n/2)ans+=Aa,acnt++;
				else if(bcnt+1<=n/2)ans+=Bb,bcnt++;
				else ans+=Cc,ccnt++;
			}
			else{
				if(bcnt+1<=n/2)ans+=Bb,bcnt++;
				else if(acnt+1<=n/2)ans+=Aa,acnt++;
				else ans+=Cc,ccnt++;
			}
		}
//		if(Acnt!=acnt)
//			cout<<i<<" A\n";
//		if(Bcnt!=bcnt)
//			cout<<i<<" B\n";
//		if(Ccnt!=ccnt)
//			cout<<i<<" C\n";
	}
	cout<<ans<<'\n';
}
signed main(){
//	ios::sync_with_stdio(0);
//	cin.tie(0);cout.tie(0);
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int T=1;
	cin>>T;
	while(T--){
//		cout<<T<<"\n\n\n\n";
		solve();
	}
	return 0;
}
