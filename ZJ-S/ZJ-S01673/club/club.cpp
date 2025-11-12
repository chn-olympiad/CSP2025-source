#include<bits/stdc++.h>
using namespace std;
struct A{
	int id,a1,a2,a3;
}a[100005];
long long t,n,a1[100005],a2[100005],a3[100005],t1,t2,t3,ans,tt1,tt2,tt3;
bool b1,b2,b3;
long long ab(int x,int y){
	if(x>y)return x-y;
	return y-x;
}
bool cmp1(long long x,long long y){
	return min(ab(a[x].a1,a[x].a2),ab(a[x].a1,a[x].a3))<min(ab(a[y].a1,a[y].a2),ab(a[y].a1,a[y].a3));
}
bool cmp2(long long x,long long y){
	return min(ab(a[x].a1,a[x].a2),ab(a[x].a2,a[x].a3))<min(ab(a[y].a1,a[y].a2),ab(a[y].a2,a[y].a3));
}
bool cmp3(long long x,long long y){
	return min(ab(a[x].a3,a[x].a2),ab(a[x].a1,a[x].a3))<min(ab(a[y].a3,a[y].a2),ab(a[y].a1,a[y].a3));
}
void aa(int i){
	int x1=a[i].a1,x2=a[i].a2,x3=a[i].a3;
	if(x1>=x2&&x1>=x3)a1[++t1]=a[i].id;
	else if(x2>x1&&x2>=x3)a2[++t2]=a[i].id;
	else a3[++t3]=a[i].id;
	return;
}
void solve(){
	if(t1-tt1>n/2){
		if(b1)sort(a1+1,a1+t1+1,cmp1),b1=0;
		for(int i = tt1+1 ; t1-i>=n/2;i++){
			int q2=ab(a[a1[i]].a2,a[a1[i]].a1),q3=ab(a[a1[i]].a3,a[a1[i]].a1);
			if(q2<q3||(q2==q3&&t2<=t3))a2[++t2]=a1[i];
			else if(q2>q3||(q2==q3&&t2>t3))a3[++t3]=a1[i];
			tt1=i;
		}
		solve();
	}else if(t2-tt2>n/2){
		if(b2)sort(a2+1,a2+t2+1,cmp2),b2=0;
		for(int i = tt2+1 ; t2-i>=n/2;i++){
			int q1=ab(a[a2[i]].a2,a[a2[i]].a1),q3=ab(a[a2[i]].a2,a[a2[i]].a3);
			if(q1<q3||(q1==q3&&t1<=t3))a1[++t1]=a2[i];
			else if(q1>q3||(q1==q3&&t1>t3))a3[++t3]=a2[i];
			tt2=i;
		}
		solve();
	}else if(t3-tt3>n/2){
		if(b3)sort(a3+1,a3+t3+1,cmp3),b3=0;
		for(int i = tt3+1 ; t3-i>=n/2;i++){
			int q1=ab(a[a3[i]].a3,a[a3[i]].a1),q2=ab(a[a3[i]].a3,a[a3[i]].a2);
			if(q1<q2||(q1==q2&&t1<=t2))a1[++t1]=a3[i];
			else if(q1>q2||(q1==q2&&t1>t2))a2[++t2]=a3[i];
			tt3=i;
		}
		solve();
	}else return;
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin >> t ;
	while(t--){
		n=t1=t2=t3=tt1=tt2=tt3=ans=0;
		b1=b2=b3=1;
		cin >> n ;
		for(int i = 1 ; i <= n ; i++)cin >> a[i].a1 >> a[i].a2>>a[i].a3,a[i].id=i,aa(i);
		solve();
		for(int i=tt1+1;i<=t1;i++)ans+=a[a1[i]].a1;
		for(int i=tt2+1;i<=t2;i++)ans+=a[a2[i]].a2;
		for(int i=tt3+1;i<=t3;i++)ans+=a[a3[i]].a3;
		cout << ans<< endl;
	}
	return 0 ;
}
