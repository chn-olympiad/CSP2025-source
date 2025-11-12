#include<iostream>
#include<iomanip>
#include<cstdlib>
#include<cstdio>
#include<cstring>
#include<stack>
#include<queue>
#include<algorithm>
#include<map>
#include<cmath>
#include<set>
using namespace std;
long long read(){
	long long dat=0,t=1;
	char ch=getchar();
	while(ch<'0'||ch>'9'){
		if(ch=='-')t=-t;
		ch=getchar();
	}
	while(ch>='0'&&ch<='9'){
		dat=(dat<<1)+(dat<<3)+(ch&15);
		ch=getchar();
	}
	return dat*t;
}
long long n,m,t;
long long a[200004],b[200004],c[200004],f1[200004],f2[200004],f3[200004],q1,q2,q3;
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	t=read();
	for(;t>=1;t-=1){
		long long i,j,k=0;
		n=read();
		q1=q2=q3=0;
		m=0;
		for(i=1;i<=n;i++){
			a[i]=read();
			b[i]=read();
			c[i]=read();
			if(a[i]>=b[i]&&a[i]>=c[i]){
				q1+=1;
				m=m+a[i];
				f1[q1]=min(a[i]-b[i],a[i]-c[i]);
			}else if(b[i]>=a[i]&&b[i]>=c[i]){
				q2+=1;
				m=m+b[i];
				f2[q2]=min(b[i]-a[i],b[i]-c[i]);
			}else if(c[i]>=a[i]&&c[i]>=b[i]){
				q3+=1;
				m=m+c[i];
				f3[q3]=min(c[i]-a[i],c[i]-b[i]);
			}
		}
		if(q1>(n/2)){
			k=q1-(n/2);
			sort(f1+1,f1+q1+1);	
			for(i=1;i<=k;i++){
				m=m-f1[i];
			}
		}else if(q2>(n/2)){
			k=q2-(n/2);
			sort(f2+1,f2+q2+1);	
			for(i=1;i<=k;i++){
				m=m-f2[i];
			}
		}else if(q3>(n/2)){
			k=q3-(n/2);
			sort(f3+1,f3+q3+1);	
			for(i=1;i<=k;i++){
				m=m-f3[i];
			}
		}
		printf("%lld\n",m);
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}