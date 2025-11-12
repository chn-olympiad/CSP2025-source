#include<bits/stdc++.h>
using namespace std;
struct nd{
	string th1,th2;
	string ss1,ss2;
	int xl,xr,zl,zr;
	int xc,zc;
};
map<pair<string,string>,vector<nd> >mp;
int n,m;
string s1,s2;
nd cl(string sss1,string sss2){
	nd ret;
	ret.xl=0;
	ret.zr=sss1.length()-1;
	string tth1="",tth2="";
	string eth1="",eth2="";
	int l=-1,r=-1;
	for(int i=0;i<=ret.zr;i++){
		if(sss1[i]!=sss2[i]){
			if(l==-1){
				l=i;
				ret.xr=l;
			}
			r=i;
			eth1=tth1+sss1[i];
			eth2=tth2+sss2[i];
		}
		if(l!=-1){
			tth1+=sss1[i];
			tth2+=sss2[i];
		}
	}
	ret.th1=eth1;
	ret.th2=eth2;
	ret.ss1=sss1;
	ret.ss2=sss2;
	ret.xr=l-1;
	ret.zl=r+1;
	ret.xc=ret.xr-ret.xl+1;
	ret.zc=ret.zr-ret.zl+1;
	return ret;
}
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>s1>>s2;
		nd d=cl(s1,s2);
		mp[{d.th1,d.th2}].push_back(d);
	}
	for(int i=1;i<=m;i++){
		cin>>s1>>s2;
		int ans=0;
		if(s1.length()!=s2.length()){
			cout<<0<<"\n";
			continue;
		}
		nd d=cl(s1,s2);
		for(int j=0;j<mp[{d.th1,d.th2}].size();j++){
			nd dd=mp[{d.th1,d.th2}][j];
			if(d.xc<dd.xc||d.zc<dd.zc){
				continue;
			}
			bool f=1;
			if(dd.xc!=-1){
				for(int k1=0,k2=d.xr-dd.xc+1;k2<=d.xr;k1++,k2++){
					if(dd.ss1[k1]!=s1[k2]){
						f=0;
						break;
					}
				}
			}
			if(f==0){
				continue;
			}
			if(dd.zc!=-1){
				for(int k1=dd.zl,k2=d.zr;k1<=dd.zr;k1++,k2++){
					if(dd.ss1[k1]!=s1[k2]){
						f=0;
						break;
					}
				}
			}
			if(f==0){
				continue;
			}
			ans++;
		}
		cout<<ans<<"\n";
	}
}
