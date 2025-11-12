#include<bits/stdc++.h>
using namespace std;
int n,t,a[100010][5],cnt1,cnt2,cnt3,ans,anss;
int f[100010];
void solve1(){
	anss=0;
	memset(f,0,sizeof(f));
	for(int i=1;i<=n;i++){
		ans+=a[i][1];
		a[i][2]-=a[i][1];
		a[i][3]-=a[i][1];
		f[i]=max(a[i][2],a[i][3]);
	}
	sort(f+1,f+1+n);
	for(int i=n/2+1;i<=n;i++){
		ans+=f[i];
	}
	anss=max(ans,anss);
}
void solve2(){
	anss=0;
	memset(f,0,sizeof(f));
	for(int i=1;i<=n;i++){
		ans+=a[i][2];
		a[i][1]-=a[i][2];
		a[i][3]-=a[i][2];
		f[i]=max(a[i][1],a[i][3]);
	}
	sort(f+1,f+1+n);
	for(int i=n/2+1;i<=n;i++){
		ans+=f[i];
	}
	anss=max(ans,anss);
}
void solve3(){
	anss=0;
	memset(f,0,sizeof(f));
	for(int i=1;i<=n;i++){
		ans+=a[i][3];
		a[i][2]-=a[i][3];
		a[i][1]-=a[i][3];
		f[i]=max(a[i][1],a[i][2]);
	}
	sort(f+1,f+1+n);
	for(int i=n/2+1;i<=n;i++){
		ans+=f[i];
	}
	anss=max(ans,anss);
}
void solve(){
	for(int i=1;i<=n;i++){
		ans+=max(a[i][1],max(a[i][2],a[i][3]));
	}
}
int main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	scanf("%d",&t);
	while(t--){
		memset(f,0,sizeof(f));
		scanf("%d",&n);
		cnt1=0,cnt2=0,cnt3=0,ans=0;
		bool flag=false;
		for(int i=1;i<=n;i++){
			scanf("%d %d %d",&a[i][1],&a[i][2],&a[i][3]);
			if(a[i][1]>=a[i][2]&&a[i][1]>=a[i][3]){
				cnt1++;
			}
			if(a[i][2]>=a[i][1]&&a[i][2]>=a[i][3]){
				cnt2++;
			}
			if(a[i][3]>=a[i][1]&&a[i][3]>=a[i][2]){
				cnt3++;
			}
			if(a[i][2]||a[i][3]){
				flag=false;
			}
		}
		if(flag){
			int p[100010];
			for(int i=1;i<=n;i++){
				p[i]=a[i][1];
			}
			sort(p+1,p+1+n);
			for(int i=n;i>=n/2+1;i++){
				ans+=p[i];
			}
			cout<<ans<<"\n";
			continue;
		}
		if(cnt1<=n/2&&cnt2<=n/2&&cnt3<=n/2){
			solve();
		}
		if(cnt1>n/2){
			solve1();
		}
		if(cnt2>n/2){
			solve2();
		}
		if(cnt3>n/2){
			solve3();
		}
		cout<<ans<<"\n";
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
