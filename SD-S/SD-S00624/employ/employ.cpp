#include<bits/stdc++.h>
using namespace std;

const int N=505;
int n,m,a[N],c[N],p[N],t[N],s,tt[N];

int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++){
		scanf("%1d",&a[i]);
		t[i]=t[i-1]+(a[i]==0);
		p[i]=i;
	}
	for(int i=1;i<=n;i++){
		scanf("%d",&c[i]);
		
//		printf("%d ",t[i]);
	}
	do{
		int l=0;
		for(int i=1;i<=n;i++) tt[i]=t[i];
		for(int i=1;i<=n;i++){
			if(tt[i-1]>=c[p[i]]){
				l++;
				tt[i]++;
//				break;
			}
		}
		if(l<m) s++;
	}while(next_permutation(p+1,p+1+n));
	printf("%d",s);
	return 0;
}
