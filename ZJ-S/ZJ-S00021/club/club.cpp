#include<bits/stdc++.h>
using namespace std;
int t,n,mx=0;
bool fa=1,fb=1;
struct lk{
	int a;
	int b;
	int c;
}a[100005],b[100005];
bool cmp1(lk a,lk b){
	if(a.a==b.a)return a.b>b.b;
	return a.a>b.a;
}
bool cmp2(lk a,lk b){
	return a.b>b.b;
}
void bp(int i,int v,int cnt1,int cnt2,int cnt3){
	if(cnt1<=n/2&&cnt2<=n/2&&cnt3<=n/2&&i<=n+1){
		if(cnt1+cnt2+cnt3==n){
			mx=max(mx,v);
			return;
		}
			
//	cout<<v<<' ';
		if(cnt1<n/2){
			bp(i+1,v+a[i].a,cnt1+1,cnt2,cnt3);
		}
		if(cnt2<n/2){
			bp(i+1,v+a[i].b,cnt1,cnt2+1,cnt3);
		}
		if(cnt3<n/2){
			bp(i+1,v+a[i].c,cnt1,cnt2,cnt3+1);
		}
	}
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.ans","w",stdout);
	cin>>t;
	for(int i=1;i<=t;i++){
		cin>>n;
		mx=0;
		for(int j=1;j<=n;j++){
			cin>>a[j].a>>a[j].b>>a[j].c;
			if(a[j].b!=0){
				fa=0;
			}
			if(a[j].c!=0){
				fa=0;
				fb=0;
			}
			b[j].a=0;
			b[j].b=a[j].b-a[j].a;
			b[j].c=a[j].c-a[j].a;
		}
		if(fa){
			sort(a+1,a+n+1,cmp1);
			for(int j=1;j<=n/2;j++){
				mx+=a[j].a;
			}
			cout<<mx;
		}
		else if(fb){
			sort(b+1,b+n+1,cmp2);
			int j;
			for(j=1;j<=n/2;j++){
				if(b[j].b<0)break;
				mx+=a[j].b;
			}
			int n1=min(n,n/2+j);
			for(;j<=n1;j++){
				mx+=a[j].a;
			}
			for(;j<=n;j++){
				mx+=a[j].b;
			}
			cout<<mx;
		}
		else{
			bp(1,0,0,0,0);
			cout<<mx;
		}
//		sort(b+1,b+n+1,cmp);
//		for(int i=1;i<=n;i++){
//			cout<<b[i].a<<' '<<b[i].b<<' '<<b[i].c<<endl;
//		}
		cout<<endl;
	}
	
	fclose(stdin);
	fclose(stdout);
	return 0;
}
//666我的签到题呢 
//25+0+0+0=25 有三吗 
