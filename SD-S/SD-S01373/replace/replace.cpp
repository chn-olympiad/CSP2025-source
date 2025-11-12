#include<bits/stdc++.h>
using namespace std;
unordered_map<string,string> a;
string p[200010]={""};
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	int n,q;
	cin>>n>>q;
	string h,b;
	int y=0;
	for(int i=0;i<n;i++){
		cin>>h>>b;
		if(a[h]=="")a[h]=b,p[y++]=h;
	}
	string f,d;
	while(q--){
		cin>>f>>d;
		long long ans=0;
		int l=f.size();
		for(int i=0;i<y;i++){
			int pl=f.find(p[i]);
			if(pl!=-1){
				string o=a[p[i]];
				string hh=f;
				int len=o.size();
				for(int ss=0,j=pl;ss<len;j++,ss++)hh[j]=o[ss];
				if(hh==d)ans++;
			}
		}
		cout<<ans<<"\n";
	}
	return 0;
}

