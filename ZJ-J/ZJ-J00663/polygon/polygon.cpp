#include<bits/stdc++.h>
using namespace std;
int n,a[5005];

int main() {
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	//如何用O(n^2)的时间求出每段区间的最大值
	// 炸了，想不出来，骗分吧
	cin>>n;
	bool flag=true;
	for(int i=1; i<=n; i++) {
		cin>>a[i];
		if(a[i]!=1) flag=0;
	}
	long long ans=0;
	if(flag) {
		for(int i=3; i<=n; i++) {
			long long x=1,y=1;
			for(int j=1; j<=i; j++) {
				y*=j;
				y%=998244353;
			}
			for(int j=0; j<=i-1; j++) {
				x*=n-j;
				x%=998244353;
			}
			ans+=x/y;
			ans%=998244353;
		}
		cout<<ans%998244353;
		return 0;
	} else {
		if(n==3) {
			int x=a[1]+a[2]+a[3];
			int y=max(max(a[1],a[2]),a[3]);
			if(x>2*y) cout<<1;
			else cout<<0;
			return 0;
		} else {
			if(n==4) {
				for(int k1=0; k1<=1; k1++) {
					for(int k2=0; k2<=1; k2++) {
						for(int k3=0; k3<=1; k3++) {
							for(int k4=0; k4<=1; k4++) {
								if(k1+k2+k3+k4<3) continue;
								int w=0,z=0;
								if(k1) w+=a[1],z=max(z,a[1]);
								if(k2) w+=a[2],z=max(z,a[2]);
								if(k3) w+=a[3],z=max(z,a[3]);
								if(k4) w+=a[4],z=max(z,a[4]);
								if(w>2*z) ans++;
							}
						}
					}
				}
				cout<<ans;
				return 0;
			}
			if(n==5) {
				for(int k1=0; k1<=1; k1++) {
					for(int k2=0; k2<=1; k2++) {
						for(int k3=0; k3<=1; k3++) {
							for(int k4=0; k4<=1; k4++) {
								for(int k5=0; k5<=1; k5++) {

									if(k1+k2+k3+k4+k5<3) continue;
									int w=0,z=0;
									if(k1) w+=a[1],z=max(z,a[1]);
									if(k2) w+=a[2],z=max(z,a[2]);
									if(k3) w+=a[3],z=max(z,a[3]);
									if(k4) w+=a[4],z=max(z,a[4]);
									if(k5) w+=a[5],z=max(z,a[5]);
									if(w>2*z) ans++;
								}
							}
						}
					}
				}
				cout<<ans;
				return 0;
			}
			if(n==6) {
				for(int k1=0; k1<=1; k1++) {
					for(int k2=0; k2<=1; k2++) {
						for(int k3=0; k3<=1; k3++) {
							for(int k4=0; k4<=1; k4++) {
								for(int k5=0; k5<=1; k5++) {
									for(int k6=0; k6<=1; k6++) {

										if(k1+k2+k3+k4+k5+k6<3) continue;
										int w=0,z=0;
										if(k1) w+=a[1],z=max(z,a[1]);
										if(k2) w+=a[2],z=max(z,a[2]);
										if(k3) w+=a[3],z=max(z,a[3]);
										if(k4) w+=a[4],z=max(z,a[4]);
										if(k5) w+=a[5],z=max(z,a[5]);
										if(k6) w+=a[6],z=max(z,a[6]);
										if(w>2*z) ans++;
									}
								}
							}
						}
					}
				}
				cout<<ans;
				return 0;
			}
			if(n==7) {
				for(int k1=0; k1<=1; k1++) {
					for(int k2=0; k2<=1; k2++) {
						for(int k3=0; k3<=1; k3++) {
							for(int k4=0; k4<=1; k4++) {
								for(int k5=0; k5<=1; k5++) {
									for(int k6=0; k6<=1; k6++) {
										for(int k7=0; k7<=1; k7++) {

											if(k1+k2+k3+k4+k5+k6+k7<3) continue;
											int w=0,z=0;
											if(k1) w+=a[1],z=max(z,a[1]);
											if(k2) w+=a[2],z=max(z,a[2]);
											if(k3) w+=a[3],z=max(z,a[3]);
											if(k4) w+=a[4],z=max(z,a[4]);
											if(k5) w+=a[5],z=max(z,a[5]);
											if(k6) w+=a[6],z=max(z,a[6]);
											if(k7) w+=a[7],z=max(z,a[7]);
											if(w>2*z) ans++;
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
			if(n==8) {
				for(int k1=0; k1<=1; k1++) {
					for(int k2=0; k2<=1; k2++) {
						for(int k3=0; k3<=1; k3++) {
							for(int k4=0; k4<=1; k4++) {
								for(int k5=0; k5<=1; k5++) {
									for(int k6=0; k6<=1; k6++) {
										for(int k7=0; k7<=1; k7++) {
											for(int k8=0; k8<=1; k8++) {

												if(k1+k2+k3+k4+k5+k6+k7+k8<3) continue;
												int w=0,z=0;
												if(k1) w+=a[1],z=max(z,a[1]);
												if(k2) w+=a[2],z=max(z,a[2]);
												if(k3) w+=a[3],z=max(z,a[3]);
												if(k4) w+=a[4],z=max(z,a[4]);
												if(k5) w+=a[5],z=max(z,a[5]);
												if(k6) w+=a[6],z=max(z,a[6]);
												if(k7) w+=a[7],z=max(z,a[7]);
												if(k8) w+=a[8],z=max(z,a[8]);
												if(w>2*z) ans++;
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
			if(n==9) {
				for(int k1=0; k1<=1; k1++) {
					for(int k2=0; k2<=1; k2++) {
						for(int k3=0; k3<=1; k3++) {
							for(int k4=0; k4<=1; k4++) {
								for(int k5=0; k5<=1; k5++) {
									for(int k6=0; k6<=1; k6++) {
										for(int k7=0; k7<=1; k7++) {
											for(int k8=0; k8<=1; k8++) {
												for(int k9=0; k9<=1; k9++) {

													if(k1+k2+k3+k4+k5+k6+k7+k8+k9<3) continue;
													int w=0,z=0;
													if(k1) w+=a[1],z=max(z,a[1]);
													if(k2) w+=a[2],z=max(z,a[2]);
													if(k3) w+=a[3],z=max(z,a[3]);
													if(k4) w+=a[4],z=max(z,a[4]);
													if(k5) w+=a[5],z=max(z,a[5]);
													if(k6) w+=a[6],z=max(z,a[6]);
													if(k7) w+=a[7],z=max(z,a[7]);
													if(k8) w+=a[8],z=max(z,a[8]);
													if(k9) w+=a[9],z=max(z,a[9]);
													if(w>2*z) ans++;
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
			if(n==10) {
				for(int k1=0; k1<=1; k1++) {
					for(int k2=0; k2<=1; k2++) {
						for(int k3=0; k3<=1; k3++) {
							for(int k4=0; k4<=1; k4++) {
								for(int k5=0; k5<=1; k5++) {
									for(int k6=0; k6<=1; k6++) {
										for(int k7=0; k7<=1; k7++) {
											for(int k8=0; k8<=1; k8++) {
												for(int k9=0; k9<=1; k9++) {
													for(int k10=0; k10<=1; k10++) {

														if(k1+k2+k3+k4+k5+k6+k7+k8+k9+k10<3) continue;
														int w=0,z=0;
														if(k1) w+=a[1],z=max(z,a[1]);
														if(k2) w+=a[2],z=max(z,a[2]);
														if(k3) w+=a[3],z=max(z,a[3]);
														if(k4) w+=a[4],z=max(z,a[4]);
														if(k5) w+=a[5],z=max(z,a[5]);
														if(k6) w+=a[6],z=max(z,a[6]);
														if(k7) w+=a[7],z=max(z,a[7]);
														if(k8) w+=a[8],z=max(z,a[8]);
														if(k9) w+=a[9],z=max(z,a[9]);
														if(k10) w+=a[10],z=max(z,a[10]);
														if(w>2*z) ans++;
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
				cout<<ans;
				return 0;
			}
			if(n==20) {
				for(int k1=0; k1<=1; k1++) {
					for(int k2=0; k2<=1; k2++) {
						for(int k3=0; k3<=1; k3++) {
							for(int k4=0; k4<=1; k4++) {
								for(int k5=0; k5<=1; k5++) {
									for(int k6=0; k6<=1; k6++) {
										for(int k7=0; k7<=1; k7++) {
											for(int k8=0; k8<=1; k8++) {
												for(int k9=0; k9<=1; k9++) {
													for(int k10=0; k10<=1; k10++) {
														for(int k11=0; k11<=1; k11++) {
															for(int k12=0; k12<=1; k12++) {
																for(int k13=0; k13<=1; k13++) {
																	for(int k14=0; k14<=1; k14++) {
																		for(int k15=0; k15<=1; k15++) {
																			for(int k16=0; k16<=1; k16++) {
																				for(int k17=0; k17<=1; k17++) {
																					for(int k18=0; k18<=1; k18++) {
																						for(int k19=0; k19<=1; k19++) {
																							for(int k20=0; k20<=1; k20++) {
																								if(k1+k2+k3+k4+k5+k6+k7+k8+k9+k10+k11+k12+k13+k14+k15+k16+k17+k18+k19+k20<3) continue;
																								int w=0,z=0;
																								if(k1) w+=a[1],z=max(z,a[1]);
																								if(k2) w+=a[2],z=max(z,a[2]);
																								if(k3) w+=a[3],z=max(z,a[3]);
																								if(k4) w+=a[4],z=max(z,a[4]);
																								if(k5) w+=a[5],z=max(z,a[5]);
																								if(k6) w+=a[6],z=max(z,a[6]);
																								if(k7) w+=a[7],z=max(z,a[7]);
																								if(k8) w+=a[8],z=max(z,a[8]);
																								if(k9) w+=a[9],z=max(z,a[9]);
																								if(k10) w+=a[10],z=max(z,a[10]);
																								if(k11) w+=a[11],z=max(z,a[11]);
																								if(k12) w+=a[12],z=max(z,a[12]);
																								if(k13) w+=a[13],z=max(z,a[13]);
																								if(k14) w+=a[14],z=max(z,a[14]);
																								if(k15) w+=a[15],z=max(z,a[15]);
																								if(k16) w+=a[16],z=max(z,a[16]);
																								if(k17) w+=a[17],z=max(z,a[17]);
																								if(k18) w+=a[18],z=max(z,a[18]);
																								if(k19) w+=a[19],z=max(z,a[19]);
																								if(k20) w+=a[20],z=max(z,a[20]);
																								if(w>2*z) ans++;

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
				cout<<ans;
				return 0;
			}
			if(n==19) {
				for(int k1=0; k1<=1; k1++) {
					for(int k2=0; k2<=1; k2++) {
						for(int k3=0; k3<=1; k3++) {
							for(int k4=0; k4<=1; k4++) {
								for(int k5=0; k5<=1; k5++) {
									for(int k6=0; k6<=1; k6++) {
										for(int k7=0; k7<=1; k7++) {
											for(int k8=0; k8<=1; k8++) {
												for(int k9=0; k9<=1; k9++) {
													for(int k10=0; k10<=1; k10++) {
														for(int k11=0; k11<=1; k11++) {
															for(int k12=0; k12<=1; k12++) {
																for(int k13=0; k13<=1; k13++) {
																	for(int k14=0; k14<=1; k14++) {
																		for(int k15=0; k15<=1; k15++) {
																			for(int k16=0; k16<=1; k16++) {
																				for(int k17=0; k17<=1; k17++) {
																					for(int k18=0; k18<=1; k18++) {
																						for(int k19=0; k19<=1; k19++) {

																							if(k1+k2+k3+k4+k5+k6+k7+k8+k9+k10+k11+k12+k13+k14+k15+k16+k17+k18+k19<3) continue;
																							int w=0,z=0;
																							if(k1) w+=a[1],z=max(z,a[1]);
																							if(k2) w+=a[2],z=max(z,a[2]);
																							if(k3) w+=a[3],z=max(z,a[3]);
																							if(k4) w+=a[4],z=max(z,a[4]);
																							if(k5) w+=a[5],z=max(z,a[5]);
																							if(k6) w+=a[6],z=max(z,a[6]);
																							if(k7) w+=a[7],z=max(z,a[7]);
																							if(k8) w+=a[8],z=max(z,a[8]);
																							if(k9) w+=a[9],z=max(z,a[9]);
																							if(k10) w+=a[10],z=max(z,a[10]);
																							if(k11) w+=a[11],z=max(z,a[11]);
																							if(k12) w+=a[12],z=max(z,a[12]);
																							if(k13) w+=a[13],z=max(z,a[13]);
																							if(k14) w+=a[14],z=max(z,a[14]);
																							if(k15) w+=a[15],z=max(z,a[15]);
																							if(k16) w+=a[16],z=max(z,a[16]);
																							if(k17) w+=a[17],z=max(z,a[17]);
																							if(k18) w+=a[18],z=max(z,a[18]);
																							if(k19) w+=a[19],z=max(z,a[19]);
																							if(w>2*z) ans++;


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
				cout<<ans;
				return 0;
			}
			if(n==18) {
				for(int k1=0; k1<=1; k1++) {
					for(int k2=0; k2<=1; k2++) {
						for(int k3=0; k3<=1; k3++) {
							for(int k4=0; k4<=1; k4++) {
								for(int k5=0; k5<=1; k5++) {
									for(int k6=0; k6<=1; k6++) {
										for(int k7=0; k7<=1; k7++) {
											for(int k8=0; k8<=1; k8++) {
												for(int k9=0; k9<=1; k9++) {
													for(int k10=0; k10<=1; k10++) {
														for(int k11=0; k11<=1; k11++) {
															for(int k12=0; k12<=1; k12++) {
																for(int k13=0; k13<=1; k13++) {
																	for(int k14=0; k14<=1; k14++) {
																		for(int k15=0; k15<=1; k15++) {
																			for(int k16=0; k16<=1; k16++) {
																				for(int k17=0; k17<=1; k17++) {
																					for(int k18=0; k18<=1; k18++) {


																						if(k1+k2+k3+k4+k5+k6+k7+k8+k9+k10+k11+k12+k13+k14+k15+k16+k17+k18<3) continue;
																						int w=0,z=0;
																						if(k1) w+=a[1],z=max(z,a[1]);
																						if(k2) w+=a[2],z=max(z,a[2]);
																						if(k3) w+=a[3],z=max(z,a[3]);
																						if(k4) w+=a[4],z=max(z,a[4]);
																						if(k5) w+=a[5],z=max(z,a[5]);
																						if(k6) w+=a[6],z=max(z,a[6]);
																						if(k7) w+=a[7],z=max(z,a[7]);
																						if(k8) w+=a[8],z=max(z,a[8]);
																						if(k9) w+=a[9],z=max(z,a[9]);
																						if(k10) w+=a[10],z=max(z,a[10]);
																						if(k11) w+=a[11],z=max(z,a[11]);
																						if(k12) w+=a[12],z=max(z,a[12]);
																						if(k13) w+=a[13],z=max(z,a[13]);
																						if(k14) w+=a[14],z=max(z,a[14]);
																						if(k15) w+=a[15],z=max(z,a[15]);
																						if(k16) w+=a[16],z=max(z,a[16]);
																						if(k17) w+=a[17],z=max(z,a[17]);
																						if(k18) w+=a[18],z=max(z,a[18]);

																						if(w>2*z) ans++;



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
				cout<<ans;
				return 0;
			}

			if(n==17) {
				for(int k1=0; k1<=1; k1++) {
					for(int k2=0; k2<=1; k2++) {
						for(int k3=0; k3<=1; k3++) {
							for(int k4=0; k4<=1; k4++) {
								for(int k5=0; k5<=1; k5++) {
									for(int k6=0; k6<=1; k6++) {
										for(int k7=0; k7<=1; k7++) {
											for(int k8=0; k8<=1; k8++) {
												for(int k9=0; k9<=1; k9++) {
													for(int k10=0; k10<=1; k10++) {
														for(int k11=0; k11<=1; k11++) {
															for(int k12=0; k12<=1; k12++) {
																for(int k13=0; k13<=1; k13++) {
																	for(int k14=0; k14<=1; k14++) {
																		for(int k15=0; k15<=1; k15++) {
																			for(int k16=0; k16<=1; k16++) {
																				for(int k17=0; k17<=1; k17++) {



																					if(k1+k2+k3+k4+k5+k6+k7+k8+k9+k10+k11+k12+k13+k14+k15+k16+k17<3) continue;
																					int w=0,z=0;
																					if(k1) w+=a[1],z=max(z,a[1]);
																					if(k2) w+=a[2],z=max(z,a[2]);
																					if(k3) w+=a[3],z=max(z,a[3]);
																					if(k4) w+=a[4],z=max(z,a[4]);
																					if(k5) w+=a[5],z=max(z,a[5]);
																					if(k6) w+=a[6],z=max(z,a[6]);
																					if(k7) w+=a[7],z=max(z,a[7]);
																					if(k8) w+=a[8],z=max(z,a[8]);
																					if(k9) w+=a[9],z=max(z,a[9]);
																					if(k10) w+=a[10],z=max(z,a[10]);
																					if(k11) w+=a[11],z=max(z,a[11]);
																					if(k12) w+=a[12],z=max(z,a[12]);
																					if(k13) w+=a[13],z=max(z,a[13]);
																					if(k14) w+=a[14],z=max(z,a[14]);
																					if(k15) w+=a[15],z=max(z,a[15]);
																					if(k16) w+=a[16],z=max(z,a[16]);
																					if(k17) w+=a[17],z=max(z,a[17]);

																					if(w>2*z) ans++;



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
				cout<<ans;
				return 0;
			}
			if(n==16) {
				for(int k1=0; k1<=1; k1++) {
					for(int k2=0; k2<=1; k2++) {
						for(int k3=0; k3<=1; k3++) {
							for(int k4=0; k4<=1; k4++) {
								for(int k5=0; k5<=1; k5++) {
									for(int k6=0; k6<=1; k6++) {
										for(int k7=0; k7<=1; k7++) {
											for(int k8=0; k8<=1; k8++) {
												for(int k9=0; k9<=1; k9++) {
													for(int k10=0; k10<=1; k10++) {
														for(int k11=0; k11<=1; k11++) {
															for(int k12=0; k12<=1; k12++) {
																for(int k13=0; k13<=1; k13++) {
																	for(int k14=0; k14<=1; k14++) {
																		for(int k15=0; k15<=1; k15++) {
																			for(int k16=0; k16<=1; k16++) {




																				if(k1+k2+k3+k4+k5+k6+k7+k8+k9+k10+k11+k12+k13+k14+k15+k16<3) continue;
																				int w=0,z=0;
																				if(k1) w+=a[1],z=max(z,a[1]);
																				if(k2) w+=a[2],z=max(z,a[2]);
																				if(k3) w+=a[3],z=max(z,a[3]);
																				if(k4) w+=a[4],z=max(z,a[4]);
																				if(k5) w+=a[5],z=max(z,a[5]);
																				if(k6) w+=a[6],z=max(z,a[6]);
																				if(k7) w+=a[7],z=max(z,a[7]);
																				if(k8) w+=a[8],z=max(z,a[8]);
																				if(k9) w+=a[9],z=max(z,a[9]);
																				if(k10) w+=a[10],z=max(z,a[10]);
																				if(k11) w+=a[11],z=max(z,a[11]);
																				if(k12) w+=a[12],z=max(z,a[12]);
																				if(k13) w+=a[13],z=max(z,a[13]);
																				if(k14) w+=a[14],z=max(z,a[14]);
																				if(k15) w+=a[15],z=max(z,a[15]);
																				if(k16) w+=a[16],z=max(z,a[16]);

																				if(w>2*z) ans++;



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
				cout<<ans;
				return 0;
			}
			if(n==15) {
				for(int k1=0; k1<=1; k1++) {
					for(int k2=0; k2<=1; k2++) {
						for(int k3=0; k3<=1; k3++) {
							for(int k4=0; k4<=1; k4++) {
								for(int k5=0; k5<=1; k5++) {
									for(int k6=0; k6<=1; k6++) {
										for(int k7=0; k7<=1; k7++) {
											for(int k8=0; k8<=1; k8++) {
												for(int k9=0; k9<=1; k9++) {
													for(int k10=0; k10<=1; k10++) {
														for(int k11=0; k11<=1; k11++) {
															for(int k12=0; k12<=1; k12++) {
																for(int k13=0; k13<=1; k13++) {
																	for(int k14=0; k14<=1; k14++) {
																		for(int k15=0; k15<=1; k15++) {




																			if(k1+k2+k3+k4+k5+k6+k7+k8+k9+k10+k11+k12+k13+k14+k15<3) continue;
																			int w=0,z=0;
																			if(k1) w+=a[1],z=max(z,a[1]);
																			if(k2) w+=a[2],z=max(z,a[2]);
																			if(k3) w+=a[3],z=max(z,a[3]);
																			if(k4) w+=a[4],z=max(z,a[4]);
																			if(k5) w+=a[5],z=max(z,a[5]);
																			if(k6) w+=a[6],z=max(z,a[6]);
																			if(k7) w+=a[7],z=max(z,a[7]);
																			if(k8) w+=a[8],z=max(z,a[8]);
																			if(k9) w+=a[9],z=max(z,a[9]);
																			if(k10) w+=a[10],z=max(z,a[10]);
																			if(k11) w+=a[11],z=max(z,a[11]);
																			if(k12) w+=a[12],z=max(z,a[12]);
																			if(k13) w+=a[13],z=max(z,a[13]);
																			if(k14) w+=a[14],z=max(z,a[14]);
																			if(k15) w+=a[15],z=max(z,a[15]);

																			if(w>2*z) ans++;





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
				cout<<ans;
				return 0;
			}
		}
	}

	return 0;
}




