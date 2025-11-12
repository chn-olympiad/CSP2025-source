#include<iostream>
using namespace std;
int n,m;
string s;
int c[505];
long long ans;
int p[505];
bool pd(){
	int zou=0;
	int lu=0;
	for(int i=1;i<=n;i++){
		if(lu>=m){
			return 1;
		}
		if(s[i-1]=='1'&&zou<p[i]){
			lu++;
		}else{
			zou++;
		}
	}
	return 0;
}
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m;
	cin>>s;
	bool knn=1;
	for(int i=1;i<=n;i++){
		cin>>c[i];
		if(c[i]!=0){
			knn=0;
		}
	}
	if(knn){
		cout<<0<<endl;
		return 0;
	}
	bool kn=1;
	for(int i=0;i<n;i++){
		if(s[i]=='1'){
			kn=0;
		}
	}
	if(kn){
		cout<<0<<endl;
		return 0;
	}
	if(n==m){
		for(int i=0;i<n;i++){
			if(s[i]=='0'){
				cout<<"0"<<endl;
				return 0;
			}
		}
		for(int i=1;i<=n;i++){
			if(c[i]==0){
				cout<<"0"<<endl;
				return 0;
			}
		}
		cout<<"1"<<endl;
	}else if(m==1){
		//cerr<<"2Y"<<endl;
		int mins;
		int num=0;
		ans=1;
		for(int i=0;i<n;i++){
			if(s[i]=='1'){
				mins=i;
				break;
			}
		}
		for(int i=1;i<=n;i++){
			if(c[i]>mins){
				num++;
			}
		}
		//cerr<<num<<" "<<mins<<endl;
		if(num==0){
			cout<<"0"<<endl;
			return 0;
		}
		for(int i=2;i<n;i++){
			cerr<<ans<<endl;
			ans*=i;
			ans=ans%998244353;
		}
		ans=(ans*num)%998244353;
		cout<<ans<<endl;
		return 0;
	}else if(n==1){
		cout<<"1"<<endl;
		return 0;
	}else if(n==2){
		for(int i=1;i<=n;i++){
			for(int ii=1;ii<=n;ii++){
				ans=ans%998244353;
					int zou=0;
					int lu=0;
					int zb;
					for(int j=1;j<=n;j++){
						if(lu>=m){
							ans++;
						}
						if(s[j-1]=='1'){
							if(j==1){
								zb=i;
							}else if(j==2){
								zb=ii;
							}
							if(c[zb]<=zou){
								zou++;
							}else{
								lu++;
							}
						}else{
							zou++;
						}
					}
			}
		}
		cout<<ans<<endl;
		return 0;
	}else if(n==3){
		for(int i=1;i<=n;i++){
			for(int ii=1;ii<=n;ii++){
				ans=ans%998244353;
				for(int iii=1;iii<=n;iii++){
					int zou=0;
					int lu=0;
					int zb;
					for(int j=1;j<=n;j++){
						if(lu>=m){
							ans++;
						}
						if(s[j-1]=='1'){
							if(j==1){
								zb=i;
							}else if(j==2){
								zb=ii;
							}else if(j==3){
								zb=iii;
							}
							if(c[zb]<=zou){
								zou++;
							}else{
								lu++;
							}
						}else{
							zou++;
						}
					}
				}
			}
		}
		cout<<ans<<endl;
		return 0;
	}else if(n==4){
		for(int i=1;i<=n;i++){
			for(int ii=1;ii<=n;ii++){
				ans=ans%998244353;
				for(int iii=1;iii<=n;iii++){
					for(int iiii=1;iiii<=n;iiii++){
							int zou=0;
														int lu=0;
														int zb;
														for(int j=1;j<=n;j++){
															if(lu>=m){
																ans++;
															}
															if(s[j-1]=='1'){
																if(j==1){
																	zb=i;
																}else if(j==2){
																	zb=ii;
																}else if(j==3){
																	zb=iii;
																}else if(j==4){
																	zb=iiii;
																}
																if(c[zb]<=zou){
																	zou++;
																}else{
																	lu++;
																}
															}else{
																zou++;
															}
														}
					}
				}
			}
		}
		cout<<ans<<endl;
		return 0;
	}else if(n==5){
		for(int i=1;i<=n;i++){
			for(int ii=1;ii<=n;ii++){
				ans=ans%998244353;
				for(int iii=1;iii<=n;iii++){
					for(int iiii=1;iiii<=n;iiii++){
						for(int iiiii=1;iiiii<=n;iiiii++){
							int zou=0;
														int lu=0;
														int zb;
														for(int j=1;j<=n;j++){
															if(lu>=m){
																ans++;
															}
															if(s[j-1]=='1'){
																if(j==1){
																	zb=i;
																}else if(j==2){
																	zb=ii;
																}else if(j==3){
																	zb=iii;
																}else if(j==4){
																	zb=iiii;
																}else if(j==5){
																	zb=iiiii;
																}
																if(c[zb]<=zou){
																	zou++;
																}else{
																	lu++;
																}
															}else{
																zou++;
															}
														}
						}
					}
				}
			}
		}
		cout<<ans<<endl;
		return 0;
	}else if(n==6){
		for(int i=1;i<=n;i++){
			for(int ii=1;ii<=n;ii++){
				ans=ans%998244353;
				for(int iii=1;iii<=n;iii++){
					for(int iiii=1;iiii<=n;iiii++){
						for(int iiiii=1;iiiii<=n;iiiii++){
							for(int iiiiii=1;iiiiii<=n;iiiiii++){
								int zou=0;
														int lu=0;
														int zb;
														for(int j=1;j<=n;j++){
															if(lu>=m){
																ans++;
															}
															if(s[j-1]=='1'){
																if(j==1){
																	zb=i;
																}else if(j==2){
																	zb=ii;
																}else if(j==3){
																	zb=iii;
																}else if(j==4){
																	zb=iiii;
																}else if(j==5){
																	zb=iiiii;
																}else if(j==6){
																	zb=iiiiii;
																}
																if(c[zb]<=zou){
																	zou++;
																}else{
																	lu++;
																}
															}else{
																zou++;
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
	}else if(n==7){
		for(int i=1;i<=n;i++){
			for(int ii=1;ii<=n;ii++){
				ans=ans%998244353;
				for(int iii=1;iii<=n;iii++){
					for(int iiii=1;iiii<=n;iiii++){
						for(int iiiii=1;iiiii<=n;iiiii++){
							for(int iiiiii=1;iiiiii<=n;iiiiii++){
								for(int iiiiiii=1;iiiiiii<=n;iiiiiii++){
									int zou=0;
														int lu=0;
														int zb;
														for(int j=1;j<=n;j++){
															if(lu>=m){
																ans++;
															}
															if(s[j-1]=='1'){
																if(j==1){
																	zb=i;
																}else if(j==2){
																	zb=ii;
																}else if(j==3){
																	zb=iii;
																}else if(j==4){
																	zb=iiii;
																}else if(j==5){
																	zb=iiiii;
																}else if(j==6){
																	zb=iiiiii;
																}else if(j==7){
																	zb=iiiiiii;
																}
																if(c[zb]<=zou){
																	zou++;
																}else{
																	lu++;
																}
															}else{
																zou++;
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
	}else if(n==8){
		for(int i=1;i<=n;i++){
			for(int ii=1;ii<=n;ii++){
				ans=ans%998244353;
				for(int iii=1;iii<=n;iii++){
					for(int iiii=1;iiii<=n;iiii++){
						for(int iiiii=1;iiiii<=n;iiiii++){
							for(int iiiiii=1;iiiiii<=n;iiiiii++){
								for(int iiiiiii=1;iiiiiii<=n;iiiiiii++){
									for(int iiiiiiii=1;iiiiiiii<=n;iiiiiiii++){
										int zou=0;
										int lu=0;
										int zb;
										for(int j=1;j<=n;j++){
											if(lu>=m){
												ans++;
											}
											if(s[j-1]=='1'){
												if(j==1){
													zb=i;
												}else if(j==2){
													zb=ii;
												}else if(j==3){
													zb=iii;
												}else if(j==4){
													zb=iiii;
												}else if(j==5){
													zb=iiiii;
												}else if(j==6){
													zb=iiiiii;
												}else if(j==7){
													zb=iiiiiii;
												}else if(j==8){
													zb=iiiiiiii;
												}
												if(c[zb]<=zou){
													zou++;
												}else{
													lu++;
												}
											}else{
												zou++;
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
	}else if(n==9){
		for(int i=1;i<=n;i++){
			for(int ii=1;ii<=n;ii++){
				ans=ans%998244353;
				for(int iii=1;iii<=n;iii++){
					for(int iiii=1;iiii<=n;iiii++){
						for(int iiiii=1;iiiii<=n;iiiii++){
							for(int iiiiii=1;iiiiii<=n;iiiiii++){
								for(int iiiiiii=1;iiiiiii<=n;iiiiiii++){
									for(int iiiiiiii=1;iiiiiiii<=n;iiiiiiii++){
										for(int iiiiiiiii=1;iiiiiiiii<=n;iiiiiiiii++){int zou=0;
														int lu=0;
														int zb;
														for(int j=1;j<=n;j++){
															if(lu>=m){
																ans++;
															}
															if(s[j-1]=='1'){
																if(j==1){
																	zb=i;
																}else if(j==2){
																	zb=ii;
																}else if(j==3){
																	zb=iii;
																}else if(j==4){
																	zb=iiii;
																}else if(j==5){
																	zb=iiiii;
																}else if(j==6){
																	zb=iiiiii;
																}else if(j==7){
																	zb=iiiiiii;
																}else if(j==8){
																	zb=iiiiiiii;
																}else if(j==9){
																	zb=iiiiiiiii;
																}
																if(c[zb]<=zou){
																	zou++;
																}else{
																	lu++;
																}
															}else{
																zou++;
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
	}else if(n==10){
		for(int i=1;i<=n;i++){
			for(int ii=1;ii<=n;ii++){
				ans=ans%998244353;
				for(int iii=1;iii<=n;iii++){
					for(int iiii=1;iiii<=n;iiii++){
						for(int iiiii=1;iiiii<=n;iiiii++){
							for(int iiiiii=1;iiiiii<=n;iiiiii++){
								for(int iiiiiii=1;iiiiiii<=n;iiiiiii++){
									for(int iiiiiiii=1;iiiiiiii<=n;iiiiiiii++){
										for(int iiiiiiiii=1;iiiiiiiii<=n;iiiiiiiii++){
											for(int iiiiiiiiii=1;iiiiiiiiii<=n;iiiiiiiiii++){
												int zou=0;
														int lu=0;
														int zb;
														for(int j=1;j<=n;j++){
															if(lu>=m){
																ans++;
															}
															if(s[j-1]=='1'){
																if(j==1){
																	zb=i;
																}else if(j==2){
																	zb=ii;
																}else if(j==3){
																	zb=iii;
																}else if(j==4){
																	zb=iiii;
																}else if(j==5){
																	zb=iiiii;
																}else if(j==6){
																	zb=iiiiii;
																}else if(j==7){
																	zb=iiiiiii;
																}else if(j==8){
																	zb=iiiiiiii;
																}else if(j==9){
																	zb=iiiiiiiii;
																}else if(j==10){
																	zb=iiiiiiiiii;
																}
																if(c[zb]<=zou){
																	zou++;
																}else{
																	lu++;
																}
															}else{
																zou++;
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
	}else if(n==11){
		for(int i=1;i<=n;i++){
			for(int ii=1;ii<=n;ii++){
				ans=ans%998244353;
				for(int iii=1;iii<=n;iii++){
					for(int iiii=1;iiii<=n;iiii++){
						for(int iiiii=1;iiiii<=n;iiiii++){
							for(int iiiiii=1;iiiiii<=n;iiiiii++){
								for(int iiiiiii=1;iiiiiii<=n;iiiiiii++){
									for(int iiiiiiii=1;iiiiiiii<=n;iiiiiiii++){
										for(int iiiiiiiii=1;iiiiiiiii<=n;iiiiiiiii++){
											for(int iiiiiiiiii=1;iiiiiiiiii<=n;iiiiiiiiii++){
												for(int iiiiiiiiiii=1;iiiiiiiiiii<=n;iiiiiiiiiii++){
														int zou=0;
														int lu=0;
														int zb;
														for(int j=1;j<=n;j++){
															if(lu>=m){
																ans++;
															}
															if(s[j-1]=='1'){
																if(j==1){
																	zb=i;
																}else if(j==2){
																	zb=ii;
																}else if(j==3){
																	zb=iii;
																}else if(j==4){
																	zb=iiii;
																}else if(j==5){
																	zb=iiiii;
																}else if(j==6){
																	zb=iiiiii;
																}else if(j==7){
																	zb=iiiiiii;
																}else if(j==8){
																	zb=iiiiiiii;
																}else if(j==9){
																	zb=iiiiiiiii;
																}else if(j==10){
																	zb=iiiiiiiiii;
																}else if(j==11){
																	zb=iiiiiiiiiii;
																}
																if(c[zb]<=zou){
																	zou++;
																}else{
																	lu++;
																}
															}else{
																zou++;
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
	}else if(n==12){
		for(int i=1;i<=n;i++){
			for(int ii=1;ii<=n;ii++){
				ans=ans%998244353;
				for(int iii=1;iii<=n;iii++){
					for(int iiii=1;iiii<=n;iiii++){
						for(int iiiii=1;iiiii<=n;iiiii++){
							for(int iiiiii=1;iiiiii<=n;iiiiii++){
								for(int iiiiiii=1;iiiiiii<=n;iiiiiii++){
									for(int iiiiiiii=1;iiiiiiii<=n;iiiiiiii++){
										for(int iiiiiiiii=1;iiiiiiiii<=n;iiiiiiiii++){
											for(int iiiiiiiiii=1;iiiiiiiiii<=n;iiiiiiiiii++){
												for(int iiiiiiiiiii=1;iiiiiiiiiii<=n;iiiiiiiiiii++){
													for(int iiiiiiiiiiii=1;iiiiiiiiiiii<=n;iiiiiiiiiiii++){
														int zou=0;
														int lu=0;
														int zb;
														for(int j=1;j<=n;j++){
															if(lu>=m){
																ans++;
															}
															if(s[j-1]=='1'){
																if(j==1){
																	zb=i;
																}else if(j==2){
																	zb=ii;
																}else if(j==3){
																	zb=iii;
																}else if(j==4){
																	zb=iiii;
																}else if(j==5){
																	zb=iiiii;
																}else if(j==6){
																	zb=iiiiii;
																}else if(j==7){
																	zb=iiiiiii;
																}else if(j==8){
																	zb=iiiiiiii;
																}else if(j==9){
																	zb=iiiiiiiii;
																}else if(j==10){
																	zb=iiiiiiiiii;
																}else if(j==11){
																	zb=iiiiiiiiiii;
																}else{
																	zb=iiiiiiiiiiii;
																}
																if(c[zb]<=zou){
																	zou++;
																}else{
																	lu++;
																}
															}else{
																zou++;
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
	cout<<"0"<<endl;
	return 0;
}
