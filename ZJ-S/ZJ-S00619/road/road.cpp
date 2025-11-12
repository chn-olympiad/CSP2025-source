#include<iostream>
#include<iomanip>
#include<cstdlib>
#include<cstdio>
#include<cstring>
#include<stack>
#include<queue>
#include<algorithm>
#include<map>
#include<cmath>
#include<set>
using namespace std;
long long read(){
	long long dat=0,t=1;
	char ch=getchar();
	while(ch<'0'||ch>'9'){
		if(ch=='-')t=-t;
		ch=getchar();
	}
	while(ch>='0'&&ch<='9'){
		dat=(dat<<1)+(dat<<3)+(ch&15);
		ch=getchar();
	}
	return dat*t;
}
struct node{
	long long ans=1e15;
	long long q=0;
	long long fr=-1;
};
node f[20004];
long long n,m,k,x,y,l,r,h,g,sum,tot;
long long pre[4000004],to[4000004],head[4000004],num[4000004],quan[4000004];
long long a[44][40004],b[4000004],c[44],e[44][40004],flag[40004];
void add(long long u,long long v,long long w){
	pre[++tot]=head[u];
	head[u]=tot;
	to[tot]=v;
	num[tot]=w;
}
void prim(){
	b[1]=1;
	f[1].ans=0;
	f[1].q=0;
	f[1].fr=1;
	long long i,j,t;
	for(i=head[1];i;i=pre[i]){
		j=to[i];
		if(num[i]<f[j].ans){
			f[j].ans=num[i];
			f[j].fr=1;
		}
	}
	for(i=1;i<=k;i++){
		for(j=2;j<=n;j++){
			if(a[i][1]+c[i]+a[i][j]<f[j].ans){
				f[j].ans=a[i][1]+c[i]+a[i][j];
				f[j].q=i;
				f[j].fr=1;
			}
		}
	}
	for(i=1;i<n;i++){
		long long minj=1e15,mink;
		for(j=2;j<=n;j++){
			if(b[j]==0){
				if(f[j].ans<minj){
					minj=f[j].ans;
					mink=j;
				}
			}
		}
		if(flag[f[mink].q]!=0){
			flag[f[mink].q]=1;
			e[f[mink].q][f[mink].fr]=0;
			e[f[mink].q][mink]=0;
			for(j=2;j<=n;j++){
				if(b[j]==0){
					if(f[j].q==f[mink].q){
						f[j].ans=f[j].ans-c[f[mink].q]-a[f[j].q][f[j].fr]+e[f[j].q][f[j].fr];
					}
				}
			}
			for(j=2;j<=n;j++){
				if(b[j]==0&&f[j].ans<e[f[mink].q][j]){
					f[j].ans=a[f[mink].q][j];
					f[j].q=f[mink].q;
					f[j].fr=f[mink].fr;
				//	e[f[mink].q][j]=0;
				}
			}
		}
//		for(j=2;j<=n;j++){
//			if(flag[f[j].q]==1){
//				f[j].ans=f[j].ans+
//			}
//		}
		b[mink]=1;
		sum=sum+f[mink].ans;
		for(j=head[mink];j;j=pre[j]){
			if(num[j]<f[to[j]].ans){
				f[to[j]].ans=num[j];
				f[to[j]].fr=mink;
			}
		}
		for(j=2;j<=n;j++){
			if(b[j]==0){
				t=1;
				if(t<=k){
					if(flag[t]==1){
						if(e[t][mink]+e[t][j]<f[j].ans){
							f[j].ans=e[t][mink]+e[t][j];
							f[j].q=t;
							f[j].fr=mink;	
						}
					}else{
						if(a[t][mink]+a[t][j]+c[t]<f[j].ans){
							f[j].ans=a[t][mink]+a[t][j]+c[t];
							f[j].q=t;
							f[j].fr=mink;
						}
					}
					t+=1;
					if(t<=k){
						if(flag[t]==1){
							if(e[t][mink]+e[t][j]<f[j].ans){
								f[j].ans=e[t][mink]+e[t][j];
								f[j].q=t;
								f[j].fr=mink;	
							}
						}else{
							if(a[t][mink]+a[t][j]+c[t]<f[j].ans){
								f[j].ans=a[t][mink]+a[t][j]+c[t];
								f[j].q=t;
								f[j].fr=mink;
							}
						}
						t+=1;
						if(t<=k){
							if(flag[t]==1){
								if(e[t][mink]+e[t][j]<f[j].ans){
									f[j].ans=e[t][mink]+e[t][j];
									f[j].q=t;
									f[j].fr=mink;	
								}
							}else{
								if(a[t][mink]+a[t][j]+c[t]<f[j].ans){
									f[j].ans=a[t][mink]+a[t][j]+c[t];
									f[j].q=t;
									f[j].fr=mink;
								}
							}
							t+=1;
							if(t<=k){
								if(flag[t]==1){
									if(e[t][mink]+e[t][j]<f[j].ans){
										f[j].ans=e[t][mink]+e[t][j];
										f[j].q=t;
										f[j].fr=mink;	
									}
								}else{
									if(a[t][mink]+a[t][j]+c[t]<f[j].ans){
										f[j].ans=a[t][mink]+a[t][j]+c[t];
										f[j].q=t;
										f[j].fr=mink;
									}
								}
								t+=1;
								if(t<=k){
									if(flag[t]==1){
										if(e[t][mink]+e[t][j]<f[j].ans){
											f[j].ans=e[t][mink]+e[t][j];
											f[j].q=t;
											f[j].fr=mink;	
										}
									}else{
										if(a[t][mink]+a[t][j]+c[t]<f[j].ans){
											f[j].ans=a[t][mink]+a[t][j]+c[t];
											f[j].q=t;
											f[j].fr=mink;
										}
									}
									t+=1;
									if(t<=k){
										if(flag[t]==1){
											if(e[t][mink]+e[t][j]<f[j].ans){
												f[j].ans=e[t][mink]+e[t][j];
												f[j].q=t;
												f[j].fr=mink;	
											}
										}else{
											if(a[t][mink]+a[t][j]+c[t]<f[j].ans){
												f[j].ans=a[t][mink]+a[t][j]+c[t];
												f[j].q=t;
												f[j].fr=mink;
											}
										}
										t+=1;
										if(t<=k){
											if(flag[t]==1){
												if(e[t][mink]+e[t][j]<f[j].ans){
													f[j].ans=e[t][mink]+e[t][j];
													f[j].q=t;
													f[j].fr=mink;	
												}
											}else{
												if(a[t][mink]+a[t][j]+c[t]<f[j].ans){
													f[j].ans=a[t][mink]+a[t][j]+c[t];
													f[j].q=t;
													f[j].fr=mink;
												}
											}
											t+=1;
											if(t<=k){
												if(flag[t]==1){
													if(e[t][mink]+e[t][j]<f[j].ans){
														f[j].ans=e[t][mink]+e[t][j];
														f[j].q=t;
														f[j].fr=mink;	
													}
												}else{
													if(a[t][mink]+a[t][j]+c[t]<f[j].ans){
														f[j].ans=a[t][mink]+a[t][j]+c[t];
														f[j].q=t;
														f[j].fr=mink;
													}
												}
												t+=1;
												if(t<=k){
													if(flag[t]==1){
														if(e[t][mink]+e[t][j]<f[j].ans){
															f[j].ans=e[t][mink]+e[t][j];
															f[j].q=t;
															f[j].fr=mink;	
														}
													}else{
														if(a[t][mink]+a[t][j]+c[t]<f[j].ans){
															f[j].ans=a[t][mink]+a[t][j]+c[t];
															f[j].q=t;
															f[j].fr=mink;
														}
													}
													t+=1;
													if(t<=k){
														if(flag[t]==1){
															if(e[t][mink]+e[t][j]<f[j].ans){
																f[j].ans=e[t][mink]+e[t][j];
																f[j].q=t;
																f[j].fr=mink;	
															}
														}else{
															if(a[t][mink]+a[t][j]+c[t]<f[j].ans){
																f[j].ans=a[t][mink]+a[t][j]+c[t];
																f[j].q=t;
																f[j].fr=mink;
															}
														}
														t+=1;
													}
												}
											}
										}
									}
								}
							}
						}
					}
				}
			}
		}
	}
	return;
}
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	long long i,j;
	n=read();
	m=read();
	k=read();
	for(i=1;i<=m;i++){
		long long u,v,w;
		u=read();
		v=read();
		w=read();
		add(u,v,w);
		add(v,u,w);
	}
	for(i=1;i<=k;i++){
		c[i]=read();
		for(j=1;j<=n;j++){
			a[i][j]=read();
			e[i][j]=a[i][j];
//			quan[++tot]=c[i];
//			tot-=1;
//			add(i,j);
//			quan[++tot]=c[i];
//			tot-=1;
//			add(j,i);
		}
	}
	prim();
	printf("%lld",sum);
	fclose(stdin);
	fclose(stdout);
	return 0;
}