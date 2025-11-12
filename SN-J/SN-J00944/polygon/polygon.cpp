#include<bits/stdc++.h>
using namespace std;
const int maxn=5010;
int n;
int a[maxn];
long long ans;
void solve1(){
	for(int i=1;i<=n;i++){
		for(int j=i+1;j<=n;j++){
			for(int k=j+1;k<=n;k++){
				if(a[i]+a[j]>a[k])ans++;
			}
		}
	}
}
void solve2(){
	for(int i=1;i<=n;i++){
		for(int j=i+1;j<=n;j++){
			for(int k=j+1;k<=n;k++){
				for(int h=k+1;h<=n;h++){
					if(a[i]+a[j]+a[k]>a[h])ans++;
				}
			}
		}
	}
}
void solve3(){
	for(int i=1;i<=n;i++){
		for(int j=i+1;j<=n;j++){
			for(int k=j+1;k<=n;k++){
				for(int h=k+1;h<=n;h++){
					for(int l=h+1;l<=n;l++){
						if(a[i]+a[j]+a[k]+a[h]>a[l])ans++;
					}
				}
			}
		}
	}
}
void solve4(){
	for(int i=1;i<=n;i++){
		for(int j=i+1;j<=n;j++){
			for(int k=j+1;k<=n;k++){
				for(int h=k+1;h<=n;h++){
					for(int l=h+1;l<=n;l++){
						for(int m=l+1;m<=n;m++){
							if(a[i]+a[j]+a[k]+a[h]+a[l]>a[m])ans++;
						}
					}
				}
			}
		}
	}		
}
void solve5(){
	for(int i=1;i<=n;i++){
		for(int j=i+1;j<=n;j++){
			for(int k=j+1;k<=n;k++){
				for(int h=k+1;h<=n;h++){
					for(int l=h+1;l<=n;l++){
						for(int m=l+1;m<=n;m++){
							for(int u=m+1;u<=n;u++){
								if(a[i]+a[j]+a[k]+a[h]+a[l]+a[m]>a[u])ans++;
							}
						}
					}
				}
			}
		}
	}
}
void solve6(){
	for(int i=1;i<=n;i++){
		for(int j=i+1;j<=n;j++){
			for(int k=j+1;k<=n;k++){
				for(int h=k+1;h<=n;h++){
					for(int l=h+1;l<=n;l++){
						for(int m=l+1;m<=n;m++){
							for(int u=m+1;u<=n;u++){
								for(int v=u+1;v<=n;v++){
									if(a[i]+a[j]+a[k]+a[h]+a[l]+a[m]+a[u]>a[v])ans++;
								}
							}
						}
					}
				}
			}
		}
	}
}
void solve7(){
	for(int i=1;i<=n;i++){
		for(int j=i+1;j<=n;j++){
			for(int k=j+1;k<=n;k++){
				for(int h=k+1;h<=n;h++){
					for(int l=h+1;l<=n;l++){
						for(int m=l+1;m<=n;m++){
							for(int u=m+1;u<=n;u++){
								for(int v=u+1;v<=n;v++){
									for(int w=v+1;w<=n;w++){
										if(a[i]+a[j]+a[k]+a[h]+a[l]+a[m]+a[u]+a[v]>a[w])ans++;
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
void solve8(){
	for(int i=1;i<=n;i++){
		for(int j=i+1;j<=n;j++){
			for(int k=j+1;k<=n;k++){
				for(int h=k+1;h<=n;h++){
					for(int l=h+1;l<=n;l++){
						for(int m=l+1;m<=n;m++){
							for(int u=m+1;u<=n;u++){
								for(int v=u+1;v<=n;v++){
									for(int w=v+1;w<=n;w++){
										for(int x=w+1;x<=n;x++){
											if(a[i]+a[j]+a[k]+a[h]+a[l]+a[m]+a[u]+a[v]+a[w]>a[x])ans++;
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
void solve9(){
	for(int i=1;i<=n;i++){
		for(int j=i+1;j<=n;j++){
			for(int k=j+1;k<=n;k++){
				for(int h=k+1;h<=n;h++){
					for(int l=h+1;l<=n;l++){
						for(int m=l+1;m<=n;m++){
							for(int u=m+1;u<=n;u++){
								for(int v=u+1;v<=n;v++){
									for(int w=v+1;w<=n;w++){
										for(int x=w+1;x<=n;x++){
											for(int y=x+1;y<=n;y++){
												if(a[i]+a[j]+a[k]+a[h]+a[l]+a[m]+a[u]+a[v]+a[w]+a[x]>a[y])ans++;
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
void solve10(){
	for(int i=1;i<=n;i++){
		for(int j=i+1;j<=n;j++){
			for(int k=j+1;k<=n;k++){
				for(int h=k+1;h<=n;h++){
					for(int l=h+1;l<=n;l++){
						for(int m=l+1;m<=n;m++){
							for(int u=m+1;u<=n;u++){
								for(int v=u+1;v<=n;v++){
									for(int w=v+1;w<=n;w++){
										for(int x=w+1;x<=n;x++){
											for(int y=x+1;y<=n;y++){
												for(int z=y+1;z<=n;z++){
													if(a[i]+a[j]+a[k]+a[h]+a[l]+a[m]+a[u]+a[v]+a[w]+a[x]+a[y]>a[z])ans++;
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
void solve11(){
	for(int i=1;i<=n;i++){
		for(int j=i+1;j<=n;j++){
			for(int k=j+1;k<=n;k++){
				for(int h=k+1;h<=n;h++){
					for(int l=h+1;l<=n;l++){
						for(int m=l+1;m<=n;m++){
							for(int u=m+1;u<=n;u++){
								for(int v=u+1;v<=n;v++){
									for(int w=v+1;w<=n;w++){
										for(int x=w+1;x<=n;x++){
											for(int y=x+1;y<=n;y++){
												for(int z=y+1;z<=n;z++){
													for(int o=z+1;o<=n;o++){
														if(a[i]+a[j]+a[k]+a[h]+a[l]+a[m]+a[u]+a[v]+a[w]+a[x]+a[y]+a[z]>a[o])ans++;
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
void solve12(){
	for(int i=1;i<=n;i++){
		for(int j=i+1;j<=n;j++){
			for(int k=j+1;k<=n;k++){
				for(int h=k+1;h<=n;h++){
					for(int l=h+1;l<=n;l++){
						for(int m=l+1;m<=n;m++){
							for(int u=m+1;u<=n;u++){
								for(int v=u+1;v<=n;v++){
									for(int w=v+1;w<=n;w++){
										for(int x=w+1;x<=n;x++){
											for(int y=x+1;y<=n;y++){
												for(int z=y+1;z<=n;z++){
													for(int o=z+1;o<=n;o++){
														for(int p=o+1;p<=n;p++){
															if(a[i]+a[j]+a[k]+a[h]+a[l]+a[m]+a[u]+a[v]+a[w]+a[x]+a[y]+a[z]+a[o]>a[p])ans++;
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
void solve13(){
	for(int i=1;i<=n;i++){
		for(int j=i+1;j<=n;j++){
			for(int k=j+1;k<=n;k++){
				for(int h=k+1;h<=n;h++){
					for(int l=h+1;l<=n;l++){
						for(int m=l+1;m<=n;m++){
							for(int u=m+1;u<=n;u++){
								for(int v=u+1;v<=n;v++){
									for(int w=v+1;w<=n;w++){
										for(int x=w+1;x<=n;x++){
											for(int y=x+1;y<=n;y++){
												for(int z=y+1;z<=n;z++){
													for(int o=z+1;o<=n;o++){
														for(int p=o+1;p<=n;p++){
															for(int q=p+1;q<=n;q++){
																if(a[i]+a[j]+a[k]+a[h]+a[l]+a[m]+a[u]+a[v]+a[w]+a[x]+a[y]+a[z]+a[o]+a[p]>a[q])ans++;
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
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	if(n<=2)cout<<0;
	if(n==3){
		if(a[1]+a[2]>a[3])cout<<1;
		else cout<<0;
	}
	if(n==4){
		solve1();
		solve2();
		cout<<ans;
	}
	if(n==5){
		solve1();
		solve2();
		solve3();
		cout<<ans;
	}
	if(n==6){
		solve1();
		solve2();
		solve3();
		solve4();
		cout<<ans;
	}
	if(n==7){
		solve1();
		solve2();
		solve3();
		solve4();
		solve5();
		cout<<ans;
	}
	if(n==8){
		solve1();
		solve2();
		solve3();
		solve4();
		solve5();
		solve6();
		cout<<ans;
	}
	if(n==9){
		solve1();
		solve2();
		solve3();
		solve4();
		solve5();
		solve6();
		solve7();
		cout<<ans;
	}
	if(n==10){
		solve1();
		solve2();
		solve3();
		solve4();
		solve5();
		solve6();
		solve7();
		solve8();
		cout<<ans;
	}
	if(n==11){
		solve1();
		solve2();
		solve3();
		solve4();
		solve5();
		solve6();
		solve7();
		solve8();
		solve9();
		cout<<ans;
	}
	if(n==12){
		solve1();
		solve2();
		solve3();
		solve4();
		solve5();
		solve6();
		solve7();
		solve8();
		solve9();
		solve10();
		cout<<ans;
	}
	if(n==13){
		solve1();
		solve2();
		solve3();
		solve4();
		solve5();
		solve6();
		solve7();
		solve8();
		solve9();
		solve10();
		solve11();
		cout<<ans;
	}
	if(n==14){
		solve1();
		solve2();
		solve3();
		solve4();
		solve5();
		solve6();
		solve7();
		solve8();
		solve9();
		solve10();
		solve11();
		solve12();
		cout<<ans;
	}
	if(n==15){
		solve1();
		solve2();
		solve3();
		solve4();
		solve5();
		solve6();
		solve7();
		solve8();
		solve9();
		solve10();
		solve11();
		solve12();
		solve13();
		cout<<ans;
	}
	return 0;
}
