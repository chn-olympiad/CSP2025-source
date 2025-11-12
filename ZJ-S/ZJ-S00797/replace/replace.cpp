#include<bits/stdc++.h>
using namespace std;
const int N=5000005;
int n,q,l;
int stt,end;
int len,ans;
string s1[N],s2[N];
string q1,q2;
string getand(string l1,string l2){
	int len1=l1.size(),len2=l2.size(),tot=0;
	string res,tres;
	for(int i=0;i<len1;i++){
		if(l1[i]==l2[0]){
			tot=i;
			while(l1[i]==l2[i-tot]&&i<len1&&i-tot<len2){
				tres+=l1[i];
				i++;
			}
			if(res.size()<tres.size())res=tres;
			i=tot;
			tres="";
		}
	}
	return res;
}
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	cin>>n>>q;
	for(int i=1;i<=n;i++){
		cin>>s1[i]>>s2[i];
	}
	while(q){
		q--;
		cin>>q1>>q2;
		stt=0,end=0,ans=0;
		if(q1.size()!=q2.size()){
			cout<<0<<'\n';
			continue;
		}l=q1.size();
		for(int i=1;i<=l;i++){if(q1[i-1]!=q2[i-1]&&stt==0){stt=i-1;break;}}
		for(int i=l-1;i>=0;i--){if(q1[i]!=q2[i]&&end==0){end=i;break;}}
		len=end-stt+1;
		for(int i=1;i<=n;i++){
			if(getand(q1,s1[i])==getand(q2,s2[i])&&getand(q1,s1[i]).size()>=len)ans++;
		}
		cout<<ans<<'\n';
	}
	return 0;
}
/*
4 1
xabcx xadex
ab bc
bc de
aa bb
aaaa bbbb

3 4
a b
b c
c d
aa bb
aa b
a c
b a
*/
