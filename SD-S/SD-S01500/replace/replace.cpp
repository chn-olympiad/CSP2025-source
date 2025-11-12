#include <bits/stdc++.h>
using namespace std;
long long n,q,ans;
string a[200100][2];
string b,c;
bool ww(int wz,int u){
	string jl="";
	for(int i=wz,j=0;i<wz+a[u][0].size();i++,j++){
		if(a[u][0][j]!=b[i]){
			return 0;
		}
	}
	return 1;
}
bool ww1(int wz,int u){
	string jl="";
	for(int i=0;i<wz;i++){
		jl+=b[i];
	}
	for(int i=wz,j=0;i<wz+a[u][0].size();i++,j++){
		jl+=a[u][1][j];
	}
	for(int i=wz+a[u][0].size();i<b.size();i++){
		jl+=b[i];
	}
	return (jl==c);
}
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	cin>>n>>q;
	for(int i=1;i<=n;i++){
		cin>>a[i][0]>>a[i][1];
	}
	for(int i=1;i<=q;i++){
		long long ans=0;
		cin>>b>>c;
		for(int j=1;j<=n;j++){
			if(b.size()>=a[j][0].size()){
				for(int k=0;k+a[j][0].size()<=b.size();k++){
					if(ww(k,j)){
						if(ww1(k,j)){
							if(b.size()>2000)break;
							ans++;
						}
					}
				}
			}
		}
		cout<<ans<<"\n";
	}
	return 0;
}

