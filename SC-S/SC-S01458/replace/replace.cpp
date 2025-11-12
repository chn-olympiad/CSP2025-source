#include<bits/stdc++.h>
using namespace std;
int read(){
	int s=0,f=1;char ch=getchar();
	while(!isdigit(ch)){if(ch=='-')f=-1;ch=getchar();}
	while(isdigit(ch)){s=(s<<3)+(s<<1)+(ch^48);ch=getchar();}
	return s*f;
}
const int N=2e5+5;
int n,q;
string s1[N],s2[N];
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	cin>>n>>q;
	for(int i=1;i<=n;i++) cin>>s1[i]>>s2[i];
	while(q--){
		string t1,t2;cin>>t1>>t2;
		int ans=0;
		for(int i=0;i<t1.size();i++){
			for(int j=i;j<t1.size();j++){
				string tmp1="",tmp2="",tmp3="";
				for(int k=0;k<i;k++) tmp1=tmp1+t1[k];
				for(int k=i;k<=j;k++) tmp2=tmp2+t1[k];
				for(int k=j+1;k<t1.size();k++) tmp3=tmp3+t1[k];
				for(int k=1;k<=n;k++){
					if(tmp2==s1[k]){
						if(tmp1+s2[k]+tmp3==t2) ans++;		
					}
				}
			}
		}
		cout<<ans<<'\n';
	}
	return 0;
} 
/*
3 4
a b
b c
c d
aa bb
aa b
a c
b a
*/