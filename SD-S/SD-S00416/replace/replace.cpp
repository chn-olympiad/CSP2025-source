#include<bits/stdc++.h>
using namespace std;
const int N=1e6+5;

#define ll long long
#define FOR(i,a,b) for(int i=a;i<=b;i++)
#define RFOR(i,a,b) for(int i=a;i>=b;i--)
#define FORG(i,u) for(int i=head[u];~i;i=nxt[i])

string s1[N],s2[N];
int len[N];
int kmp[N];
bool flag1[N],flag2[N];
void kmp1(int i,string diff){
	string now1=s1[i],now2=diff;
	int len1=len[i],len2=now2.size();
	int j=0;
	now2=' '+now2;
	FOR(i,1,len2){
		while(j&&now2[j+1]!=now2[i])j=kmp[j-1];
		if(now2[j+1]==now2[i])j++;
		kmp[i]=j;
	}
	j=0;
	FOR(i,1,len1){
		while(j&&now2[j+1]!=now1[i])j=kmp[j-1];
		if(now2[j+1]==now1[i])j++;
		if(j==len2)flag1[i]=1;
	}
}
void kmp2(int i,string diff){
	string now1=s2[i],now2=diff;
	int len1=len[i],len2=now2.size();
	int j=0;
	now2=' '+now2;
	FOR(i,1,len2){
		while(j&&now2[j+1]!=now2[i])j=kmp[j-1];
		if(now2[j+1]==now2[i])j++;
		kmp[i]=j;
	}
	j=0;
	FOR(i,1,len1){
		while(j&&now2[j+1]!=now1[i])j=kmp[j-1];
		if(now2[j+1]==now1[i])j++;
		if(j==len2)flag2[i]=1;
	}
}
int n,q;
void solve(){
	while(q--){
		int ans=0;
		string t1,t2;
		cin>>t1>>t2;
		int tlen=t1.size();
		t1=' '+t1,t2=' '+t2;
		int l=INT_MAX,r=0;
		for(int i=1;i<=tlen;i++){
			if(t1[i]!=t2[i])l=min(l,i),r=max(r,i);
		}
		string diff1="",diff2="";
		FOR(i,l,r)diff1+=t1[i],diff2+=t2[i];
		FOR(i,1,n){
			if(len[i]<r-l+1)continue;
			kmp1(i,diff1);
			kmp2(i,diff2);
			FOR(j,1,len[i]){
				if(flag1[j]&&flag2[j])ans++;
				flag1[j]=flag2[j]=0;
			}
		}
		cout<<ans<<"\n";
	}
}
int main(){
//	freopen("road.in","r",stdin);
//	freopen("road.out","w",stdout);
	ios::sync_with_stdio(false);
	cin>>n>>q;
	bool flagB=1;
	FOR(i,1,n){
		cin>>s1[i]>>s2[i];
		len[i]=s1[i].size();
		s1[i]=' '+s1[i];
		s2[i]=' '+s2[i];
	}
	solve();
	
	return 0;
} 
