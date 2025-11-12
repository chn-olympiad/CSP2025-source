#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int t,n;
	scanf("%d",&t);
	int a[100000],b[100000],c[100000];
	for(int i=1;i<=t;i++){
	    scanf("%d",&n);
		for(int j=1;j<=n;j++){
			scanf("%d %d %d",&a[j],&b[j],&c[j]);
		}
	}
	for(int j=1;j<=t;j++){
	    int a1=0,b1=0,c1=0,s=0;
	    for(int i=1;i<=n;i++){
	    	if(a[i]>b[i]&&a[i]>c[i]){
		        a1++;
			    s=s+a[i];
		    }
		    if(b[i]>a[i]&&b[i]>c[i]){
			    b1++;
			    s=s+b[i];
		    }
            if(c[i]>a[i]&&c[i]>b[i]){
			    c1++;
			    s=s+c[i];
		    }
		}
		printf("%d\n",s);
	}
	return 0;
}