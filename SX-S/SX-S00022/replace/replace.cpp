#include<bits/stdc++.h>
using namespace std;
int bjuli[200005];

int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	int n,q;
	cin>>n>>q;
	for(int i=1;i<=n;i++){
		string s1,s2;
		cin>>s1>>s2;
		int b1,b2;
		for(int j=0;j<=s1.size();j++){
			if(s1[j]=='b'){
				b1=j;
				break;
			}
		}for(int j=0;j<=s1.size();j++){
			if(s2[j]=='b'){
				b2=j;
				break;
			}
		}bjuli[i]=abs(b1-b2);
	}while(q--){
		long long ans=0;
		string t1,t2;
		cin>>t1>>t2;
		int b1,b2;
		for(int i=0;i<=t1.size();i++){
			if(t1[i]=='b'){
				b1=i;
				break;
			}
		}for(int i=0;i<=t1.size();i++){
			if(t2[i]=='b'){
				b2=i;
				break;
			}
		}for(int i=1;i<=n;i++){
			if(abs(b1-b2)==bjuli[i]){
				ans++;
			}
		}cout<<ans<<endl;
	}
	return 0;
}