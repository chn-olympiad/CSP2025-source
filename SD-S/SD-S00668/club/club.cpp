#include<bits/stdc++.h>
using namespace std;
long long t,n,sum,maxx,cnt[3],c[3];
struct Stud{
	long long x[3],Max;
}a[100010];
void search(long long k){
	for(long long i=0;i<3;i++)
		if(c[i]<n/2){
			c[i]++;
			sum+=a[k].x[i];
			if(!(k^n))
				maxx=max(maxx,sum);
			else
				search(k+1);
			c[i]--;
			sum-=a[k].x[i];
		}
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	scanf("%lld",&t);
	while(t--){
		bool flag=false;
		cnt[0]=cnt[1]=cnt[2]=c[0]=c[1]=c[2]=sum=maxx=0;
		scanf("%lld",&n);
		for(long long i=1;i<=n;i++){
			scanf("%lld%lld%lld",&a[i].x[0],&a[i].x[1],&a[i].x[2]);
			a[i].Max=0;
			for(long long j=1;j<3;j++)
				if(a[i].x[j]>a[i].x[a[i].Max])
					a[i].Max=j;
			cnt[a[i].Max]++;
		}
		if(cnt[0]>n/2||cnt[1]>n/2||cnt[2]>n/2)
			flag=true;
		if(flag)
			search(1);
		else
			for(long long i=1;i<=n;i++)
				maxx+=a[i].x[a[i].Max];
		printf("%lld\n",maxx);
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
