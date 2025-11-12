#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cmath>
#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>
#define Max(a,b) (((a)>(b))?(a):(b))
#define Min(a,b) (((a)<(b))?(a):(b))
#define L(i,j,k) for(int i=(j);(i)<=(k);i++)
#define R(i,j,k) for(int i=(j);(i)>=(k);i--)
#define a fhhhhhhhhhhhhhhhhdnvoiopqwpppppp
#define n hfuaisihuiuhuihuinnnnnnnnnnn
#define q poqwertyuasdjhkghjk
#define na ofjijoojoiiijjiijijjiwiiiojqjijoeqnsklafvczvvvv
#define nb afsoijjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjpo
#define naa iijjiijijjqqqqqdfg
#define mb joijjoijzxzxzxxxxxxxxxx
#define n2a xxxxxxxxxxxffffffgfgfgfg
#define n2aa bdafbuisiuwhuihuiiuhplopeqwelqwoiejsdg
#define n2b xzzzzzzzzzuhtrqwyueyqwiryfashjvxczcccccc
#define qa dwfggggggggryryeyyyyyyy
#define qb fesioioorueiooooooooohoooho
#define qaa donkkokfkdakfokdkoewnfdkkdowsdokndokn
#define qmb asasasasjijijdaiajij
#define q2a oioioioioioioioiweoriwodupsfusd
#define q2b uuuuuuuuuuuuiiiiuuuihiunijfsvunv
#define mybol jiwdjjjjjjjjjjjabcsabufcbasuybeihghsdigfuuuuuuuuuuu
#define bolll ggggggggggmmmmmmmmmmmmmdjshfhui
#define ans qwertyuijuiganvuwpejddddddddjjjjjjjjjjjjjjmmmmmmmm
using namespace std;
const int MAXN=1e5+10;
char a;
int n,q;
int na[MAXN],nb[MAXN],naa[MAXN],mb[MAXN];
int n2a[MAXN],n2b[MAXN];
int qa,qb,qaa,qmb;
int q2a,q2b;
bool mybol=false;
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	scanf("%d%d",&n,&q);
	L(i,1,n){
		scanf("%c",&a);
		while(int(a)<=int('z')&&int(a)>=int('a')){
			bool bolll=true;
			if(a!='a'&&a!='b')mybol=true;
			else{
				if(a=='a'&&bolll){
					na[i]++;
				}
				if(a=='b'){
					nb[i]=na[i]+1;
					bolll=false;
				}
				if(a=='b'&&(!bolll)){
					mybol=true;
				}
				if(a=='a'&&(!bolll)){
					naa[i]++;
				}
			}
			scanf("%c",&a);
		}
		scanf("%c",&a);
		while(int(a)<=int('z')&&int(a)>=int('a')){
			bool bolll=true;
			if(a!='a'&&a!='b')mybol=true;
			else{
				if(a=='a'&&bolll){
					n2a[i]++;
				}
				if(a=='b'){
					n2b[i]=n2a[i]+1;
					bolll=false;
				}
				if(a=='b'&&(!bolll)){
					mybol=true;
				}
			}
			scanf("%c",&a);
		}
		mb[i]=nb[i]-n2b[i];
	}
	L(i,1,q){
		scanf("%c",&a);
		while(int(a)<=int('z')&&int(a)>=int('a')){
			bool bolll=true;
			if(a!='a'&&a!='b')mybol=true;
			else{
				if(a=='a'&&bolll){
					qa++;
				}
				if(a=='b'){
					qb=qa+1;
					bolll=false;
				}
				if(a=='a'&&(!bolll)){
					qaa++;
				}
				if(a=='b'&&(!bolll)){
					mybol=true;
				}
			}
			scanf("%c",&a);
		}
		scanf("%c",&a);
		while(int(a)<=int('z')&&int(a)>=int('a')){
			bool bolll=true;
			if(a!='a'&&a!='b')mybol=true;
			else{
				if(a=='a'&&bolll){
					q2a++;
				}
				if(a=='b'){
					q2b=q2a+1;
					bolll=false;
				}
				if(a=='b'&&(!bolll)){
					mybol=true;
				}
			}
			scanf("%c",&a);
		}
		if(mybol){
			printf("0\n");
			continue;
		}
		int ans=0;
		qmb=qb-q2b;
		L(i,1,n){
			if(qmb==mb[i]){
				if(qa>=na[i]&&qaa>=naa[i]){
					ans++;
				}
			}
		}
		printf("%d\n",ans);
	}
	fclose(stdin);
	fclose(stdout);
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