#include<bits/stdc++.h>
using namespace std;
string t1,t2,u,v,o1,o2;
int n,q,l,r,ans;
map <string,string> g;
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	cin>>n>>q;
	for(int i=1;i<=n;i++){
		cin>>t1>>t2;
		g[t1]=t2;
	}
	t1=t2="";
	while(q--){
		ans=0;
		l=r=-1;
		cin>>u>>v;
		if(u.size()!=v.size()){
			cout<<0<<"\n";
			continue;
		}
		for(int i=0;i<u.size();i++){
			if(u[i]!=v[i]){
				if(l==-1) l=i;
				r=i;
			}
		}
		for(int i=l;i<=r;i++){
			t1+=u[i];
			t2+=v[i];
		}
		for(int i=l;i>=0;i--){
			if(i!=l) t1=u[i]+t1,t2=v[i]+t2;
			o1=t1,o2=t2;
			for(int j=r;j<u.size();j++){
				if(j!=r) o1+=u[j],o2+=v[j];
				if(g[o1]==o2) ans++;
			}
		}
		cout<<ans<<"\n";
	}
	return 0;
}