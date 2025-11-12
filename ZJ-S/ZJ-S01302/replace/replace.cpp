#include<bits/stdc++.h>
using namespace std;
const int N=1e7+15,P=5e6+5;
char s1[N],s2[N],in[N],t1[N],t2[N];
int idx[N],len=1,p[N],nxt,st[N],slen[N];
vector<pair<int,int> > KMP(char *s,int l,int r){
	nxt=0;
	vector<pair<int,int> > v;
	v.clear();
	for (int i=1;i<len;i++){
		p[i]=0;
	}
	for (int i=2;i<len;i++){
		while (nxt!=0 && s[nxt+1]!=s[i]){
			nxt=p[nxt];
		}
		if (s[nxt+1]==s[i]){
			p[i]=nxt+1;
			nxt=p[i];
		}
		if (p[i]==r-l+1){
			v.push_back(make_pair(st[idx[i]],i-st[idx[i]]-(r-l)));
		}
	}
	return v;
}
int check(pair<int,int> pos,int l,int r){
	if (pos.second>l){
		return 0;
	}
	int fir=pos.first,sec=pos.second;
	for (int i=fir;idx[i]==idx[fir];i++){
		if (s1[i]!=t1[i-fir+l-sec] || s2[i]!=t2[i-fir+l-sec]){
			return 0;
		}
	}
	return 1;
}
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	int n,q;
	scanf("%d%d",&n,&q);
	len=P;
	for (int i=1;i<=n;i++){
		scanf("%s",in);
		for (int j=0;in[j]!='\0';j++){
			s1[len+j]=in[j];
			idx[len+j]=i;
		}
		scanf("%s",in);
		for (int j=0;in[j]!='\0';j++){
			s2[len+j]=in[j];
		}
		st[i]=len;
		slen[i]=strlen(in);
		len+=strlen(in);
	}
	for (int _=1;_<=q;_++){
		scanf("%s%s",t1,t2);
//		if (_<=299){
//			continue;
//		}
//		if (_>=310){
//			return 0;
//		}
		for (int i=1;i<P;i++){
			s1[i]=s2[i]='&';
		}
		int lent=strlen(t1),l,r;
		for (int i=0;t1[i]!='\0';i++){
			if (t1[i]!=t2[i]){
				l=i;
				break;
			}
		}
		for (int i=lent-1;i>=0;i--){
			if (t1[i]!=t2[i]){
				r=i;
				break;
			}
		}
		for (int i=1;i<=r-l+1;i++){
			s1[i]=t1[i+l-1];
			s2[i]=t2[i+l-1];
		}
//		for (int i=1;i<len;i++){
//			cout<<s1[i];
//		}
//		cout<<'\n';
		vector<pair<int,int> > v1=KMP(s1,l,r);
		vector<pair<int,int> > v2=KMP(s2,l,r);
//		for (auto i:v1){
//			cout<<i.first<<' '<<i.second<<'\n';
//		}
		vector<pair<int,int> > f;
		f.clear();
		int j=0;
		//cout<<l<<' '<<r<<'\n';
		for (int i=0;i<v1.size();i++){
			while (j<v2.size() && v2[j]<v1[i]){
				j++;
			}
			if (j>=v2.size()){
				break;
			}
			if (v1[i]==v2[j]){
				f.push_back(v1[i]);
			}
		}
		int ans=0;
		for (auto i:f){
			ans+=check(i,l,r);
		}
		cout<<ans<<'\n';
	}
	return 0;
}
