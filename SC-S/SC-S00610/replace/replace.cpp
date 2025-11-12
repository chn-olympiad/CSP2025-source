#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=1.1e6,inf=2.1e18;

int n,q;
string dict[N][2],src,tgt;
int is(string L,string l){
	int Ll=L.length(),ll=l.length();
	for(int i=0;i<Ll-ll+1;i++){
		if(L.substr(i,ll)==l)return i;
	}
	return -1;
}
signed main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	scanf("%lld%lld",&n,&q);
	getline(cin,src);
	for(int i=0;i<n;i++){
		cin>>dict[i][0]>>dict[i][1];
	}
	while(q--){
		cin>>src>>tgt;
		int len=src.length(),s=-1,t=-1,ans=0;
		/*for(int i=0;i<len;i++){
			if(src[i]!=tgt[i]){
				if(s==-1)s=t=i;
				else t=i;
			}
		}*/
		for(int i=0;i<n;i++){
			string L=src,l=dict[i][0];
			int Ll=L.length(),ll=l.length();
			for(int ii=0;ii<Ll-ll+1;ii++){
				if(L.substr(ii,ll)==l){
					int pos=ii;
					//
					if(pos<0)continue;
					string A,B,C;
					if(pos==0)A="";
					else A=src.substr(0,pos);
					B=dict[i][1];
					if(src.length()-pos-dict[i][0].length()==0)C="";
					else C=src.substr(pos+dict[i][0].length(),src.length()-pos-dict[i][0].length());
					if(A+B+C==tgt)ans++;
				}
			}
			
		}
		printf("%lld\n",ans);
	}
	return 0;
}
/*0<=i<n*/
