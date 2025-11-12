#include<bits/stdc++.h>
using namespace std;
#define N 200100
#define L 20100
//KMP!!!
void get_p(string &s,vector<int> &p){
	p.reserve((int)s.size()+1);
	p[0]=0;
	int j=0;
	for(int i=2;i<(int)s.size();++i){
		while(j&&s[i]!=s[j+1]) j=p[j];
		if(s[i]==s[j+1])p[i]=++j;
		else p[i]=j;
	}
	return ;
}
void pipei(string &s1,string &t1,vector<int> &p1,string &s2,string &t2,vector<int> &p2,int *arr,int arrcnt,int &ans){
	int j=0;
	int pos1[N],poscnt1=0;
	for(int i=1;i<(int)s1.size();++i){
		if(j==(int)t1.size()-1)pos1[++poscnt1]=i-1,j=p1[j];
		while(j&&s1[i]!=t1[j+1]) j=p1[j];
		if(s1[i]==t1[j+1]) ++j;
	}
	if(j==(int)t1.size()-1)pos1[++poscnt1]=s1.size()-1;
	j=0;
	int pos2[N],poscnt2=0;
	for(int i=1;i<(int)s2.size();++i){
		if(j==(int)t2.size()-1)pos2[++poscnt2]=i-1,j=p2[j];
		while(j&&s2[i]!=t2[j+1]) j=p2[j];
		if(s2[i]==t2[j+1]) ++j;
	}
	if(j==(int)t2.size()-1)pos2[++poscnt2]=s2.size()-1;
	int cur1=1,cur2=1;
	while(cur1<=poscnt1&&cur2<=poscnt2){
		while(cur1<=poscnt1&&pos1[cur1]<pos2[cur2]) ++cur1;
		if(cur1>poscnt1) return ;
		while(cur2<=poscnt2&&pos2[cur2]<pos1[cur1]) ++cur2;
		if(cur2>poscnt2) return ;
		if(cur1==cur2){
			if(arr[arrcnt]<=pos1[cur1]){
				ans+=1;
//				cout<<t1<<" "<<t2<<'\n';
				return ;
			}
		}
	}
	return ;
}
int n,q;
vector<int> p[N][2];
string s[N][2];
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	cin>>n>>q;
	for(int i=1;i<=n;++i){
		cin>>s[i][0]>>s[i][1];
		s[i][0]=' '+s[i][0];
		s[i][1]=' '+s[i][1];
		get_p(s[i][0],p[i][0]);
		get_p(s[i][1],p[i][1]);
	}
	while(q--){
		string s1,s2;
		int dif[N],difcnt=0,ans=0;
		cin>>s1>>s2;
		if(s1.size()!=s2.size()){
			cout<<"0\n";
			continue;
		}
		s1=' '+s1,s2=' '+s2;
		for(int i=1;i<(int)s1.size();++i){
			if(s1[i]!=s2[i]) dif[++difcnt]=i; 
		}
//		cout<<difcnt<<'\n';
		for(int i=1;i<=n;++i){
			if(difcnt>(int)s[i][0].size()-1) continue;
			pipei(s1,s[i][0],p[i][0],s2,s[i][1],p[i][1],dif,difcnt,ans);
		}
		cout<<ans<<'\n';
	}
//	string s;
//	int p[N];
//	cin>>s;
//	s=' '+s;
//	p[0]=0;
//	int j=0;
//	for(int i=2;i<s.size();++i){
//		while(j&&s[i]!=s[j+1]) j=p[j];
//		if(s[i]==s[j+1])p[i]=++j;
//		else p[i]=j;
//	}
//	for(int i=1;i<s.size();++i){
//		printf("%d ",p[i]);
//	}
	return 0;
}
