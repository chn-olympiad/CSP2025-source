#include<bits/stdc++.h>
#define ull unsigned long long
using namespace std;
const int N = 1e3 + 10,jin = 131;
map<ull,int>p;
vector<ull>ys[N];
int n,m,cnt,ans;
ull q1[N],q2[N],power[N];
string t[N],s1,s2;
void ying(){
	ull z=0,z2=0;
	for(int i=0;i<s1.size();i++)
		z=z*jin+s1[i]-'a'+1;
	for(int i=0;i<s2.size();i++)
		z2=z2*jin+s2[i]-'a'+1;
	if(p[z]==0)p[z]=++cnt;
	ys[p[z]].push_back(z2);
}
void pre(){
	q1[0]=s1[0]-'a'+1;q2[0]=s2[0]-'a'+1;
	for(int i=1;i<s1.size();i++)
		q1[i]=q1[i-1]*jin+s1[i]-'a'+1;
	for(int i=1;i<s2.size();i++)
		q2[i]=q2[i-1]*jin+s2[i]-'a'+1;
}
ull get1(int l,int r){
	if(l==0)return q1[r];
	return q1[r]-power[l-1]*q1[l-1];
}
ull get2(int l,int r){
	if(l==0)return q2[r];
	return q2[r]-power[l-1]*q2[l-1];
}
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout); 
	power[0]=1;
	for(int i=1;i<N;i++)
		power[i]=power[i-1]*jin;
	scanf("%d%d",&n,&m);
	for(int i=0;i<n;i++){
		cin>>s1>>s2;
		ying(); 
	}
	for(int i=0;i<m;i++){
		ans=0;
		cin>>s1>>s2;
		if(s1.size()!=s2.size()){ printf("0\n");continue;}
		pre();
		int len=s1.size();
		for(int j=0;j<len;j++){
			for(int k=j;k<len;k++){
				if((!j||get1(0,j-1)==get2(0,j-1))&&((k==len-1)||get1(k+1,len-1)==get2(k+1,len-1))){
					int now=p[get1(j,k)];
					if(now==0)continue;
					ull pp=get2(j,k);
					for(int c=0;c<ys[now].size();c++){
						if(ys[now][c]==pp)ans++;
					}
				}
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

4 2
xabcx xadex
ab cd
bc de
aa bb
xabcx xadex
aaaa bbbb
*/
