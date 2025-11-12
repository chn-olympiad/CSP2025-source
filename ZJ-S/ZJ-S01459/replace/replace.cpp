#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
inline int read(){//mention int/long long!!!
	int s=0,w=1;
	char ch=getchar();
	while(ch<'0'||ch>'9'){
		if(ch=='-')w=-1;
		ch=getchar();
	}
	while(ch>='0'&&ch<='9')s=s*10+ch-'0',ch=getchar();
	return s*w;
}
void Designant(){//freopen!!!
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
}
const int MAX=2e5+11;
int n,q;
char f[MAX];
string s1[MAX],s2[MAX],t1[MAX],t2[MAX];
int h1[MAX],h2[MAX];
bool flagA=1;
void get_in(int i){
	scanf("%s",f);
	int g=strlen(f);
	for(int j=0,num=0;j<g;j++){
		s1[i].push_back(f[j]);
		if(f[j]!='a'&&f[j]!='b')flagA=0;
		if(f[j]=='b')num++;
		if(num>1)flagA=0;
	}
	scanf("%s",f);
	for(int j=0,num=0;j<g;j++){
		s2[i].push_back(f[j]);
		if(f[j]!='a'&&f[j]!='b')flagA=0;
		if(f[j]=='b')num++;
		if(num>1)flagA=0;
	}
}
void get_in2(int i){
	scanf("%s",f);
	int g=strlen(f);
	for(int j=0,num=0;j<g;j++){
		t1[i].push_back(f[j]);
		if(f[j]!='a'&&f[j]!='b')flagA=0;
		if(f[j]=='b')num++;
		if(num>1)flagA=0;
	}
	scanf("%s",f);
	g=strlen(f);
	for(int j=0,num=0;j<g;j++){
		t2[i].push_back(f[j]);
		if(f[j]!='a'&&f[j]!='b')flagA=0;
		if(f[j]=='b')num++;
		if(num>1)flagA=0;
	}
}
string b1,b2;
int nxt[MAX*50];
bool avai[MAX][3];
void make_kmp(string s,int op,int len1){
//	cout<<"s="<<s<<endl;
	nxt[0]=0;
	int l=s.length();
	for(int i=1;i<l;i++){
//		printf("i=%d\n",i);
		int j=nxt[i-1];
		while(j>0&&s[j]!=s[i])j=nxt[j-1];
		if(s[j]==s[i])j++;
		nxt[i]=j;
//		printf("%d ",j);
	}
//	puts("");
	for(int i=len1*2;i<l;i++){
		if(nxt[i]==len1){
			avai[i-2*len1][op]=1;
//			printf("d=%d\n",i-2*len1);
		}
	}
}
int main(){
	Designant();
	n=read(),q=read();
	for(int i=1;i<=n;i++){
		get_in(i);
	}
	for(int i=1;i<=q;i++){
		get_in2(i);
	}
	if(flagA&&n>110){
		for(int i=1;i<=n;i++){
			for(int j=0;j<(int)s1[i].length();j++){
				if(s1[i][j]=='b')h1[i]=j;
			}
			for(int j=0;j<(int)s1[i].length();j++){
				if(s2[i][j]=='b')h2[i]=j;
			}
		}
		for(int p=1;p<=q;p++){
			ll ans=0;
			b1=t1[p],b2=t2[p];
			if(b1.length()!=b2.length()){
				puts("0");
				continue;
			}
			int aa=0,bb=0,tk=b1.length();
			for(int j=0;j<tk;j++){
				if(t1[p][j]=='b')aa=j;
			}
			for(int j=0;j<tk;j++){
				if(t2[p][j]=='b')bb=j;
			}
			for(int i=1;i<=n;i++){
				if(aa-bb==h1[i]-h2[i]){
					if(aa>=h1[i]&&tk-aa>=(int)s1[i].length()-h1[i])ans++;
				}
			}
			printf("%lld\n",ans);
		}
		fclose(stdin);
		fclose(stdout);
		return 0;
	}
	for(int p=1;p<=q;p++){
//		printf("p=%d\n",p);
		b1=t1[p],b2=t2[p];
		if(b1.length()!=b2.length()){
			puts("0");
			continue;
		}
		int l=0,r=0;
		for(int i=0;i<(int)b1.length();i++){
			if(b1[i]!=b2[i]){
				l=i;
				break;
			}
		}
		for(int i=b1.length()-1;i<(int)b1.length();i--){
			if(b1[i]!=b2[i]){
				r=i;
				break;
			}
		}
		int ans=0;
		for(int i=1;i<=n;i++){
//			printf("i=%d\n",i);
			int g=s1[i].length();
			make_kmp(s1[i]+"$"+b1,1,g);
			make_kmp(s2[i]+"$"+b2,2,g);
			for(int j=0;j<(int)b1.length();j++){
				if(avai[j][1]&&avai[j][2]&&j<=l&&j+g>r)ans++;
				avai[j][1]=avai[j][2]=0;
			}
		}
		printf("%d\n",ans);
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
