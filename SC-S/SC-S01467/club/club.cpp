#include<bits/stdc++.h>
using namespace std;
int t;
long long n,m,m2,b1,b2,b3;
struct ccf{
	long long a1,a2,a3;
}a[100005];
bool tamp1(ccf x,ccf y){
	if(x.a1<y.a1) return false;
	return true;
}
bool tamp2(ccf x,ccf y){
	if(x.a2<y.a2) return false;
	return true;
}
bool tamp3(ccf x,ccf y){
	if(x.a3<y.a3) return false;
	return true;
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	while(t--){
		cin>>n;
		for(int i=1;i<=n;i++){
			cin>>a[i].a1>>a[i].a2>>a[i].a3;
		}
		
		sort(a+1,a+n+1,tamp1);
		for(int i=1;i<=n;i++){
			if(a[i].a1>a[i].a2&&a[i].a1>a[i].a3&&b1<n/2){
				m+=a[i].a1;
				b1++;
			}
			if(a[i].a2>a[i].a1&&a[i].a2>a[i].a3&&b2<n/2){
				m+=a[i].a2;
				b2++;
			}
			if(a[i].a3>a[i].a2&&a[i].a3>a[i].a1&&b3<n/2){
				m+=a[i].a3;
				b3++;
			}
		}
		
		sort(a+1,a+n+1,tamp2);
		for(int i=1;i<=n;i++){
			if(a[i].a1>a[i].a2&&a[i].a1>a[i].a3&&b1<n/2){
				m2+=a[i].a1;
				b1++;
			}
			if(a[i].a2>a[i].a1&&a[i].a2>a[i].a3&&b2<n/2){
				m2+=a[i].a2;
				b2++;
			}
			if(a[i].a3>a[i].a2&&a[i].a3>a[i].a1&&b3<n/2){
				m2+=a[i].a3;
				b3++;
			}
		}	
		m=max(m,m2);
		m2=0;
		
		sort(a+1,a+n+1,tamp3);
		for(int i=1;i<=n;i++){
			if(a[i].a1>a[i].a2&&a[i].a1>a[i].a3&&b1<n/2){
				m2+=a[i].a1;
				b1++;
			}
			if(a[i].a2>a[i].a1&&a[i].a2>a[i].a3&&b2<n/2){
				m2+=a[i].a2;
				b2++;
			}
			if(a[i].a3>a[i].a2&&a[i].a3>a[i].a1&&b3<n/2){
				m2+=a[i].a3;
				b3++;
			}
		}
		m=max(m,m2);
		cout<<m;
		m=0;
		m2=0;
		b1=0;
		b2=0;
		b3=0;
	}
	return 0;
}