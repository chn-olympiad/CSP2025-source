#include<bits/stdc++.h>
using namespace std;
long long n,q,a[200005],b[200005],c,d,len[200005],l,ans;
char x[5000005],y[5000005];
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	scanf("%lld%lld",&n,&q);
	for(int i=1;i<=n;i++){
		scanf("%s%s",x,y);
		len[i]=strlen(x);
		//printf("%lld\n",len[i]);
		for(int j=0;j<len[i];j++)
			if(x[j]=='b')a[i]=j;
			else if(y[j]=='b')b[i]=j;
	}
	while(q--){
		scanf("%s%s",x,y);
		l=strlen(x);
		if(l!=strlen(y)){
			printf("0\n");
			continue;
		}
		for(int i=0;i<l;i++)
			if(x[i]=='b')c=i;
			else if(y[i]=='b')d=i;
		ans=0;
		for(int i=1;i<=n;i++){
			if(d-c==b[i]-a[i]&&c>=a[i]&&len[i]-a[i]<=l-c)ans++;
		}
		printf("%lld\n",ans);
	}
	return 0;
}
