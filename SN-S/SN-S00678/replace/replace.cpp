//赵子晗 SN-S00678 西安市曲江第二中学 
#include<bits/stdc++.h>
#define ll long long
using namespace std;

ll n,q;
map<string,string>d;

int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	
	cin>>n>>q;
	while(n--){
		string a,b;
		cin>>a>>b;
		d[a]=b;
	}
	while(q--){
		string a,b;
		cin>>a>>b;
		ll ans=0;
		for(auto u:d)
		{
			for(int i=0;i<a.size();i++){
				if(a[i]==u.first[0]){
					string se=a;
					bool f=1;
					for(ll j=i,k=0;j<a.size(),k<u.first.size();j++,k++){
						if((a[j]!=u.first[k])||(b[j]!=u.second[k])){
							f=0;
							break;
						}
						else se[j]=u.second[k];
					}
					if((se==b)&&f) ans++;
				}
			}
		}
		cout<<ans<<"\n";
	}
	
	return 0;
}
