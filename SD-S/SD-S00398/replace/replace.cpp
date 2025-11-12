#include<bits/stdc++.h>
using namespace std;
//#define int long long
#define fi first
#define se second
#define pii pair<int,int>
#define pb push_back
const int N=2e5+5,mod=1e9+7;
int read(){
	int w=1,x=0;
	char ch=getchar();
	while(ch>'9'||ch<'0') {
		if(ch=='-')w=-1;
		ch=getchar();
	}
	while(ch>='0'&&ch<='9'){
		x=x*10+ch-'0';
		ch=getchar();
	}
	return x*w;
}
int n,q,vb1[N],vb2[N],vb3,vb4;
vector<char>s1[N],s2[N];
signed main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	n=read();
	q=read();
	string s;
	int f=1;
	for(int i=1;i<=n;i++){
		s1[i].pb(' '),s2[i].pb(' ');
		cin>>s;
		int m=s.size();
		s=' '+s;
		for(int j=1;j<=m;j++){
			s1[i].pb(s[j]);
			if((s[j]!='a'&&s[j]!='b')||(vb1[i]!=0&&s[j]=='b'))f=0;
			if(s[j]=='b')vb1[i]=j;	
		}
		cin>>s;
		s=' '+s;
		for(int j=1;j<=m;j++){
			s2[i].pb(s[j]);
			if((s[j]!='a'&&s[j]!='b')||(vb2[i]!=0&&s[j]=='b'))f=0;
			if(s[j]=='b')vb2[i]=j;
		}
	}
	if(f==1){
		string t1,t2;
		int ans;
		for(int i=1;i<=q;i++){
			ans=0;
			cin>>t1>>t2;
			vb3=vb4=0;
			int m=t1.size();
			t1=' '+t1;
			t2=' '+t2;
			
			for(int j=1;j<=m;j++){
				if(t1[j]=='b')vb3=j;
				if(t2[j]=='b')vb4=j;
				if(vb3&&vb4)break;
			}
			for(int k=1;k<=n;k++){
			int l1=s1[k].size()-1;
				if(vb1[k]-vb2[k]==vb3-vb4&&m>l1){
					if(vb3>vb4){
						if(vb4>=vb2[k]&&m-vb3>=l1-vb1[k])ans++;
					}
					if(vb3<vb4){
						if(vb3>=vb1[k]&&m-vb4>=l1-vb2[k])ans++;
					}
				}
			}
			cout<<ans<<endl;
	
		}
	}
	else {
		string t1,t2;
		int ans;
		for(int i=1;i<=q;i++){
			ans=0;
			cin>>t1>>t2;
			int m=t1.size();
			t1=' '+t1;
			t2=' '+t2;
			int st=1e9,ed=0;
			for(int j=1;j<=m;j++){
				if(t1[j]!=t2[j]){
					st=min(st,j);
					ed=max(ed,j);
				}
			}
			for(int k=1;k<=n;k++){
				int l1=s1[k].size()-1,l2=ed-st+1;
				if(l1<l2)continue;
				int st1=1e9,ed1=0;
				for(int e=1;e<=l1;e++){
					if(s1[k][e]!=s2[k][e]){
						st1=min(st1,e);
						ed1=max(ed1,e);
					}
				}
				//cout<<st1<<" "<<ed1<<endl;
				if(ed1-st1==ed-st&&m>=l1){
					int ff=0;
					if(st>=st1&&m-ed>=l1-ed1){
					ff=1;
						//cout<<k<<"   dqwd"<<endl;
						for(int e=1;e<=l1;e++){
							if(t1[st-st1+e]!=s1[k][e]||t2[st-st1+e]!=s2[k][e]){
								//cout<<e<<" "<<t1[st+e]<<s1[k][st1+e]<<t2[st+e]<<s2[k][st1+e]<<endl;
								ff=0;
								break;
							}
						}
					}
					if(ff==1){
						ans++;
						//cout<<k<<endl;
					}
				}
			}
			cout<<ans<<endl;
	
		}
	}
	
	return 0;
}


