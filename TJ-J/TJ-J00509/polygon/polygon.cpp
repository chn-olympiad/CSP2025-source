#include<bits/stdc++.h>
using namespace std;
int a[6008];

int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	int n,sum=0;
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a,a+n+1);
	if(n<3){
		cout<<0;
	}else if(n==3){
		if(a[1]+a[2]>a[3]){
			cout<<1;
		}else{
			cout<<0;
		}
	}else{
		if(n<=10){
			for(int i=1;i<=10;i++){
				for(int j=i+1;j<=10;j++){
					for(int ii=j+1;ii<=10;ii++){
						if(a[i]+a[j]>a[ii]){
							sum++;
						}
					}
				}
			}
			for(int i=1;i<=10;i++){
				for(int j=i+1;j<=10;j++){
					for(int ii=j+1;ii<=10;ii++){
						for(int jj=ii+1;jj<=10;jj++){
							if(a[i]+a[j]+a[ii]>a[jj]){
								sum++;
							}
						}
					}
				}
			}
			for(int i=1;i<=10;i++){
				for(int j=i+1;j<=10;j++){
					for(int ii=j+1;ii<=10;ii++){
						for(int jj=ii+1;jj<=10;jj++){
							for(int iii=jj+1;iii<=10;iii++){
								if(a[i]+a[j]+a[ii]+a[jj]>a[iii]){
									sum++;
								}
							}
						}
					}
				}
			}
			for(int i=1;i<=10;i++){
				for(int j=i+1;j<=10;j++){
					for(int ii=j+1;ii<=10;ii++){
						for(int jj=ii+1;jj<=10;jj++){
							for(int iii=jj+1;iii<=10;iii++){
								for(int jjj=iii+1;jjj<=10;jjj++){
									if(a[i]+a[j]+a[ii]+a[jj]+a[iii]>a[jjj]){
										sum++;
									}
								}
							}
						}
					}
				}
			}
			for(int i=1;i<=10;i++){
				for(int j=i+1;j<=10;j++){
					for(int ii=j+1;ii<=10;ii++){
						for(int jj=ii+1;jj<=10;jj++){
							for(int iii=jj+1;iii<=10;iii++){
								for(int jjj=iii+1;jjj<=10;jjj++){
									for(int iiii=jjj+1;iiii<=10;iiii++){
										if(a[i]+a[j]+a[ii]+a[jj]+a[iii]+a[jjj]>a[iiii]){
											sum++;
										}
									}
								}
							}
						}
					}
				}
			}
			for(int i=1;i<=10;i++){
				for(int j=i+1;j<=10;j++){
					for(int ii=j+1;ii<=10;ii++){
						for(int jj=ii+1;jj<=10;jj++){
							for(int iii=jj+1;iii<=10;iii++){
								for(int jjj=iii+1;jjj<=10;jjj++){
									for(int iiii=jjj+1;iiii<=10;iiii++){
										for(int jjjj=iiii+1;jjjj<=10;jjjj++){
											if(a[i]+a[j]+a[ii]+a[jj]+a[iii]+a[jjj]+a[iiii]>a[jjjj]){
												sum++;
											}
										}
									}
								}
							}
						}
					}
				}
			}
			for(int i=1;i<=10;i++){
				for(int j=i+1;j<=10;j++){
					for(int ii=j+1;ii<=10;ii++){
						for(int jj=ii+1;jj<=10;jj++){
							for(int iii=jj+1;iii<=10;iii++){
								for(int jjj=iii+1;jjj<=10;jjj++){
									for(int iiii=jjj+1;iiii<=10;iiii++){
										for(int jjjj=iiii+1;jjjj<=10;jjjj++){
											for(int iiiii=jjjj+1;iiiii<=10;iiiii++){
												if(a[i]+a[j]+a[ii]+a[jj]+a[iii]+a[jjj]+a[iiii]+a[jjjj]>a[iiiii]){
													sum++;
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
			if(a[1]+a[2]+a[3]+a[4]+a[5]+a[6]+a[7]+a[8]+a[9]>a[10]){
				sum++;
			}
			cout<<sum;
		}
	}
	return 0;
}
