#include<bits/stdc++.h>
using namespace std;
unordered_map<string,string> ma;
int n,m;
string tf[200005],bf[200005];
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		//string bt;
		cin>>tf[i]>>bf[i];
		//ma[tf[i]]=bt;
	}
	for(int i=1;i<=m;i++){
		string aska,askb;
		int cnt=0;
		cin>>aska>>askb;
		for(int j=1;j<=n;j++){
			int wz=0;
			//cout<<"i "<<i<<" j "<<j<<" ififif"<<endl;
			while(aska.find(tf[j],wz)!=string::npos){
				int ret=aska.find(tf[j],wz);
				//cout<<"i "<<i<<" j "<<j<<" ret "<<ret<<" ";
				string ct=aska;
				int idx=0;
				for(int k=ret;k<(ret+tf[j].length());k++){
					ct[k]=bf[j][idx++];
				}
				if(ct==askb) cnt++;
				//cout<<"wz "<<wz<<endl;
				//cout<<ct<<" "<<askb<<endl;
				wz=ret+1;
			}
		}
		cout<<cnt<<endl;
	}
	return 0;
}