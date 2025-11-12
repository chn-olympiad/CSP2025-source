#include<bits/stdc++.h>
using namespace std;
const int N=2e5+10;
string s1[N],s2[N];
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	int n,q;
	cin>>n>>q;
	for(int i=1;i<=n;i++){
		cin>>s1[i]>>s2[i];
	}while(q--){
		string t1,t2;
		cin>>t1>>t2;
		int lt1=t1.size();
		bool diff=false;
		int ans=0;
		for(int i=0;i<lt1;i++){
			if(t1[i]!=t2[i]) {
				diff=true;
			}
			for(int j=lt1-1;j>=0;j--){
				bool ch=false;
				if(t1[j]!=t2[j]) ch=true;
				string t="",tt="",ttt="";
				for(int k=i;k<=j;k++){
					t+=t1[k];
					tt+=t2[k];
				}
//				cerr<<t<<" "<<tt<<"\n";
				for(int k=1;k<=n;k++){
					if(t==s1[k]){
						if(tt==s2[k]){
							
//							cerr<<t<<" "<<tt;
							ans++;
						}
					}
				}
				if(ch) break;
			}
//			cerr<<"Aya";
			if(diff) break;
		}
		cout<<ans<<"\n";
//		cerr<<ans<<"\n";
	}
	return 0;
}
