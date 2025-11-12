#include<bits/stdc++.h>
using namespace std;
const int N=5e6+5;
map<string,string> mp;
map<string ,int > f;
int n,q;
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	cin>>n>>q;
	for(int i=1;i<=n;i++){
		string a,b;
		cin>>a>>b;
		mp[a]=b;
		f[a]=1;
	}
	//cout<<f["bc"];
	while(q--){
		int ans=0;
		string y,x;
		cin>>y>>x;
		for(int i=0;i<y.size();i++){
			for(int j=y.size()-1;j>=i;j--){
				string a;
				a.clear();
				for(int k=i;k<=j;k++){
					a=a+y[k];
					//cout<<y[k];
				}
				//cout<<i<<" "<<j<<" "<<a<<"\n";
				//cout<<a<<"\n"; 
				if(f[a]==1){
					//cout<<a<<"\n";
					string b;
					b.clear();
					for(int k=i;k<=j;k++){
						b+=y[k];
						y[k]=mp[a][k-i];
						//cout<<mp[a][x-i];
					}
					//cout<<b<<"1743529345";
					//cout<<y<<" "<<x<<"\n";
					int check=0;
					for(int t=0;t<y.size();t++){
						if(y[t]!=x[t]) check=1;
					}
					if(!check){
						ans++;
					}
					for(int x=i;x<=j;x++){
						y[x]=b[i-x];
					}
				}
			}
		}
		cout<<ans<<"\n";
	}
	
} 