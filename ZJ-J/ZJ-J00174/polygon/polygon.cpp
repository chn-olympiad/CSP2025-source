#include<bits/stdc++.h>
#define int long long
using namespace std;
int n,a[10],maxx,sum,ans;
signed main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	cin>>n;
	for(int i=1;i<=n;i++) cin>>a[i];
	if(n==3){
		for(int i=1;i<=n;i++){
			for(int j=i+1;j<=n;j++){
				for(int k=j+1;k<=n;k++){
					maxx=max(a[i],max(a[j],a[k]));
					sum=a[i]+a[j]+a[k];
					if(sum>2*maxx) ans++;
				}
			}
		}
	}
	if(n==4){
		for(int i=1;i<=n;i++){
			for(int j=i+1;j<=n;j++){
				for(int k=j+1;k<=n;k++){
					maxx=max(a[i],max(a[j],a[k]));
					sum=a[i]+a[j]+a[k];
					if(sum>2*maxx) ans++;
				}
			}
		}
		maxx=-2e9,sum=0;
		for(int i=1;i<=n;i++){
			for(int j=i+1;j<=n;j++){
				for(int k=j+1;k<=n;k++){
					for(int l=k+1;l<=n;l++){
						maxx=max(a[i],max(a[j],max(a[l],a[k])));
						sum=a[i]+a[j]+a[k]+a[l];
						if(sum>2*maxx) ans++;
					}
				}
			}
		}
	}
	if(n==5){
		for(int i=1;i<=n;i++){
			for(int j=i+1;j<=n;j++){
				for(int k=j+1;k<=n;k++){
					maxx=max(a[i],max(a[j],a[k]));
					sum=a[i]+a[j]+a[k];
					if(sum>2*maxx) ans++;
				}
			}
		}
		maxx=-2e9,sum=0;
		for(int i=1;i<=n;i++){
			for(int j=i+1;j<=n;j++){
				for(int k=j+1;k<=n;k++){
					for(int l=k+1;l<=n;l++){
						maxx=max(a[i],max(a[j],max(a[l],a[k])));
						sum=a[i]+a[j]+a[k]+a[l];
						if(sum>2*maxx) ans++;
					}
				}
			}
		}
		maxx=-2e9,sum=0;
		for(int i=1;i<=n;i++){
			for(int j=i+1;j<=n;j++){
				for(int k=j+1;k<=n;k++){
					for(int l=k+1;l<=n;l++){
						for(int o=l+1;o<=n;o++){
							maxx=max(a[i],max(a[j],max(a[l],max(a[k],a[o]))));
							sum=a[i]+a[j]+a[k]+a[l]+a[o];
							if(sum>2*maxx) ans++;
						}
					}
				}
			}
		}
	}
	if(n==6){
		for(int i=1;i<=n;i++){
			for(int j=i+1;j<=n;j++){
				for(int k=j+1;k<=n;k++){
					maxx=max(a[i],max(a[j],a[k]));
					sum=a[i]+a[j]+a[k];
					if(sum>2*maxx) ans++;
				}
			}
		}
		maxx=-2e9,sum=0;
		for(int i=1;i<=n;i++){
			for(int j=i+1;j<=n;j++){
				for(int k=j+1;k<=n;k++){
					for(int l=k+1;l<=n;l++){
						maxx=max(a[i],max(a[j],max(a[l],a[k])));
						sum=a[i]+a[j]+a[k]+a[l];
						if(sum>2*maxx) ans++;
					}
				}
			}
		}
		maxx=-2e9,sum=0;
		for(int i=1;i<=n;i++){
			for(int j=i+1;j<=n;j++){
				for(int k=j+1;k<=n;k++){
					for(int l=k+1;l<=n;l++){
						for(int o=l+1;o<=n;o++){
							maxx=max(a[i],max(a[j],max(a[l],max(a[k],a[o]))));
							sum=a[i]+a[j]+a[k]+a[l]+a[o];
							if(sum>2*maxx) ans++;
						}
					}
				}
			}
		}
		maxx=-2e9,sum=0;
		for(int i=1;i<=n;i++){
			for(int j=i+1;j<=n;j++){
				for(int k=j+1;k<=n;k++){
					for(int l=k+1;l<=n;l++){
						for(int o=l+1;o<=n;o++){
							for(int p=o+1;p<=n;p++){
								maxx=max(a[i],max(a[j],max(a[l],max(a[k],max(a[o],a[p])))));
								sum=a[i]+a[j]+a[k]+a[l]+a[o]+a[p];
								if(sum>2*maxx) ans++;
							}
						}
					}
				}
			}
		}
	}
	if(n==7){
		for(int i=1;i<=n;i++){
			for(int j=i+1;j<=n;j++){
				for(int k=j+1;k<=n;k++){
					maxx=max(a[i],max(a[j],a[k]));
					sum=a[i]+a[j]+a[k];
					if(sum>2*maxx) ans++;
				}
			}
		}
		maxx=-2e9,sum=0;
		for(int i=1;i<=n;i++){
			for(int j=i+1;j<=n;j++){
				for(int k=j+1;k<=n;k++){
					for(int l=k+1;l<=n;l++){
						maxx=max(a[i],max(a[j],max(a[l],a[k])));
						sum=a[i]+a[j]+a[k]+a[l];
						if(sum>2*maxx) ans++;
					}
				}
			}
		}
		maxx=-2e9,sum=0;
		for(int i=1;i<=n;i++){
			for(int j=i+1;j<=n;j++){
				for(int k=j+1;k<=n;k++){
					for(int l=k+1;l<=n;l++){
						for(int o=l+1;o<=n;o++){
							maxx=max(a[i],max(a[j],max(a[l],max(a[k],a[o]))));
							sum=a[i]+a[j]+a[k]+a[l]+a[o];
							if(sum>2*maxx) ans++;
						}
					}
				}
			}
		}
		maxx=-2e9,sum=0;
		for(int i=1;i<=n;i++){
			for(int j=i+1;j<=n;j++){
				for(int k=j+1;k<=n;k++){
					for(int l=k+1;l<=n;l++){
						for(int o=l+1;o<=n;o++){
							for(int p=o+1;p<=n;p++){
								maxx=max(a[i],max(a[j],max(a[l],max(a[k],max(a[o],a[p])))));
								sum=a[i]+a[j]+a[k]+a[l]+a[o]+a[p];
								if(sum>2*maxx) ans++;
							}
						}
					}
				}
			}
		}
		maxx=-2e9,sum=0;
		for(int i=1;i<=n;i++){
			for(int j=i+1;j<=n;j++){
				for(int k=j+1;k<=n;k++){
					for(int l=k+1;l<=n;l++){
						for(int o=l+1;o<=n;o++){
							for(int p=o+1;p<=n;p++){
								for(int q=p+1;q<=n;q++){
									maxx=max(a[i],max(a[j],max(a[l],max(a[k],max(a[o],max(a[p],a[q]))))));
									sum=a[i]+a[j]+a[k]+a[l]+a[o]+a[p]+a[q];
									if(sum>2*maxx) ans++;
								}
							}
						}
					}
				}
			}
		}
	}
	if(n==8){
		for(int i=1;i<=n;i++){
			for(int j=i+1;j<=n;j++){
				for(int k=j+1;k<=n;k++){
					maxx=max(a[i],max(a[j],a[k]));
					sum=a[i]+a[j]+a[k];
					if(sum>2*maxx) ans++;
				}
			}
		}
		maxx=-2e9,sum=0;
		for(int i=1;i<=n;i++){
			for(int j=i+1;j<=n;j++){
				for(int k=j+1;k<=n;k++){
					for(int l=k+1;l<=n;l++){
						maxx=max(a[i],max(a[j],max(a[l],a[k])));
						sum=a[i]+a[j]+a[k]+a[l];
						if(sum>2*maxx) ans++;
					}
				}
			}
		}
		maxx=-2e9,sum=0;
		for(int i=1;i<=n;i++){
			for(int j=i+1;j<=n;j++){
				for(int k=j+1;k<=n;k++){
					for(int l=k+1;l<=n;l++){
						for(int o=l+1;o<=n;o++){
							maxx=max(a[i],max(a[j],max(a[l],max(a[k],a[o]))));
							sum=a[i]+a[j]+a[k]+a[l]+a[o];
							if(sum>2*maxx) ans++;
						}
					}
				}
			}
		}
		maxx=-2e9,sum=0;
		for(int i=1;i<=n;i++){
			for(int j=i+1;j<=n;j++){
				for(int k=j+1;k<=n;k++){
					for(int l=k+1;l<=n;l++){
						for(int o=l+1;o<=n;o++){
							for(int p=o+1;p<=n;p++){
								maxx=max(a[i],max(a[j],max(a[l],max(a[k],max(a[o],a[p])))));
								sum=a[i]+a[j]+a[k]+a[l]+a[o]+a[p];
								if(sum>2*maxx) ans++;
							}
						}
					}
				}
			}
		}
		maxx=-2e9,sum=0;
		for(int i=1;i<=n;i++){
			for(int j=i+1;j<=n;j++){
				for(int k=j+1;k<=n;k++){
					for(int l=k+1;l<=n;l++){
						for(int o=l+1;o<=n;o++){
							for(int p=o+1;p<=n;p++){
								for(int q=p+1;q<=n;q++){
									maxx=max(a[i],max(a[j],max(a[l],max(a[k],max(a[o],max(a[p],a[q]))))));
									sum=a[i]+a[j]+a[k]+a[l]+a[o]+a[p]+a[q];
									if(sum>2*maxx) ans++;
								}
							}
						}
					}
				}
			}
		}
		maxx=-2e9,sum=0;
		for(int i=1;i<=n;i++){
			for(int j=i+1;j<=n;j++){
				for(int k=j+1;k<=n;k++){
					for(int l=k+1;l<=n;l++){
						for(int o=l+1;o<=n;o++){
							for(int p=o+1;p<=n;p++){
								for(int q=p+1;q<=n;q++){
									for(int r=q+1;r<=n;r++){
										maxx=max(a[i],max(a[j],max(a[l],max(a[k],max(a[o],max(a[p],max(a[q],a[r])))))));
										sum=a[i]+a[j]+a[k]+a[l]+a[o]+a[p]+a[q]+a[r];
										if(sum>2*maxx) ans++;
									}
								}
							}
						}
					}
				}
			}
		}
	}
	cout<<ans;
	return 0;
}
