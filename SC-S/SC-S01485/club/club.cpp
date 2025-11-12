#include<bits/stdc++.h>
using namespace std;
struct st{
	int a1,a2,a3;
	int a12;
};
struct st1{
	int ikxb,chazhi;
};
int cmp1(st p,st q){
	return p.a1>q.a1;
}
int cmp2(st p,st q){
	return p.a2>q.a2;
}
int cmp3(st p,st q){
	return p.a3>q.a3;
}
st a[100005];
st1 a1b[100005],a2b[100005];
int n,maxs,ta,tb;
void sol2(){
	int ans2=0;
		ans2=max(a[1].a1+a[2].a2,ans2);
		ans2=max(a[1].a1+a[2].a3,ans2);
		ans2=max(a[1].a2+a[2].a1,ans2);
		ans2=max(a[1].a2+a[2].a3,ans2);
		ans2=max(a[1].a3+a[2].a1,ans2);
		ans2=max(a[1].a3+a[2].a2,ans2);
		cout<<ans2<<endl;
	return;
}
void sola(){
	sort(a+1,a+n+1,cmp1);
	long long ansa=0;
	for(int i=1;i<=maxs;i++){
		ansa+=a[i].a1;
	}
	cout<<ansa<<endl;
	return;
}
int kxa1=0,kxa2=0;
int cmpx2(st1 q1,st1 q2){
	return q1.chazhi>q2.chazhi;
}
void solb(){
	long long ansb=0;
	for(int i=1;i<=n;i++){
		if(a[i].a1>=a[i].a2){
			kxa1++;
			a1b[kxa1].ikxb=i;
			a1b[kxa1].chazhi=a[i].a1-a[i].a2;
		}
		else{
			kxa2++;
			a2b[kxa2].ikxb=i;
			a2b[kxa2].chazhi=a[i].a2-a[i].a1;
		}
	}
	if(kxa1>=kxa2){
		sort(a1b+1,a1b+kxa1+1,cmpx2);
		for(int i=1;i<=maxs;i++){
			ansb+=a[a1b[i].ikxb].a1;
		}
		for(int i=maxs+1;i<=kxa1;i++){
			ansb+=a[a1b[i].ikxb].a1;
		}
		for(int i=1;i<=kxa2;i++){
			ansb+=a[a2b[i].ikxb].a2;
		}
		cout<<ansb<<endl;
		return;
	}
	else{
		sort(a2b+1,a2b+kxa2+1,cmpx2);
		for(int i=1;i<=maxs;i++){
			ansb+=a[a2b[i].ikxb].a2;
		}
		for(int i=maxs+1;i<=kxa2;i++){
			ansb+=a[a2b[i].ikxb].a2;
		}
		for(int i=1;i<=kxa1;i++){
			ansb+=a[a1b[i].ikxb].a1;
		}
		cout<<ansb<<endl;
		return;
	}
}
void sol4(){
	
}
void sol(){
	cin>>n;
	maxs=n/2;
	ta=0;
	tb=0;
	for(int i=1;i<=n;i++){
		cin>>a[i].a1>>a[i].a2>>a[i].a3;
		if(a[i].a3!=0){
			tb=1;
		} 
		if(a[i].a2!=0){
			ta=1;
		} 
	}
	if(n==2){
		sol2(); 
	}
	else if(ta==0&&tb==0){
		sola();
	}
	else if(tb==0){
		solb();
	}
	else if(n==4){
		sol4();
	}
//	else 
//	solc();
	return;
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int t;
	cin>>t;
	for(int i=1;i<=t;i++){
		sol();
	}
	return 0;
} 