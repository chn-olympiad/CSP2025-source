#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N=2e5+5;
int n,q,n1,n2,num[N],ans,kp[N];
string s1[N],s2[N];
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	bool flag=true;
	cin>>n>>q;
	for(int i=1;i<=n;i++){
		cin>>s1[i]>>s2[i];
		num[i]=s1[i].size();
	}
	while(q--){
		int ans=0;
		string t1,t2;
		cin>>t1>>t2;
		n1=t1.size(),n2=t2.size();
		t1=' '+t1;
		if(n1!=n2){
			cout<<0<<'\n';
			continue;
		}
		for(int i=1;i<=n;i++){
			for(int j=1;j+num[i]-1<=n1;j++){
				string gg=t1.substr(j,num[i]),pp;
				if(gg==s1[i]){
					gg=s2[i];
				}
				if(j-1>0){
					pp+=t1.substr(1,j-1);
				}
				pp+=gg;
				if(n1-j-num[i]+1>0){
					pp+=t1.substr(j+num[i],n1-j-num[i]+1);
				}
//				cout<<pp<<' '<<t2<<'\n';
				if(pp==t2){
//					cout<<pp<<' '<<t2<<'\n';
					ans++;
				}
			}
		}
		cout<<ans<<'\n';
	}
	return 0;
}
