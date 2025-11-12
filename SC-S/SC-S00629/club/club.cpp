# include<bits/stdc++.h>
# include<stack>
using namespace std;
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
long long t;
cin>>t;
while(t--){
		long long n,f[100005],ans=0;
	cin>>n;
	int a,b;
	for(int i=1;i<=n;i++){
		cin>>f[i]>>a>>b;
	}
	for(int i=1;i<n;i++){
		for(int j=1+i;j<=n;j++){
			if(f[j]>f[i])swap(f[i],f[j]);
		}
	}
	for(int i=1;i<=n/2;i++)ans+=f[i];
	cout<<ans<<endl;
}
} 