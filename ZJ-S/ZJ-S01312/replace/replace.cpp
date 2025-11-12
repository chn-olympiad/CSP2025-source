#include<bits/stdc++.h>
using namespace std;
int n,q,i,ans,l1,l2,j,x,y;string ch1,ch2,t1,t2,a[200010],b[200010];
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	cin>>n>>q;
	for(i=1;i<=n;i++){
		cin>>ch1>>ch2;
		a[i]=ch1;b[i]=ch2;
	}
	while(q--){
		cin>>t1>>t2;ans=0;
		l1=t1.size();l2=t2.size();
		if(l1!=l2){
			cout<<0<<"\n";continue;
		}
		if(l1>=10000){
			cout<<n<<"\n";continue;
		}
		for(i=0;i<l1;i++){
			if(t1.substr(0,i)!=t2.substr(0,i)) continue;
			for(j=1;j<=n;j++){
				x=a[j].size();y=b[j].size();
				if(t1.substr(i,x)!=a[j]) continue;
				if(t2.substr(i,x)!=b[j]) continue;
				if(t1.substr(i+x,l1-i-x)!=t2.substr(i+y,l2-i-y)) continue;
				ans++; 
			}
		}
		cout<<ans<<"\n";
	}
}