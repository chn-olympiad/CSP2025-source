#include<bits/stdc++.h>
using namespace std;
void jiao(string &a,string &b){
	string di,ff,re,nt;int fl=0;
	di=ff=re=nt="";
	for(int i=0;i<a.size();i++){
		if(a[i]!=b[i]||fl){
			di+=a[i];
			ff+=b[i];
			fl=1;
		}
	}
	fl=0;
	for(int i=di.size()-1;i>=0;i--){
		if(di[i]!=ff[i]||fl){
			re=di[i]+re;
			nt=ff[i]+nt;
			fl=1;
		}
	}
	a=re,b=nt;
}
const int N=2*1e5+10;
string a[N][2],b[N][2];
int main(){
	freopen("replace.in","r",stdin);freopen("replace.out","w",stdout);
	int n,m;string s1,s2;
	cin>>n>>m;
	for(int i=0;i<n;i++){
		cin>>s1>>s2;
		jiao(s1,s2);
		a[i][0]=s1;
		a[i][1]=s2;
		
	}
	for(int i=0;i<m;i++){
		cin>>s1>>s2;
		jiao(s1,s2);
		b[i][0]=s1;
		b[i][1]=s2;
		
	}
	
	for(int i=0;i<m;i++){
		int ans=0;
		for(int j=0;j<n;j++){
			if(a[j][0]==b[i][0]&&a[j][1]==b[i][1]){
				ans++;
			}
		}
		cout<<ans<<"\n";
	}
	
	return 0;
}