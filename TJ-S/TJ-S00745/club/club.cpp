#include<bits/stdc++.h>
using namespace std;
struct node{
	int a,b,c;
}v[100005][3];
int l[100005];
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int t;
	scanf("%d",&t);
	while(t--){
		int n,aa=0,bb=0,cc=0,ans=0;
		scanf("%d",&n);
		for(int i=1,aaa,bbb,ccc;i<=n;i++){
			scanf("%d%d%d",&aaa,&bbb,&ccc);
			int h=max(aaa,max(bbb,ccc));
			ans+=h;
			if(h==aaa){
				aa++;
				v[aa][0].a=aaa;
				v[aa][0].b=bbb;
				v[aa][0].c=ccc;
			}else if(h==bbb){
				bb++;
				v[bb][1].a=aaa;
				v[bb][1].b=bbb;
				v[bb][1].c=ccc;
			}else{
				cc++;
				v[cc][2].a=aaa;
				v[cc][2].b=bbb;
				v[cc][2].c=ccc;
			}
		}
		if(aa<=n/2&&bb<=n/2&&cc<=n/2){
			printf("%d\n",ans);
			continue;
		}
		if(aa>n/2){
			for(int i=1;i<=aa;i++){
				l[i]=v[i][0].a-max(v[i][0].b,v[i][0].c);
			}
			sort(l+1,l+1+aa);
			for(int i=aa;i>n/2;i--){
				ans-=l[aa-i+1];
			}
		}
		if(bb>n/2){
			for(int i=1;i<=bb;i++){
				l[i]=v[i][1].b-max(v[i][1].a,v[i][1].c);
			}
			sort(l+1,l+1+bb);
			for(int i=bb;i>n/2;i--){
				ans-=l[bb-i+1];
			}
		}
		if(cc>n/2){
			for(int i=1;i<=cc;i++){
				l[i]=v[i][2].c-max(v[i][2].a,v[i][2].b);
			}
			sort(l+1,l+1+cc);
			for(int i=cc;i>n/2;i--){
				ans-=l[cc-i+1];
			}
		}
		printf("%d\n",ans);
	}
	return 0;
} 
