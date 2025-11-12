#include<bits/stdc++.h>
using namespace std;
const int N=1e5+10;
int T,n;
int x[N][5];

struct node{
	int n,some;
}A[N],B[N],C[N];
long long a,c,b;
long long ans;
int t1,t2,t3;
bool cmp1(node w,node u){
	return x[w.n][1]-max(x[w.n][2],x[w.n][3])>x[u.n][1]-max(x[u.n][2],x[u.n][3]);
}
bool cmp2(node w,node u){
	return x[w.n][2]-max(x[w.n][1],x[w.n][3])>x[u.n][2]-max(x[u.n][1],x[u.n][3]);
}
bool cmp3(node w,node u){
	return x[w.n][3]-max(x[w.n][2],x[w.n][1])>x[u.n][3]-max(x[u.n][2],x[u.n][1]);
}

int main(){
	
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	
	scanf("%d",&T);
	while(T--){
		ans=0;
		t1=t2=t3=0;
		a=b=c=0;
		memset(A,0,sizeof A);
		memset(B,0,sizeof B);
		memset(C,0,sizeof C);
		memset(x,0,sizeof x);
		scanf("%d",&n);
		for(int i=1;i<=n;i++){
			scanf("%d %d %d",&x[i][1],&x[i][2],&x[i][3]);
			if(x[i][1]>=x[i][2]&&x[i][1]>=x[i][3]){
				A[++t1].n=i;
				A[t1].some=x[i][1];
				a+=x[i][1];
			}
			else if(x[i][2]>=x[i][1]&&x[i][2]>=x[i][3]){
				B[++t2].n=i;
				B[t2].some=x[i][2];
				b+=x[i][2];
			}
			else {
				C[++t3].n=i;
				C[t3].some=x[i][3];
				c+=x[i][3];
			}
		} 
		if(t1>n/2){
			sort(A+1,A+1+t1,cmp1); 
			for(int i=1;i<=n/2;i++) ans+=A[i].some;
			ans+=b;ans+=c;
			for(int i=n/2+1;i<=t1;i++){
				ans+=max(x[A[i].n][2],x[A[i].n][3]);
			}
		}
		else if(t2>n/2){
			sort(B+1,B+1+t2,cmp2); 
			for(int i=1;i<=n/2;i++) ans+=B[i].some;
			ans+=a;ans+=c;
			for(int i=n/2+1;i<=t2;i++){
				ans+=max(x[B[i].n][1],x[B[i].n][3]);
			}
		}
		else if(t3>n/2){
			sort(C+1,C+1+t3,cmp3); 
			for(int i=1;i<=n/2;i++) ans+=C[i].some;
			ans+=a;ans+=b;
			for(int i=n/2+1;i<=t3;i++){
				ans+=max(x[C[i].n][1],x[C[i].n][2]);
			}
		}
		else{
			ans=a+b+c;
		}
		printf("%lld\n",ans);
		
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
