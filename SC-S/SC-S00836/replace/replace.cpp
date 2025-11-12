#include<bits/stdc++.h>
using namespace std;
const int N=2e5+5;
int n,q;
struct String{
	string s,s1;
}t[N],z[N];
void init(){
	scanf("%d%d",&n,&q);
	for(int i=1;i<=n;i++){
		cin>>z[i].s>>z[i].s1;
	}
	for(int i=1;i<=q;i++){
		cin>>t[i].s>>t[i].s1;
	}
}
void solve(){
	init();
	for(int i=1;i<=q;i++){
		int ans=0;
		string a=t[i].s;
		for(int l=0;l<a.size();l++){
			for(int j=1;j<=n;j++){
				a=t[i].s;
				string b=a.substr(l,z[j].s.size());
				if(b==z[j].s){
					for(int r=l;r<l+z[j].s.size();r++){
						a[r]=z[j].s1[r-l];
					}
					int f=1;
					for(int r=0;r<a.size();r++){
						if(a[r]!=t[i].s1[r]){
							f=0;
							break;
						}
					}
					if(f) ans++;
				}
				
			}
		}
		printf("%d\n",ans);
	}
}
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	solve();
	return 0;
}