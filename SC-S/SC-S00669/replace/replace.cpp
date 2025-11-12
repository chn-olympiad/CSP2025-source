#include<bits/stdc++.h>
using namespace std;
int read(){
	int f=1,k=0;char c=getchar();
	while(!isdigit(c)&&c!='-') c=getchar();
	if(c=='-') f=-1,c=getchar();
	while(isdigit(c)) k=k*10+(c-'0'),c=getchar();
	return f*k;
}
const int N=110;
int n,q;
string s[N][3];
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	n=read(),q=read();
	for(int i=1;i<=n;i++){
		cin>>s[i][1]>>s[i][2];
	}
	if(n<=100){
		while(q--){
			string t1,t2;cin>>t1>>t2;
			if(t1.size()!=t2.size()){
				puts("0");
				continue;
			}
			int ans=0;
			for(int i=1;i<=n;i++){
				int len=s[i][1].size();
				for(int j=0;j+len-1<t1.size();j++){
					if(t1.substr(j,len)==s[i][1]){
						string tmp1=t1.substr(0,j)+s[i][2]+t1.substr(j+len,t1.size()-j-len);
						if(tmp1==t2) ans++;
					}
				}
			}
			cout<<ans<<"\n";
		}
	}else{
		while(q--) puts("0");
	}
	return 0;
}