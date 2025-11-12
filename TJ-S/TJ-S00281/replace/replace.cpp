#include<bits/stdc++.h>
using namespace std;
const int N = 2e5 + 5;
int n,q,ppp[N][2],ans;
string s1,s2;
int main(){
    freopen("replace.in","r",stdin);
    freopen("replace.out","w",stdout);
	cin>>n>>q;
	for(int i=1;i<=n;i++){
		cin>>s1>>s2;
		int l=s1.length(),pos1=-1,pos2=-1;
		for(int i=0;i<l;i++){
			if(s1[i]=='b') pos1=i;
			if(s2[i]=='b') pos2=i;
			if(pos1>-1&&pos2>-1) break;
		}
		ppp[i][0]=pos2-pos1;
		ppp[i][1]=l;
		cout<<ppp[i][0]<<' '<<ppp[i][1]<<'\n';
	}
	for(int i=1;i<=q;i++){
		ans=0;
		cin>>s1>>s2;
		if(s1.length()!=s2.length()){
			cout<<0<<'\n';
		}else{
			int len=s1.length(),pos1,pos2;
			for(int j=0;j<len;j++){
				if(s1[j]=='b') {
					pos1=i;
				}
				if(s2[j]=='b'){
					pos2=i;
				}
			}
			int dif=pos1-pos2;
			cout<<dif<<'\n';
			for(int j=1;j<=n;j++){
				if(dif==ppp[j][0]&&len<=ppp[j][1]){
					ans++;
				}
			}
		}
		cout<<ans<<'\n';
	}
	return 0;
}

