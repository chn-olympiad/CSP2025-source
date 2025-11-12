#include<bits/stdc++.h>
using namespace std;
int n,t,ans,cnt;
const int N=2e4+10;
struct pe{
	int f;
	int s;
	int t;
}a[N];
bool cmpf(pe x,pe y){
	return x.f>=y.f;
}
bool cmps(pe x,pe y){
	return x.s>=y.s;
}
bool cmpt(pe x,pe y){
	return x.t>=y.t;
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	while(t--){
		cin>>n;
		for(int i=1;i<=n;i++)
			cin>>a[i].f>>a[i].s>>a[i].t;
		sort(a+1,a+n+1,cmpf);
		for(int i=1;i<=n/2;i++)
			cnt+=a[i].f;
		for(int i=n/2+1;i<=n;i++){
			cnt+=max(a[i].s,a[i].t);
		}
		ans=max(ans,cnt);
		cnt=0;
		sort(a+1,a+n+1,cmps);
		for(int i=1;i<=n/2;i++)
			cnt+=a[i].s;
		for(int i=n/2+1;i<=n;i++)
			cnt+=max(a[i].f,a[i].t);
		ans=max(ans,cnt);
		cnt=0;
		sort(a+1,a+n+1,cmpt);
		for(int i=1;i<=n/2;i++)
			cnt+=a[i].t;
		for(int i=n/2+1;i<=n;i++)
			cnt+=max(a[i].f,a[i].s);
		ans=max(ans,cnt);
		cout<<ans<<endl;
		cnt=0;
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}