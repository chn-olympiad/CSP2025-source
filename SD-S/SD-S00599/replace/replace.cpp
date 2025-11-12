#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
const int _MAXn=2e5+100;

int n,q;
string str[2][_MAXn];

string qry1,qry2; 
int minp,maxp;
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout); 
	cin>>n>>q;
	for(int i=1;i<=n;i++){
		cin>>str[0][i]>>str[1][i];
	}
	for(;q;q--){
		minp=0x3f3f3f3f,maxp=-0x3f3f3f3f;
		cin>>qry1>>qry2;
		if(qry1.size()!=qry2.size()){
			cout<<"0\n";
			continue;
		}
		for(int i=1;i<=qry1.size();i++){
			if(qry1[i-1]!=qry2[i-1])minp=min(minp,i-1),maxp=max(maxp,i-1); 
		}
		int ans=0;
		for(int i=1;i<=n;i++){
			int pos=-1;
			while(true){
				pos=qry1.find(str[0][i],pos+1);
				if(pos==string::npos)break;
				if(!(pos<=minp&&(pos+str[0][i].size()-1)>=maxp))continue;
				if(qry2.substr(pos,str[0][i].size())==str[1][i])ans++;
			}
		}
		cout<<ans<<'\n';
	}
	return 0;
}

