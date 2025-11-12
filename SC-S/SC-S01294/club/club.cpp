#include<bits/stdc++.h>
using namespace std;
long long t,top=0;
long long ai[100050][5];
long long cii[2][2];
long long cc[2][2][2][2];
long long ci[2][2][2][2][2][2][2][2][2][2];
long long ans[100050];
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	scanf("%lld",&t);
	while(t--){
		memset(cii,0,sizeof(cii));
		memset(ci,0,sizeof(ci));
		memset(cc,0,sizeof(cc));
		memset(ans,0,sizeof(ans));
		memset(ai,0,sizeof(ai));
		bool flag2=true,flag3=true;
		long long n;scanf("%lld",&n);
		for(long long i=0;i<n;i++){
			for(long long j=0;j<3;j++){
				scanf("%lld",&ai[i][j]);
			}
			if(ai[i][2]!=0)flag3=false;
			if(ai[i][1]!=0)flag2=false;
		}
		if(flag2==true&&flag3==true){
			for(long long i=0;i<n;i++){
				ans[i]=ai[i][0];
			}
			sort(ans+1,ans+n+1);
			long long sum=0;
			for(long long i=n;i>(n/2);i--){
				sum+=ans[i];
			}
			printf("%lld\n",sum);
			continue;
		}
		if(n==2){		
			memset(cii,0,sizeof(cii));
			for(long long i=0;i<=2;i++){
				for(long long j=0;j<=2;j++){
					cii[i][j]=(ai[0][i]+ai[1][j]);
					long long sum1=0,sum2=0,sum3=0;
					if(i==0)sum1++;
					else if(i==1)sum2++;
					else sum3++;
					if(j==0)sum1++;
					else if(j==1)sum2++;
					else sum3++;
					if(sum1<=(n/2)&&sum2<=(n/2)&&sum3<=(n/2)){
						ans[++top]=cii[i][j];
					}
				}
			}
			sort(ans+1,ans+top+1);
			printf("%lld\n",ans[top]);
			continue;
		}
		if(n==4){
			for(long long a=0;a<=2;a++){
				for(long long b=0;b<=2;b++){
					for(long long c=0;c<=2;c++){
						for(long long d=0;d<=2;d++){
							cc[a][b][c][d]=(ai[0][a]+ai[1][b]+ai[2][c]+ai[3][d]);
							long long sum1=0,sum2=0,sum3=0;
							if(a==0)sum1++;
							else if(a==1)sum2++;
							else sum3++;
							if(b==0)sum1++;
							else if(b==1)sum2++;
							else sum3++;
							if(c==0)sum1++;
							else if(c==1)sum2++;
							else sum3++;
							if(d==0)sum1++;
							else if(d==1)sum2++;
							else sum3++;
							if(sum1<=(n/2)&&sum2<=(n/2)&&sum3<=(n/2)){
								ans[++top]=cc[a][b][c][d];
							}							
						}
					}
				}
			}
			sort(ans+1,ans+top+1);
			printf("%lld\n",ans[top]);
			continue;
		}
		if(n==10){	
			memset(ci,0,sizeof(ci));
			for(long long a=0;a<=2;a++){
				for(long long b=0;b<=2;b++){
					for(long long c=0;c<=2;c++){
						for(long long d=0;d<=2;d++){
							for(long long e=0;e<=2;e++){
								for(long long f=0;f<=2;f++){
									for(long long g=0;g<=2;g++){
										for(long long h=0;h<=2;h++){
											for(long long i=0;i<=2;i++){
												for(long long j=0;j<=2;j++){
													long long sum=(ai[0][a]+ai[1][b]+ai[2][c]+ai[3][d]+ai[4][e]+ai[5][f]+ai[6][g]+ai[7][h]+ai[8][i]+ai[9][j]);
													ci[a][b][c][d][e][f][g][h][i][j]=sum;
													long long sum1=0,sum2=0,sum3=0;
													if(a==0)sum1++;
													else if(a==1)sum2++;
													else sum3++;
													if(b==0)sum1++;
													else if(b==1)sum2++;
													else sum3++;
													if(c==0)sum1++;
													else if(c==1)sum2++;
													else sum3++;
													if(d==0)sum1++;
													else if(d==1)sum2++;
													else sum3++;
													if(e==0)sum1++;
													else if(e==1)sum2++;
													else sum3++;
													if(f==0)sum1++;
													else if(f==1)sum2++;
													else sum3++;
													if(g==0)sum1++;
													else if(g==1)sum2++;
													else sum3++;
													if(h==0)sum1++;
													else if(h==1)sum2++;
													else sum3++;
													if(i==0)sum1++;
													else if(i==1)sum2++;
													else sum3++;
													if(j==0)sum1++;
													else if(j==1)sum2++;
													else sum3++;
													if(sum1<=(n/2)&&sum2<=(n/2)&&sum3<=(n/2)){
														ans[++top]=sum;
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
			sort(ans+1,ans+top+1);
			printf("%lld\n",ans[top]);
			continue;
		}
	}
	return 0;
}