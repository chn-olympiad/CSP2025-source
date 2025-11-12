#include<bits/stdc++.h>
using namespace std;
const int N=1e5;
struct node{
	int a,b,c;
	int ab,ac,bc;
	int a1,b1,c1;
	string cl;
}s[N],a[N],b[N],c[N];
bool cmpa(node a,node b){
	return a.a1<b.a1;
}
bool cmpb(node a,node b){
	return a.b1<b.b1;
}
bool cmpc(node a,node b){
	return a.c1<b.c1;
}
int main(){
	freopen("club4.in","r",stdin);
	freopen("club.out","w",stdout);
	int t;
	cin>>t;
	while(t--){
		int n;
		cin>>n;
		for(int i=1;i<=n;i++){
			cin>>s[i].a>>s[i].b>>s[i].c;
			if(s[i].a>=s[i].b&&s[i].b>=s[i].c)s[i].cl="ab";
			else if(s[i].a>=s[i].c&&s[i].c>=s[i].b)s[i].cl="ac";
			else if(s[i].b>=s[i].a&&s[i].a>=s[i].c)s[i].cl="ba";
			else if(s[i].b>=s[i].c&&s[i].c>=s[i].a)s[i].cl="bc";
			else if(s[i].c>=s[i].a&&s[i].a>=s[i].b)s[i].cl="ca";
			else if(s[i].c>=s[i].b&&s[i].b>=s[i].a)s[i].cl="cb";
			s[i].ab=abs(s[i].a-s[i].b);
			s[i].bc=abs(s[i].b-s[i].c);
			s[i].ac=abs(s[i].a-s[i].c);
			s[i].a1=min(s[i].ab,s[i].ac);
			s[i].b1=min(s[i].ab,s[i].bc);
			s[i].c1=min(s[i].ac,a[i].bc);
		}
		int la=0,lb=0,lc=0;
		for(int i=1;i<=n;i++){
			if(s[i].cl[0]=='a'){
				la++;
				a[la]=s[i];
			}
			if(s[i].cl[0]=='b'){
				lb++;
				b[lb]=s[i];
			}
			if(s[i].cl[0]=='c'){
				lc++;
				c[lc]=s[i];
			}
		}
		sort(a+1,a+la+1,cmpa);
		if(la>n/2){
			for(int i=1;i<=la-n/2;i++){
				if(a[i].ab<a[i].ac)b[++lb]=a[i];
				else c[++lc]=a[i];
				a[i]={0,0,0,0,0,0,0,0,0,""};
			}
		}
		sort(b+1,b+lb+1,cmpb);
		if(lb>n/2){
			for(int i=1;i<=lb-n/2;i++){
				if(b[i].ab<b[i].bc)a[++la]=b[i];
				else c[++lc]=b[i];
				b[i]={0,0,0,0,0,0,0,0,0,""};
			}
		}
		sort(c+1,c+lc+1,cmpc);
		if(lc>n/2){
			for(int i=1;i<=lc-n/2;i++){
				if(c[i].bc<c[i].ac)b[++lb]=c[i];
				else a[++la]=c[i];
				c[i]={0,0,0,0,0,0,0,0,0,""};
			}
		}
		int ans=0;
		for(int i=1;i<=la;i++)ans+=a[i].a;
		for(int i=1;i<=lb;i++)ans+=b[i].b;
		for(int i=1;i<=lc;i++)ans+=c[i].c;
		cout<<ans<<"\n";
	}
	return 0;
}