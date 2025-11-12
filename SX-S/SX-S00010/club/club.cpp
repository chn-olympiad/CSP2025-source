#include<bits/stdc++.h>
using namespace std;

struct sss{
	int a1,a2,a3,max_;
} a[100005],a1_max[100005],a2_max[100005],a3_max[100005];
int T,n,ans,a11,a22,a33;
bool cmp1(sss a,sss b){
	return a.a1>b.a1;
}
bool cmp2(sss a,sss b){
	return a.a2>b.a2;
}
bool cmp3(sss a,sss b){
	return a.a3>b.a3;
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>T;
	while(T--){
		ans=0; a11=0; a22=0; a33=0;
		cin>>n;
		for(int i=0;i<n;i++){
			cin>>a[i].a1>>a[i].a2>>a[i].a3;
			if(a[i].a1>a[i].a2&&a[i].a1>a[i].a3){
				a1_max[a11++]=a[i];
			}
			else if(a[i].a2>a[i].a1&&a[i].a2>a[i].a3) a2_max[a22++]=a[i];
			else a3_max[a33++]=a[i];
			if(a[i].a1==0&&a[i].a2==0&&a[i].a3==0) a[i].max_=0;
		}
		sort(a1_max,a1_max+a11,cmp1);
		sort(a2_max,a2_max+a22,cmp2);
		sort(a3_max,a3_max+a33,cmp3);
		for(int i=0;i<n/2;i++){
			if(i<a11) ans+=a1_max[i].a1;
			if(i<a22) ans+=a2_max[i].a2;
			if(i<a33) ans+=a3_max[i].a3;
		}
		cout<<ans<<endl;
	}
	return 0;
}