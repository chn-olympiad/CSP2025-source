#include <bits/stdc++.h>
using namespace std;

const int N=200000 + 10;
int n,q;
string a[N],b[N];
string x,y;
long long ans=0;
string z1=" ",z2=" ",ans1,ans2;

void getss(int l,int r){
	for(int i=l;i<=r;i++){
		z1=z1+x[i];
		z2=z2+y[i];
	}
}

int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	cin>>n>>q;
	for(int i=1;i<=n;i++){
		cin>>a[i]>>b[i];
	}	
	
	for(int i=1;i<=q;i++){
		cin>>x>>y;
		
		
		for(int i=1;i<=n;i++){
			int len=a[i].size();
			for(int j=0;j<x.size()-len+1;j++){
				z1="";z2="";ans1="";ans2="";
				getss(j,j+len-1);
				if(z1==a[i]&&z2==b[i]){
					ans++;
				}
			} 
		}
		cout<<ans<<endl;
	}
	
	return 0;
} 
