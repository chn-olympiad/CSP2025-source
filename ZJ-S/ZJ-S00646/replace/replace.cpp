#include<bits/stdc++.h>
using namespace std;
int n,q,ans,fl,fll;
string s1[200005],s2[200005],p1,p2,x1;
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	cin>>n>>q;
	for(int i=1;i<=n;i++){
		cin>>s1[i]>>s2[i];
	}
	while(q--){
		cin>>p1>>p2;ans=0;x1=p1;
		if(p1.size()!=p2.size()){cout<<"0\n";continue;}
		for(int i=1;i<=n;i++){
			for(int j=0;j<p1.size()-s1[i].size()+1;j++){
				fl=1;
				for(int k=j;k<=j+s1[i].size()-1;k++){
					if(s1[i][k-j]!=p1[k]){fl=0;break;}
				}
				if(fl==1){
					for(int k=j;k<=j+s2[i].size()-1;k++){
						p1[k]=s2[i][k-j];
					}
					fll=1;
					for(int k=0;k<p1.size();k++)
						if(p1[k]!=p2[k]){fll=0;break;}
					cout<<p1<<" "<<p2<<'\n';
					if(fll==1)ans++,p1=x1;
				}
				p1=x1;
			}
		}
		cout<<ans<<"\n";
	}
	return 0;
}

