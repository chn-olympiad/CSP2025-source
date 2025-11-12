#include<bits/stdc++.h>
using namespace std;
int n,t,maxa[100005],nume[5],x,y,z;
struct club{
	int maxn,k,nmaxn;
}a[100005];
bool cmp(club ca,club cb){
	return ca.maxn>cb.maxn;
}
int read(){
	int res=0,f=1;
	char ch=getchar();
	while(!isdigit(ch)){
		if(ch=='-') f=-1;
		ch=getchar();
	}
	while(isdigit(ch)){
		res=res*10+ch-'0';
		ch=getchar();
	}
	return res*f;
}
int maxx(int a,int b,int c){
	return max(max(a,b),c);
}
void solve(){
	n=read();
	long long ans=0;
	for(int i=0;i<n;i++){
		x=read(),y=read(),z=read();
		a[i].maxn=maxx(x,y,z);
		if(a[i].maxn==x) a[i].k=1,a[i].nmaxn=max(y,z);
		else if(a[i].maxn==y) a[i].k=2,a[i].nmaxn=max(x,z);
		else a[i].k=3,a[i].nmaxn=max(y,z);
	}
	sort(a,a+n,cmp);
	for(int i=0;i<n;i++){
		if(nume[a[i].k]<n/2){
			ans+=a[i].maxn;
			nume[a[i].k]++;
		}else{
			ans+=a[i].nmaxn; 
		}
	}
	cout<<ans;
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	t=read();
	while(t--){
		solve();
	}
	return 0;
}

