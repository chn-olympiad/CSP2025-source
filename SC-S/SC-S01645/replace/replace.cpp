#include<bits/stdc++.h>
#define froepen freopen
/*rp+++++++++++++++++++
++++++++++++++++++++
++++++++++++++++++++++
+++++++++++++++++++++++
++++++++++++++++++++
++++++++++++++++++++++++++
+++++++++++++++++++++
++++++++++++++++++++++++
++++++++++++++++++++++
+++++++++++++++++
+++++++++++++++++++
++++++++++++++++++++
++++++++++++++++++
++++++++++++++++++
+++++++++++++++++++
++++++++++++++++++++
++++++++++++++++++++++
+++++++++++++++++++++++
++++++++++++++++++++
++++++++++++++++++++++++++
+++++++++++++++++++++
++++++++++++++++++++++++
++++++++++++++++++++++
+++++++++++++++++
+++++++++++++++++++
++++++++++++++++++++
++++++++++++++++++
++++++++++++++++++*/
using namespace std;
const int ts=false;
//class trie{
//	public:
//};
//struct midint{
//	int a[5000320];
//	int& operator[](int i){
//		return a[i+1500000];
//	}
//};
int plc[200320],prc[200320];
bool ta=true;
bool check(string s,bool yj=true){
	if(!ta)return false;
	bool meet=false;
	for(int j=0;j<s.size();++j){
			if(s[j]!='a'&&s[j]!='b'||s[j]=='b'&&meet)return false;
			if(s[j]=='b')meet=true;
		}
		if(yj)ta=meet;
		return meet;
}
int main(){
	if(!ts){
		ios::sync_with_stdio(false);
		cin.tie(0);
		cout.tie(0);
		froepen("replace.in","r",stdin);
		froepen("replace.out","w",stdout);
	}
	int n,m;
	cin>>n>>m;
	string a[n],b[n];
	for(int i=0;i<n;++i){
		cin>>a[i]>>b[i];
		if(check(a[i])&&check(b[i])){
			plc[i]=a[i].find("b");prc[i]=b[i].find("b");
		}
	}
	int outp=0;
	for(int i=0;i<m;++i){
		string p,q;
		cin>>p>>q;
		
		if(p.size()!=q.size())cout<<"0\n";
		else if(check(p,false)&&check(q,false)){
			int qlc=p.find("b"),qrc=q.find("b"),ans=0;
			for(int i=0;i<n;++i){
				if(plc[i]-prc[i]==qlc-qrc&&qlc+n-plc[i]-1<n&&qlc-prc[i]>=0)++ans;
			}
			cout<<ans<<"\n";
		}
		else{
			int l=0,r,ans=0;
			while(l<p.size()&&p[l]==q[l])++l;
			r=p.size()-1;
			while(r>=0&&p[r]==q[r])--r;
		//	if(outp==3924375)return 0;
		//	cout<<l<<" "<<r<<endl;
			for(int j=0;j<n;++j){
				int ai=a[j].find(p.substr(l,r-l+1));
			//	cout<<ai<<" ";
				++outp;
			//	cout<<outp<<" ";
				int bi=ai;
				if(ai>=n||ai<0||q.substr(l,r-l+1)!=b[j].substr(bi,r-l+1)){
			//		cout<<"nue ";
					continue;
				}
				
				ai=p.find(a[j]);bi=ai;
				if(ai>=n||ai<0||bi!=q.find(b[j])){
			//		cout<<"nue ";
					continue;
				}
			//	cout<<" c"<<j<<"c ";
				++ans;
			}
			cout<<ans<<"\n";
		}
	}
}