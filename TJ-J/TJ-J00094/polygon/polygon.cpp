#include <bits/stdc++.h>
using namespace std;

#define int long long

int n;
int a[5005];
int cnt;

signed main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0); 
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	if(n==3){
		if(a[1]+a[2]+a[3]>2*a[3]) cnt++;
	}
	else if(n==4){
		for(int i=1;i<=n;i++){
			for(int j=i+1;j<=n;j++){
				for(int k=j+1;k<=n;k++){
					if(a[i]+a[j]+a[k]>2*a[k]) cnt++;
				}
			}
		}
		for(int i=1;i<=n;i++){
			for(int j=i+1;j<=n;j++){
				for(int k=j+1;k<=n;k++){
					for(int ii=k+1;ii<=n;ii++){
						if(a[i]+a[j]+a[k]+a[ii]>2*a[ii]) cnt++;
					}
				}
			}
		}
	}
	else if(n==5){
		for(int i=1;i<=n;i++){
			for(int j=i+1;j<=n;j++){
				for(int k=j+1;k<=n;k++){
					if(a[i]+a[j]+a[k]>2*a[k]) cnt++;
				}
			}
		}
		for(int i=1;i<=n;i++){
			for(int j=i+1;j<=n;j++){
				for(int k=j+1;k<=n;k++){
					for(int ii=k+1;ii<=n;ii++){
						if(a[i]+a[j]+a[k]+a[ii]>2*a[ii]) cnt++;
					}
				}
			}
		}
		for(int i=1;i<=n;i++){
			for(int j=i+1;j<=n;j++){
				for(int k=j+1;k<=n;k++){
					for(int ii=k+1;ii<=n;ii++){
						for(int jj=ii+1;jj<=n;jj++){
							if(a[i]+a[j]+a[k]+a[ii]+a[jj]>2*a[jj]) cnt++;
						}
					}
				}
			}
		}
	}
	else if(n==6){
		for(int i=1;i<=n;i++){
			for(int j=i+1;j<=n;j++){
				for(int k=j+1;k<=n;k++){
					if(a[i]+a[j]+a[k]>2*a[k]) cnt++;
				}
			}
		}
		for(int i=1;i<=n;i++){
			for(int j=i+1;j<=n;j++){
				for(int k=j+1;k<=n;k++){
					for(int ii=k+1;ii<=n;ii++){
						if(a[i]+a[j]+a[k]+a[ii]>2*a[ii]) cnt++;
					}
				}
			}
		}
		for(int i=1;i<=n;i++){
			for(int j=i+1;j<=n;j++){
				for(int k=j+1;k<=n;k++){
					for(int ii=k+1;ii<=n;ii++){
						for(int jj=ii+1;jj<=n;jj++){
							if(a[i]+a[j]+a[k]+a[ii]+a[jj]>2*a[jj]) cnt++;
						}
					}
				}
			}
		}
		for(int i=1;i<=n;i++){
			for(int j=i+1;j<=n;j++){
				for(int k=j+1;k<=n;k++){
					for(int ii=k+1;ii<=n;ii++){
						for(int jj=ii+1;jj<=n;jj++){
							for(int kk=jj+1;kk<=n;kk++){
								if(a[i]+a[j]+a[k]+a[ii]+a[jj]+a[kk]>2*a[kk]) cnt++;
							}
						}
					}
				}
			}
		}
	}
	else if(n==7){
		for(int i=1;i<=n;i++){
			for(int j=i+1;j<=n;j++){
				for(int k=j+1;k<=n;k++){
					if(a[i]+a[j]+a[k]>2*a[k]) cnt++;
				}
			}
		}
		for(int i=1;i<=n;i++){
			for(int j=i+1;j<=n;j++){
				for(int k=j+1;k<=n;k++){
					for(int ii=k+1;ii<=n;ii++){
						if(a[i]+a[j]+a[k]+a[ii]>2*a[ii]) cnt++;
					}
				}
			}
		}
		for(int i=1;i<=n;i++){
			for(int j=i+1;j<=n;j++){
				for(int k=j+1;k<=n;k++){
					for(int ii=k+1;ii<=n;ii++){
						for(int jj=ii+1;jj<=n;jj++){
							if(a[i]+a[j]+a[k]+a[ii]+a[jj]>2*a[jj]) cnt++;
						}
					}
				}
			}
		}
		for(int i=1;i<=n;i++){
			for(int j=i+1;j<=n;j++){
				for(int k=j+1;k<=n;k++){
					for(int ii=k+1;ii<=n;ii++){
						for(int jj=ii+1;jj<=n;jj++){
							for(int kk=jj+1;kk<=n;kk++){
								if(a[i]+a[j]+a[k]+a[ii]+a[jj]+a[kk]>2*a[kk]) cnt++;
							}
						}
					}
				}
			}
		}
		for(int i=1;i<=n;i++){
			for(int j=i+1;j<=n;j++){
				for(int k=j+1;k<=n;k++){
					for(int ii=k+1;ii<=n;ii++){
						for(int jj=ii+1;jj<=n;jj++){
							for(int kk=jj+1;kk<=n;kk++){
								for(int iii=kk+1;iii<=n;iii++){
									if(a[i]+a[j]+a[k]+a[ii]+a[jj]+a[kk]+a[iii]>2*a[iii]) cnt++;
								}
							}
						}
					}
				}
			}
		}
	}
	else if(n==8){
		for(int i=1;i<=n;i++){
			for(int j=i+1;j<=n;j++){
				for(int k=j+1;k<=n;k++){
					if(a[i]+a[j]+a[k]>2*a[k]) cnt++;
				}
			}
		}
		for(int i=1;i<=n;i++){
			for(int j=i+1;j<=n;j++){
				for(int k=j+1;k<=n;k++){
					for(int ii=k+1;ii<=n;ii++){
						if(a[i]+a[j]+a[k]+a[ii]>2*a[ii]) cnt++;
					}
				}
			}
		}
		for(int i=1;i<=n;i++){
			for(int j=i+1;j<=n;j++){
				for(int k=j+1;k<=n;k++){
					for(int ii=k+1;ii<=n;ii++){
						for(int jj=ii+1;jj<=n;jj++){
							if(a[i]+a[j]+a[k]+a[ii]+a[jj]>2*a[jj]) cnt++;
						}
					}
				}
			}
		}
		for(int i=1;i<=n;i++){
			for(int j=i+1;j<=n;j++){
				for(int k=j+1;k<=n;k++){
					for(int ii=k+1;ii<=n;ii++){
						for(int jj=ii+1;jj<=n;jj++){
							for(int kk=jj+1;kk<=n;kk++){
								if(a[i]+a[j]+a[k]+a[ii]+a[jj]+a[kk]>2*a[kk]) cnt++;
							}
						}
					}
				}
			}
		}
		for(int i=1;i<=n;i++){
			for(int j=i+1;j<=n;j++){
				for(int k=j+1;k<=n;k++){
					for(int ii=k+1;ii<=n;ii++){
						for(int jj=ii+1;jj<=n;jj++){
							for(int kk=jj+1;kk<=n;kk++){
								for(int iii=kk+1;iii<=n;iii++){
									if(a[i]+a[j]+a[k]+a[ii]+a[jj]+a[kk]+a[iii]>2*a[iii]) cnt++;
								}
							}
						}
					}
				}
			}
		}
		for(int i=1;i<=n;i++){
			for(int j=i+1;j<=n;j++){
				for(int k=j+1;k<=n;k++){
					for(int ii=k+1;ii<=n;ii++){
						for(int jj=ii+1;jj<=n;jj++){
							for(int kk=jj+1;kk<=n;kk++){
								for(int iii=kk+1;iii<=n;iii++){
									for(int jjj=iii+1;jjj<=n;jjj++){
										if(a[i]+a[j]+a[k]+a[ii]+a[jj]+a[kk]+a[iii]+a[jjj]>2*a[jjj]) cnt++;
									}
								}
							}
						}
					}
				}
			}
		}
	}
	else if(n==9){
		for(int i=1;i<=n;i++){
			for(int j=i+1;j<=n;j++){
				for(int k=j+1;k<=n;k++){
					if(a[i]+a[j]+a[k]>2*a[k]) cnt++;
				}
			}
		}
		for(int i=1;i<=n;i++){
			for(int j=i+1;j<=n;j++){
				for(int k=j+1;k<=n;k++){
					for(int ii=k+1;ii<=n;ii++){
						if(a[i]+a[j]+a[k]+a[ii]>2*a[ii]) cnt++;
					}
				}
			}
		}
		for(int i=1;i<=n;i++){
			for(int j=i+1;j<=n;j++){
				for(int k=j+1;k<=n;k++){
					for(int ii=k+1;ii<=n;ii++){
						for(int jj=ii+1;jj<=n;jj++){
							if(a[i]+a[j]+a[k]+a[ii]+a[jj]>2*a[jj]) cnt++;
						}
					}
				}
			}
		}
		for(int i=1;i<=n;i++){
			for(int j=i+1;j<=n;j++){
				for(int k=j+1;k<=n;k++){
					for(int ii=k+1;ii<=n;ii++){
						for(int jj=ii+1;jj<=n;jj++){
							for(int kk=jj+1;kk<=n;kk++){
								if(a[i]+a[j]+a[k]+a[ii]+a[jj]+a[kk]>2*a[kk]) cnt++;
							}
						}
					}
				}
			}
		}
		for(int i=1;i<=n;i++){
			for(int j=i+1;j<=n;j++){
				for(int k=j+1;k<=n;k++){
					for(int ii=k+1;ii<=n;ii++){
						for(int jj=ii+1;jj<=n;jj++){
							for(int kk=jj+1;kk<=n;kk++){
								for(int iii=kk+1;iii<=n;iii++){
									if(a[i]+a[j]+a[k]+a[ii]+a[jj]+a[kk]+a[iii]>2*a[iii]) cnt++;
								}
							}
						}
					}
				}
			}
		}
		for(int i=1;i<=n;i++){
			for(int j=i+1;j<=n;j++){
				for(int k=j+1;k<=n;k++){
					for(int ii=k+1;ii<=n;ii++){
						for(int jj=ii+1;jj<=n;jj++){
							for(int kk=jj+1;kk<=n;kk++){
								for(int iii=kk+1;iii<=n;iii++){
									for(int jjj=iii+1;jjj<=n;jjj++){
										if(a[i]+a[j]+a[k]+a[ii]+a[jj]+a[kk]+a[iii]+a[jjj]>2*a[jjj]) cnt++;
									}
								}
							}
						}
					}
				}
			}
		}
		for(int i=1;i<=n;i++){
			for(int j=i+1;j<=n;j++){
				for(int k=j+1;k<=n;k++){
					for(int ii=k+1;ii<=n;ii++){
						for(int jj=ii+1;jj<=n;jj++){
							for(int kk=jj+1;kk<=n;kk++){
								for(int iii=kk+1;iii<=n;iii++){
									for(int jjj=iii+1;jjj<=n;jjj++){
										for(int kkk=jjj+1;kkk<=n;kkk++){
											if(a[i]+a[j]+a[k]+a[ii]+a[jj]+a[kk]+a[iii]+a[jjj]+a[kkk]>2*a[kkk]) cnt++;
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
	else if(n==10){
		for(int i=1;i<=n;i++){
			for(int j=i+1;j<=n;j++){
				for(int k=j+1;k<=n;k++){
					if(a[i]+a[j]+a[k]>2*a[k]) cnt++;
				}
			}
		}
		for(int i=1;i<=n;i++){
			for(int j=i+1;j<=n;j++){
				for(int k=j+1;k<=n;k++){
					for(int ii=k+1;ii<=n;ii++){
						if(a[i]+a[j]+a[k]+a[ii]>2*a[ii]) cnt++;
					}
				}
			}
		}
		for(int i=1;i<=n;i++){
			for(int j=i+1;j<=n;j++){
				for(int k=j+1;k<=n;k++){
					for(int ii=k+1;ii<=n;ii++){
						for(int jj=ii+1;jj<=n;jj++){
							if(a[i]+a[j]+a[k]+a[ii]+a[jj]>2*a[jj]) cnt++;
						}
					}
				}
			}
		}
		for(int i=1;i<=n;i++){
			for(int j=i+1;j<=n;j++){
				for(int k=j+1;k<=n;k++){
					for(int ii=k+1;ii<=n;ii++){
						for(int jj=ii+1;jj<=n;jj++){
							for(int kk=jj+1;kk<=n;kk++){
								if(a[i]+a[j]+a[k]+a[ii]+a[jj]+a[kk]>2*a[kk]) cnt++;
							}
						}
					}
				}
			}
		}
		for(int i=1;i<=n;i++){
			for(int j=i+1;j<=n;j++){
				for(int k=j+1;k<=n;k++){
					for(int ii=k+1;ii<=n;ii++){
						for(int jj=ii+1;jj<=n;jj++){
							for(int kk=jj+1;kk<=n;kk++){
								for(int iii=kk+1;iii<=n;iii++){
									if(a[i]+a[j]+a[k]+a[ii]+a[jj]+a[kk]+a[iii]>2*a[iii]) cnt++;
								}
							}
						}
					}
				}
			}
		}
		for(int i=1;i<=n;i++){
			for(int j=i+1;j<=n;j++){
				for(int k=j+1;k<=n;k++){
					for(int ii=k+1;ii<=n;ii++){
						for(int jj=ii+1;jj<=n;jj++){
							for(int kk=jj+1;kk<=n;kk++){
								for(int iii=kk+1;iii<=n;iii++){
									for(int jjj=iii+1;jjj<=n;jjj++){
										if(a[i]+a[j]+a[k]+a[ii]+a[jj]+a[kk]+a[iii]+a[jjj]>2*a[jjj]) cnt++;
									}
								}
							}
						}
					}
				}
			}
		}
		for(int i=1;i<=n;i++){
			for(int j=i+1;j<=n;j++){
				for(int k=j+1;k<=n;k++){
					for(int ii=k+1;ii<=n;ii++){
						for(int jj=ii+1;jj<=n;jj++){
							for(int kk=jj+1;kk<=n;kk++){
								for(int iii=kk+1;iii<=n;iii++){
									for(int jjj=iii+1;jjj<=n;jjj++){
										for(int kkk=jjj+1;kkk<=n;kkk++){
											if(a[i]+a[j]+a[k]+a[ii]+a[jj]+a[kk]+a[iii]+a[jjj]+a[kkk]>2*a[kkk]) cnt++;
										}
									}
								}
							}
						}
					}
				}
			}
		}
		for(int i=1;i<=n;i++){
			for(int j=i+1;j<=n;j++){
				for(int k=j+1;k<=n;k++){
					for(int ii=k+1;ii<=n;ii++){
						for(int jj=ii+1;jj<=n;jj++){
							for(int kk=jj+1;kk<=n;kk++){
								for(int iii=kk+1;iii<=n;iii++){
									for(int jjj=iii+1;jjj<=n;jjj++){
										for(int kkk=jjj+1;kkk<=n;kkk++){
											for(int iiii=kkk+1;iiii<=n;iiii++){
												for(int iiii=kkk+1;iiii<=n;iiii++){
													if(a[i]+a[j]+a[k]+a[ii]+a[jj]+a[kk]+a[iii]+a[jjj]+a[kkk]+a[iiii]>2*a[iiii]) cnt++;
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
	cout<<cnt;
	return 0;
}

