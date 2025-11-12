#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
const int N=5e6+10,M=2e5+10;
const long long seca=26,secb=26,moda=998244353,modb=998244353;
char inpa[N],inpb[N];
long long suma[M],sumb[M];
long long powa[M],powb[M];
long long hasha(int l,int r){
	if(l>r) return 0;
	return (suma[r]-(suma[l-1]*powa[r-l+1]%moda)+moda)%moda;
}
long long hashb(int l,int r){
	if(l>r) return 0;
	return (sumb[r]-(sumb[l-1]*powb[r-l+1]%modb)+modb)%modb;
}
struct node{
	int a,b,s;
}hashs[N];
/*bool cmp(node x,node y){
	if(x.a==y.a) return x.b<y.b;
	return x.a<y.a;
}*/
void init(){
	powa[0]=1;powb[0]=1;
	for(int i=1;i<=M;i++){
		powa[i]=powa[i-1]*seca%moda;
		powb[i]=powb[i-1]*secb%modb;
	}
}
int n,q;
int main(){
	freopen(".in","r",stdin);
	freopen(".out","w",stdout);
	scanf("%d%d",&n,&q);
	init();
	for(int i=1;i<=n;i++){
		scanf("%s%s",inpa,inpb);
		int len=strlen(inpa);
		hashs[i].s=len;
		for(int j=0;j<len;j++){
			hashs[i].a=(hashs[i].a*seca%moda)+(inpa[j]-'a'+1);hashs[i].a%=moda;
			hashs[i].b=(hashs[i].b*secb%modb)+(inpb[j]-'a'+1);hashs[i].b%=modb;
		}
	}
	//sort(hashs+1,hashs+n+1,cmp);
	for(int t=1;t<=q;t++){
		scanf("%s%s",inpa,inpb);
		int len=strlen(inpa),ans=0;
		suma[0]=(inpa[0]-'a'+1);
		sumb[0]=(inpb[0]-'a'+1);
		for(int i=1;i<len;i++){
			suma[i]=(suma[i-1]*seca%moda)+(inpa[i]-'a'+1);suma[i]%=moda;
			sumb[i]=(sumb[i-1]*secb%modb)+(inpb[i]-'a'+1);sumb[i]%=modb;
		}
		for(int i=0;i<len;i++){
			for(int j=1;j<=n;j++){
				if(hasha(i,i+hashs[j].s-1)==hashs[j].a&&
				   hashb(0,len-1)==(((hashb(0,i-1)*powa[len-i]%moda)+(hashs[j].b*powb[len-(i+hashs[j].s)]%modb))%moda+(hashb(i+hashs[j].s,len-1)))%moda){
					++ans; 
					
				}//printf("%lld %lld\n",hashb(0,len-1),(((hashb(0,i-1)*powa[len-1-i+1]%moda)+(hashs[j].b*powb[len-(i+hashs[j].s)]%modb))%moda+(hashb(i+hashs[j].s,len-1)))%moda);
			}
		}
		printf("%d\n",ans);
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
