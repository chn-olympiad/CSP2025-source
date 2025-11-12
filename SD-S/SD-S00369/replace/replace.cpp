#include<iostream>
#include<cstdio>
#include<string>
#include<map>
using namespace std;
const int N=200005;
long long read(){
	long long x=0;
	char c=getchar();
	while (c<'0' || c>'9') c=getchar();
	while (c>='0' && c<='9') {
		x*=10;
		x+=(c-'0'); 
		c=getchar();
	}
	return x;
}
string s[N][3];
int n,q;
int totsiz=0;
map<int,int> mp;
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	n=read(),q=read();
	for (int i=1;i<=n;i++){
		cin>>s[i][1]>>s[i][2];
		int b1=0,b2=0;
		for (int j=0;j<s[i][1].length();j++){
			if (s[i][1][j]=='b'){
				b1=j;
				break;
			}
		}
		for (int j=0;j<s[i][2].length();j++){
			if (s[i][2][j]=='b'){
				b2=j;
				break;
			}
		}
		mp[b1-b2]++;
		totsiz+=s[i][1].length();
	}
	if (totsiz>2000){//B
		while (q--){
			string a,b;
			cin>>a>>b;
			int b1=0,b2=0;
			for (int j=0;j<a.length();j++){
				if (a[j]=='b'){
					b1=j;
					break;
				}
			}
			for (int j=0;j<b.length();j++){
				if (b[j]=='b'){
					b2=j;
					break;
				}
			}
			printf("%d\n",mp[b1-b2]);
		}
		return 0;
	}
	while (q--){
		string a,b;
		long long ans=0;
		int l=-1,r=0;
		cin>>a>>b; 
		if (a.length()!=b.length()){
			printf("0\n");
			continue;
		}
		for (int i=0;i<a.length();i++){
			if (a[i]!=b[i]){
				if (l==-1) l=r=i;
				else r=i;
			}
		}
		//printf("%d %d\n",l,r);
		for (int i=1;i<=n;i++){//s
			if (s[i][1].length()<r-l+1 || s[i][1].length()>a.length()) continue;
			for (int j=0;j<=a.length()-s[i][1].length();j++){
				//printf("%d %d\n",i,j);
				string sub1="",sub2="";
				for (int k=j;k<j+s[i][1].length();k++){
					sub1+=a[k];
					sub2+=b[k];
				}
				if (sub1==s[i][1] && sub2==s[i][2]) ans++;
				
			}
		}
		printf("%lld\n",ans);
	} 
    return 0;
}

