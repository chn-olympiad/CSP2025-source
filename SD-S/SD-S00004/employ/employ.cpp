#include<iostream>
#include<cstdio>
#include<algorithm> 

using namespace std;

inline int Rd(){
	int x=0,f=1; char c=getchar();
	while (c<'0' || c>'9'){
		if (c=='-') f=-1;
		c=getchar();
	}
	while (c>='0'&&c<='9'){
		x=(x<<1)+(x<<3)+(c^'0');
		c=getchar();
	}
	return x*f;
}

int n,m,p[20],a[20],cnt,ans;
char s[20];

int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	n=Rd();m=Rd();
	for (int i=1;i<=n;i++) p[i]=i;
	scanf(" %s",s+1);
	for (int i=1;i<=n;i++){
		a[i]=Rd();
	}
	do{
		cnt=0;
		for (int i=1;i<=n;i++){
			if (s[i]=='0'){
				cnt++;
			}else{
				if (cnt>=a[p[i]]){
					cnt++;
				}
			}
		}
		if (n-cnt>=m) ans++;
	}while (next_permutation(p+1,p+n+1));
	printf("%d\n",ans);
	return 0;
}
/*

*/
