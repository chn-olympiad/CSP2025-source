#include<bits/stdc++.h>
using namespace std;
int n,q,i,L1,L2,l1,l2,j,ans;string a[200010],b[200010],t1,t2;
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	cin>>n>>q;
	for(i=1;i<=n;i++)cin>>a[i]>>b[i];
	while(q--){
		cin>>t1>>t2;
		L1=t1.size();L2=t2.size();ans=0;
		for(i=1;i<=n;i++){
			l1=a[i].size();l2=b[i].size();
			if(l1>L1||l1>L2||l2>L1||l2>L2)continue;
			for(j=0;j<L1-l1+1;j++)
				if(t1.substr(j,l1)==a[i]&&t1.substr(0,j)+b[i]+t1.substr(j+l1,L1-l1)==t2)break;
			if(j<L1-l1+1)ans++;
		}
		cout<<ans<<"\n";
	}
	return 0;
}
