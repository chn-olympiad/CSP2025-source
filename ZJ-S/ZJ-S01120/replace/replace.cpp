#include<bits/stdc++.h>
using namespace std;
const int N=5e6+5;
int n,q,lenop,al,lent,lens,l,r,ll=1;
int sl[N],sr[N];
char op[N],s1[N],s2[N],t1[N],t2[N];
bool _1,_2=true,_3,_4;
bool pd(int sl_,int sr_,int tl_){
	bool _=true;
	for(int i=sl_;i<=sr_;i++){
		if(s1[i]!=t1[tl_+i-sl_] || s2[i]!=t2[tl_+i-sl_]){
			_=false;
			break;
		}
	}
	return _;
}
signed main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	cin>>n>>q;
	sl[1]=1;
	for(int i=1;i<=n;i++){
		cin>>op;
		lenop=strlen(op);
		for(int j=1;j<=lenop;j++)
			s1[sl[i]+j-1]=op[j-1];
		sr[i]=sl[i]+lenop-1;
		cin>>op;
		for(int j=1;j<=lenop;j++)
			s2[sl[i]+j-1]=op[j-1];
		sl[i+1]=sl[i]+lenop;
	}
	for(int i=1;i<=q;i++){
		al=0;
		cin>>t1>>t2;
		lent=strlen(t1);
		for(int k=lent;k>0;k--){
			t1[k]=t1[k-1];
			t2[k]=t2[k-1];
		}
		t1[0]=t2[0]=' ';
		for(int j=1;j<=n;j++){
			lens=sr[j]-sl[j]+1;
			for(int o=1;o<=lent-lens+1;o++){
				_1=true;
				if(pd(sl[j],sr[j],o)){
					for(int k=1;k<=o-1;k++){
						if(t1[k]!=t2[k])
							_1=false;
					}
					for(int k=o+lens;k<=lent;k++){
						if(t1[k]!=t2[k])
							_1=false;
					}
					if(_1){
						al++;
						break;
					}
				}
			}
		}
		cout<<al<<endl;
	}
	return 0;
}
