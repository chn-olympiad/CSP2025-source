#include<bits/stdc++.h>
using namespace std;

int n;
int stick[5005];
int maxn;
long long ans;
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	ios::sync_with_stdio(false);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>stick[i];
		maxn=max(maxn,stick[i]);
	}
	
	if(n<3){
		cout<<0;
		return 0;
	}
	if(n==3){
		int num=stick[1]+stick[2]+stick[3];
		if(num>maxn*2)cout<<1;
		else cout<<0;
		return 0;
	}
	if(maxn==1){
		ans=1;
		for(int i=1;i<=n;i++){
			ans*=2;
			ans%=998244353;
		}
		long long cnt=n*(n-1)/2%998244353;
		ans=ans-1-cnt-n;
		cout<<ans;
	}
	
	else{
		for(int i=1;i<=n-2;i++){
			for(int j=i+1;j<=n-1;j++){
				for(int k=j+1;k<=n;k++){
					long long num=stick[i]+stick[j]+stick[k];
					if(num>stick[k]*2)ans++;
				}
			}
		}
		for(int i=1;i<=n-3;i++){
			for(int j=i+1;j<=n-2;j++){
				for(int k=j+1;k<=n-1;k++){
					for(int p=k+1;p<=n;p++){
						long long num=stick[i]+stick[j]+stick[k]+stick[p];
						if(num>stick[p]*2)ans++;
					}
				}
			}
		}
		if(n==4){
			cout<<ans;return 0;
		}
		for(int i=1;i<=n-4;i++){
			for(int j=i+1;j<=n-3;j++){
				for(int k=j+1;k<=n-2;k++){
					for(int p=k+1;p<=n-1;p++){
						for(int q=p+1;q<=n;q++){
							long long num=stick[i]+stick[j]+stick[k]+stick[p]+stick[q];
							if(num>stick[q]*2)ans++;
						}
					}
				}
			}
		}
		if(n==5){
			cout<<ans;return 0;
		}
		
		for(int i=1;i<=n-5;i++){
			for(int j=i+1;j<=n-4;j++){
				for(int k=j+1;k<=n-3;k++){
					for(int p=k+1;p<=n-2;p++){
						for(int q=p+1;q<=n-1;q++){
							for(int u=q+1;u<=n;u++){
								long long num=stick[i]+stick[j]+stick[k]+stick[p]+stick[q];
								num+=stick[u];
								if(num>stick[u]*2)ans++;
							}
						}
					}
				}
			}
		}
		if(n==6){
			cout<<ans;return 0;
		}
		
		for(int i=1;i<=n-6;i++){
			for(int j=i+1;j<=n-5;j++){
				for(int k=j+1;k<=n-4;k++){
					for(int p=k+1;p<=n-3;p++){
						for(int q=p+1;q<=n-2;q++){
							for(int u=q+1;u<=n-1;u++){
								for(int v=u+1;v<=n;v++){
									long long num=stick[i]+stick[j]+stick[k]+stick[p]+stick[q];
									num+=stick[u]+stick[v];
									if(num>stick[v]*2)ans++;
								}
								
							}
						}
					}
				}
			}
		}
		if(n==7){
			cout<<ans%998244353;
			return 0;
		}
		
		for(int i=1;i<=n-7;i++){
			for(int j=i+1;j<=n-6;j++){
				for(int k=j+1;k<=n-5;k++){
					for(int p=k+1;p<=n-4;p++){
						for(int q=p+1;q<=n-3;q++){
							for(int u=q+1;u<=n-2;u++){
								for(int v=u+1;v<=n-1;v++){
									for(int w=v+1;w<=n;w++){
										long long num=stick[i]+stick[j]+stick[k]+stick[p]+stick[q];
										num+=stick[u]+stick[v]+stick[w];
										if(num>stick[w]*2)ans++;
									}
								}
								
							}
						}
					}
				}
			}
		}
		if(n==8){
			cout<<ans%998244353;return 0;
		}
		for(int i=1;i<=n-8;i++){
			for(int j=i+1;j<=n-7;j++){
				for(int k=j+1;k<=n-6;k++){
					for(int p=k+1;p<=n-5;p++){
						for(int q=p+1;q<=n-4;q++){
							for(int u=q+1;u<=n-3;u++){
								for(int v=u+1;v<=n-2;v++){
									for(int w=v+1;w<=n-1;w++){
										for(int e=w+1;e<=n;e++){
											long long num=stick[i]+stick[j]+stick[k]+stick[p]+stick[q];
											num+=stick[u]+stick[v]+stick[w]+stick[e];
											if(num>stick[e]*2)ans++;
										}
									}
								}
								
							}
						}
					}
				}
			}
		}
		if(n==9){
			cout<<ans%998244353;return 0;
		}
		for(int i=1;i<=n-9;i++){
			for(int j=i+1;j<=n-8;j++){
				for(int k=j+1;k<=n-7;k++){
					for(int p=k+1;p<=n-6;p++){
						for(int q=p+1;q<=n-5;q++){
							for(int u=q+1;u<=n-4;u++){
								for(int v=u+1;v<=n-3;v++){
									for(int w=v+1;w<=n-2;w++){
										for(int e=w+1;e<=n-1;e++){
											for(int r=e+1;r<=n;r++){
												long long num=stick[i]+stick[j]+stick[k]+stick[p]+stick[q];
												num+=stick[u]+stick[v]+stick[w]+stick[e]+stick[r];
												if(num>stick[r]*2)ans++;
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
		if(n==10){
			cout<<ans%998244353;return 0;
		}
		for(int i=1;i<=n-10;i++){
			for(int j=i+1;j<=n-9;j++){
				for(int k=j+1;k<=n-8;k++){
					for(int p=k+1;p<=n-7;p++){
						for(int q=p+1;q<=n-6;q++){
							for(int u=q+1;u<=n-5;u++){
								for(int v=u+1;v<=n-4;v++){
									for(int w=v+1;w<=n-3;w++){
										for(int e=w+1;e<=n-2;e++){
											for(int r=e+1;r<=n-1;r++){
												for(int t=r+1;t<=n;t++){
													long long num=stick[i]+stick[j]+stick[k]+stick[p]+stick[q];
													num+=stick[u]+stick[v]+stick[w]+stick[e]+stick[r]+stick[t];
													if(num>stick[t]*2)ans++;
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
		if(n==11){
			cout<<ans%998244353;return 0;
		}
		for(int i=1;i<=n-11;i++){
			for(int j=i+1;j<=n-10;j++){
				for(int k=j+1;k<=n-9;k++){
					for(int p=k+1;p<=n-8;p++){
						for(int q=p+1;q<=n-7;q++){
							for(int u=q+1;u<=n-6;u++){
								for(int v=u+1;v<=n-5;v++){
									for(int w=v+1;w<=n-4;w++){
										for(int e=w+1;e<=n-3;e++){
											for(int r=e+1;r<=n-2;r++){
												for(int t=r+1;t<=n-1;t++){
													for(int y=t+1;y<=n;y++){
														long long num=stick[i]+stick[j]+stick[k]+stick[p]+stick[q];
														num+=stick[u]+stick[v]+stick[w]+stick[e]+stick[r]+stick[t];
														num+=stick[y];
														if(num>stick[y]*2)ans++;
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
		if(n==12){
			cout<<ans%998244353;return 0;
		}
		for(int i=1;i<=n-12;i++){
			for(int j=i+1;j<=n-11;j++){
				for(int k=j+1;k<=n-10;k++){
					for(int p=k+1;p<=n-9;p++){
						for(int q=p+1;q<=n-8;q++){
							for(int u=q+1;u<=n-7;u++){
								for(int v=u+1;v<=n-6;v++){
									for(int w=v+1;w<=n-5;w++){
										for(int e=w+1;e<=n-4;e++){
											for(int r=e+1;r<=n-3;r++){
												for(int t=r+1;t<=n-2;t++){
													for(int y=t+1;y<=n-1;y++){
														for(int s=y+1;s<=n;s++){
															long long num=stick[i]+stick[j]+stick[k]+stick[p]+stick[q];
															num+=stick[u]+stick[v]+stick[w]+stick[e]+stick[r]+stick[t];
															num+=stick[y]+stick[s];
															if(num>stick[s]*2)ans++;
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
		if(n==13){
			cout<<ans%998244353;return 0;
		}
		for(int i=1;i<=n-13;i++){
			for(int j=i+1;j<=n-12;j++){
				for(int k=j+1;k<=n-11;k++){
					for(int p=k+1;p<=n-10;p++){
						for(int q=p+1;q<=n-9;q++){
							for(int u=q+1;u<=n-8;u++){
								for(int v=u+1;v<=n-7;v++){
									for(int w=v+1;w<=n-6;w++){
										for(int e=w+1;e<=n-5;e++){
											for(int r=e+1;r<=n-4;r++){
												for(int t=r+1;t<=n-3;t++){
													for(int y=t+1;y<=n-2;y++){
														for(int s=y+1;s<=n-1;s++){
															for(int d=s+1;d<=n;d++){
																long long num=stick[i]+stick[j]+stick[k]+stick[p]+stick[q];
																num+=stick[u]+stick[v]+stick[w]+stick[e]+stick[r]+stick[t];
																num+=stick[y]+stick[s]+stick[d];
																if(num>stick[d]*2)ans++;
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
		if(n==14){
			cout<<ans%998244353;return 0;
		}
		for(int i=1;i<=n-14;i++){
			for(int j=i+1;j<=n-13;j++){
				for(int k=j+1;k<=n-12;k++){
					for(int p=k+1;p<=n-11;p++){
						for(int q=p+1;q<=n-10;q++){
							for(int u=q+1;u<=n-9;u++){
								for(int v=u+1;v<=n-8;v++){
									for(int w=v+1;w<=n-7;w++){
										for(int e=w+1;e<=n-6;e++){
											for(int r=e+1;r<=n-5;r++){
												for(int t=r+1;t<=n-4;t++){
													for(int y=t+1;y<=n-3;y++){
														for(int s=y+1;s<=n-2;s++){
															for(int d=y+1;d<=n-1;d++){
																for(int g=d+1;g<=n;g++){
																	long long num=stick[i]+stick[j]+stick[k]+stick[p]+stick[q];
																	num+=stick[u]+stick[v]+stick[w]+stick[e]+stick[r]+stick[t];
																	num+=stick[y]+stick[s]+stick[d]+stick[g];
																	if(num>stick[g]*2)ans++;
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
		if(n==15){
			cout<<ans%998244353;return 0;
		}
		for(int i=1;i<=n-15;i++){
			for(int j=i+1;j<=n-14;j++){
				for(int k=j+1;k<=n-13;k++){
					for(int p=k+1;p<=n-12;p++){
						for(int q=p+1;q<=n-11;q++){
							for(int u=q+1;u<=n-10;u++){
								for(int v=u+1;v<=n-9;v++){
									for(int w=v+1;w<=n-8;w++){
										for(int e=w+1;e<=n-7;e++){
											for(int r=e+1;r<=n-6;r++){
												for(int t=r+1;t<=n-5;t++){
													for(int y=t+1;y<=n-4;y++){
														for(int s=y+1;s<=n-3;s++){
															for(int d=y+1;d<=n-2;d++){
																for(int g=d+1;g<=n-1;g++){
																	for(int h=g+1;h<=n;h++){
																		long long num=stick[i]+stick[j]+stick[k]+stick[p]+stick[q];
																		num+=stick[u]+stick[v]+stick[w]+stick[e]+stick[r]+stick[t];
																		num+=stick[y]+stick[s]+stick[d]+stick[g]+stick[h];
																		if(num>stick[h]*2)ans++;
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
		if(n==16){
			cout<<ans%998244353;return 0;
		}
		for(int i=1;i<=n-16;i++){
			for(int j=i+1;j<=n-15;j++){
				for(int k=j+1;k<=n-14;k++){
					for(int p=k+1;p<=n-13;p++){
						for(int q=p+1;q<=n-12;q++){
							for(int u=q+1;u<=n-11;u++){
								for(int v=u+1;v<=n-10;v++){
									for(int w=v+1;w<=n-9;w++){
										for(int e=w+1;e<=n-8;e++){
											for(int r=e+1;r<=n-7;r++){
												for(int t=r+1;t<=n-6;t++){
													for(int y=t+1;y<=n-5;y++){
														for(int s=y+1;s<=n-4;s++){
															for(int d=y+1;d<=n-3;d++){
																for(int g=d+1;g<=n-2;g++){
																	for(int h=g+1;h<=n-1;h++){
																		for(int l=h+1;l<=n;l++){
																			long long num=stick[i]+stick[j]+stick[k]+stick[p]+stick[q];
																			num+=stick[u]+stick[v]+stick[w]+stick[e]+stick[r]+stick[t];
																			num+=stick[y]+stick[s]+stick[d]+stick[g]+stick[h]+stick[l];
																			if(num>stick[l]*2)ans++;
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
		if(n==17){
			cout<<ans%998244353;return 0;
		}
		for(int i=1;i<=n-17;i++){
			for(int j=i+1;j<=n-16;j++){
				for(int k=j+1;k<=n-15;k++){
					for(int p=k+1;p<=n-14;p++){
						for(int q=p+1;q<=n-13;q++){
							for(int u=q+1;u<=n-12;u++){
								for(int v=u+1;v<=n-11;v++){
									for(int w=v+1;w<=n-10;w++){
										for(int e=w+1;e<=n-9;e++){
											for(int r=e+1;r<=n-8;r++){
												for(int t=r+1;t<=n-7;t++){
													for(int y=t+1;y<=n-6;y++){
														for(int s=y+1;s<=n-5;s++){
															for(int d=y+1;d<=n-4;d++){
																for(int g=d+1;g<=n-3;g++){
																	for(int h=g+1;h<=n-2;h++){
																		for(int l=h+1;l<=n-1;l++){
																			for(int z=l+1;z<=n;z++){
																				long long num=stick[i]+stick[j]+stick[k]+stick[p]+stick[q];
																				num+=stick[u]+stick[v]+stick[w]+stick[e]+stick[r]+stick[t];
																				num+=stick[y]+stick[s]+stick[d]+stick[g]+stick[h]+stick[l];
																				num+=stick[z];
																				if(num>stick[z]*2)ans++;
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
		if(n==18){
			cout<<ans%998244353;return 0;
		}
		for(int i=1;i<=n-18;i++){
			for(int j=i+1;j<=n-17;j++){
				for(int k=j+1;k<=n-16;k++){
					for(int p=k+1;p<=n-15;p++){
						for(int q=p+1;q<=n-14;q++){
							for(int u=q+1;u<=n-13;u++){
								for(int v=u+1;v<=n-12;v++){
									for(int w=v+1;w<=n-11;w++){
										for(int e=w+1;e<=n-10;e++){
											for(int r=e+1;r<=n-9;r++){
												for(int t=r+1;t<=n-8;t++){
													for(int y=t+1;y<=n-7;y++){
														for(int s=y+1;s<=n-6;s++){
															for(int d=y+1;d<=n-5;d++){
																for(int g=d+1;g<=n-4;g++){
																	for(int h=g+1;h<=n-3;h++){
																		for(int l=h+1;l<=n-2;l++){
																			for(int z=l+1;z<=n-1;z++){
																				for(int ab=z+1;ab<=n;ab++){
																					long long num=stick[i]+stick[j]+stick[k]+stick[p]+stick[q];
																					num+=stick[u]+stick[v]+stick[w]+stick[e]+stick[r]+stick[t];
																					num+=stick[y]+stick[s]+stick[d]+stick[g]+stick[h]+stick[l];
																					num+=stick[z]+stick[ab];
																					if(num>stick[ab]*2)ans++;
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
		if(n==19){
			cout<<ans%998244353;return 0;
		}
		for(int i=1;i<=n-19;i++){
			for(int j=i+1;j<=n-18;j++){
				for(int k=j+1;k<=n-17;k++){
					for(int p=k+1;p<=n-16;p++){
						for(int q=p+1;q<=n-15;q++){
							for(int u=q+1;u<=n-14;u++){
								for(int v=u+1;v<=n-13;v++){
									for(int w=v+1;w<=n-12;w++){
										for(int e=w+1;e<=n-11;e++){
											for(int r=e+1;r<=n-10;r++){
												for(int t=r+1;t<=n-9;t++){
													for(int y=t+1;y<=n-8;y++){
														for(int s=y+1;s<=n-7;s++){
															for(int d=y+1;d<=n-6;d++){
																for(int g=d+1;g<=n-5;g++){
																	for(int h=g+1;h<=n-4;h++){
																		for(int l=h+1;l<=n-3;l++){
																			for(int z=l+1;z<=n-2;z++){
																				for(int ab=z+1;ab<=n-1;ab++){
																					for(int abc=ab+1;abc<=n;abc++){
																					long long num=stick[i]+stick[j]+stick[k]+stick[p]+stick[q];
																					num+=stick[u]+stick[v]+stick[w]+stick[e]+stick[r]+stick[t];
																					num+=stick[y]+stick[s]+stick[d]+stick[g]+stick[h]+stick[l];
																					num+=stick[z]+stick[ab]+stick[abc];
																					if(num>stick[abc]*2)ans++;
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
		if(n==20){
			cout<<ans%998244353;return 0;
		}
	}
	return 0;
}
		
		
		
	