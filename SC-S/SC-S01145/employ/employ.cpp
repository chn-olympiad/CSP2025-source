#include<bits/stdc++.h>
using namespace std;
const long long eps=998244353;
int n,m,s[505],c[505];
long long f[505][505],ans,vis[20],bai,kkk;
char sss;
inline bool check(){
	bai=0;
	kkk=0;
	for(int i=1;i<=n;i++){
		kkk+=vis[i];
	}
	if(kkk<m){
		return false;
	}
	kkk=0;
	for(int i=1;i<=n;i++){
		if(vis[i]==1){
			if(bai<c[i]&&s[i]!=0){
				kkk++;
			}
			else{
				bai++;
			}
		}
			
	}
	if(kkk<m){
		return false;
	}
	return true;
}
int main(){
	cin.tie(0);
	cout.tie(0);
	ios::sync_with_stdio(false);
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>sss;
		s[i]=sss-'0';
	}
	for(int i=1;i<=n;i++){
		cin>>c[i];
	}
	sort(c+1,c+1+n);
	if(n<=18){
		if(n==1){
			for(int i1=0;i1<=1;i1++){
				vis[1]=i1;
				if(check()){
					ans++;
				}
			}
		}
		else if(n==2){
			for(int i1=0;i1<=1;i1++){
				vis[1]=i1;
				for(int i2=0;i2<=1;i2++){
					vis[2]=i2;
					if(check()){
						ans++;
					}
				}
			}
		}
		else if(n==3){
			for(int i1=0;i1<=1;i1++){
				vis[1]=i1;
				for(int i2=0;i2<=1;i2++){
					vis[2]=i2;
					for(int i3=0;i3<=1;i3++){
						vis[3]=i3;
						if(check()){
							ans++;
						}
					}
				}
			}
		}
		else if(n==4){
			for(int i1=0;i1<=1;i1++){
				vis[1]=i1;
				for(int i2=0;i2<=1;i2++){
					vis[2]=i2;
					for(int i3=0;i3<=1;i3++){
						vis[3]=i3;
						for(int i4=0;i4<=1;i4++){
							vis[4]=i4;
							if(check()){
								ans++;
							}
						}
					}
				}
			}
		}
		else if(n==5){
			for(int i1=0;i1<=1;i1++){
				vis[1]=i1;
				for(int i2=0;i2<=1;i2++){
					vis[2]=i2;
					for(int i3=0;i3<=1;i3++){
						vis[3]=i3;
						for(int i4=0;i4<=1;i4++){
							vis[4]=i4;
							for(int i5=0;i5<=1;i5++){
								vis[5]=i5;
								if(check()){
									ans++;
								}
							}
						}
					}
				}
			}
		}
		else if(n==6){
			for(int i1=0;i1<=1;i1++){
				vis[1]=i1;
				for(int i2=0;i2<=1;i2++){
					vis[2]=i2;
					for(int i3=0;i3<=1;i3++){
						vis[3]=i3;
						for(int i4=0;i4<=1;i4++){
							vis[4]=i4;
							for(int i5=0;i5<=1;i5++){
								vis[5]=i5;
								for(int i6=0;i6<=1;i6++){
									vis[6]=i6;
									if(check()){
										ans++;
									}
								}
							}
						}
					}
				}
			}
		}
		else if(n==7){
			for(int i1=0;i1<=1;i1++){
				vis[1]=i1;
				for(int i2=0;i2<=1;i2++){
					vis[2]=i2;
					for(int i3=0;i3<=1;i3++){
						vis[3]=i3;
						for(int i4=0;i4<=1;i4++){
							vis[4]=i4;
							for(int i5=0;i5<=1;i5++){
								vis[5]=i5;
								for(int i6=0;i6<=1;i6++){
									vis[6]=i6;
									for(int i7=0;i7<=1;i7++){
										vis[7]=i7;
										if(check()){
											ans++;
										}
									}
								}
							}
						}
					}
				}
			}
		}
		else if(n==8){
			for(int i1=0;i1<=1;i1++){
				vis[1]=i1;
				for(int i2=0;i2<=1;i2++){
					vis[2]=i2;
					for(int i3=0;i3<=1;i3++){
						vis[3]=i3;
						for(int i4=0;i4<=1;i4++){
							vis[4]=i4;
							for(int i5=0;i5<=1;i5++){
								vis[5]=i5;
								for(int i6=0;i6<=1;i6++){
									vis[6]=i6;
									for(int i7=0;i7<=1;i7++){
										vis[7]=i7;
										for(int i8=0;i8<=1;i8++){
											vis[8]=i8;
											if(check()){
												ans++;
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
		else if(n==9){
			for(int i1=0;i1<=1;i1++){
				vis[1]=i1;
				for(int i2=0;i2<=1;i2++){
					vis[2]=i2;
					for(int i3=0;i3<=1;i3++){
						vis[3]=i3;
						for(int i4=0;i4<=1;i4++){
							vis[4]=i4;
							for(int i5=0;i5<=1;i5++){
								vis[5]=i5;
								for(int i6=0;i6<=1;i6++){
									vis[6]=i6;
									for(int i7=0;i7<=1;i7++){
										vis[7]=i7;
										for(int i8=0;i8<=1;i8++){
											vis[8]=i8;
											for(int i9=0;i9<=1;i9++){
												vis[9]=i9;
												if(check()){
													ans++;
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
		else if(n==10){
			for(int i1=0;i1<=1;i1++){
				vis[1]=i1;
				for(int i2=0;i2<=1;i2++){
					vis[2]=i2;
					for(int i3=0;i3<=1;i3++){
						vis[3]=i3;
						for(int i4=0;i4<=1;i4++){
							vis[4]=i4;
							for(int i5=0;i5<=1;i5++){
								vis[5]=i5;
								for(int i6=0;i6<=1;i6++){
									vis[6]=i6;
									for(int i7=0;i7<=1;i7++){
										vis[7]=i7;
										for(int i8=0;i8<=1;i8++){
											vis[8]=i8;
											for(int i9=0;i9<=1;i9++){
												vis[9]=i9;
												for(int i10=0;i10<=1;i10++){
													vis[10]=i10;
													if(check()){
														ans++;
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
		else if(n==11){
			for(int i1=0;i1<=1;i1++){
				vis[1]=i1;
				for(int i2=0;i2<=1;i2++){
					vis[2]=i2;
					for(int i3=0;i3<=1;i3++){
						vis[3]=i3;
						for(int i4=0;i4<=1;i4++){
							vis[4]=i4;
							for(int i5=0;i5<=1;i5++){
								vis[5]=i5;
								for(int i6=0;i6<=1;i6++){
									vis[6]=i6;
									for(int i7=0;i7<=1;i7++){
										vis[7]=i7;
										for(int i8=0;i8<=1;i8++){
											vis[8]=i8;
											for(int i9=0;i9<=1;i9++){
												vis[9]=i9;
												for(int i10=0;i10<=1;i10++){
													vis[10]=i10;
													for(int i11=0;i11<=1;i11++){
														vis[11]=i11;
														if(check()){
															ans++;
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
		else if(n==12){
			for(int i1=0;i1<=1;i1++){
				vis[1]=i1;
				for(int i2=0;i2<=1;i2++){
					vis[2]=i2;
					for(int i3=0;i3<=1;i3++){
						vis[3]=i3;
						for(int i4=0;i4<=1;i4++){
							vis[4]=i4;
							for(int i5=0;i5<=1;i5++){
								vis[5]=i5;
								for(int i6=0;i6<=1;i6++){
									vis[6]=i6;
									for(int i7=0;i7<=1;i7++){
										vis[7]=i7;
										for(int i8=0;i8<=1;i8++){
											vis[8]=i8;
											for(int i9=0;i9<=1;i9++){
												vis[9]=i9;
												for(int i10=0;i10<=1;i10++){
													vis[10]=i10;
													for(int i11=0;i11<=1;i11++){
														vis[11]=i11;
														for(int i12=0;i12<=1;i12++){
															vis[12]=i12;
															if(check()){
																ans++;
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
		else if(n==13){
			for(int i1=0;i1<=1;i1++){
				vis[1]=i1;
				for(int i2=0;i2<=1;i2++){
					vis[2]=i2;
					for(int i3=0;i3<=1;i3++){
						vis[3]=i3;
						for(int i4=0;i4<=1;i4++){
							vis[4]=i4;
							for(int i5=0;i5<=1;i5++){
								vis[5]=i5;
								for(int i6=0;i6<=1;i6++){
									vis[6]=i6;
									for(int i7=0;i7<=1;i7++){
										vis[7]=i7;
										for(int i8=0;i8<=1;i8++){
											vis[8]=i8;
											for(int i9=0;i9<=1;i9++){
												vis[9]=i9;
												for(int i10=0;i10<=1;i10++){
													vis[10]=i10;
													for(int i11=0;i11<=1;i11++){
														vis[11]=i11;
														for(int i12=0;i12<=1;i12++){
															vis[12]=i12;
															for(int i13=0;i13<=1;i13++){
																vis[13]=i13;
																if(check()){
																	ans++;
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
		else if(n==14){
			for(int i1=0;i1<=1;i1++){
				vis[1]=i1;
				for(int i2=0;i2<=1;i2++){
					vis[2]=i2;
					for(int i3=0;i3<=1;i3++){
						vis[3]=i3;
						for(int i4=0;i4<=1;i4++){
							vis[4]=i4;
							for(int i5=0;i5<=1;i5++){
								vis[5]=i5;
								for(int i6=0;i6<=1;i6++){
									vis[6]=i6;
									for(int i7=0;i7<=1;i7++){
										vis[7]=i7;
										for(int i8=0;i8<=1;i8++){
											vis[8]=i8;
											for(int i9=0;i9<=1;i9++){
												vis[9]=i9;
												for(int i10=0;i10<=1;i10++){
													vis[10]=i10;
													for(int i11=0;i11<=1;i11++){
														vis[11]=i11;
														for(int i12=0;i12<=1;i12++){
															vis[12]=i12;
															for(int i13=0;i13<=1;i13++){
																vis[13]=i13;
																for(int i14=0;i14<=1;i14++){
																	vis[14]=i14;
																	if(check()){
																		ans++;
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
		else if(n==15){
			for(int i1=0;i1<=1;i1++){
				vis[1]=i1;
				for(int i2=0;i2<=1;i2++){
					vis[2]=i2;
					for(int i3=0;i3<=1;i3++){
						vis[3]=i3;
						for(int i4=0;i4<=1;i4++){
							vis[4]=i4;
							for(int i5=0;i5<=1;i5++){
								vis[5]=i5;
								for(int i6=0;i6<=1;i6++){
									vis[6]=i6;
									for(int i7=0;i7<=1;i7++){
										vis[7]=i7;
										for(int i8=0;i8<=1;i8++){
											vis[8]=i8;
											for(int i9=0;i9<=1;i9++){
												vis[9]=i9;
												for(int i10=0;i10<=1;i10++){
													vis[10]=i10;
													for(int i11=0;i11<=1;i11++){
														vis[11]=i11;
														for(int i12=0;i12<=1;i12++){
															vis[12]=i12;
															for(int i13=0;i13<=1;i13++){
																vis[13]=i13;
																for(int i14=0;i14<=1;i14++){
																	vis[14]=i14;
																	for(int i15=0;i15<=1;i15++){
																		vis[15]=i15;
																		if(check()){
																			ans++;
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
		else if(n==16){
			for(int i1=0;i1<=1;i1++){
				vis[1]=i1;
				for(int i2=0;i2<=1;i2++){
					vis[2]=i2;
					for(int i3=0;i3<=1;i3++){
						vis[3]=i3;
						for(int i4=0;i4<=1;i4++){
							vis[4]=i4;
							for(int i5=0;i5<=1;i5++){
								vis[5]=i5;
								for(int i6=0;i6<=1;i6++){
									vis[6]=i6;
									for(int i7=0;i7<=1;i7++){
										vis[7]=i7;
										for(int i8=0;i8<=1;i8++){
											vis[8]=i8;
											for(int i9=0;i9<=1;i9++){
												vis[9]=i9;
												for(int i10=0;i10<=1;i10++){
													vis[10]=i10;
													for(int i11=0;i11<=1;i11++){
														vis[11]=i11;
														for(int i12=0;i12<=1;i12++){
															vis[12]=i12;
															for(int i13=0;i13<=1;i13++){
																vis[13]=i13;
																for(int i14=0;i14<=1;i14++){
																	vis[14]=i14;
																	for(int i15=0;i15<=1;i15++){
																		vis[15]=i15;
																		for(int i16=0;i16<=1;i16++){
																			vis[16]=i16;
																			if(check()){
																				ans++;
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
		else if(n==17){
			for(int i1=0;i1<=1;i1++){
				vis[1]=i1;
				for(int i2=0;i2<=1;i2++){
					vis[2]=i2;
					for(int i3=0;i3<=1;i3++){
						vis[3]=i3;
						for(int i4=0;i4<=1;i4++){
							vis[4]=i4;
							for(int i5=0;i5<=1;i5++){
								vis[5]=i5;
								for(int i6=0;i6<=1;i6++){
									vis[6]=i6;
									for(int i7=0;i7<=1;i7++){
										vis[7]=i7;
										for(int i8=0;i8<=1;i8++){
											vis[8]=i8;
											for(int i9=0;i9<=1;i9++){
												vis[9]=i9;
												for(int i10=0;i10<=1;i10++){
													vis[10]=i10;
													for(int i11=0;i11<=1;i11++){
														vis[11]=i11;
														for(int i12=0;i12<=1;i12++){
															vis[12]=i12;
															for(int i13=0;i13<=1;i13++){
																vis[13]=i13;
																for(int i14=0;i14<=1;i14++){
																	vis[14]=i14;
																	for(int i15=0;i15<=1;i15++){
																		vis[15]=i15;
																		for(int i16=0;i16<=1;i16++){
																			vis[16]=i16;
																			for(int i17=0;i17<=1;i17++){
																				vis[17]=i17;
																				if(check()){
																					ans++;
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
		else if(n==18){
			for(int i1=0;i1<=1;i1++){
				vis[1]=i1;
				for(int i2=0;i2<=1;i2++){
					vis[2]=i2;
					for(int i3=0;i3<=1;i3++){
						vis[3]=i3;
						for(int i4=0;i4<=1;i4++){
							vis[4]=i4;
							for(int i5=0;i5<=1;i5++){
								vis[5]=i5;
								for(int i6=0;i6<=1;i6++){
									vis[6]=i6;
									for(int i7=0;i7<=1;i7++){
										vis[7]=i7;
										for(int i8=0;i8<=1;i8++){
											vis[8]=i8;
											for(int i9=0;i9<=1;i9++){
												vis[9]=i9;
												for(int i10=0;i10<=1;i10++){
													vis[10]=i10;
													for(int i11=0;i11<=1;i11++){
														vis[11]=i11;
														for(int i12=0;i12<=1;i12++){
															vis[12]=i12;
															for(int i13=0;i13<=1;i13++){
																vis[13]=i13;
																for(int i14=0;i14<=1;i14++){
																	vis[14]=i14;
																	for(int i15=0;i15<=1;i15++){
																		vis[15]=i15;
																		for(int i16=0;i16<=1;i16++){
																			vis[16]=i16;
																			for(int i17=0;i17<=1;i17++){
																				vis[17]=i17;
																				for(int i18=0;i18<=1;i18++){
																					vis[18]=i18;
																					if(check()){
																						ans++;
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
	}
	else{
		if(s[1]==1){
			f[1][1]=n;
		}
		else{
			f[1][0]=n;
		}
		for(int i=2;i<=n;i++){
			for(int j=1;j<=n;j++){
				for(int k=1;k<=n;k++){
					if(s[i]==1&&i-j<c[k]){
						f[i][j]+=f[i-1][j-1];
					}
					else{
						f[i][j]+=f[i-1][j];
					}
					f[i][j]%=eps;
				}
			}
		}
		for(int i=m;i<=n;i++){
			ans+=f[n][i];
			ans%=eps;
		}
	}
	cout<<ans;	
	return 0;
}