#include<bits/stdc++.h>
using namespace std;
int t,n,a[10005],ans;
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	cin>>t;
	while(t--){
		cin>>n;
		for(int i=1;i<=n;i++){
			cin>>a[i]>>ans>>ans;
		}
		sort(a+1,a+n+1);
		ans=0;
		for(int i=n;i>=n/2+1;i--){
			ans+=a[i];
		}
		cout<<ans<<endl;
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
