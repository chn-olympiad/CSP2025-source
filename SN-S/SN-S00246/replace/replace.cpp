//张爱熙 SN-S00246 西安高新第一中学 
#include<bits/stdc++.h>
using namespace std;
const int N=2e5+5;
int n,m,k,cnt;
string a,b;
struct node{
	string x,y;
}c[N];
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++) cin>>c[i].x>>c[i].y;
	for(int i=1;i<=m;i++){
		cin>>a>>b;
		cnt=0;
		for(int j=1;j<=n;j++){
			int p=0;
			while(a.find(c[j].x,p)<a.size()){
				string k;
				if(a.find(c[j].x,p)>0) k+=a.substr(0,a.find(c[j].x,p));
				k+=c[j].y;
				if(a.find(c[j].x,p)+c[j].x.size()<a.size()) k+=a.substr(a.find(c[j].x,p)+c[j].x.size(),a.size()-a.find(c[j].x,p)-c[j].x.size());
				if(k==b) cnt++;
				p=a.find(c[j].x,p)+c[j].x.size();
			}
		}
		cout<<cnt<<"\n";
	}
	return 0;
}
