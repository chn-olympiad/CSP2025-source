#include<bits/stdc++.h>
using namespace std;
#define int long long
struct stu{
	int a[45],fjs;
}s[100005];
int n,t;
int maxb(int a[]){
	int mab=4;
	for(int i=1;i<=3;i++) if(a[i]>a[mab]) mab=i;
	return mab;
}
int secb(int a[]){
	return a[1]+a[2]+a[3]-max(max(a[1],a[2]),a[3])-min(min(a[1],a[2]),a[3]);
}
int fjs(int a[]){
	return a[maxb(a)]-secb(a);
}
bool cmp(stu a,stu b){
	return a.fjs>b.fjs;
}
signed main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin.tie(0);
	cout.tie(0);
	ios::sync_with_stdio(0);
	cin>>t;
	while(t--){
		int qwerty[10]={0},ans=0;
		cin>>n;
		for(int i=1;i<=n;i++){
			cin>>s[i].a[1]>>s[i].a[2]>>s[i].a[3];
			s[i].fjs=fjs(s[i].a);
		}
		sort(s+1,s+n+1,cmp);
		for(int i=1;i<=n;i++){
			int mb=maxb(s[i].a),answ=ans;
			qwerty[mb]++;
			if(qwerty[mb]>n/2) ans+=secb(s[i].a);
			else ans+=s[i].a[mb];
		}
		cout<<ans<<'\n';
	}
	return 0;
}
