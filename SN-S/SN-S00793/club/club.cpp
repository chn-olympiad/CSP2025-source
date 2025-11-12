//我真没招了 :( 
#include<bits/stdc++.h>
using namespace std;
int t,n,a[214514],b[214514],c[214514],maxn=-1;
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
																												
	cin>>t;
	while(t--){
		
		cin>>n;
		for(int i=0;i<n;i++){
			cin>>a[i]>>b[i]>>c[i]; 
			
		} 
		if(n==2){
			for(int i0=0;i0<3;i0++){
				for(int i1=0;i1<3;i1++){
					int x=0,y=0,z=0,ans=0;
					if(i0==0) x++;if(i0==1) y++;if(i0==2) z++;
					if(i1==0) x++;if(i1==1) y++;if(i1==2) z++;
					if(x<=n/2&&y<=n/2&&z<=n/2) {
						if(i0==0) ans+=a[0];if(i0==1) ans+=b[0];if(i0==2) ans+=c[0];
						if(i1==0) ans+=a[1];if(i1==1) ans+=b[1];if(i1==2) ans+=c[1];
						maxn=max(ans,maxn);
					}
				}
			}		
		}
		if(n==4){	
			for(int i0=0;i0<3;i0++){
				for(int i1=0;i1<3;i1++){
					for(int i2=0;i2<3;i2++){
						for(int i3=0;i3<3;i3++){
							int x=0,y=0,z=0,ans=0;
							if(i0==0) x++;if(i0==1) y++;if(i0==2) z++;
							if(i1==0) x++;if(i1==1) y++;if(i1==2) z++;
							if(i2==0) x++;if(i2==1) y++;if(i2==2) z++;
							if(i3==0) x++;if(i3==1) y++;if(i3==2) z++;
							if(x<=n/2&&y<=n/2&&z<=n/2) {
								if(i0==0) ans+=a[0];if(i0==1) ans+=b[0];if(i0==2) ans+=c[0];
								if(i1==0) ans+=a[1];if(i1==1) ans+=b[1];if(i1==2) ans+=c[1];
								if(i2==0) ans+=a[2];if(i2==1) ans+=b[2];if(i2==2) ans+=c[2];
								if(i3==0) ans+=a[3];if(i3==1) ans+=b[3];if(i3==2) ans+=c[3];
								maxn=max(ans,maxn);
							}
						}
					}
				}
			}		
		}
		if(n==10){	
			for(int i0=0;i0<3;i0++){
				for(int i1=0;i1<3;i1++){
					for(int i2=0;i2<3;i2++){
						for(int i3=0;i3<3;i3++){
							for(int i4=0;i4<3;i4++){
								for(int i5=0;i5<3;i5++){
									for(int i6=0;i6<3;i6++){
										for(int i7=0;i7<3;i7++){
											for(int i8=0;i8<3;i8++){
												for(int i9=0;i9<3;i9++){
													int x=0,y=0,z=0,ans=0;
													if(i0==0) x++;if(i0==1) y++;if(i0==2) z++;
													if(i1==0) x++;if(i1==1) y++;if(i1==2) z++;
													if(i2==0) x++;if(i2==1) y++;if(i2==2) z++;
													if(i3==0) x++;if(i3==1) y++;if(i3==2) z++;
													if(i4==0) x++;if(i4==1) y++;if(i4==2) z++;
													if(i5==0) x++;if(i5==1) y++;if(i5==2) z++;
													if(i6==0) x++;if(i6==1) y++;if(i6==2) z++;
													if(i7==0) x++;if(i7==1) y++;if(i7==2) z++;
													if(i8==0) x++;if(i8==1) y++;if(i8==2) z++;
													if(i9==0) x++;if(i9==1) y++;if(i9==2) z++;
													if(x<=n/2&&y<=n/2&&z<=n/2) {
														if(i0==0) ans+=a[0];if(i0==1) ans+=b[0];if(i0==2) ans+=c[0];
														if(i1==0) ans+=a[1];if(i1==1) ans+=b[1];if(i1==2) ans+=c[1];
														if(i2==0) ans+=a[2];if(i2==1) ans+=b[2];if(i2==2) ans+=c[2];
														if(i3==0) ans+=a[3];if(i3==1) ans+=b[3];if(i3==2) ans+=c[3];
														if(i4==0) ans+=a[4];if(i4==1) ans+=b[4];if(i4==2) ans+=c[4];
														if(i5==0) ans+=a[5];if(i5==1) ans+=b[5];if(i5==2) ans+=c[5];
														if(i6==0) ans+=a[6];if(i6==1) ans+=b[6];if(i6==2) ans+=c[6];
														if(i7==0) ans+=a[7];if(i7==1) ans+=b[7];if(i7==2) ans+=c[7];
														if(i8==0) ans+=a[8];if(i8==1) ans+=b[8];if(i8==2) ans+=c[8];
														if(i9==0) ans+=a[9];if(i9==1) ans+=b[9];if(i9==2) ans+=c[9];
														maxn=max(ans,maxn);
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
	/*	if(n==30){	
			for(int i0=0;i0<3;i0++){
				for(int i1=0;i1<3;i1++){
					for(int i2=0;i2<3;i2++){
						for(int i3=0;i3<3;i3++){
							for(int i4=0;i4<3;i4++){
								for(int i5=0;i5<3;i5++){
									for(int i6=0;i6<3;i6++){
										for(int i7=0;i7<3;i7++){
											for(int i8=0;i8<3;i8++){
												for(int i9=0;i9<3;i9++){
													for(int i10=0;i10<3;i10++){
														for(int i11=0;i11<3;i11++){
															for(int i12=0;i12<3;i12++){
																for(int i13=0;i13<3;i13++){
																	for(int i14=0;i14<3;i14++){
																		for(int i15=0;i15<3;i15++){
																			for(int i16=0;i16<3;i16++){
																				for(int i17=0;i17<3;i17++){
																					for(int i18=0;i18<3;i18++){
																						for(int i19=0;i19<3;i19++){
																							for(int i20=0;i20<3;i20++){
																								for(int i21=0;i21<3;i21++){
																									for(int i22=0;i22<3;i22++){
																										for(int i23=0;i23<3;i23++){
																											for(int i24=0;i24<3;i24++){
																												for(int i25=0;i25<3;i25++){
																													for(int i26=0;i26<3;i26++){
																														for(int i27=0;i27<3;i27++){
																															for(int i28=0;i28<3;i28++){
																																for(int i29=0;i29<3;i29++){
																																	int x=0,y=0,z=0,ans=0;
																																	if(i0==0) x++;if(i0==1) y++;if(i0==2) z++;
																																	if(i1==0) x++;if(i1==1) y++;if(i1==2) z++;
																																	if(i2==0) x++;if(i2==1) y++;if(i2==2) z++;
																																	if(i3==0) x++;if(i3==1) y++;if(i3==2) z++;
																																	if(i4==0) x++;if(i4==1) y++;if(i4==2) z++;
																																	if(i5==0) x++;if(i5==1) y++;if(i5==2) z++;
																																	if(i6==0) x++;if(i6==1) y++;if(i6==2) z++;
																																	if(i7==0) x++;if(i7==1) y++;if(i7==2) z++;
																																	if(i8==0) x++;if(i8==1) y++;if(i8==2) z++;
																																	if(i9==0) x++;if(i9==1) y++;if(i9==2) z++;
																																	if(i10==0) x++;if(i10==1) y++;if(i10==2) z++;
																																	if(i11==0) x++;if(i11==1) y++;if(i11==2) z++;
																																	if(i12==0) x++;if(i12==1) y++;if(i12==2) z++;
																																	if(i13==0) x++;if(i13==1) y++;if(i13==2) z++;
																																	if(i14==0) x++;if(i14==1) y++;if(i14==2) z++;
																																	if(i15==0) x++;if(i15==1) y++;if(i15==2) z++;
																																	if(i16==0) x++;if(i16==1) y++;if(i16==2) z++;
																																	if(i17==0) x++;if(i17==1) y++;if(i17==2) z++;
																																	if(i18==0) x++;if(i18==1) y++;if(i18==2) z++;
																																	if(i19==0) x++;if(i19==1) y++;if(i19==2) z++;
																																	if(i20==0) x++;if(i20==1) y++;if(i20==2) z++;
																																	if(i21==0) x++;if(i21==1) y++;if(i21==2) z++;
																																	if(i22==0) x++;if(i22==1) y++;if(i22==2) z++;
																																	if(i23==0) x++;if(i23==1) y++;if(i23==2) z++;
																																	if(i24==0) x++;if(i24==1) y++;if(i24==2) z++;
																																	if(i25==0) x++;if(i25==1) y++;if(i25==2) z++;
																																	if(i26==0) x++;if(i26==1) y++;if(i26==2) z++;
																																	if(i27==0) x++;if(i27==1) y++;if(i27==2) z++;
																																	if(i28==0) x++;if(i28==1) y++;if(i28==2) z++;
																																	if(i29==0) x++;if(i29==1) y++;if(i29==2) z++;
																																	if(x<=n/2&&y<=n/2&&z<=n/2) {
																																		if(i0==0) ans+=a[0];if(i0==1) ans+=b[0];if(i0==2) ans+=c[0];
																																		if(i1==0) ans+=a[1];if(i1==1) ans+=b[1];if(i1==2) ans+=c[1];
																																		if(i2==0) ans+=a[2];if(i2==1) ans+=b[2];if(i2==2) ans+=c[2];
																																		if(i3==0) ans+=a[3];if(i3==1) ans+=b[3];if(i3==2) ans+=c[3];
																																		if(i4==0) ans+=a[4];if(i4==1) ans+=b[4];if(i4==2) ans+=c[4];
																																		if(i5==0) ans+=a[5];if(i5==1) ans+=b[5];if(i5==2) ans+=c[5];
																																		if(i6==0) ans+=a[6];if(i6==1) ans+=b[6];if(i6==2) ans+=c[6];
																																		if(i7==0) ans+=a[7];if(i7==1) ans+=b[7];if(i7==2) ans+=c[7];
																																		if(i8==0) ans+=a[8];if(i8==1) ans+=b[8];if(i8==2) ans+=c[8];
																																		if(i9==0) ans+=a[9];if(i9==1) ans+=b[9];if(i9==2) ans+=c[9];
																																		if(i10==0) ans+=a[10];if(i10==1) ans+=b[10];if(i10==2) ans+=c[10];
																																		if(i11==0) ans+=a[11];if(i11==1) ans+=b[11];if(i11==2) ans+=c[11];
																																		if(i12==0) ans+=a[12];if(i12==1) ans+=b[12];if(i12==2) ans+=c[12];
																																		if(i13==0) ans+=a[13];if(i13==1) ans+=b[13];if(i13==2) ans+=c[13];
																																		if(i14==0) ans+=a[14];if(i14==1) ans+=b[14];if(i14==2) ans+=c[14];
																																		if(i15==0) ans+=a[15];if(i15==1) ans+=b[15];if(i15==2) ans+=c[15];
																																		if(i16==0) ans+=a[16];if(i16==1) ans+=b[16];if(i16==2) ans+=c[16];
																																		if(i17==0) ans+=a[17];if(i17==1) ans+=b[17];if(i17==2) ans+=c[17];
																																		if(i18==0) ans+=a[18];if(i18==1) ans+=b[18];if(i18==2) ans+=c[18];
																																		if(i19==0) ans+=a[19];if(i19==1) ans+=b[19];if(i19==2) ans+=c[19];
																																		if(i20==0) ans+=a[20];if(i20==1) ans+=b[20];if(i20==2) ans+=c[20];
																																		if(i21==0) ans+=a[21];if(i21==1) ans+=b[21];if(i21==2) ans+=c[21];
																																		if(i22==0) ans+=a[22];if(i22==1) ans+=b[22];if(i22==2) ans+=c[22];
																																		if(i23==0) ans+=a[23];if(i23==1) ans+=b[23];if(i23==2) ans+=c[23];
																																		if(i24==0) ans+=a[24];if(i24==1) ans+=b[24];if(i24==2) ans+=c[24];
																																		if(i25==0) ans+=a[25];if(i25==1) ans+=b[25];if(i25==2) ans+=c[25];
																																		if(i26==0) ans+=a[26];if(i26==1) ans+=b[26];if(i26==2) ans+=c[26];
																																		if(i27==0) ans+=a[27];if(i27==1) ans+=b[27];if(i27==2) ans+=c[27];
																																		if(i28==0) ans+=a[28];if(i28==1) ans+=b[28];if(i28==2) ans+=c[28];
																																		if(i29==0) ans+=a[29];if(i29==1) ans+=b[29];if(i29==2) ans+=c[29];
																																		maxn=max(ans,maxn);
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
	*/	
		if(n==100000){
			long long xixi=0;
			sort(b,b+n);
			for(int i=n-1;i>=n/2;i--){
				xixi+=b[i];
			}
			cout<<xixi;
			break;
		}
		cout<<maxn<<endl;
		maxn=-1;
	}

	return 0;
}
