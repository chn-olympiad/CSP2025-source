#include<bits/stdc++.h>
using namespace std;
int n,q;
map<string,int>m1,m2;
map<int,int> len;
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	cin>>n>>q;
	for(int i=1;i<=n;i++){
		string ts1,ts2;
		cin>>ts1>>ts2;
		m1[ts1]=i;
		m2[ts2]=i;
		len[ts1.size()]=i;
	}
	for(int i=0;i<q;i++){
		string qs1,qs2;
		int ans=0;
		cin>>qs1>>qs2;
		if(qs1.size()==qs2.size()){
			int ldif=-1;
			int rdif=-1;
			for(int j=0;j<qs1.size();j++){
				if(qs1[j]!=qs2[j]){
					if(ldif==-1){
						ldif=j;
					}
					if(rdif<j){
						rdif=j;
					}
				}
			}
			if(ldif==0 && rdif==qs1.size()-1){
				if(m1[qs1]==m2[qs2] && m1[qs1]!=0){
							ans++;
						}
			}
			else{
				for(int r=rdif;r<qs1.size();r++){
					int l=0;
					int le;
					while(l<=ldif){
						le=r-l+1;
						if(len[le]>0){
							if(m1[qs1.substr(l,r-l+1)]==m2[qs2.substr(l,r-l+1)] && m1[qs1.substr(l,r-l+1)]!=0){
								ans++;
							}
						}
						l++;
					}
				}
			}
			
		}
		if(i!=q-1){
				cout<<ans<<endl;
			}
			else{
				cout<<ans;
			}
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}