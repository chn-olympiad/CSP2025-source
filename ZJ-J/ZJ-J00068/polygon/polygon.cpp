#include<bits/stdc++.h>
using namespace std;
const int MAXN=5e3;
int n;
long long a[MAXN],ans;
int mx=-1;
bool cmp(int a,int b){
	return a>b;
}

int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++) cin>>a[i];
	sort(a+1,a+n+1,cmp);
	for(int u=0;u<=1;u++){
		if(u) mx=a[1];
		for(int b=0;b<=1;b++){
			if(b) mx=a[2];
			for(int c=0;c<=1;c++){
				if(c) mx=a[3];
				for(int d=0;d<=1;d++){
					if(d) mx=a[4];
					for(int e=0;e<=1;e++){
						if(e) mx=a[5];
						for(int f=0;f<=1;f++){
							if(f) mx=a[6];
							for(int g=0;g<=1;g++){
								if(g) mx=a[7];
								for(int h=0;h<=1;h++){
									if(h) mx=a[8];
									for(int i=0;i<=1;i++){
										if(i) mx=a[9];
										for(int j=0;j<=1;j++){
											if(j) mx=a[10];
											for(int k=0;k<=1;k++){
												if(k) mx=a[11];
												for(int l=0;l<=1;l++){
													if(l) mx=a[12];
													for(int m=0;m<=1;m++){
														if(m) mx=a[13];
														for(int n=0;n<=1;n++){
															if(n) mx=a[14];
															for(int o=0;o<=1;o++){
																if(o) mx=a[15];
																for(int p=0;p<=1;p++){
																	if(p) mx=a[16];
																	for(int q=0;q<=1;q++){
																		if(q) mx=a[17];
																		for(int r=0;r<=1;r++){
																			if(r) mx=a[18];
																			for(int s=0;s<=1;s++){
																				if(s) mx=a[19];
																				for(int t=0;t<=1;t++){
																					if(t) mx=a[20];
																					if(a[1]*u+a[2]*b+a[3]*c+a[4]*d+a[5]*e+a[6]*f+a[7]*g+a[8]*h+a[9]*i+a[10]*j+a[11]*k+a[12]*l+a[13]*m+a[14]*n+a[15]*o+a[16]*p+a[17]*q+a[18]*r+a[19]*s+a[20]*t>2*mx) ans++;
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
							}
						}
					}
				}
			}
		}
	}
	cout<<ans<<endl;
	return 0;
}
