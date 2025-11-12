#include <bits/stdc++.h>
using namespace std;
int n,q,sum;
string y[2000005],yp[2000005];
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	ios::sync_with_stdio(0);
	cin>>n>>q;
	for(int i=0;i<n;i++){
		cin>>y[i]>>yp[i];
	}
	while(q--){
		string s1,s2;
		cin>>s1>>s2;
		int wz;
		bool x=true;
		sum=0;
		for(int i=0;i<n;i++){
			x=true;
			for(int j=0;j<s1.size();j++){
				if(y[i][0]==s1[j]){
					wz=j;
					break;
				}
			}
			for(int j=wz;j<y[i].size()+wz;j++){
				if(y[i][j-wz]!=s1[j]){
					x=false;
					break;
				}
			}
			if(x){//y[i]是s1的子集 
				for(int j=wz;j<yp[i].size()+wz;j++){
					if(yp[i][j-wz]!=s2[j]){
						x=false;
						break;
					}
				}
				if(x){//yp[i]是s2对应位置的子集 
					for(int j=0;j<wz;j++){
						if(s1[j]!=s2[j]){x=false;break;}
					}
					for(int j=wz+y[i].size();j<s1.size();j++){
						if(s1[j]!=s2[j]){x=false;break;}
					}
					if(x)sum++;
				}
			}
		}
		cout<<sum<<endl;
	}
	return 0;
}
