#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	int n;
	cin>>n;
	int a[5005];
	
	for(int i=1;i<=n;i++){
		cin>>a[i];
		
	}
	sort(a+1,a+1+n);
	
	if(n==3){
		int sum=0,maxa=0;
		for(int i=1;i<=n;i++){
			sum+=a[i];
			maxa=max(maxa,a[i]);
		}
		if(sum>(maxa*2)) cout<<1;
		else cout<<0;
		return 0;
	}
	int ans=0;
	for(int len=3;len<=n;len++){
		if(len==3){
			for(int i=1;i<=n-2;i++){
				for(int j=i+1;j<=n-1;j++){
					for(int k=j+1;k<=n;k++){
						int sum=a[i]+a[j]+a[k];
						int maxa=a[i];
						maxa=max(maxa,a[j]);
						maxa=max(maxa,a[k]);
						if(sum>(maxa*2)) ans++;
					}
				}
			}
		}
		if(len==4){
			for(int i=1;i<=n-3;i++){
				for(int j=i+1;j<=n-2;j++){
					for(int k=j+1;k<=n-1;k++){
						for(int l=k+1;l<=n;l++){
							int sum=a[i]+a[j]+a[k]+a[l];
							int maxa=a[i];
							maxa=max(maxa,a[j]);
							maxa=max(maxa,a[k]);
							maxa=max(maxa,a[l]);
							if(sum>(maxa*2)) ans++;
						}
					}
				}
			}
		}		
		if(len==5){
			for(int i=1;i<=n-4;i++){
				for(int j=i+1;j<=n-3;j++){
					for(int k=j+1;k<=n-2;k++){
						for(int l=k+1;l<=n-1;l++){
							for(int q=l+1;q<=n;q++){
								int sum=a[i]+a[j]+a[k]+a[l]+a[q];
								int maxa=a[i];
								maxa=max(maxa,a[j]);
								maxa=max(maxa,a[k]);
								maxa=max(maxa,a[l]);
								maxa=max(maxa,a[q]);
								if(sum>(maxa*2)) ans++;
							}
						}
					}
				}
			}
		}
		if(len==6){
			for(int i=1;i<=n-5;i++){
				for(int j=i+1;j<=n-4;j++){
					for(int k=j+1;k<=n-3;k++){
						for(int l=k+1;l<=n-2;l++){
							for(int q=l+1;q<=n-1;q++){
								for(int w=q+1;w<=n;w++){
									int sum=a[i]+a[j]+a[k]+a[l]+a[q]+a[w];
									int maxa=a[i];
									maxa=max(maxa,a[j]);
									maxa=max(maxa,a[k]);
									maxa=max(maxa,a[l]);
									maxa=max(maxa,a[q]);
									maxa=max(maxa,a[w]);
									if(sum>(maxa*2)) ans++;
								}
							}
						}
					}
				}
			}
		}
		if(len==7){
			for(int i=1;i<=n-6;i++){
				for(int j=i+1;j<=n-5;j++){
					for(int k=j+1;k<=n-4;k++){
						for(int l=k+1;l<=n-3;l++){
							for(int q=l+1;q<=n-2;q++){
								for(int w=q+1;w<=n-1;w++){
									for(int e=w+1;e<=n;e++){
										int sum=a[i]+a[j]+a[k]+a[l]+a[q]+a[w]+a[e];
										int maxa=a[i];
										maxa=max(maxa,a[j]);
										maxa=max(maxa,a[k]);
										maxa=max(maxa,a[l]);
										maxa=max(maxa,a[q]);
										maxa=max(maxa,a[w]);
										maxa=max(maxa,a[e]);
										if(sum>(maxa*2)) ans++;
									}
								}
							}
						}
					}
				}
			}
		}
		if(len==8){
			for(int i=1;i<=n-7;i++){
				for(int j=i+1;j<=n-6;j++){
					for(int k=j+1;k<=n-5;k++){
						for(int l=k+1;l<=n-4;l++){
							for(int q=l+1;q<=n-3;q++){
								for(int w=q+1;w<=n-2;w++){
									for(int e=w+1;e<=n-1;e++){
										for(int r=e+1;r<=n;r++){
											int sum=a[i]+a[j]+a[k]+a[l]+a[q]+a[w]+a[e]+a[r];
											int maxa=a[i];
											maxa=max(maxa,a[j]);
											maxa=max(maxa,a[k]);
											maxa=max(maxa,a[l]);
											maxa=max(maxa,a[q]);
											maxa=max(maxa,a[w]);
											maxa=max(maxa,a[e]);
											maxa=max(maxa,a[r]);
											if(sum>(maxa*2)) ans++;
										}
									}
								}
							}
						}
					}
				}
			}
		}
		if(len==9){
			for(int i=1;i<=n-8;i++){
				for(int j=i+1;j<=n-7;j++){
					for(int k=j+1;k<=n-6;k++){
						for(int l=k+1;l<=n-5;l++){
							for(int q=l+1;q<=n-4;q++){
								for(int w=q+1;w<=n-3;w++){
									for(int e=w+1;e<=n-2;e++){
										for(int r=e+1;r<=n-1;r++){
											for(int t=r+1;t<=n;t++){
												int sum=a[i]+a[j]+a[k]+a[l]+a[q]+a[w]+a[e]+a[r]+a[t];
												int maxa=a[i];
												maxa=max(maxa,a[j]);
												maxa=max(maxa,a[k]);
												maxa=max(maxa,a[l]);
												maxa=max(maxa,a[q]);
												maxa=max(maxa,a[w]);
												maxa=max(maxa,a[e]);
												maxa=max(maxa,a[r]);
												maxa=max(maxa,a[t]);
												if(sum>(maxa*2)) ans++;
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
		if(len==10){
			for(int i=1;i<=n-9;i++){
				for(int j=i+1;j<=n-8;j++){
					for(int k=j+1;k<=n-7;k++){
						for(int l=k+1;l<=n-6;l++){
							for(int q=l+1;q<=n-5;q++){
								for(int w=q+1;w<=n-4;w++){
									for(int e=w+1;e<=n-3;e++){
										for(int r=e+1;r<=n-2;r++){
											for(int t=r+1;t<=n-1;t++){
												for(int x=t+1;x<=n;x++){
													int sum=a[i]+a[j]+a[k]+a[l]+a[q]+a[w]+a[e]+a[r]+a[t]+a[x];
													int maxa=a[i];
													maxa=max(maxa,a[j]);
													maxa=max(maxa,a[k]);
													maxa=max(maxa,a[l]);
													maxa=max(maxa,a[q]);
													maxa=max(maxa,a[w]);
													maxa=max(maxa,a[e]);
													maxa=max(maxa,a[r]);
													maxa=max(maxa,a[t]);
													maxa=max(maxa,a[x]);
													if(sum>(maxa*2)) ans++;
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
	cout<<ans%998244353<<endl;
}
