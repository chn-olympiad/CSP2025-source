#include <bits/stdc++.h>
using namespace std;
int n,q,i,sum,j,fin;string xz,mb;
struct no{
	string yl,th;
}s[200010];
int fi(int t,int w){
	int i;string xzyx;
	for(i=t;i<=w;i++)
		xzyx+=xz[i];
	for(i=1;i<=n;i++)
		if(s[i].yl==xzyx) return i;
	return -1;
}
string th(int t,int w,int diji){
	int i;string sx=xz;
	for(i=t;i<=w;i++)
		sx[i]=s[diji].th[i-t];
	return sx;
}
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	scanf("%d%d",&n,&q);
	for(i=1;i<=n;i++) cin>>s[i].yl>>s[i].th;
	while(q--){
		cin>>xz>>mb;sum=0;
		for(i=1;i<=n;i++){
			for(j=1;j<=n-i+1;j++)
				if(fin=fi(j,j+i-1)!=-1)
					if(th(j,j+i-1,fin)==mb)sum++;
		}
		printf("%d\n",sum);
	}
	return 0;
}