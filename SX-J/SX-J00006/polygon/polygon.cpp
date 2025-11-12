#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	ll n;
	cin>>n;
	if(n<3){
		cout<<"0";
		return 0;
	}
	else if(n==3){
		ll q,w,e;
		cin>>q>>w>>e;
		if(q+w>e&&q+e>w&&w+e>q){
			if(max(q,w)-min(q,w)<e&&max(q,e)-min(q,e)<w&&max(w,e)-min(w,e)<q){
				cout<<"1";
				return 0;
			}
		}
			cout<<"0";
	}
	return 0;
}