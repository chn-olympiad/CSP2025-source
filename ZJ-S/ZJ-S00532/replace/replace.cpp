#include<bits/stdc++.h>
using namespace std;
typedef unsigned long long ull;
typedef long long ll;
string a[200005],b[200005];
string t1,t2;
ull H1[200005],H2[200005],T1[200005],T2[200005],pw[200005];
int n,q;
int P1[200005],P2[200005];
namespace SubTaskA{
	void Main(){
		int ans=0;
		for(int i=1;i<=n;i++){
			for(int j=0;j<a[i].size();j++){
				if(a[i][j]=='b'){
					P1[i]=j; break;
				}
			}
			for(int j=0;j<b[i].size();j++){
				if(b[i][j]=='b'){
					P2[i]=j; break;
				}
			}
		}
		char ch;
		while(q--){
			t1=t2="";
			ch=getchar();
			while(ch<'a'||ch>'z') ch=getchar();
			while(ch>='a'&&ch<='z'){
				t1+=ch; ch=getchar();
			}
			while(ch<'a'||ch>'z') ch=getchar();
			while(ch>='a'&&ch<='z'){
				t2+=ch; ch=getchar();
			}
			if(t1.size()!=t2.size()){
				puts("0");
				continue;
			}
			int p1=0,p2=0;
			for(int i=0;i<t1.size();i++){
				if(t1[i]=='b'){
					p1=i; break;
				}
			}
			for(int i=0;i<t2.size();i++){
				if(t2[i]=='b'){
					p2=i; break;
				}
			}
			for(int i=1;i<=n;i++){
				if(P2[i]-P1[i]!=p2-p1) continue;
				if(t1.size()-p1>=a[i].size()-P1[i]&&t2.size()-p2>=b[i].size()-P2[i]){
					if(p1>=P1[i]&&p2>=P2[i]) ans++;
				}
			}
		}
		printf("%d\n",ans);
	}
};
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	pw[0]=1;
	for(int i=1;i<=200000;i++) pw[i]=pw[i-1]*29;
	scanf("%d%d",&n,&q);
	char ch;
	bool SA=1;
	for(int i=1;i<=n;i++){
		int cnt=0;
		ch=getchar();
		while(ch<'a'||ch>'z') ch=getchar();
		while(ch>='a'&&ch<='z'){
			a[i]+=ch; ch=getchar();
			if(ch>'b') SA=0;
			if(ch=='b') cnt++;
		}
		for(int j=0;j<a[i].size();j++) H1[i]=H1[i]*29+(a[i][j]-'a'+1);
		while(ch<'a'||ch>'z') ch=getchar();
		while(ch>='a'&&ch<='z'){
			b[i]+=ch; ch=getchar();
			if(ch>'b') SA=0;
			if(ch=='b') cnt++;
		}
		for(int j=0;j<b[i].size();j++) H2[i]=H2[i]*29+(b[i][j]-'a'+1);
		if(cnt!=2) SA=0;
	}
	if(SA){
		SubTaskA::Main();
		return 0;
	}
	while(q--){
		t1=t2="";
		ch=getchar();
		while(ch<'a'||ch>'z') ch=getchar();
		while(ch>='a'&&ch<='z'){
			t1+=ch; ch=getchar();
		}
		while(ch<'a'||ch>'z') ch=getchar();
		while(ch>='a'&&ch<='z'){
			t2+=ch; ch=getchar();
		}
		if(t1.size()!=t2.size()){
			puts("0");
			continue;
		}
		T1[0]=t1[0]-'a'+1;
		for(int i=1;i<t1.size();i++) T1[i]=T1[i-1]*29+(t1[i]-'a'+1);
		T2[0]=t2[0]-'a'+1;
		for(int i=1;i<t2.size();i++) T2[i]=T2[i-1]*29+(t2[i]-'a'+1);
		ll ans=0;
		for(int i=0;i<t1.size();i++){
			for(int j=1;j<=n;j++){
				if(i-a[j].size()<0) continue;
				if(H1[j]==T1[i]-T1[i-a[j].size()]*pw[a[j].size()]&&H2[j]==T2[i]-T2[i-b[j].size()]*pw[b[j].size()]){
					if(T1[i-a[j].size()]==T2[i-b[j].size()]){
						if(T1[t1.size()-1]-T1[i]*pw[t1.size()-i-1]==T2[t2.size()-1]-T2[i]*pw[t2.size()-i-1]){
							ans++;
						}
					}
				}
			}
		}
		printf("%lld\n",ans);
	}
	return 0;
}