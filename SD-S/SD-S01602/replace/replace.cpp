#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int mod=1e9+9;
const int mod2=998244853;
const int N=2e5+5;
int n,q;
string s,ss;
struct node{
	int s1,s2;
	int s11,s22;
	int len;
	string m1,m2;
}a[N];
int sl[1000004],s2l[1000006];
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout); 
	scanf("%d%d",&n,&q);
	for(int i=1;i<=n;i++){
		cin>>s>>ss;
		a[i].len=s.size();
	/*	a[i].s1=hsh(s);
		a[i].s2=hsh(ss);
		a[i].s11=hsh2(s);
		a[i].s22=hsh2(ss);*/
		s='#'+s;
		ss='#'+ss;
		a[i].m1=s,a[i].m2=ss;
	}
	for(int i=1;i<=q;i++){
		cin>>s>>ss;
		if(ss.size()!=s.size()){
			printf("0\n");
			continue;
		}
		int ln=s.size();
		int ans=0;
		s='#'+s;
		ss='#'+ss;
		string res;
		res=s;
		string hh;
		for(int j=1;j<=n;j++){
			int fl=0;
			res=s;
			int ji=1;
			for(int bg=1;bg+a[j].len-1<=s.size();bg++){
				fl=0;
				res=s;
				hh=a[j].m2;
				for(int l=bg;l<=bg+a[j].len-1;l++){
					res[l]=hh[l-bg+1];
					if(s[l]!=a[j].m1[l-bg+1]) {
					//	cout<<j<<" "<<l<<" "<<bg<<endl;
					//	cout<<s[l]<<" "<<a[j].m1[l-bg+1]<<endl;
						fl=1;
						break;
					}
				}
				//cout<<fl<<endl;
				//cout<<j<<" "<<bg<<" "<<res<<" "<<ss<<endl;
				if(!fl){
					int fl2=0;
					for(int u=1;u<=s.size();u++){
						if(res[u]!=ss[u]) {
				//			cout<<res[u]<<" "<<a[j].m2[u]<<endl;
							 fl2=1;
						}
					}
					if(!fl2) ans++;
				//	cout<<fl2<<"ans???"<<ans<<endl;
				//	cout<<bg<<" "<<j<<endl;
				}
			} 
		}	
		printf("%d\n",ans);
	}
	return 0;
}
