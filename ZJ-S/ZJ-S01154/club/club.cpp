#include<bits/stdc++.h>
using namespace std;
long long A,B,C,s,t,n,x,y,z,a[100005],b[100005],c[100005];
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	scanf("%lld",&t);
	while(t--){
		A=B=C=s=0;
		scanf("%lld",&n);
		for(long long i=1;i<=n;i++){
			scanf("%lld%lld%lld",&x,&y,&z);
			if(x>=y&&x>=z){
				s+=x;
				A++;
				a[A]=x-max(y,z);
			}else{
				if(y>=x&&y>=z){
					s+=y;
					B++;
					b[B]=y-max(x,z);
				}else{
					s+=z;
					C++;
					c[C]=z-max(x,y);
				}
			}
		}
		if(A>n/2){
			sort(a+1,a+A+1);
			for(long long i=0;A-i>n/2;i++){
				s-=a[i+1];
			}
		}
		if(B>n/2){
			sort(b+1,b+B+1);
			for(long long i=0;B-i>n/2;i++){
				s-=b[i+1];
			}
		}
		if(C>n/2){
			sort(c+1,c+C+1);
			for(long long i=0;C-i>n/2;i++){
				s-=c[i+1];
			}
		}
		printf("%lld\n",s);
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
