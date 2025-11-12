#include<bits/stdc++.h>

using namespace std;
int n,q;
struct Node{
	int s[700],fa,va;
}a[1000055];
string s1,s2,s3,s4;
int cnt=0;
int ss=0,ls=0;
void build(int f,int dp){
	int k=(s1[dp]-'a'+1)*27+(s2[dp]-'a'+1);
	if(a[f].s[k]==0){
		cnt++;
		a[f].s[k]=cnt;
		a[cnt].fa=f;
	}
	if(dp==s1.length()) a[a[f].s[k]].va++;
	build(a[f].s[k],dp+1);
}
int ans=0;
int fr=0;
int query(int f,int dp){
	int k=(s3[dp]-'a'+1)*27+(s4[dp]-'a'+1);
	if(a[f].s[k]!=0&&dp>=s3.length()-ls){
		ans+=a[a[f].s[k]].va;
	}
	query(a[f].s[k],dp+1);
}
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin.tie(0),ios_base::sync_with_stdio(false);
	cin>>n>>q;
	for(int i=1;i<=n;i++){
		cin>>s1>>s2;
		build(0,1);
	}
	for(int i=1;i<=q;i++){
		cin>>s3>>s4;
		ss=0,ls=0;
		for(int j=0;j<s3.length();j++){
			if(s3[j]==s4[j]) ss++;
			else break;
		}
		for(int j=s3.length();j>=0;j--){
			if(s3[j]==s4[j]) ls++;
			else break;
		}
		for(int j=0;j<ss;j++){
			query(1,j+1);
		}
	}
	cout<<ans<<"\n";
	return 0;
}

