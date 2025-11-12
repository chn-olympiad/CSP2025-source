#include<bits/stdc++.h>
using namespace std;
string st[100000],st1[100000]; 
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	int n;cin>>n;
	int q;cin>>q;
	for(int i=1;i<=n;i++){
		cin>>st[i]>>st1[i];
	} 
	int ans=0;
	for(int i=1;i<=q;i++){
		ans=0;
		string qu,qu1;cin>>qu>>qu1;
		for(int i=0;i<qu.size()-1;i++)for(int j=i;j<qu.size();j++){
			string tmp="";
			
			for(int z=i;z<=j;z++)tmp+=qu[z];
			//cout<<i<<" "<<j<<" "<<tmp<<"\n";
			for(int k=1;k<=n;k++)if(tmp==st[k]){
				string tt=qu;
				for(int kk=i;kk<=j;kk++)tt[kk]=st1[k][kk-i];
				//cout<<tt<<"  1"<<endl;
				if(tt==qu1)ans++;
			}
		}
		cout<<ans;
	}
	
}