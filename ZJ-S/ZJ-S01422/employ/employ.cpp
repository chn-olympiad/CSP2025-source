#include <bits/stdc++.h>
using namespace std;

int n,m,p[20];
string na;

long long jia(long long kn){
	int a[20]={0},sx[20];
	for(long long i=0;i<n;i++){
		if(a[kn%10]==1 || kn%10>=n) return 0;
		a[kn%10]=1;
		sx[i]=kn%10;
		kn/=10;
	}
	int z=0,l=0;
	for(long long i=0;i<n;i++){
		if(na[i]=='0' || z>=p[sx[i]]) z++;
		else l++;
	}
	if(l>=m){
		return 1;
		//for(long long i=0;i<n;i++) cout<<'a'<<sx[i]<<' ';
		//cout<<endl;
	}
	else return 0;
}

int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m>>na;
	for(int i=0;i<n;i++) cin>>p[i];
	
	long long mj=1,ans=0;
	for(int i=0;i<n;i++) mj*=10;
	
	
	for(long long i=mj/10;i<mj;i++){
		//if(jia(i)==1) cout<<i<<endl;
		ans=(ans+jia(i))%998244353;
	}
	cout<<ans;
	return 0;
}
