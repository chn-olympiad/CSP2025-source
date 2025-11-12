#include<bits/stdc++.h>
#define ll long long
#define inf64 (ll)0x3f3f3f3f3f3f3f3f
#define inf32 (int)0x3f3f3f3f
#define _inf32 (int)0xc0c0c0c0
#define _inf64 (ll)0xc0c0c0c0c0c0c0c0
#define N 200010
#define LEN 5000100
inline int in(){
	int sum=0,op=0,c=getchar();
	while(c<48||57<c)op=(c=='-'?0:1),c=getchar();
	while(48<=c&&c<=57)sum=(sum<<3)+(sum<<1)+c-48,c=getchar();
	return op?(~sum)+1:sum;
}
using namespace std;
int n,q,ans;
int l,r;
int ls[N],lt;
vector<int> nex1[N],nex2[N];
string s1[N],s2[N],t1,t2;
unordered_set<int> st;
int main(){
//	freopen("replace3.in","r",stdin);
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	n=in(),q=in();
	for(int i=1;i<=n;i++){
		cin>>s1[i]>>s2[i];
		ls[i]=s1[i].size();
		nex1[i].push_back(0);
		for(int j=1;j<ls[i];j++){
			int NEX=nex1[i][j-1];
			while(NEX && s1[i][NEX]!=s1[i][j]){
				NEX=nex1[i][NEX-1];
			}
			if(s1[i][NEX]==s1[i][j]){
				nex1[i].push_back(NEX+1);
			}else{
				nex1[i].push_back(0);
			}
		}
		nex2[i].push_back(0);
		for(int j=1;j<ls[i];j++){
			int NEX=nex2[i][j-1];
			while(NEX && s2[i][NEX]!=s2[i][j]){
				NEX=nex2[i][NEX-1];
			}
			if(s2[i][NEX]==s2[i][j]){
				nex2[i].push_back(NEX+1);
			}else{
				nex2[i].push_back(0);
			}
		}
	}
	for(int it=1;it<=q;it++){
//		cerr<<it<<endl;
		ans=0;
		l=inf32;
		cin>>t1>>t2;
		if(t1.size()!=t2.size()){
			printf("0\n");
			continue;
		}
		lt=t1.size();
		for(int i=0;i<lt;i++){
			if(t1[i]!=t2[i]){
				if(l==inf32)l=i;
				r=i;
			}
		}
		for(int is=1;is<=n;is++){
			st.clear();
			for(int i1=0,j1=0;i1<lt;){
				while(j1 && s1[is][j1]!=t1[i1]){
					j1=nex1[is][j1-1];
				}
				i1++;
				if(s1[is][j1]==t1[i1-1]){
					j1++;
				}
				if(j1==ls[is]){
					j1=nex1[is][j1-1];
					st.insert(i1-1);
				}
			}
			for(int i2=0,j2=0;i2<lt;){
				while(j2 && s2[is][j2]!=t2[i2]){
					j2=nex2[is][j2-1];
				}
				i2++;
				if(s2[is][j2]==t2[i2-1]){
					j2++;
				}
				if(j2==ls[is]){
					j2=nex2[is][j2-1];
					if(st.count(i2-1)){
						if(i2-ls[is]<=l && r<=i2-1){
							ans++;
						}
					}
				}
			}
		}
		printf("%d\n",ans);
	}
//	freopen("chk.out","w",stdout);
//	system("fc replace.out replace4.ans");
}
/*
1 1
aba aba
ababacaba ababacaba
O(q*L1+n*L2)
*/