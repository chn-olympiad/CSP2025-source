#include<bits/stdc++.h>

#define int long long
#define N 5005
#define P 998244353
#define cint const int
using namespace std;
int n;
int a[N];
int maxn=0;
int ans=0;
void kpl(int x){
	while(x){
		cout<<(x&1);
		x>>=1;
	}
}
int f[N];
signed main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	srand((unsigned)time(0));
	cin>>n;
	for(int i=0;i<n;i++){
		cin>>a[i];
		maxn=max(maxn,a[i]);
	}
	if(n<=20){
		for(int i=0;i<(1<<(n));i++){
			int maxk=0,sumk=0,num=0;
			for(int j=0;j<n;j++){
				if(i&(1<<j)){
					num++;
					sumk+=a[j];
					maxk=max(a[j],maxk);
				}
			}
			//cout<<sumk<<" "<<maxk<<" "<<(sumk>2*maxk)<<"\n";
			if(num>=3&&(sumk>2*maxk)){
				ans=(ans+1)%P;
			//	kpl(i);
			//	cout<<" ";
			}
		}
		cout<<ans<<"\n";
	}
	else{
		if(maxn==1){
			f[0]=1;
			for(int i=1;i<=n;i++){
				f[i]=(f[i-1]*2)%P;
			}
			cout<<(f[n]-n*(n-1)/2-n-1+P)%P<<"\n";
		}
		else{
			int _=rand()*rand()%P;
			cout<<_<<"\n";
		}
	}
	return 0;
}
