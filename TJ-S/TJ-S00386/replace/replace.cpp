#include<bits/stdc++.h>
using namespace std;
int n,q;
string s[200005][3];
string a,b;
int c[1000006];
int ans;
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	cin>>n>>q;
	for(int i=1;i<=n;i++){
		cin>>s[i][1]>>s[i][2];
	}
	for(int i=1;i<=q;i++){
		cin>>a>>b;
		int l=a.size();
		int st,ed;
		ans=0;
		for(int i=0;i<l;i++){
			if(a[i]!=b[i]){st=i;break;}
		}
		for(int i=l-1;i>0;i--){
			if(a[i]!=b[i]){ed=i;break;}
		}
		int len=ed-st+1;
		for(int i=1;i<=n;i++){
			if(s[i][1].size()==len){
				int flag=1;
				for(int j=0;j<len;j++){
					if(s[i][1][j]!=a[j+st]||s[i][2][j]!=b[j+st]){flag=0;break;}
				}
				if(flag)ans++;
			}
//			else if(s[i][1].size()>len){
//				for(int k=0;k<=s[i][1].size()-len;k++){
//					int fl=1;
//					for(int j=0;j<len;j++){
//						if(s[i][1][j+k]!=a[j+st]||s[i][2][j+k]!=b[j+st]){fl=0;break;}
//					}
//					if(fl==1){ans++;break;}
//				}
//			}
		}
		cout<<ans<<"\n";
	}
	return 0;
}
