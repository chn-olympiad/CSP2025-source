#include<bits/stdc++.h>
#define cmin(a,b) a=std::min(a,b)
#define cmax(a,b) a=std::max(a,b)
#define inf
#define mod 998244353
#define maxn 5000006
#define ll long long
int n,q,ans[maxn];
char s1[maxn],s2[maxn];
std::vector<int> vec[2][maxn];
int hash(char *s,int l,int r){
	int res=0;
	for(int i=l;i<=r;i++){
		res=(res*131%mod+s[i]-'a'+1)%mod;
	}
	return res;
}
int hash2(char *s,int l,int r){
	int res=0;
	for(int i=r;i>=l;i--){
		res=(res*131%mod+s[i]-'a'+1)%mod;
	}
	return res;
}
struct Qst{
	int h1,h2,id;
	bool operator <(Qst oth){
		if(h1!=oth.h1) return h1<oth.h1;
		if(h2!=oth.h2) return h2<oth.h2;
		return id<oth.id;
	}
}qry[maxn];
int pos;
int solve1(int id,char *s1,char *s2){
	int len=strlen(s1+1);
	int L=len+1,R=0;
	for(int i=1;i<=len;i++){
		if(s1[i]!=s2[i]){
			cmin(L,i),R=i;
		}
	}
	if(!R) return -1;
	int h1=hash(s1,L,R),h2=hash(s2,L,R);
	qry[++pos]={h1,h2,id};
	vec[0][id].push_back(hash2(s1,1,L-1));
	vec[1][id].push_back(hash(s1,R+1,len));
	return 0;
}
int solve2(int id,char *s1,char *s2){
	int len=strlen(s1+1);
	int L=len+1,R=0;
	for(int i=1;i<=len;i++){
		if(s1[i]!=s2[i]){
			cmin(L,i),R=i;
		}
	}
	if(!R) return -1;
	int h1=hash(s1,L,R),h2=hash(s2,L,R);
	qry[++pos]={h1,h2,id};
	int res=0;
	vec[0][id].push_back(0);
	vec[1][id].push_back(0);
	for(int i=L-1;i>=1;i--){
		res=(res*131%mod+s1[i]-'a'+1)%mod;
		vec[0][id].push_back(res);
	}
	res=0;
	for(int i=R+1;i<=len;i++){
		res=(res*131%mod+s1[i]-'a'+1)%mod;
		vec[1][id].push_back(res);
	}
	return 0;
}
std::map<int,int> mp1,mp2;
void solve(int L,int R){
//	puts("F");
	int mid=L-1;
	while(mid<R&&qry[mid+1].id<=n){
		mid++;
	}
//	printf("%d %d %d\n",L,mid,R);
	for(int j=mid+1;j<=R;j++){
//		printf("*%lld\n",qry[j].id);
		for(int v:vec[0][qry[j].id]){
//			printf("*********%lld\n",v);
			mp1[v]++;
		}
		for(int v:vec[1][qry[j].id]){
			mp2[v]++;
		}
		for(int i=L;i<=mid;i++){
//		printf("%lld\n",qry[i].id);
			int v1=vec[0][qry[i].id][0];
			int v2=vec[1][qry[i].id][0];
//			printf("W %lld %lld\n",v1,v2);
			ans[qry[j].id]+=mp1[v1]*mp2[v2];
//			printf("%lld %lld\n",mp1[v1],mp2[v2]);
		}
		mp1.clear(),mp2.clear();
	}
}
signed main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	scanf("%d%d",&n,&q);
	for(int i=1;i<=n;i++){
		scanf("%s%s",s1+1,s2+1);
		solve1(i,s1,s2); 
	}
	for(int i=1;i<=q;i++){
		scanf("%s%s",s1+1,s2+1);
		solve2(n+i,s1,s2); 
	}
	std::sort(qry+1,qry+n+q+1);
	for(int i=2,lst=1;i<=n+q+1;i++){
		if(qry[i-1].h1!=qry[i].h1||qry[i-1].h2!=qry[i].h2){
			solve(lst,i-1);
			lst=i;
		}
	}
	for(int i=n+1;i<=n+q;i++){
		printf("%d\n",ans[i]);
	}
	return 0;
}
/*

*/

