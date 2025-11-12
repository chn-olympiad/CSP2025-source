#include<bits/stdc++.h>
#define ll long long
#define ull unsigned long long
#define pii pair<int,int>
#define p(i,j) make_pair(i,j)
using namespace std;
const int N=2e5+10;
int n,m,x,y,z,sum,ans,tmp,cnt,now,u,v,l,r,k,T,a[N];
string s1[N],s2[N],t1,t2;
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>T;
	for(int i=1;i<=n;i++) cin>>s1[i]>>s2[i];
	while(T--){
		ans=0;
		cin>>t1>>t2;
		if(t1.size()!=t2.size()){
			cout<<"0\n";
			continue;
		} 
		for(int i=1;i<=n;i++){
			if(t1.size()>=s1[i].size()){ 
//			int of=1,pt=0;
//			while(of){
//				of=0;
				for(int j=0;j<=t1.size()-s1[i].size();j++){
//					cout<<t1<<" "<<j<<"\n";
					int f=1;
					for(int k=0;k<s1[i].size();k++){
						if(t1[j+k]!=s1[i][k]){
//							cout<<t1<<" "<<s1[i]<<" "<<j+k<<" "<<k<<" "<<t1[j+k]<<" "<<s1[i][k]<<"\n";
							f=0;
							break;
						}
					}
					if(f){
	//					of=1;
//						cout<<t1<<" "<<j<<" "<<s1[i]<<"\n";
						string tmp=t1;
						for(int k=0;k<s1[i].size();k++) tmp[j+k]=s2[i][k];
						if(tmp==t2) ans++;
					}
	//					if(f) break;
				}
			}
//			}
		}
		cout<<ans<<"\n";
	}
	return 0;
}

