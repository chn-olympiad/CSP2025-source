#include<bits/stdc++.h>
using namespace std;
int n,q,ans=0;
string a[200005],b[200005];
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	cin>>n>>q;
	for(int i=1;i<=n;i++)cin>>a[i]>>b[i];
	for(int ii=1;ii<=q;ii++){
		string cnt,sum;
		cin>>cnt>>sum;
		for(int i=1;i<=n;i++){
			if(cnt==a[i])ans++;
			if(sum==b[i])ans++;
		}
		cout<<ans<<endl;
		ans=0;
	}
	return 0;
}
