#include<bits/stdc++.h>
using namespace std;
const int N=1e5+10;
long long t,n,shu[N],big,maxx,fl1=1,fl2=1;
struct node{
	int b[4];
}a[N];
bool cmp(node x,node y){
	if(x.b[1]==y.b[1]&&x.b[2]==y.b[2])return x.b[3]>y.b[3];
	else if(x.b[1]==y.b[1])return x.b[2]>y.b[2];
	return x.b[1]>y.b[1];
}
bool cmp2(node x,node y){
	if(x.b[1]==x.b[2]) return 1;
	return max(x.b[1],x.b[2])>max(y.b[1],y.b[2]);
}
void read(){
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i].b[1]>>a[i].b[2]>>a[i].b[3];
		if(a[i].b[2]!=0)fl1=0;
		if(a[i].b[3]!=0)fl2=0;
	}
}
void dfs(int cen,long long cnt){
	if(cen==n+1){
		maxx=max(maxx,cnt);
	}
	for(int i=1;i<=3;i++){
		if(shu[i]<big){
			shu[i]++;
			dfs(cen+1,cnt+a[cen].b[i]);
			shu[i]--;
		}
	}
}
void solve1(){
	maxx=0;
	big=n/2;
	dfs(1,0);
	cout<<maxx<<endl;
}
void solve2(){
	long long ans=0;
	sort(a+1,a+n+1,cmp);
	for(int i=1;i<=n/2;i++)ans+=a[i].b[1];
	cout<<ans<<endl;
}void solve3(){
	long long v1=0,v2=0,ans=0;
	sort(a+1,a+n+1,cmp2);
	for(int i=1;i<=n;i++){
		if(a[i].b[1]<a[i].b[2]&&v2<n/2){
			v2++;
			ans+=a[i].b[2];
		}else if(a[i].b[1]>a[i].b[2]&&v1<n/2){
			v1++;
			ans+=a[i].b[1];
		}else ans+=a[i].b[2];
	}
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	while(t--){
		read();
		if(fl1&&n>30){
			solve2();
		}else if(fl2&&n>30){
			solve3();
		}else solve1();
	}
	return 0;
}