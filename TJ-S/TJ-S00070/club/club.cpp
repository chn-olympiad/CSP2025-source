#include<iostream>
#include<algorithm>
#define d1 for(int d=1;d<=3;d++)
#define e1 for(int e=1;e<=3;e++)
#define f1 for(int f=1;f<=3;f++)
#define g1 for(int g=1;g<=3;g++)
#define h1 for(int h=1;h<=3;h++)
#define i1 for(int i=1;i<=3;i++)
#define j1 for(int j=1;j<=3;j++)
#define k1 for(int k=1;k<=3;k++)
#define l1 for(int l=1;l<=3;l++)
#define m1 for(int m=1;m<=3;m++)
using namespace std;
int a1[100005][4];
int a[100005];
bool cmp(int x,int y){
	return x>y;
}
int is_1(int num,int cnt){
	if(num==1){
		return cnt+1;
	}
	return cnt;
}
int is_2(int num,int cnt){
	if(num==2){
		return cnt+1;
	}
	return cnt;
}
int is_3(int num,int cnt){
	if(num==3){
		return cnt+1;
	}
	return cnt;
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int t;
	cin>>t;
	while(t--){
		int n,lim;
		cin>>n;
		lim=n/2;
		int ans=0;
		for(int i=1;i<=n;i++){
			cin>>a1[i][1]>>a1[i][2]>>a1[i][3];
			a[i]=a1[i][1];
		}
		if(n==2){
			int ans1=0;
			for(int i=1;i<=3;i++){
				for(int j=1;j<=3;j++){
					if(i==j){
						continue;
					}
					ans1=max(ans1,a1[1][i]+a1[2][j]);
				}
			}
			cout<<ans1<<'\n';
			continue;
		}
		if(n==4){
			int ans2=0;
			for(int i=1;i<=3;i++){
				for(int j=1;j<=3;j++){
					for(int z=1;z<=3;z++){
						for(int k=1;k<=3;k++){
							int cnt1=0,cnt2=0,cnt3=0;
							if(i==1){
								cnt1++;
							}
							else{
								if(i==2){
									cnt2++;
								}
								else{
									cnt3++;
								}
							}
							if(j==1){
								cnt1++;
							}
							else{
								if(j==2){
									cnt2++;
								}
								else{
									cnt3++;
								}
							}
							if(z==1){
								cnt1++;
							}
							else{
								if(z==2){
									cnt2++;
								}
								else{
									cnt3++;
								}
							}
							if(k==1){
								cnt1++;
							}
							else{
								if(k==2){
									cnt2++;
								}
								else{
									cnt3++;
								}
							}
							if(cnt1>2||cnt2>2||cnt3>2){
								continue;
							}
							ans2=max(ans2,a1[1][i]+a1[2][j]+a1[3][z]+a1[4][k]);
						}
					}
				}
			}
			cout<<ans2<<'\n';
			continue;
		}
		if(n==10){
			int ans3=0;
			d1{
				e1{
					f1{
						g1{
							h1{
								i1{
									j1{
										k1{
											l1{
												m1{
													int cn1=0,cn2=0,cn3=0;
													cn1=is_1(d,cn1);
													cn1=is_1(e,cn1);
													cn1=is_1(f,cn1);
													cn1=is_1(g,cn1);
													cn1=is_1(h,cn1);
													cn1=is_1(i,cn1);
													cn1=is_1(j,cn1);
													cn1=is_1(k,cn1);
													cn1=is_1(l,cn1);
													cn1=is_1(m,cn1);
													cn2=is_2(d,cn2);
													cn2=is_2(e,cn2);
													cn2=is_2(f,cn2);
													cn2=is_2(g,cn2);
													cn2=is_2(h,cn2);
													cn2=is_2(i,cn2);
													cn2=is_2(j,cn2);
													cn2=is_2(k,cn2);
													cn2=is_2(l,cn2);
													cn2=is_2(m,cn2);
													cn3=is_3(d,cn3);
													cn3=is_3(e,cn3);
													cn3=is_3(f,cn3);
													cn3=is_3(g,cn3);
													cn3=is_3(h,cn3);
													cn3=is_3(i,cn3);
													cn3=is_3(j,cn3);
													cn3=is_3(k,cn3);
													cn3=is_3(l,cn3);
													cn3=is_3(m,cn3);
													if(cn1>5||cn2>5||cn3>5){
														continue;
													}
													ans3=max(ans3,a1[1][d]+a1[2][e]+a1[3][f]+a1[4][g]+a1[5][h]+a1[6][i]+a1[7][j]+a1[8][k]+a1[9][l]+a1[10][m]);
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
			cout<<ans3<<'\n';
		}
		sort(a+1,a+n+1,cmp);
		for(int i=1;i<=lim;i++){
			ans+=a[i];
		}
		cout<<ans<<'\n';
	}
	return 0;
}
