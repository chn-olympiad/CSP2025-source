#include<iostream>
#include<map>
#include<algorithm>
#include<string>
#define int long long
using namespace std;
const int N=500010,mod=1e13+7,base=37;
int n,q,ne[N],ne2[N];
map<pair<string,string>,int> hsh;
signed main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	cin>>n>>q;
	for(int i=1;i<=n;i++){
		string a,b;
		cin>>a>>b;
		hsh[{a,b}]++;
	}
	while(q--){
		string a,b;
		cin>>a>>b;
		string lefa=a,lefb=b;
		reverse(lefa.begin(),lefa.end()),reverse(lefb.begin(),lefb.end());
		int cnt=0;
		for(int l=0;l<a.size();l++){
//			if(nowa!=nowb)
//				break;
			string nea="",neb="",nela=lefa,nelb=lefb;
//			reverse(nela.begin(),nela.end()),reverse(nelb.begin(),nelb.end());
			for(int r=l;r<a.size();r++){
				nea+=a[r],neb+=b[r],nela.erase(nela.end()-1),nelb.erase(nelb.end()-1);
//				cout<<nea<<' '<<neb<<' '<<nela<<' '<<nelb<<endl;
				string lef=nela,left=nelb;
				reverse(lef.begin(),lef.end()),reverse(left.begin(),left.end());
				if(lef==left){
					if(hsh.count({nea,neb}))
						cnt+=hsh[{nea,neb}];
				}
				else
					break;
			}
//			nowa+=a[l],nowb+=b[l];
			lefa.erase(lefa.end()-1),lefb.erase(lefb.end()-1);
		}
		cnt+=hsh[{a,b}];
		cout<<cnt<<endl;
	}
}
