#include<bits/stdc++.h>
//#define int long long
using namespace std;
const int N=5005;
int n,sm[N],a[N],ans;
int s(int x){
	int sum=0;
	for(int i=1;i<=n;i++){
		int k=1;
		for(int j=1;j<=i;j++){
			k*=j;
		}
		sum+=k;
	}
	return sum;
}
int fg(int sd,int x,bool f){
	if(f){
		int sum=sm[x]-sd,p;
		if(sum<=0) return 0;
		for(int i=1;i<=x;i++){
			if(sm[i]>=sum){
				p=i;
				break;
			}
		}
		int as=s(x)-fg(sum,p-1,0);
		cout<<as<<" ";
		return as;
	}else{
		int sum=sm[x]-sd,p;
		for(int i=1;i<=x;i++){
			if(sm[i]>sum){
				p=i;
				break;
			}
		}
		int as=s(x)-fg(sum,p-1,1);
		cout<<as<<" ";
		return as;
	}
}//xǰ<sd
signed main(){
//	freopen("polygon.in","r",stdin);
//	freopen("polygon.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0),cout.tie(0);
	cin>>n;
	for(int i=1;i<=n;i++) cin>>a[i];
	for(int i=1;i<=n;i++) sm[i]=sm[i-1]+a[i];
	sort(a+1,a+n+1);
	for(int i=1;i<=n;i++){
		ans+=fg(a[i]*2,i,1);
		cout<<"\n";
	}
	cout<<ans;
	return 0;
}
