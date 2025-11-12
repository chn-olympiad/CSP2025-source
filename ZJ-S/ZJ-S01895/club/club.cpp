#include<iostream>
#include<algorithm>
#include<cstdio>
#include<cstring>
using namespace std;
const int mx=1e5+10;
int t;
int n,a[mx][3];
struct peaple{
	int mi;
	int d;
}b[mx];

bool cmp(peaple x,peaple y){
	return x.d<y.d;
}

int cnt[3];

long long ans=0;

int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	
	cin>>t;
	while(t--){
		cin>>n;
		memset(cnt,0,sizeof(cnt));
		ans=0;
		for(int i=1;i<=n;i++){
			int max0=0,max1=0;
			int mind;
			for(int j=0;j<3;j++){
				cin>>a[i][j];
				if(a[i][j]>max0){
					max1=max0;
					max0=a[i][j];
					mind=j;
				}
				else if(a[i][j]>max1) max1=a[i][j];
			}
			b[i].mi=mind;
			b[i].d=max0-max1;
			cnt[mind]++;
			ans+=max0;
		}
		sort(b+1,b+n+1,cmp);
		int mind,max0=0;
		for(int i=0;i<3;i++){
			if(cnt[i]>max0){
				max0=cnt[i];
				mind=i;
			}
		}
		for(int i=1;i<=n;i++){
			if(max0<=n/2) break;
			if(b[i].mi==mind){
				ans-=b[i].d;
				max0--;
			}
		}
		cout<<ans<<endl;
	}
	
	return 0;
}
