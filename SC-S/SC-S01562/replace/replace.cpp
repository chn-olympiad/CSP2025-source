#include<bits/stdc++.h>
#define fi first
#define se second 
#define endl "\n"
//#define int long long 
using namespace std;
const int maxn=2e5+10;
int n,q;
string a[maxn][2],t1,t2;
signed main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	ios_base::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	cin>>n>>q;
	for(int i=1;i<=n;i++){
		cin>>a[i][0]>>a[i][1];
	}
	while(q--){
		cin>>t1>>t2;
		int cnt=0;int r=0,l=0;
		for(int i=0;i<(int)t1.size();i++){
			if(t1[i]!=t2[i]){
				r=i;
				break;
			}
		}
		for(int i=(int)t1.size()-1;i>=0;i--){
			if(t1[i]!=t2[i]){
				l=i;
				break;
			}
		}
		cnt=l-r+1;
		int ans=0;
		string f;
		int x=0,y=0;
		for(int i=1;i<=n;i++){
			x=(int)a[i][0].size();y=(int)t1.size();
			if(cnt>x){
				continue;
			}
			else{
				for(int j=0;j<=r;j++){
					if(j+x<l)continue;
					bool h=true;
					for(int k=j;k<x+j;k++){
						if(a[i][0][k-j]!=t1[k]){h=false;break;}
					}
					if(h==true){
						f="";
						for(int k=0;k<j;k++){f+=t1[k];}
						f+=a[i][1];
						for(int k=x+j;k<y;k++){f+=t1[k];}
						if(f==t2){ans++;}
					}
				}
			}
		}
		cout<<ans<<endl;
	}
	return 0;
}