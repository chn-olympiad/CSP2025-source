#include<iostream>
#include<algorithm>
using namespace std;
const int N=1e5+7;
int n;
struct stud{
	int a,b,c;
}s[N];
int cnta=0,cntb=0,cntc=0,sum=0;
bool cmp1(int x,int y){
	return x>=y;
}
bool cmp(stud x,stud y){
	int xl[3]={x.a,x.b,x.c};
	int yl[3]={y.a,y.b,y.c};
	sort(xl,xl+3,cmp1),sort(yl,yl+3,cmp1);
	xl[0]-=xl[1];
	xl[1]-=xl[2];
	xl[2]=0;
	yl[0]-=yl[1];
	yl[1]-=yl[2];
	yl[2]=0;
	sort(xl,xl+3,cmp1),sort(yl,yl+3,cmp1);
	if(xl[0]==yl[0]){
		if(xl[1]==yl[1]) return xl[2]>=yl[2];
		return xl[1]>=yl[1];
	}
	return xl[0]>=yl[0];
}
bool check_A(){
	for(int i=1;i<=n;i++)
		if(s[i].c) return 0;
	return 1;
}
int abs(int x){
	if(x<0) return 0-x;
	return x;
}
bool cmp_A(stud x,stud y){
	return abs(x.a-x.b)>=abs(y.a-y.b);
}
void solve_A(){
	sort(s+1,s+n+1,cmp_A);
	int cnta=0;
	for(int i=1;i<=n;i++){
		if(s[i].a>=s[i].b){
			if(cnta<n/2) sum+=s[i].a,cnta++;
			else sum+=s[i].b,cntb++;
		}
		else{
			if(cntb<n/2) sum+=s[i].b,cntb++;
			else sum+=s[i].a,cnta++;
		}
	}
	cout<<sum<<'\n';
	return ;
}
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int T;
	cin>>T;
	while(T--){
		sum=cnta=cntb=cntc=0;
		cin>>n;
		for(int i=1;i<=n;i++)
			cin>>s[i].a>>s[i].b>>s[i].c;
		if(check_A()){
			solve_A();
			continue;
		}
		sort(s+1,s+n+1,cmp);
		for(int i=1;i<=n;i++){
			int maxx=max(s[i].a,max(s[i].b,s[i].c));
			if(maxx==s[i].a){
				if(cnta<(n/2)) sum+=s[i].a,cnta++;
				else if(s[i].b>s[i].c) sum+=s[i].b,cntb++;
				else sum+=s[i].c,cntc++;
			}
			if(maxx==s[i].b){
				if(cntb<(n/2)) sum+=s[i].b,cntb++;
				else if(s[i].a>s[i].c) sum+=s[i].a,cnta++;
				else sum+=s[i].c,cntc++;
			}
			if(maxx==s[i].c){
				if(cntc<(n/2)) sum+=s[i].c,cntc++;
				else if(s[i].b>s[i].a) sum+=s[i].b,cntb++;
				else sum+=s[i].a,cnta++;
			}
		}
		cout<<sum<<'\n';
	}
	return 0;
}
