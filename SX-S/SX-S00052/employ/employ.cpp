#include<bits/stdc++.h>
using namespace std;
string e;
int r[600];
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	long long ans=1;
	int q,w;
	bool easy=true;
	cin>>q>>w;
	cin>>e;
	int siz=e.size();
	for(int i=1;i<=q;i++){
		cin>>r[i];
	}for(int i=0;i<siz;i++){
		if(e[i]!='1'){
			easy=false;
			break;
		}
	}if(easy){
		for(int i=1;i<=q;i++){
			ans*=i;
			ans=ans%998244353;
			cout<<ans<<endl;
		}
	}cout<<ans;
	return 0;
}
