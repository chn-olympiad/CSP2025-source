#include<bits/stdc++.h>
using namespace std;
int t,n;
int a,b,c,ca,cb,cc,s;
int main() {
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	while(t--) {
		cin>>n;
		for(int i=0;i<n;i++){
			cin>>a>>b>>c;
			if(max(a,max(b,c))==a){
				if(ca+1<=n/2) ca++,s+=a;
			}
			else if(max(b,max(a,c))==b){
				if(cb+1<=n/2) cb++,s+=b;
			}	
			else cc++,s+=c;
			cout<<s<<' ';
		}
		cout<<s<<endl;
	}
	return 0;
}

