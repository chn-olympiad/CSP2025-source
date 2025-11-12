#include<bits/stdc++.h>
using namespace std;
int t;
int n;
int maxx;
struct peo{
	int a1;
	int a2;
	int a3;
}p[100010];
void find(int one,int one_p,int two,int two_p,int three,int three_p,int th){
	if(th==n){
		if(one_p<n/2){
			maxx=max(maxx,one+two+three+p[th].a1);
		}
		if(two_p<n/2){
			maxx=max(maxx,one+two+three+p[th].a2);
		}
		if(three_p<n/2){
			maxx=max(maxx,one+two+three+p[th].a3);
		}
		return;
	}
	if(one_p<n/2){
		find(one+p[th].a1,one_p+1,two,two_p,three,three_p,th+1);
	}
	if(two_p<n/2){
		find(one,one_p,two+p[th].a2,two_p+1,three,three_p,th+1);
	}
	if(three_p<n/2){
		find(one,one_p,two,two_p,three+p[th].a3,three_p+1,th+1);
	}
	return;
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	scanf("%d",&t);
	while(t--){
		maxx=0;
		scanf("%d",&n);
		for(int i=1;i<=n;i++){
			scanf("%d%d%d",&p[i].a1,&p[i].a2,&p[i].a3);
		}
		find(0,0,0,0,0,0,1);
		printf("%d\n",maxx);
	}
    fclose(stdin);
    fclose(stdout);
	return 0;
} 
