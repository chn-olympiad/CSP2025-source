#include<bits/stdc++.h>
using namespace std;
int n,q;
string st,en;
struct node{
	string a,b;
}er[200005];
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin>>n>>q;
	for(int i=1;i<=n;i++){
		cin>>er[i].a>>er[i].b;
	}
	while(q--){
		int ans=0;
		cin>>st>>en;
		for(int i=1;i<=n;i++){
			string stt=st;
			if(st.find(er[i].a)>st.size()-1) continue;
			int wz=st.find(er[i].a);
			for(int j=wz;j<=wz+er[i].a.size()-1;j++){
				stt[j]=er[i].b[j-wz];
			}
			if(stt==en) ans++;
		}
		cout<<ans<<"\n";
	}
	return 0;
}
