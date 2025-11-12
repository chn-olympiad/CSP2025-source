#include<bits/stdc++.h>
using namespace std;
int n,q,fl;
long long ans;
string a[200005],b[200005],c,d,e;
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	cin>>n>>q;
	for(int i=1;i<=n;i++){
		cin>>a[i]>>b[i];
		
	}
	while(q--){
		cin>>c>>d;
		ans=0;
		if(c.size()!=d.size()){
			cout<<0<<endl;
			continue;
		}e=c;
		for(int i=1;i<=n;i++){
			for(int j=0;j<e.size();j++){
				fl=0;
				for(int k=0;k<a[i].size();k++){
					if(e[j+k]!=a[i][k]){
						fl=1;
						break;
					}
				}if(fl==0){
					for(int k=0;k<a[i].size();k++) e[j+k]=b[i][k];
					fl=0;
					if(e==d) ans++;
					e=c;
				}
			}
		}
		cout<<ans<<endl;
	}
	return 0;
}
