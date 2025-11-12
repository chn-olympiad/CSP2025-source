#include<bits/stdc++.h>
using namespace std;
int n,q,ans;
vector<string> a1,b1;
int main(){
	//ios::sync_with_stdio(false);
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	cin>>n>>q;
	string a,b;
	for(int i=1;i<=n;i++){
		cin>>a>>b;
		a1.push_back(a);
		b1.push_back(b);
	} 
	while(q--){
		ans=0;
		cin>>a>>b;
		if(a.size()!=b.size()){
			cout<<0<<endl;
			continue;
		}
		int s1=0,t1=a.size()-1;
		while(a[s1]==b[s1]) s1++;
		while(a[t1]==b[t1]) t1--;
		//cout<<s1<<" "<<t1<<endl;
		for(int j=1;j<=n;j++){
			string z1=a1[j-1],z2=b1[j-1];
			int k1=s1,k2=s1-1,k3=0,pan=1;
			while(z1[k3]!=a[s1]&&k3+1<z1.size()){
				if(z1[k3]!=z2[k3]){
					pan=0;
					break;
				}
				k3++;
			}
			//cout<<endl;
			//cout<<k3<<" ";
			if(pan==0) continue;
			int ji=k3-1;
			for(int i=k3;i<z1.size();i++){
				if(k1>=a.size()){
					pan=0;
					break;
				}
				if(z1[k3]!=a[k1]||z2[k3]!=b[k1]){
					pan=0;
					break;
				}
				k3++;
				k1++;
			}
			//cout<<k1<<" ";
			if(pan==0||k1<=t1) continue;
			for(int i=ji;i>=0;i--){
				if(k2<0){
					pan=0;
					break;
				}
				if(z1[ji]!=a[k2]||z2[ji]!=b[k2]){
					pan=0;
					break;
				}
				ji--;
				k2--;
			}
			if(pan==0) continue;
			//cout<<j<<" ";
			ans++;
		}
		cout<<ans<<endl;
	}
	return 0;
}

