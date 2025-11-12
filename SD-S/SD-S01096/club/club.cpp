#include<bits/stdc++.h>
using namespace std;
long long n,summ,b[5],T;
struct node{
	long long fi,se,th,xv1,xv2,xv3;
}a[100010];
bool cmp(node aa,node bb){
	return aa.fi-aa.se>bb.fi-bb.se;
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>T;
	while(T--){
		cin>>n;
		memset(b,0,sizeof(b));
		summ=0;
		for(int i=1;i<=n;i++){
			cin>>a[i].fi>>a[i].se>>a[i].th;
			a[i].xv1=1;
			a[i].xv2=2;
			a[i].xv3=3;
			if(a[i].fi<a[i].se)swap(a[i].fi,a[i].se),swap(a[i].xv1,a[i].xv2);
			if(a[i].fi<a[i].th)swap(a[i].fi,a[i].th),swap(a[i].xv1,a[i].xv3);
			if(a[i].se<a[i].th)swap(a[i].se,a[i].th),swap(a[i].xv2,a[i].xv3);
		}
		sort(a+1,a+n+1,cmp);
//		for(int i=1;i<=n;i++)cout<<a[i].fi<<' '<<a[i].xv1<<' '<<a[i].se<<' '<<a[i].xv2<<' '<<a[i].th<<' '<<a[i].xv3<<endl;
		for(int i=1;i<=n;i++){
			if(b[a[i].xv1]==n/2){
				b[a[i].xv2]++;
				summ+=a[i].se;
			}else{
				b[a[i].xv1]++;
				summ+=a[i].fi;
			}
//			cout<<sum<<endl;
		}
		cout<<summ;
	}
	return 0;
}

