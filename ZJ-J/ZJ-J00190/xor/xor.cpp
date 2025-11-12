#include<bits/stdc++.h>
using namespace std;
int a[500005];
int sum[500005];
bitset<2000005>b;
int getint(){
	int res=0;
	char ch;
	ch=getchar();
	while (!isdigit(ch))ch=getchar();
	while (isdigit(ch)){
		res=res*10+ch-'0';
		ch=getchar();
	}
	return res;
}
int main(){
	//freopen("xor.in","r",stdin);
	//freopen("xor.out","w",stdout);
	int n,k;
	n=getint();k=getint();
	for (int i=1;i<=n;i++){
		a[i]=getint();
		sum[i]=sum[i-1]^a[i];
	}
	b[0]=true;
	int r=0;
	int ans=0;
	for (int i=1;i<=n;i++){
		if (b[sum[i]^k]==true){
			ans++;
			for (int j=r;j<=i-1;j++)b[sum[j]]=false;
			r=i;
		}
		b[sum[i]]=true;
	}
	printf("%d\n",ans);
	return 0;
}
