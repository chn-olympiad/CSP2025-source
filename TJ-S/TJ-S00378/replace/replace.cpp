#include<bits/stdc++.h>
#define ll long long 
using namespace std;
struct ch{
	string a,b;
}c[200005];
int n,q;
int ans;
string ga,gb;
bool comp(int k){
	for(int i=0;i<=(strlen(ga.c_str())-strlen(c[k].a.c_str()));i++){
		//cout<<ga[i]<<" "<<c[k].a[0]<<endl;
		if(ga[i]==c[k].a[0]){
			bool flag=0;
			for(int j=0;j<strlen(c[k].a.c_str());j++){
				if(ga[i+j]!=c[k].a[j]){
					flag=1;
					break;
				}
			}
			if(flag==0){
				for(int j=0;j<strlen(c[k].a.c_str());j++){
					//cout<<ga[i+j]<<" "<<c[k].a[j]<<endl;
					ga[i+j]=c[k].b[j];
				}
				//cout<<ga<<endl;
				if(ga==gb) return true;
			}
		}
	}
	return false;
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	cin>>n>>q;
	for(int i=1;i<=n;i++){
		cin>>c[i].a>>c[i].b;
	}
	for(int i=1;i<=q;i++){
		ans=0;
		cin>>ga>>gb;
		if(strlen(ga.c_str())!=strlen(gb.c_str())){
			cout<<0<<endl;
			continue;
		}
		for(int j=1;j<=n;j++){
			if(comp(j)) ans++;
		}
		cout<<ans<<endl;
	}
	return 0;
}
