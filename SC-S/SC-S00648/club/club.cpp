#include <bits/stdc++.h>
using namespace std;
int t;
long long ans;
int n,a1[100005],a2[100005],a3[100005];
long long f[105][105][105];
bool check_A(){
	for(int i=1;i<=n;++i){
		if(a2[i]!=0 || a3[i]!=0) return false;
	}
	return true;
}
bool check_B(){
	for(int i=1;i<=n;++i){
		if(a3[i]) return false;
	} 
	return true;
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	while(t--){
		cin>>n;
		for(int i=1;i<=n;++i){
			cin>>a1[i]>>a2[i]>>a3[i];
		}
		if(check_A()){
			sort(a1+1,a1+n+1);
			long long ans=0;
			for(int i=n;i>n/2;--i){
				ans+=a1[i];
			}
			cout<<ans<<endl;
			continue;
		}
		if(check_B()){
			for(int i=1;i<=n/2;++i){
				ans+=a1[i];
			}
			for(int i=n/2+1;i<=n;++i){
				ans+=a2[i];
			}
			cout<<ans<<endl;
			continue;
		}
		for(int i=2;i<=n;i+=2){
			for(int j=i/2;j>=0;--j){
				for(int k=i-j;i-j-k<=n/2;--k){
					f[i][j][k]=0;
				}
			}
		}
		f[1][0][0]=a3[1],f[1][1][0]=a1[1],f[1][0][1]=a2[1];
		for(int i=2;i<=n;i++){
			int tmp=i/2;
			if(i%2==1) tmp++;
			for(int j=tmp;j>=0;--j){
				for(int k=i-j;i-j-k<=tmp && k<=tmp;--k){
					if(i-k-j>=i/2) continue;
					if(j)
						f[i][j][k]=max(f[i][j][k],f[i-1][j-1][k]+a1[i]);
					if(k)
						f[i][j][k]=max(f[i][j][k],f[i-1][j][k-1]+a2[i]);
					f[i][j][k]=max(f[i][j][k],f[i-1][j][k]+a3[i]);
				}
			}
		}
		long long ans=0;
		for(int i=1;i<=n;++i){
			for(int j=i/2;j>=0;--j){
				for(int k=i-j;i-j-k<=n/2;--k){
					ans=max(ans,f[i][j][k]);
				}
			}
		}
		cout<<ans<<endl;
	}
	

	fclose(stdin);
	fclose(stdout);
	return 0;
}