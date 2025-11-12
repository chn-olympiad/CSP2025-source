#include <iostream>
using namespace std;
const long long mod = 998244353;
int quick_power(long long a,long long k,long long mod){
	int res = 1 % mod;
	while(k){
		if(k&1) res = (long long)res * a % mod;
		a = (long long) a * a % mod;
		k >>= 1;
	}
	return res;
}
void check_all(int a[],int n,long long & cnt){
	int sum=0;
	int maxn=-1;
	for(int i=0;i<n;i++){
		sum+=a[i];
		maxn = max(maxn,a[i]);
	}
	if(sum>maxn*2){
		cnt++;
	}
}
void check_3(int a[],int n,long long & cnt){
	for(int i=0;i<n-2;i++){
		for(int j=i+1;j<n-1;j++){
			for(int k=j+1;k<n;k++){
				int sum = a[i]+a[j]+a[k];
				int maxn = max(max(a[i],a[j]),max(a[i],a[k]));
				if(sum>maxn*2){
					cnt++;
				}
			}
		}
	}
}
void check_4(int a[],int n,long long & cnt){
	for(int i=0;i<n-3;i++){
		for(int j=i+1;j<n-2;j++){
			for(int k=j+1;k<n-1;k++){
				for(int s=k+1;s<n;s++){
					int sum = a[i]+a[j]+a[k]+a[s];
					int maxn = max(max(a[i],a[j]),max(a[s],a[k]));
					if(sum>maxn*2){
						cnt++;
					}
				}
			}
		}
	}
}
void check_5(int a[],int n,long long & cnt){
	for(int i=0;i<n-4;i++){
		for(int j=i+1;j<n-3;j++){
			for(int k=j+1;k<n-2;k++){
				for(int s=k+1;s<n-1;s++){
					for(int t=s+1;t<n;t++){
						int sum = a[i]+a[j]+a[k]+a[s]+a[t];
						int maxn = max(a[t],max(max(a[i],a[j]),max(a[s],a[k])));
						if(sum>maxn*2){
							cnt++;
						}
					}
				}
			}
		}
	}
}
void check_6(int a[],int n,long long & cnt){
	for(int i=0;i<n-5;i++){
		for(int j=i+1;j<n-4;j++){
			for(int k=j+1;k<n-3;k++){
				for(int s=k+1;s<n-2;s++){
					for(int t=s+1;t<n-1;t++){
						for(int f=t+1;f<n;f++){
							int sum = a[i]+a[j]+a[k]+a[s]+a[t]+a[f];
							int maxn = max(max(a[t],a[f]),max(max(a[i],a[j]),max(a[s],a[k])));
							if(sum>maxn*2){
								cnt++;
							}
						}
					}
				}
			}
		}
	}
}
void check_7(int a[],int n,long long & cnt){
	for(int i=0;i<n-6;i++){
		for(int j=i+1;j<n-5;j++){
			for(int k=j+1;k<n-4;k++){
				for(int s=k+1;s<n-3;s++){
					for(int t=s+1;t<n-2;t++){
						for(int f=t+1;f<n-1;f++){
							for(int w=f+1;w<n;w++){
								int sum = a[i]+a[j]+a[k]+a[s]+a[t]+a[f]+a[w];
								int maxn = max(a[w],max(max(a[t],a[f]),max(max(a[i],a[j]),max(a[s],a[k]))));
								if(sum>maxn*2){
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
void check_8(int a[],int n,long long & cnt){
	for(int i=0;i<n-7;i++){
		for(int j=i+1;j<n-6;j++){
			for(int k=j+1;k<n-5;k++){
				for(int s=k+1;s<n-4;s++){
					for(int t=s+1;t<n-3;t++){
						for(int f=t+1;f<n-2;f++){
							for(int w=f+1;w<n-1;w++){
								for(int r=w+1;r<n;r++){
									int sum = a[i]+a[j]+a[k]+a[s]+a[t]+a[f]+a[w]+a[r];
									int maxn = max(max(a[w],a[r]),max(max(a[t],a[f]),max(max(a[i],a[j]),max(a[s],a[k]))));
									if(sum>maxn*2){
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
void check_9(int a[],int n,long long & cnt){
	for(int i=0;i<n-8;i++){
		for(int j=i+1;j<n-7;j++){
			for(int k=j+1;k<n-6;k++){
				for(int s=k+1;s<n-5;s++){
					for(int t=s+1;t<n-4;t++){
						for(int f=t+1;f<n-3;f++){
							for(int w=f+1;w<n-2;w++){
								for(int r=w+1;r<n-1;r++){
									for(int q=r+1;q<n;q++){
										int sum = a[i]+a[j]+a[k]+a[s]+a[t]+a[f]+a[w]+a[r]+a[q];
										int maxn = max(a[q],max(max(a[w],a[r]),max(max(a[t],a[f]),max(max(a[i],a[j]),max(a[s],a[k])))));
										if(sum>maxn*2){
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
}
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	
	int n;
	cin>>n;
	int a[n+2];
	int flag = 1;
	for(int i=0;i<n;i++){
		cin>>a[i];
		if(a[i]!=1){
			flag = 0;
		}
	}
	long long cnt=0;
	if(n<3){
		cout<<0;
	}
	else if(flag){
		cout<<(quick_power(2,n,mod) - (1+n+n*(n-1)/2)%mod + mod)%mod;
	}
	else if(n==3){
		check_all(a,n,cnt);
		cnt%=mod;
		cout<<cnt;
	}
	else if(n==4){
		check_3(a,n,cnt);
		cnt%=mod;
		check_all(a,n,cnt);
		cnt%=mod;
		cout<<cnt;
	}
	else if(n==5){
		check_3(a,n,cnt);
		cnt%=mod;
		check_4(a,n,cnt);
		cnt%=mod;
		check_all(a,n,cnt);
		cnt%=mod;
		cout<<cnt;
	}
	else if(n==6){
		check_3(a,n,cnt);
		cnt%=mod;
		check_4(a,n,cnt);
		cnt%=mod;
		check_5(a,n,cnt);
		cnt%=mod;
		check_all(a,n,cnt);
		cnt%=mod;
		cout<<cnt;
	}
	else if(n==7){
		check_3(a,n,cnt);
		cnt%=mod;
		check_4(a,n,cnt);
		cnt%=mod;
		check_5(a,n,cnt);
		cnt%=mod;
		check_6(a,n,cnt);
		cnt%=mod;
		check_all(a,n,cnt);
		cnt%=mod;
		cout<<cnt;
	}
	else if(n==8){
		check_3(a,n,cnt);
		cnt%=mod;
		check_4(a,n,cnt);
		cnt%=mod;
		check_5(a,n,cnt);
		cnt%=mod;
		check_6(a,n,cnt);
		cnt%=mod;
		check_7(a,n,cnt);
		cnt%=mod;
		check_all(a,n,cnt);
		cnt%=mod;
		cout<<cnt;
	}
	else if(n==9){
		check_3(a,n,cnt);
		cnt%=mod;
		check_4(a,n,cnt);
		cnt%=mod;
		check_5(a,n,cnt);
		cnt%=mod;
		check_6(a,n,cnt);
		cnt%=mod;
		check_7(a,n,cnt);
		cnt%=mod;
		check_8(a,n,cnt);
		cnt%=mod;
		check_all(a,n,cnt);
		cnt%=mod;
		cout<<cnt;
	}
	else if(n==10){
		check_3(a,n,cnt);
		cnt%=mod;
		check_4(a,n,cnt);
		cnt%=mod;
		check_5(a,n,cnt);
		cnt%=mod;
		check_6(a,n,cnt);
		cnt%=mod;
		check_7(a,n,cnt);
		cnt%=mod;
		check_8(a,n,cnt);
		cnt%=mod;
		check_9(a,n,cnt);
		cnt%=mod;
		check_all(a,n,cnt);
		cnt%=mod;
		cout<<cnt;
	}
	
	return 0;
}
