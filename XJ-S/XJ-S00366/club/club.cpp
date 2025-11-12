#include<iostream>
#include<algorithm>
#include<string.h>
#include<vector>
using namespace std;
#define int long long
const int N=1e5+5;
int n;
struct node{
	int a,b,c;
}a[N],A[N],B[N],C[N];
int T,AA,BB,CC;
bool cmp(node p,node q){
	if(p.a>=max(p.b,p.c)&&q.a>=max(q.b,q.c)){
		int sum=p.a-q.a;
		if(p.b>p.c){
			if(q.b>q.c)
			    sum+=q.b-p.b;
			else
			    sum+=q.c-p.b;
		}
		else{
			if(q.b>q.c)
			    sum+=q.b-p.c;
			else
			    sum+=q.c-p.c;
		}
		return (sum>0?1:0);
	}
	if(p.b>=max(p.a,p.c)&&q.b>=max(q.a,q.c)){
		int sum=p.b-q.b;
		if(p.a>p.c){
			if(q.a>q.c)
			    sum+=q.a-p.a;
			else
			    sum+=q.c-p.a;
		}
		else{
			if(q.a>q.c)
			    sum+=q.a-p.c;
			else
			    sum+=q.c-p.c;
		}
		return (sum>0?1:0);
	}
	if(p.c>=max(p.b,p.a)&&q.c>=max(q.b,q.a)){
		int sum=p.c-q.c;
		if(p.a>p.b){
			if(q.a>q.b)
			    sum+=q.a-p.a;
			else
			    sum+=q.b-p.a;
		}
		else{
			if(q.a>q.b)
			    sum+=q.a-p.b;
			else
			    sum+=q.b-p.b;
		}
		return (sum>0?1:0);
	}
}
void solve(){
	AA=BB=CC=0;
	cin>>n;
	int ans=0;
	for(int i=1;i<=n;i++){
		cin>>a[i].a>>a[i].b>>a[i].c;
		if(a[i].a>=max(a[i].b,a[i].c)){
			A[++AA]=(node){a[i].a,a[i].b,a[i].c};
			continue;
		}
		if(a[i].b>=max(a[i].a,a[i].c)){
			B[++BB]=(node){a[i].a,a[i].b,a[i].c};
			continue;
		}
		if(a[i].c>=max(a[i].b,a[i].a)){
			C[++CC]=(node){a[i].a,a[i].b,a[i].c};
		}
	}
		
	sort(A+1,A+AA+1,cmp);
	sort(B+1,B+BB+1,cmp);
	sort(C+1,C+CC+1,cmp);
	int aa=0,bb=0,cc=0;
	if(AA>n/2){
		for(int i=1;i<=AA;i++){
			if(aa<n/2) ans+=A[i].a,aa++;
			else{
				if(A[i].b>A[i].c)
				    ans+=A[i].b,bb++;
				else
				    ans+=A[i].c,cc++;
			}
		}
		for(int i=1;i<=BB;i++){
			if(bb<n/2) ans+=B[i].b,bb++;
			else{
				if(a[i].a>a[i].c)
				    ans+=B[i].a,aa++;
				else
				    ans+=B[i].c,cc++;
			}
		}
		for(int i=1;i<=CC;i++){
			if(cc<n/2) ans+=C[i].c,cc++;
			else{
				if(a[i].a>a[i].b)
				    ans+=C[i].a,aa++;
				else
				    ans+=C[i].b,bb++;
			}
		}
	}
	if(BB>n/2){
		for(int i=1;i<=BB;i++){
			if(bb<n/2) ans+=B[i].b,bb++;
			else{
				if(a[i].a>a[i].c)
				    ans+=B[i].a,aa++;
				else
				    ans+=B[i].c,cc++;
			}
		}
		for(int i=1;i<=AA;i++){
			if(aa<n/2) ans+=A[i].a,aa++;
			else{
				if(A[i].b>A[i].c)
				    ans+=A[i].b,bb++;
				else
				    ans+=A[i].c,cc++;
			}
		}
		
		for(int i=1;i<=CC;i++){
			if(cc<n/2) ans+=C[i].c,cc++;
			else{
				if(a[i].a>a[i].b)
				    ans+=C[i].a,aa++;
				else
				    ans+=C[i].b,bb++;
			}
		}
	}
	if(CC>n/2){
		for(int i=1;i<=CC;i++){
			if(cc<n/2) ans+=C[i].c,cc++;
			else{
				if(a[i].a>a[i].b)
				    ans+=C[i].a,aa++;
				else
				    ans+=C[i].b,bb++;
			}
		}
		for(int i=1;i<=AA;i++){
			if(aa<n/2) ans+=A[i].a,aa++;
			else{
				if(A[i].b>A[i].c)
				    ans+=A[i].b,bb++;
				else
				    ans+=A[i].c,cc++;
			}
		}
		for(int i=1;i<=BB;i++){
			if(bb<n/2) ans+=B[i].b,bb++;
			else{
				if(a[i].a>a[i].c)
				    ans+=B[i].a,aa++;
				else
				    ans+=B[i].c,cc++;
			}
		}
		
	}
	if(AA<=n/2&&BB<=n/2&&CC<=n/2){
		for(int i=1;i<=AA;i++){
			if(aa<n/2) ans+=A[i].a,aa++;
			else{
				if(A[i].b>A[i].c)
				    ans+=A[i].b,bb++;
				else
				    ans+=A[i].c,cc++;
			}
		}
		for(int i=1;i<=BB;i++){
			if(bb<n/2) ans+=B[i].b,bb++;
			else{
				if(a[i].a>a[i].c)
				    ans+=B[i].a,aa++;
				else
				    ans+=B[i].c,cc++;
			}
		}
		for(int i=1;i<=CC;i++){
			if(cc<n/2) ans+=C[i].c,cc++;
			else{
				if(a[i].a>a[i].b)
				    ans+=C[i].a,aa++;
				else
				    ans+=C[i].b,bb++;
			}
		}
	}
	cout<<ans<<endl;
}
signed main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>T;
	while(T--)
	    solve();
	return 0;
} 
