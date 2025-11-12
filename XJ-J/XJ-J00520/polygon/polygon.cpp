#include<bits/stdc++.h> 
using namespace std;
int main(){
freopen("polygon.in","r",stdin);
freopen("polygon.out","w",stdout);
int n,ans,a,b,c,d,e;
cin>>n;
ans=0;
a=0;
b=0;
c=0;
d=0;
e=0;
int _n[n+5];
for(int i=0;i<n;++i){
	cin>>_n[i];
}
for(int i=3;i<=n;i++){
	for(int o=0;o<i;o++){
		if(_n[a]+_n[b]+_n[o]>2*max(_n[a],_n[b])&&o!=a&&o!=b){
			ans++;
		}
	}
}
cout<<ans;
return 0;
}
