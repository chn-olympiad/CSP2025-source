#include<bits/stdc++.h>
using namespace std;
string a,b;
map <string,map <string,int> > ma;
int n,q,st,en,k,siz[5000005],qwe[5000005];
string s,z;
signed main(){
	freopen("replace4.in","r",stdin);
	freopen("replace.out","w",stdout);
	cin.tie(0);
	cout.tie(0);
	ios::sync_with_stdio(0);
	cin>>n>>q;
	for(int i=1;i<=n;i++){
		cin>>a>>b;
		ma[a][b]++;
	}
	for(int j=1;j<=q;j++){
		int ans=0;
		cin>>a>>b;
		int sa=a.size(),sib=b.size(),str=-1,end=0;
		if(sa==sib){
			for(int i=0;i<sa;i++){
				if(a[i]!=b[i]) {
					en=i;
					if(str==-1) str=i;
				}
			}
			string h,p;
			for(int i=str;i<=en;i++){
				h+=a[i];
				p+=b[i];
			}
			if(ma[h][p]){
				ans+=ma[h][p];
			}
			for(int i=str-1;i>=0;i--){
				h=a[i]+h;
				p=b[i]+p;
				if(ma[h][p]){
					ans+=ma[h][p];
				}
				string ch=h,cp=p;
				for(int k=en+1;k<sa;k++){
					h+=a[k];
					p+=b[k];
					if(ma[h][p]){
						ans+=ma[h][p];
					}
				}
			}
		}
		cout<<ans;
		cout<<endl;
	}
	return 0;
} 
