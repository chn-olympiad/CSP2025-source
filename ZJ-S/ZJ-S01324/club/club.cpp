#include <bits/stdc++.h>
using namespace std;
int T,n,i,js[10],sum;
struct no{
	int fi,se,th,zy;
}a[100010];
bool cmp(no q,no h){
	if((q.zy&&h.zy)||(q.zy==0&&h.zy==0)){
		if(q.fi!=h.fi) return q.fi>h.fi;
		else if(q.se!=h.se) return q.se>h.se;
		return q.th>h.th;
	}
	else return q.zy>h.zy;
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	scanf("%d",&T);
	while(T--){
		scanf("%d",n);sum=0;memset(js,0,sizeof(js));
		for(i=1;i<=n;i++){
			scanf("%d%d%d",&a[i].fi,&a[i].se,&a[i].th);
			if((a[i].fi==0)+(a[i].se==0)+(a[i].th==0)==2) a[i].zy=1;
		}
		sort(a+1,a+n+1,cmp);
		for(i=1;i<=n;i++)
			if(a[i].fi>a[i].se&&a[i].fi>a[i].th){
				if(js[1]<n/2) js[1]++,sum+=a[i].fi;
				else
					if(a[i].se>a[i].th) js[2]++,sum+=a[i].se;
					else if(a[i].se<a[i].th) js[3]++,sum+=a[i].th;
					else
						if(js[2]>js[3]) js[3]++,sum+=a[i].th;
						else js[2]++,sum+=a[i].se;
			}
			else if(a[i].se>a[i].fi&&a[i].se>a[i].th){
				if(js[2]<n/2) js[2]++,sum+=a[i].se;
				else
					if(a[i].fi>a[i].th) js[1]++,sum+=a[i].fi;
					else if(a[i].fi<a[i].th) js[3]++,sum+=a[i].th;
					else
						if(js[1]>js[3]) js[3]++,sum+=a[i].th;
						else js[1]++,sum+=a[i].fi;
			}
			else if(a[i].th>a[i].se&&a[i].th>a[i].fi){
				if(js[3]<n/2) js[3]++,sum+=a[i].th;
				else
					if(a[i].se>a[i].fi) js[2]++,sum+=a[i].se;
					else if(a[i].se<a[i].fi) js[1]++,sum+=a[i].fi;
					else
						if(js[2]>js[1]) js[1]++,sum+=a[i].fi;
						else js[2]++,sum+=a[i].se;
			}
			else{
				if(a[i].fi==a[i].se&&a[i].fi>a[i].th){
					if(js[2]>js[1]) js[1]++,sum+=a[i].fi;
					else js[2]++,sum+=a[i].se;
				}
				else if(a[i].fi==a[i].th&&a[i].fi>a[i].se){
					if(js[3]>js[1]) js[1]++,sum+=a[i].fi;
					else js[3]++,sum+=a[i].th;
				}
				else if(a[i].th==a[i].se&&a[i].th>a[i].fi){
					if(js[2]>js[3]) js[3]++,sum+=a[i].th;
					else js[2]++,sum+=a[i].se;
				}
				else if(a[i].th==a[i].fi&&a[i].fi==a[i].se){
					if(js[1]==js[2]&&js[2]>js[3]){
						js[3]++,sum+=a[i].th;
					}
					else if(js[1]==js[3]&&js[1]>js[2]){
						js[2]++,sum+=a[i].se;
					}
					else if(js[3]==js[2]&&js[3]>js[1]){
						js[1]++,sum+=a[i].fi;
					}
					else js[1]++,sum+=a[i].fi;
				}
			}
		printf("%d\n",sum);
	}
	return 0;
}