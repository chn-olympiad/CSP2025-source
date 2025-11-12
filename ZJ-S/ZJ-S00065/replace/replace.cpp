#include<bits/stdc++.h>
using namespace std;
int n,q;
string s[100005][3];
int f(string a,string b,int l,int r,int ll,int rr){
	if(l>r||ll>rr) return 1;
	for(int i=l;i<=r;i++){
		if(a[i]!=b[i+(ll-l)]) return 0;
	}
	return 1;
}
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	cin>>n>>q;
	for(int i=1;i<=n;i++){
		cin>>s[i][1]>>s[i][2];
	}
	while(q--){
		string s1,s2;
		cin>>s1>>s2;
		int len=s1.size(),ans=0,pos1=-1,pos2=len;
		for(int i=0;i<len;i++){
			if(s1[i]==s2[i]) pos1=i;
			else break;
		}
		for(int i=len-1;i>=0;i--){
			if(s1[i]==s2[i]) pos2=i;
			else break;
		}
		for(int i=1;i<=n;i++){
			int ln=s[i][1].size();
			for(int j=0,k=ln-1;k<len;j++,k++){
				if(j-1<=pos1&&k+1>=pos2&&f(s[i][1],s1,0,ln-1,j,k)&&f(s[i][2],s2,0,ln-1,j,k)){
					ans++;
				}
			}
		}
		cout<<ans<<endl;
	}
	return 0;
}