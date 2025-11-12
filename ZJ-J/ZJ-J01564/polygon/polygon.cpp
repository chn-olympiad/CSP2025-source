#include <bits/stdc++.h>
using namespace std;

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);

	int n;
	cin>>n;
	int a[n];
	bool f=1;
	for(int i=0;i<n;i++){
		cin>>a[i];
		if(a[i]!=1){
			f=0;
		}
	}
	sort(a,a+n);
	if(f){
		int t0=1,cnt=0,n1=n;
		int t1=1;
		for(int i=3;i<=n;i++){
			t0=1,t1=1,n1=n;
			for(int j=1;j<=i;j++){
				t0*=n1;
				n1--;
			}
			for(int j=1;j<=i;j++){
				t1*=j;
			}
			cnt+=(t0/t1);
		}
		cout<<cnt;
	}else{
		if(n<=2){
			cout<<"0";
		}else if(n==3){
			int cnt=0;
			if(a[0]+a[1]>a[2]){
				cnt++;
			}
			cout<<cnt;
		}else if(n==4){
			int cnt=0;
			for(int i=0;i<n;i++){
				for(int j=i+1;j<n;j++){
					for(int k=j+1;k<n;k++){
						if(a[i]+a[j]>a[k]){
							cnt++;
						}
					}
				}
			}
			if(a[0]+a[1]+a[2]>a[3]){
				cnt++;
			}
			cout<<cnt;
		}else if(n==5){
			int cnt=0;
			for(int i=0;i<n;i++){
				for(int j=i+1;j<n;j++){
					for(int k=j+1;k<n;k++){
						if(a[i]+a[j]>a[k]){
							cnt++;
						}
					}
				}
			}
			for(int i=0;i<n;i++){
				for(int j=i+1;j<n;j++){
					for(int k=j+1;k<n;k++){
						for(int l=k+1;l<n;l++){
							if(a[i]+a[j]+a[k]>a[l]){
								cnt++;
							}
						}
					}
				}
			}
			if(a[0]+a[1]+a[2]+a[3]>a[4]){
				cnt++;
			}
			cout<<cnt;
		}else if(n==6){
			int cnt=0;
			for(int i=0;i<n;i++){
				for(int j=i+1;j<n;j++){
					for(int k=j+1;k<n;k++){
						if(a[i]+a[j]>a[k]){
							cnt++;
						}
					}
				}
			}
			for(int i=0;i<n;i++){
				for(int j=i+1;j<n;j++){
					for(int k=j+1;k<n;k++){
						for(int l=k+1;l<n;l++){
							if(a[i]+a[j]+a[k]>a[l]){
								cnt++;
							}
						}
					}
				}
			}
			for(int i=0;i<n;i++){
				for(int j=i+1;j<n;j++){
					for(int k=j+1;k<n;k++){
						for(int l=k+1;l<n;l++){
							for(int m=l+1;m<n;m++){
								if(a[i]+a[j]+a[k]+a[l]>a[m]){
									cnt++;
								}
							}
						}
					}
				}
			}
			if(a[0]+a[1]+a[2]+a[3]+a[4]>a[5]){
				cnt++;
			}
			cout<<cnt;
		}else if(n==7){
			int cnt=0;
			for(int i=0;i<n;i++){
				for(int j=i+1;j<n;j++){
					for(int k=j+1;k<n;k++){
						if(a[i]+a[j]>a[k]){
							cnt++;
						}
					}
				}
			}
			for(int i=0;i<n;i++){
				for(int j=i+1;j<n;j++){
					for(int k=j+1;k<n;k++){
						for(int l=k+1;l<n;l++){
							if(a[i]+a[j]+a[k]>a[l]){
								cnt++;
							}
						}
					}
				}
			}
			for(int i=0;i<n;i++){
				for(int j=i+1;j<n;j++){
					for(int k=j+1;k<n;k++){
						for(int l=k+1;l<n;l++){
							for(int m=l+1;m<n;m++){
								if(a[i]+a[j]+a[k]+a[l]>a[m]){
									cnt++;
								}
							}
						}
					}
				}
			}
			for(int i=0;i<n;i++){
				for(int j=i+1;j<n;j++){
					for(int k=j+1;k<n;k++){
						for(int l=k+1;l<n;l++){
							for(int m=l+1;m<n;m++){
								for(int o=m+1;o<n;o++){
									if(a[i]+a[j]+a[k]+a[l]+a[m]>a[o]){
										cnt++;
									}
								}
							}
						}
					}
				}
			}
			if(a[0]+a[1]+a[2]+a[3]+a[4]+a[5]>a[6]){
				cnt++;
			}
			cout<<cnt;
		}else if(n==8){
			int cnt=0;
			for(int i=0;i<n;i++){
				for(int j=i+1;j<n;j++){
					for(int k=j+1;k<n;k++){
						if(a[i]+a[j]>a[k]){
							cnt++;
						}
					}
				}
			}
			for(int i=0;i<n;i++){
				for(int j=i+1;j<n;j++){
					for(int k=j+1;k<n;k++){
						for(int l=k+1;l<n;l++){
							if(a[i]+a[j]+a[k]>a[l]){
								cnt++;
							}
						}
					}
				}
			}
			for(int i=0;i<n;i++){
				for(int j=i+1;j<n;j++){
					for(int k=j+1;k<n;k++){
						for(int l=k+1;l<n;l++){
							for(int m=l+1;m<n;m++){
								if(a[i]+a[j]+a[k]+a[l]>a[m]){
									cnt++;
								}
							}
						}
					}
				}
			}
			for(int i=0;i<n;i++){
				for(int j=i+1;j<n;j++){
					for(int k=j+1;k<n;k++){
						for(int l=k+1;l<n;l++){
							for(int m=l+1;m<n;m++){
								for(int o=m+1;o<n;o++){
									if(a[i]+a[j]+a[k]+a[l]+a[m]>a[o]){
										cnt++;
									}
								}
							}
						}
					}
				}
			}
			for(int i=0;i<n;i++){
				for(int j=i+1;j<n;j++){
					for(int k=j+1;k<n;k++){
						for(int l=k+1;l<n;l++){
							for(int m=l+1;m<n;m++){
								for(int o=m+1;o<n;o++){
									for(int p=o+1;p<n;p++){
										if(a[i]+a[j]+a[k]+a[l]+a[m]+a[o]>a[p]){
											cnt++;
										}
									}
								}
							}
						}
					}
				}
			}
			if(a[0]+a[1]+a[2]+a[3]+a[4]+a[5]+a[6]>a[7]){
				cnt++;
			}
			cout<<cnt;
		}else if(n==9){
			int cnt=0;
			for(int i=0;i<n;i++){
				for(int j=i+1;j<n;j++){
					for(int k=j+1;k<n;k++){
						if(a[i]+a[j]>a[k]){
							cnt++;
						}
					}
				}
			}
			for(int i=0;i<n;i++){
				for(int j=i+1;j<n;j++){
					for(int k=j+1;k<n;k++){
						for(int l=k+1;l<n;l++){
							if(a[i]+a[j]+a[k]>a[l]){
								cnt++;
							}
						}
					}
				}
			}
			for(int i=0;i<n;i++){
				for(int j=i+1;j<n;j++){
					for(int k=j+1;k<n;k++){
						for(int l=k+1;l<n;l++){
							for(int m=l+1;m<n;m++){
								if(a[i]+a[j]+a[k]+a[l]>a[m]){
									cnt++;
								}
							}
						}
					}
				}
			}
			for(int i=0;i<n;i++){
				for(int j=i+1;j<n;j++){
					for(int k=j+1;k<n;k++){
						for(int l=k+1;l<n;l++){
							for(int m=l+1;m<n;m++){
								for(int o=m+1;o<n;o++){
									if(a[i]+a[j]+a[k]+a[l]+a[m]>a[o]){
										cnt++;
									}
								}
							}
						}
					}
				}
			}
			for(int i=0;i<n;i++){
				for(int j=i+1;j<n;j++){
					for(int k=j+1;k<n;k++){
						for(int l=k+1;l<n;l++){
							for(int m=l+1;m<n;m++){
								for(int o=m+1;o<n;o++){
									for(int p=o+1;p<n;p++){
										if(a[i]+a[j]+a[k]+a[l]+a[m]+a[o]>a[p]){
											cnt++;
										}
									}
								}
							}
						}
					}
				}
			}
			for(int i=0;i<n;i++){
				for(int j=i+1;j<n;j++){
					for(int k=j+1;k<n;k++){
						for(int l=k+1;l<n;l++){
							for(int m=l+1;m<n;m++){
								for(int o=m+1;o<n;o++){
									for(int p=o+1;p<n;p++){
										for(int q=p+1;q<n;q++){
											if(a[i]+a[j]+a[k]+a[l]+a[m]+a[o]+a[p]>a[q]){
												cnt++;
											}
										}
									}
								}
							}
						}
					}
				}
			}
			if(a[0]+a[1]+a[2]+a[3]+a[4]+a[5]+a[6]+a[7]>a[8]){
				cnt++;
			}
			cout<<cnt;
		}else if(n==10){
			int cnt=0;
			for(int i=0;i<n;i++){
				for(int j=i+1;j<n;j++){
					for(int k=j+1;k<n;k++){
						if(a[i]+a[j]>a[k]){
							cnt++;
						}
					}
				}
			}
			for(int i=0;i<n;i++){
				for(int j=i+1;j<n;j++){
					for(int k=j+1;k<n;k++){
						for(int l=k+1;l<n;l++){
							if(a[i]+a[j]+a[k]>a[l]){
								cnt++;
							}
						}
					}
				}
			}
			for(int i=0;i<n;i++){
				for(int j=i+1;j<n;j++){
					for(int k=j+1;k<n;k++){
						for(int l=k+1;l<n;l++){
							for(int m=l+1;m<n;m++){
								if(a[i]+a[j]+a[k]+a[l]>a[m]){
									cnt++;
								}
							}
						}
					}
				}
			}
			for(int i=0;i<n;i++){
				for(int j=i+1;j<n;j++){
					for(int k=j+1;k<n;k++){
						for(int l=k+1;l<n;l++){
							for(int m=l+1;m<n;m++){
								for(int o=m+1;o<n;o++){
									if(a[i]+a[j]+a[k]+a[l]+a[m]>a[o]){
										cnt++;
									}
								}
							}
						}
					}
				}
			}
			for(int i=0;i<n;i++){
				for(int j=i+1;j<n;j++){
					for(int k=j+1;k<n;k++){
						for(int l=k+1;l<n;l++){
							for(int m=l+1;m<n;m++){
								for(int o=m+1;o<n;o++){
									for(int p=o+1;p<n;p++){
										if(a[i]+a[j]+a[k]+a[l]+a[m]+a[o]>a[p]){
											cnt++;
										}
									}
								}
							}
						}
					}
				}
			}
			for(int i=0;i<n;i++){
				for(int j=i+1;j<n;j++){
					for(int k=j+1;k<n;k++){
						for(int l=k+1;l<n;l++){
							for(int m=l+1;m<n;m++){
								for(int o=m+1;o<n;o++){
									for(int p=o+1;p<n;p++){
										for(int q=p+1;q<n;q++){
											if(a[i]+a[j]+a[k]+a[l]+a[m]+a[o]+a[p]>a[q]){
												cnt++;
											}
										}
									}
								}
							}
						}
					}
				}
			}
			for(int i=0;i<n;i++){
				for(int j=i+1;j<n;j++){
					for(int k=j+1;k<n;k++){
						for(int l=k+1;l<n;l++){
							for(int m=l+1;m<n;m++){
								for(int o=m+1;o<n;o++){
									for(int p=o+1;p<n;p++){
										for(int q=p+1;q<n;q++){
											for(int r=q+1;r<n;r++){
												if(a[i]+a[j]+a[k]+a[l]+a[m]+a[o]+a[p]+a[q]>a[r]){
													cnt++;
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
			if(a[0]+a[1]+a[2]+a[3]+a[4]+a[5]+a[6]+a[7]+a[8]>a[9]){
				cnt++;
			}
			cout<<cnt;
		}
	}
	
	return 0;
} 
