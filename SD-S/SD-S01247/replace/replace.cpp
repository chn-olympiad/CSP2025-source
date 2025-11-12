#include<bits/stdc++.h>
#define re register
#define ll long long
#define ull unsigned long long
using namespace std;
const int N=2e5+5;
inline int rd(){
	int x=0,f=1;
	char ch=getchar();
	while(ch<'0'||ch>'9'){
		if(ch=='-')f=-1;
		ch=getchar();
	}
	while(ch>='0'&&ch<='9'){
		x=(x<<3)+(x<<1)+(ch^48);
		ch=getchar();
	}
	return x*f;
}
ull s[N][3];
int n,q;
int tot1,tot2;
map<ull,int>mp1,mp2;
set<int>st1[N],st2[N];
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	n=rd(),q=rd();
	for(re int i=1;i<=n;i++){
		string s1,s2;
		cin>>s1,cin>>s2;
		ull x=0,y=0;
		for(re int j=0;j<s1.size();j++){
			x=x*131+s1[j]-'a'+1;
			y=y*131+s2[j]-'a'+1;
		}
		//printf("i:%d x:%lld y:%lld\n",i,x,y);
		s[i][1]=x,s[i][2]=y;
		if(!mp1[x])mp1[x]=++tot1;
		if(!mp2[y])mp2[y]=++tot2;
		st1[mp1[x]].insert(i);
		st2[mp2[y]].insert(i);
	}
	while(q--){
		int ans=0;
		string s1,s2;
		cin>>s1,cin>>s2;
		int l=1,r=s1.size();
		while(s1[l-1]==s2[l-1])l++;
		while(s1[r-1]==s2[r-1])r--;
		for(re int i=1;i<=l;i++){
			ull x=0,y=0;
			for(re int j=i;j<=s1.size();j++){
				x=x*131+s1[j-1]-'a'+1;
				y=y*131+s2[j-1]-'a'+1;
				//printf("l:%d r:%d x:%lld y:%lld\n",i,j,x,y);
				if(!mp1[x]||!mp2[y]||j<r)continue;
				for(auto it:st1[mp1[x]])if(st2[mp2[y]].count(it))ans++;
			}
		}
		printf("%d\n",ans);
	}
	return 0;
}
/*
3 4
a b
b c
c d
aa bb
aa b
a c
b a

*/

