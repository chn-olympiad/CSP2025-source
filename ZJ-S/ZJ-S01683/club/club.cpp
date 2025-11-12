#include<bits/stdc++.h>
#define N 100005
#define ll long long
using namespace std;
int T;
int n;
int a[N][4];
int b[N][4];
int t[4];
int c[N],cnt;
ll ans=0;
int main(){
	freopen("club.in","r",stdin),freopen("club.out","w",stdout);
	cin>>T;
	while(T--){
		cin>>n;
		for(int i=1;i<=n;i++){
			for(int j=1;j<=3;j++){
				cin>>a[i][j];
				b[i][j]=j;
			}
			if(a[i][1]<a[i][2]) swap(a[i][1],a[i][2]),swap(b[i][1],b[i][2]);
			if(a[i][2]<a[i][3]) swap(a[i][2],a[i][3]),swap(b[i][2],b[i][3]);
			if(a[i][1]<a[i][2]) swap(a[i][1],a[i][2]),swap(b[i][1],b[i][2]);
			t[b[i][1]]++;
			ans+=a[i][1];
		}
		int id=-1;
		for(int j=1;j<=3;j++){
			if(t[j]>n/2) id=j;
		}
		if(id==-1){
			cout<<ans<<'\n';
			goto A;
		}
		for(int i=1;i<=n;i++){
			if(b[i][1]==id) c[++cnt]=a[i][1]-a[i][2];
		}
		sort(c+1,c+cnt+1);
		for(int i=1;i<=t[id]-n/2;i++){
			ans-=c[i];
		}
		cout<<ans<<'\n';
		A:;
		cnt=0;
		for(int i=1;i<=3;i++) t[i]=0;
		ans=0;
	}
	return 0;
}