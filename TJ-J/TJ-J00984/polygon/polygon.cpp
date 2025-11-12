#include<bits/stdc++.h>
using namespace std;
long long n,a[5005],x=0,sum=0,ax[5005],p=998244353,cnt=0,f[5005][5005];
map<string,int> m;
void dg(int x){
	if(x>3){
		long long ans=0,k=0;
		string s="",l;
		for(int i=1;i<=n;i++){
			if(ax[i]==1){
				ans+=a[i];
				k=max(k,a[i]);
				l=i-'0';
				s=s+l;
			//	cout<<i<<" ";
			}
		}
	//	cout<<endl;
		if(ans>2*k&&m[s]==0){
			cnt++;
			m[s]++;
			cnt%=p;
		}
	}
	if(x==n+1){
		return;
	}
	for(int i=1;i<=n;i++){
		if(ax[i]==0){
			ax[i]=1;
			dg(x+1);
			ax[i]=0;
		}
	}
}
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		sum+=a[i];
		x=max(x,a[i]);
	}
	if(n==3){
		if(sum>2*x){
			cout<<1;
		}else{
			cout<<0;
		}
	}else if(n>3&&n<=20){
		dg(1);
		cout<<cnt%p;
	}else{
		sum=0;
		for(int i=1;i<=n;i++){
			f[i][0]=1;
		}
		for(int i=1;i<=n;i++){
			for(int j=1;j<=i;j++){
				f[i][j]=f[i-1][j-1]+f[i-1][j];
				f[i][j]%=p;
			}
		}
		for(int i=3;i<=n;i++){
			for(int j=3;j<=i;j++){
				sum=sum+f[i][j]%p;
				sum%=p;
			}
		}
		cout<<sum%p;
	}
	return 0;
} 
