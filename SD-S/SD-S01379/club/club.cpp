#include<bits/stdc++.h>
using namespace std;
int t,n,a[100010][10],b[100010],cnta,cntb,cntc,maxx,ans,tot,f1=1,f2=1,v[100010];
struct node{
	int x,y,op;
}c[100010],d[100010];
bool cmp1(node a,node b){
	if(a.x==b.x){
		return a.y<b.y;
	}
	else return a.x>b.x;
}
bool cmp2(node a,node b){
	if(a.y==b.y){
		return a.x<b.x;
	}
	else return a.y>b.y;
}
void q(int x){
	if(x>n){
		maxx=max(maxx,ans);
		return ;
	}
	for(int i=1;i<=3;i++){
		tot++;
		if(cnta+1>n/2&&i==1){
			continue;
		}
		if(cntb+1>n/2&&i==2){
			continue;
		}
		if(cntc+1>n/2&&i==3){
			continue;
		}
		if(i==1){
			cnta++;
		}
		if(i==2){
			cntb++;
		}
		if(i==3){
			cntc++;
		}
		ans+=a[x][i];
		q(x+1);
		ans-=a[x][i];
		if(i==1){
			cnta--;
		}
		if(i==2){
			cntb--;
		}
		if(i==3){
			cntc--;
		}
	}
}
signed main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	scanf("%d",&t);
	while(t--){
		tot=0;
		ans=0;
		cnta=0;
		cntb=0;
		cntc=0;
		maxx=-1;
		scanf("%d",&n);
		for(int i=1;i<=n;i++){
			scanf("%d%d%d",&a[i][1],&a[i][2],&a[i][3]);
			b[i]=a[i][1];
			c[i].x=a[i][1];
			c[i].y=a[i][2];
			c[i].op=i;
			d[i].x=a[i][1];
			d[i].y=a[i][2];
			d[i].op=i;
			if(a[i][2]!=0||a[i][3]!=0){
				f1=0;
			}
			if(a[i][3]!=0){
				f2=0;
			}
		}
		if(f1){
			sort(b+1,b+1+n);
			for(int i=n;i>n/2;i--){
				maxx+=b[i];
			}
		}
//		else if(f2){
//			sort(c+1,c+1+n,cmp1);
//			sort(d+1,d+1+n,cmp2);
//			int c1,c2;
//			while(c1<=n/2||c2<=n/2){
//				while(v[c[c1].op]){
//					c1++;
//				}
//				while(v[d[c2].op]){
//					c2++;
//				}
//				if(c[c1+1].x>d[c2+1].y){
//					c1++;
//					maxx+=c[c1].x;
//					v[c[c1].op]=1;
//				}
//				else if(c[c1+1].x<d[c2+1].y){
//					c2++;
//					maxx+=d[c2].x;
//					v[d[c2].op]=1;
//				}
//				else if(c[c1+1].x==d[c2+1].y){
//					if(c[c1+1].y<d[c2+1].x){
//						c1++;
//						maxx+=c[c1].x;
//						v[c[c1].op]=1;
//					}
//					else if(c[c1+1].y>d[c2+1].x){
//						c2++;
//						maxx+=d[c2].x;
//						v[d[c2].op]=1;
//					}
//				}
//			}
//		}
		else q(1);
//		cout<<n<<" "<<tot<<" ";
		printf("%d\n",maxx);
	}
    return 0;
}

