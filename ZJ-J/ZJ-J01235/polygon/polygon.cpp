#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int N=5e3+5;
const ll mod=998244353;
int n=5000;
int a[N];
int f;
ll sum;
ll g(ll x){
	ll y=1;
	for(ll i=n,j=x;i>=n-x+1;i--,j--){
		y*=i;
//		cout<<y<<endl;
		y%=mod;
	}
	for(ll j=x;j>=1;j--) y/=j;
	return y;
}
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++) cin>>a[i],f+=(a[i]==1);
	if(f==n){
		for(int i=3;i<=n;i++) sum+=g(i)%mod,sum%=mod;
		cout<<sum%mod;
	}
	else if(n<=3){
		if(n==1||n==2) cout<<0;
		else{
			sort(a+1,a+n+1); 
			if(a[1]+a[2]>a[3]) cout<<1;
			else cout<<0;
		}
	}
	else if(n<=20){
		sort(a+1,a+n+1);
		if(3<=n){
			for(int i=n;i>=3;i--){
				for(int j=i-1;j>=2;j--){
					for(int k=j-1;k>=1;k--){
						if(a[j]+a[k]>a[i]) sum++;
					}
				}
			}
		}
		if(4<=n){
			for(int q=n;q>=4;q--){
				for(int i=q-1;i>=3;i--){
					for(int j=i-1;j>=2;j--){
						for(int k=j-1;k>=1;k--){
							if(a[j]+a[k]+a[i]>a[q]) sum++;
							else break;
						}
					}
				}
			}
		}
		if(5<=n){
			for(int q6=n;q6>=5;q6--){
				for(int q=q6-1;q>=4;q--){
					for(int i=q-1;i>=3;i--){
						for(int j=i-1;j>=2;j--){
							for(int k=j-1;k>=1;k--){
								if(a[j]+a[k]+a[i]+a[q]>a[q6]) sum++;
								else break;
							}
						}
					}
				}
			}
		}
		if(6<=n){
			for(int q5=n;q5>=6;q5--){
				for(int q6=q5-1;q6>=5;q6--){
					for(int q=q6-1;q>=4;q--){
						for(int i=q-1;i>=3;i--){
							for(int j=i-1;j>=2;j--){
								for(int k=j-1;k>=1;k--){
									if(a[j]+a[k]+a[i]+a[q]+a[q6]>a[q5]) sum++;
									else break;
								}
							}
						}
					}
				}
			}
		}
		if(7<=n){
			for(int q4=n;q4>=7;q4--){
				for(int q5=q4-1;q5>=6;q5--){
					for(int q6=q5-1;q6>=5;q6--){
						for(int q=q6-1;q>=4;q--){
							for(int i=q-1;i>=3;i--){
								for(int j=i-1;j>=2;j--){
									for(int k=j-1;k>=1;k--){
										if(a[j]+a[k]+a[i]+a[q]+a[q6]+a[q5]>a[q4]) sum++;
										else break;
									}
								}
							}
						}
					}
				}
			}
		}
		if(8<=n){
				for(int q3=n;q3>=8;q3--){
					for(int q4=q3-1;q4>=7;q4--){
						for(int q5=q4-1;q5>=6;q5--){
							for(int q6=q5-1;q6>=5;q6--){
								for(int q=q6-1;q>=4;q--){
									for(int i=q-1;i>=3;i--){
										for(int j=i-1;j>=2;j--){
											for(int k=j-1;k>=1;k--){
												if(a[j]+a[k]+a[i]+a[q]+a[q6]+a[q5]+a[q4]>a[q3]) sum++;
												else break;
											}
										}
									}
								}
							}
						}
					}
				}
		}
		if(9<=n){
			for(int q2=n;q2>=9;q2--){
				for(int q3=q2-1;q3>=8;q3--){
					for(int q4=q3-1;q4>=7;q4--){
						for(int q5=q4-1;q5>=6;q5--){
							for(int q6=q5-1;q6>=5;q6--){
								for(int q=q6-1;q>=4;q--){
									for(int i=q-1;i>=3;i--){
										for(int j=i-1;j>=2;j--){
											for(int k=j-1;k>=1;k--){
												if(a[j]+a[k]+a[i]+a[q3]+a[q4]+a[q5]+a[q6]+a[q]>a[q2]) sum++;
												else break;
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
		if(10<=n){
			for(int q1=n;q1>=10;q1--){
				for(int q2=q1-1;q2>=9;q2--){
					for(int q3=q2-1;q3>=8;q3--){
						for(int q4=q3-1;q4>=7;q4--){
							for(int q5=q4-1;q5>=6;q5--){
								for(int q6=q5-1;q6>=5;q6--){
									for(int q=n;q>=4;q--){
										for(int i=q-1;i>=3;i--){
											for(int j=i-1;j>=2;j--){
												for(int k=j-1;k>=1;k--){
													if(a[j]+a[k]+a[i]+a[q3]+a[q4]+a[q5]+a[q6]+a[q]+a[q2]>a[q1]) sum++;
													else break;
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
		cout<<sum%mod;
	}
	return 0;
} 
