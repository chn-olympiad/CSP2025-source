//¶ÎÑÅçÍ SN-S00438 ¸¨ÂÖÖĞÑ§
#include<bits/stdc++.h>
using namespace std;
int n,q,ans;
bool lk;
map<string,string>a;
string p,w,e,x;
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>q;
	for(int i=1;i<=n;i++){
		string h,l;
		cin>>h>>l;
		a[h]=l;
		a[l]=h;
	}
	for(int i=1;i<=q;i++){
		p="";
		w="";
		lk=0;
		int f=0,g=0;
		string s,z;
		cin>>s>>z;
		for(int i=0;i<s.size();i++){
			if(s[i]!=z[i]&&lk==0){
				f=i;
				lk=1;
			}
			else if(s[i]!=z[i])g=i;
		}
		for(int i=f+1;i<g;i++){
			p+=s[i];
			w+=z[i];
		}
		for(int i=f;i>=0;i--){
			x=s[i]+p;
			e=z[i]+w;
			for(int o=0;o<s.size()-g;o++){
				x+=s[o+g];
				e+=z[o+g];
				if(a[x]==e){
					ans++;
				}
			}
			p=s[i]+p;
			w=z[i]+w;
		}
		cout<<ans<<"\n";
		ans=0;
	}
	return 0;
}
