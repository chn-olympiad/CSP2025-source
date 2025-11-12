#include <bits/stdc++.h>
using namespace std;
const int MAXN=1e5+99;
long long a[MAXN];
long long b[MAXN];
long long c[MAXN];
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	long long t;
	cin>>t;
	while(t--){
		long long n,ans=0;
		bool bzero=true;
		bool czero=true;
		cin>>n;
		for(int i=1;i<=n;i++){
			cin>>a[i]>>b[i]>>c[i];
			if(b[i]!=0){
				bzero=false;
			}
			if(c[i]!=0){
				czero=false;
			}
		}
		if(bzero&&czero){
			int num=n/2;
			long long sum=0;
			sort(a+1,a+n+1);
			for(int i=num+1;i<=n;i++){
				sum+=a[i];
			}
			cout<<sum<<endl;
		}
		if(n==2){
			int sum,Max=-1;
			sum=a[1]+b[2];
			Max=max(sum,Max);      
			sum=a[1]+c[2];
			Max=max(sum,Max);
			sum=b[1]+a[2];
			Max=max(sum,Max);
			sum=b[1]+c[2];
			Max=max(sum,Max);
			sum=c[1]+a[2];
			Max=max(sum,Max);
			sum=c[1]+b[2];
			Max=max(sum,Max);
			cout<<Max<<endl;
		}
	}
	return 0;
}
