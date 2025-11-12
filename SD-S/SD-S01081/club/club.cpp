#include <bits/stdc++.h> 
 #define int long long //Scanf注意 
using namespace std; 
const int N=2e5;
//const int mod;
//const double eps 
int power(int a,int b){
	int res=1;
	while(b){
		if(b&1) res=res*a;
		a=a*a,b>>=1;
	}
	return res;
} 
int rd(){
	int x=0,f=1;
	char ch=getchar();
	while(ch<'0'||ch>'9'){
		if(ch=='-') f=-1;
		ch=getchar();
	}
	while(ch>='0'&&ch<='9'){
		x=x*10+(ch-'0');
		ch=getchar();
	}
	return x*f;
}
int T;
int n;
int a[N][4];
int p[N]; 
int b[4];
int k[4][N];
bool cmp1(int x,int y){
	return p[x]>p[y];
}
bool cmp2(int x,int y){
	return p[x]>p[y];
}
bool cmp3(int x,int y){
	return p[x]>p[y];
}
void sol(){
	scanf("%lld",&n);
	int Ans=0;
	b[1]=b[2]=b[3]=0;
	for(int i=1;i<=n;i++){
		scanf("%lld%lld%lld",&a[i][1],&a[i][2],&a[i][3]);
		int Max=max(a[i][1],max(a[i][2],a[i][3]));
		Ans+=Max;
		if(Max==a[i][1]){
			k[1][++b[1]]=i;
			int nt=max(a[i][2],a[i][3]);
			p[i]=a[i][1]-nt;
		} 
		else if(Max==a[i][2]){
			k[2][++b[2]]=i;
			int nt=max(a[i][1],a[i][3]);
			p[i]=a[i][2]-nt;
		}  
		else{
			int nt=max(a[i][2],a[i][1]);
			k[3][++b[3]]=i; 
			p[i]=a[i][3]-nt;
		} 
	}
	int Maxx=max(b[1],max(b[2],b[3]));
	if(Maxx<=n/2) {
		printf("%lld\n",Ans);
		return ;
	}
	if(Maxx==b[1]){
		sort(k[1]+1,k[1]+b[1]+1,cmp1);
		for(int i=b[1];i>n/2;i--){
			int nt=max(a[k[1][i]][2],a[k[1][i]][3]);
			Ans-=a[k[1][i]][1];
			Ans+=nt; 
		}
	}
	if(Maxx==b[2]){
		sort(k[2]+1,k[2]+b[2]+1,cmp1);
		for(int i=b[2];i>n/2;i--){
			int nt=max(a[k[2][i]][1],a[k[2][i]][3]);
			Ans-=a[k[2][i]][2];
			Ans+=nt; 
		}
	}
	if(Maxx==b[3]){
		sort(k[3]+1,k[3]+b[3]+1,cmp1);
		for(int i=b[3];i>n/2;i--){
			int nt=max(a[k[3][i]][2],a[k[3][i]][1]);
			Ans-=a[k[3][i]][3];
			Ans+=nt; 
		}
	}
	printf("%lld\n",Ans);
	return ;
}
// unordered_map<int,int> mp; 
signed main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
//  ios::sync_with_stdio(false);
//	cin.tie(0),cout.tie(0);
//	int st=clock();
//  int ed=clock();
//	cout<<ed-st;
	scanf("%lld",&T);
	while(T--) sol();
	return 0;
}
// long long 开了吗
// mod 
// 数组大小
// upper_bound()严格大于 lower_bound()不严格
// freopen!
// 函数是否返回值 
// system("fc XXX XXX") 

