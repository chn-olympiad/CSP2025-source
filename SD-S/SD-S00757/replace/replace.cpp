#include<iostream>
using namespace std;
const int N=2e5+10;
string a[N],b[N];int n,q;
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin>>n>>q;
	for(int i=1;i<=n;i++) cin>>a[i]>>b[i];
	while(q--){
		string t1,t2;
		cin>>t1>>t2;
		int ans=0;m
		for(int i=1;i<=n;i++){
			int pos=t1.find(a[i]);
			while(0<=pos&&pos<=t1.size()){
				string k=t1.substr(0,pos)+b[i]+t1.substr(pos+b[i].size(),t1.size()-pos-b[i].size());
				if(k==t2) ans++;
				pos=t1.find(a[i],pos+1);
			}
		}
		cout<<ans<<endl;
	}

	return 0;
}
