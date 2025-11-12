#include<bits/stdc++.h>
using namespace std;
long long n,t,len,sa,sb,sc,lqx,lqy,lqz,sum1,sum2,sum3;
struct s{
	long long c[5];
}a[100005];
bool cmpa(s x,s y){
	return x.c[1]>=y.c[1];
}
bool cmpb(s x,s y){
	return x.c[2]>=y.c[2];
}
bool cmpc(s x,s y){
	return x.c[3]>=y.c[3];
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0); 
	cin>>t;
	while(t--){
		cin>>n;
		len=n/2;
		for(int i=1;i<=n;i++){
			cin>>a[i].c[1]>>a[i].c[2]>>a[i].c[3];
		}
		sort(a+1,a+n+1,cmpa);
		for(int i=1;i<=len;i++){
			sa+=a[i].c[1];
		}
		sort(a+1,a+n+1,cmpb);
		for(int i=1;i<=len;i++){
			sb+=a[i].c[2];
		}
		sort(a+1,a+n+1,cmpc);
		for(int i=1;i<=len;i++){
			sc+=a[i].c[3];
		}
		if(sa>=sb && sa>=sc){
			lqx=1;
		}else if(sb>=sc && sb>=sa){
			lqx=2;
		}else{
			lqx=3;
		}
		sort(a+1,a+n+1,cmpa);
		sum1+=sa;
		for(int i=len+1;i<=n;i++){
			sum1+=max(a[i].c[2],a[i].c[3]);
		}
		sort(a+1,a+n+1,cmpb);
		sum2+=sb;
		for(int i=len+1;i<=n;i++){
			sum2+=max(a[i].c[1],a[i].c[3]);
		}
		sort(a+1,a+n+1,cmpc);
		sum3+=sc;
		for(int i=len+1;i<=n;i++){
			sum3+=max(a[i].c[2],a[i].c[1]);
		}
		cout<<max({sum1,sum2,sum3})<<endl;
		for(int i=1;i<=n;i++){
			a[i].c[1]=0;
			a[i].c[2]=0;
			a[i].c[3]=0;
		}
		n=0,len=0,sa=0,sb=0,sc=0,lqx=0,lqy=0,lqz=0,sum1=0,sum2=0,sum3=0;
	}
	return 0;
} 