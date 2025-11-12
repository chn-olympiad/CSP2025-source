#include<bits/stdc++.h>
using namespace std;
const int maxn=5e5+10;
int n,k,sum;
int a[maxn],qz[maxn],f[maxn];
map<int,int>cnt;
int yh(int x,int y){
	int js=1,ans=0;
	while(x>0||y>0){
		if(x%2!=y%2){
			ans+=js;
		}
		x/=2;
		y/=2;
		js*=2;
	}
	return ans;
}
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin >> n >> k;
	for(int i=1;i<=n;i++){
		cin >> a[i];
		qz[i]=yh(qz[i-1],a[i]);
		cnt[a[i]]++;
	}
	if(cnt[1]==n){
		if(k==1) cout << n;
		else if(k==0) cout << n/2;
		else cout << 0;
		return 0;
	}
	if(cnt[1]+cnt[0]==n){
		if(k==1) cout << cnt[1];
		else if(k==0) cout << cnt[0]+cnt[1]/2;
		else cout << 0;
		return 0;
	}
	//for(int len=0;len<=n;len++){
		for(int i=1;i<=n;i++){
			f[i]=max(f[i],f[i-1]);
			for(int j=i;j<=n;j++){
				if(i==j) sum=a[i];
				else
					sum=abs(qz[j]-qz[i-1]);
				if(sum==k){
					f[j]=max(f[j],f[i-1]+1);
				}
			}
		}
	//}
	cout << f[n] ;
	return 0;
}
