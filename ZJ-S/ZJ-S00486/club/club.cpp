#include<bits/stdc++.h>
using namespace std;
const int N=1e5+5;
struct club{
	int a,id;
}x[N],y[N],z[N],o[N];
int T,n,ans,to[N],af[N],b[N],c[N],d[N],mx,my,mz;
bool flag[N],fsub1,fsub2;
bool cmp(club x,club y){
	return x.a>y.a;
}
int p1(int i){
	if(mx>my){
		if(mx>mz)return af[i];
		else return c[i];
	} 
	else {
		if(my>mz)return b[i];
		return c[i];
	}
}
int p2(int i){
	if(mx>my){
		if(mx>mz)return c[i];
		else return b[i];
	} 
	else {
		if(my>mz)return af[i];
		return b[i];
	}
}
int p3(int i){
	if(mx>my){
		if(mx>mz)return b[i];
		else return af[i];
	} 
	else {
		if(my>mz)return c[i];
		return af[i];
	}
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	scanf("%d",&T);
	while(T--){
		scanf("%d",&n);
		memset(flag,false,sizeof(flag));
		ans=0;
//		for(int i=1;i<=n;i++){
//			scanf("%d%d%d",&x[i].a,&y[i].a,&z[i].a);
//			x[i].id=y[i].id=z[i].id=i;
//			if(y[i].a!=0)fsub1=true,fsub2=true;
//			if(z[i].a!=0)fsub1=true;
//		}
		mx=0;my=0;mz=0;
		for(int i=1;i<=n;i++){
			scanf("%d%d%d",&af[i],&b[i],&c[i]);
			x[i].a=af[i];y[i].a=b[i];z[i].a=c[i];
			x[i].id=y[i].id=z[i].id=i;
			if(af[i]>=max(b[i],c[i])){
				if(af[i]>max(b[i],c[i]))mx++;
			}
			else if(b[i]>c[i])my++;
			else if(c[i]>b[i])mz++;
			if(y[i].a!=0)fsub1=true,fsub2=true;
			if(z[i].a!=0)fsub1=true;
		}
		if(!fsub1){
			for(int i=1;i<=n/2;i++){
				ans+=x[i].a;
			}
			printf("%d\n",ans);
			continue;
		}
		if(my<=n/2&&mx<=n/2&&mz<=n/2){
		sort(x+1,x+n+1,cmp);
		sort(y+1,y+n+1,cmp);
		sort(z+1,z+n+1,cmp);
		int hx=1,hy=1,hz=1,tx=0,ty=0,tz=0;
		for(int i=1;i<=n;i++){
			while(flag[x[hx].id])hx++;
			while(flag[y[hy].id])hy++;
			while(flag[z[hz].id])hz++;
			if(x[hx].a>max(y[hy].a,z[hz].a)&&tx<n/2){	
				flag[x[hx].id]=true;
				tx++;
//				ans+=x[hx].a;
				ans+=af[x[hx].id];
				to[x[hx].id]=1;
			}
			else{
				if(y[hy].a>z[hz].a){
					if(ty>=n/2){
						if((x[hx].a>z[hz].a&&tx<n/2)||tz>=n/2){
							flag[x[hx].id]=true;
							tx++;
//							ans+=x[hx].a;
							ans+=af[x[hx].id];
							to[x[hx].id]=1;	
						}
						else if(tz<n/2){
							flag[z[hz].id]=true;
							tz++;
//							ans+=z[hz].a;
							ans+=c[z[hz].id];
							to[z[hz].id]=3;	
						}
					}
					flag[y[hy].id]=true;
					ty++;
//					ans+=y[hy].a;
					ans+=b[y[hy].id];
					to[y[hy].id]=2;
				}
				else if(tz<n/2){
					flag[z[hz].id]=true;
					tz++;
//					ans+=z[hz].a;
					ans+=c[z[hz].id];
					to[z[hz].id]=3;
				}
				else{
					if(tz>=n/2){
						if((x[hx].a>y[hy].a&&tx<n/2)||ty>=n/2){
							flag[x[hx].id]=true;
							tx++;
//							ans+=x[hx].a;
							ans+=af[x[hx].id];
							to[x[hx].id]=1;	
						}
						else{
							flag[y[hy].id]=true;
							ty++;
//							ans+=y[hy].a;
							ans+=b[y[hy].id];
							to[y[hy].id]=3;	
						}
					}
				}
			}
		}
		printf("%d\n",ans);
		continue;
		}
		int ans1=0,ans2=0;
		for(int i=1;i<=n;i++){
			o[i].a=p1(i)-p2(i);
			if(p3(i)>max(p2(i),p1(i))){
				o[i].a=-INT_MAX+10;
			}
			o[i].id=i;
		}
		sort(o+1,o+n+1,cmp);
		for(int i=1;i<=n/2;i++){
			ans1+=p1(o[i].id);
//			cout<<o[i].id<<endl;
		}
		for(int i=n/2+1;i<=n;i++){
			ans1+=max(p2(o[i].id),p3(o[i].id));
		}
		for(int i=1;i<=n;i++){
			o[i].a=p1(i)-p3(i);
			if(p2(i)>max(p3(i),p1(i))){
				o[i].a=-INT_MAX+10;
			}
			o[i].id=i;
		}
		sort(o+1,o+n+1,cmp);
		for(int i=1;i<=n/2;i++){
			ans2+=p1(o[i].id);
//			cout<<o[i].id<<endl;
		}
		for(int i=n/2+1;i<=n;i++){
			ans2+=max(p2(o[i].id),p3(o[i].id));
		}
		printf("%d\n",max(ans1,ans2));
	}
	return 0;
}