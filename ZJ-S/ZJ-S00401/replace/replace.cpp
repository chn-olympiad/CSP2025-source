#include <bits/stdc++.h>
using namespace std;
int n,q,f,b;
int t,ans;
string x,y;
struct node{
	string a,b;
}a[100010];
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	cin>>n>>q;
	for(int i=0;i<n;i++){
		cin>>a[i].a>>a[i].b;
	}
	while(q--){
		cin>>x>>y;
		f=b=t=ans=0;
		for(int i=0;i<x.size();i++){
			if(x[i]!=y[i]){
				if(!t) f=i;
				if(t==2){
					t++;
					cout<<0<<"\n";
					break;
				}
				t=1;
				b=i;
			}else{
				if(t==1) t=2;
			}
		}
		if(t==3) continue;
		for(int i=0;i<=f;i++){
			for(int j=b;j<x.size();j++){
				string k=x.substr(i,j-i+1),o=y.substr(i,j-i+1);
				for(int l=0;l<n;l++){
					if(a[l].a==k and a[l].b==o){
						ans++;
					}
				}
			}
		}
		cout<<ans<<"\n";
	}
	return 0;
}

