#include<bits/stdc++.h>
using namespace std;
const int MAXS=5001;
const int MOD=998244353;
int a[MAXS];
int n;
int x=0;
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	int Maxs=-1;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		x+=a[i];
		if(Maxs<a[i]){
			Maxs=a[i];
		}
	}
	Maxs=Maxs*2;
	int m=0;
	if(n<=4){
		int ans=0;
		if(x>Maxs){
			ans+=1;
		}
		if(n==4){
			for(int i=1;i<=2;i++){
				for(int j=i+1;j<=3;j++){
					for(int k=j+1;k<=4;k++){
						m=0;
						m=max(a[i],max(a[k],a[j]));
						m=m*2;
						if(a[i]+a[j]+a[k]>m){
							ans+=1;
						}
					}
				}
			}
		}
		cout<<ans%MOD<<endl;
	}
	/*	if(n==5){
			for(int i=1;i<=3;i++){
				for(int j=i+1;j<=4;j++){
					for(int k=j+1;k<=5;k++){
						m=0;
						m=max(a[i],max(a[k],a[j]));
						m=m*2;
						if(a[i]+a[j]+a[k]>m){
							ans+=1;
						//	cout<<a[i]<<"  "<<a[j]<<"  "<<a[k]<<endl;
						}
					}
				}
			}
			for(int i=1;i<=2;i++){
				for(int j=i+1;j<=3;j++){
					for(int k=j+1;k<=4;k++){
						for(int z=k+1;z<=5;z++)
							m=0;
							m=max(max(a[i],a[z]),max(a[k],a[j]));
							m=m*2;
							if(a[i]+a[j]+a[k]+a[z]>m){
								ans+=1;
							//	cout<<a[i]<<"  "<<a[j]<<"  "<<a[k]<<"  "<<a[i2]<<endl;
							}
					}
				}
			}
		}
		if(n==6){
			for(int i=1;i<=4;i++){
				for(int j=i+1;j<=5;j++){
					for(int k=j+1;k<=6;k++){
						m=0;
						m=max(a[i],max(a[k],a[j]));
						m=m*2;
						if(a[i]+a[j]+a[k]>m){
							ans+=1;
						}
					}
				}
			}
			for(int i=1;i<=3;i++){
				for(int j=i+1;j<=4;j++){
					for(int k=j+1;k<=5;k++){
						for(int i2=k+1;i2<=6;i2++)
							m=0;
							m=max(max(a[i],a[i2]),max(a[k],a[j]));
							m=m*2;
							if(a[i]+a[j]+a[k]+a[i2]>m){
								ans+=1;
							//	cout<<a[i]<<"  "<<a[j]<<"  "<<a[k]<<"  "<<a[i2]<<endl;
							}
					}
				}
			}
			for(int i=1;i<=2;i++){
				for(int j=i+1;j<=3;j++){
					for(int k=j+1;k<=4;k++){
						for(int i2=k+1;i2<=5;i2++)
							for(int i3=i2+1;i3<=6;i3++)
								m=0;
								m=max(max(max(a[i],a[i2]),max(a[k],a[j])),a[i3]);
								m=m*2;
								if(a[i]+a[j]+a[k]+a[i2]+a[i3]>m){
									ans+=1;
							//	cout<<a[i]<<"  "<<a[j]<<"  "<<a[k]<<"  "<<a[i2]<<endl;
								}	
					}
				}
			}
		}
		if(n==7){
			for(int i=1;i<=5;i++){
				for(int j=i+1;j<=6;j++){
					for(int k=j+1;k<=7;k++){
						m=0;
						m=max(a[i],max(a[k],a[j]));
						m=m*2;
						if(a[i]+a[j]+a[k]>m){
							ans+=1;
						}
					}
				}
			}
			for(int i=1;i<=4;i++){
				for(int j=i+1;j<=5;j++){
					for(int k=j+1;k<=6;k++){
						for(int i2=k+1;i2<=7;i2++)
							m=0;
							m=max(max(a[i],a[i2]),max(a[k],a[j]));
							m=m*2;
							if(a[i]+a[j]+a[k]+a[i2]>m){
								ans+=1;
							//	cout<<a[i]<<"  "<<a[j]<<"  "<<a[k]<<"  "<<a[i2]<<endl;
							}
					}
				}
			}
			for(int i=1;i<=3;i++){
				for(int j=i+1;j<=4;j++){
					for(int k=j+1;k<=5;k++){
						for(int i2=k+1;i2<=6;i2++)
							for(int i3=i2+1;i3<=7;i3++)
								m=0;
								m=max(max(max(a[i],a[i2]),max(a[k],a[j])),a[i3]);
								m=m*2;
								if(a[i]+a[j]+a[k]+a[i2]+a[i3]>m){
									ans+=1;
							//	cout<<a[i]<<"  "<<a[j]<<"  "<<a[k]<<"  "<<a[i2]<<endl;
								}	
					}
				}
			}
			for(int i=1;i<=2;i++){
				for(int j=i+1;j<=3;j++){
					for(int k=j+1;k<=4;k++){
						for(int i2=k+1;i2<=5;i2++)
							for(int i3=i2+1;i3<=6;i3++)
								for(int i4=i3+1;i4<=7;i4++)
									m=0;
									m=max(max(max(max(a[i],a[i2]),max(a[k],a[j])),a[i3]),a[i4]);
									m=m*2;
									if(a[i]+a[j]+a[k]+a[i2]+a[i3]+a[i4]>m){
										ans+=1;
									}	
					}
				}
			}
		}
		if(n==8){
			for(int i=1;i<=6;i++){
				for(int j=i+1;j<=7;j++){
					for(int k=j+1;k<=8;k++){
						m=0;
						m=max(a[i],max(a[k],a[j]));
						m=m*2;
						if(a[i]+a[j]+a[k]>m){
							ans+=1;
						}
					}
				}
			}
			for(int i=1;i<=5;i++){
				for(int j=i+1;j<=6;j++){
					for(int k=j+1;k<=7;k++){
						for(int i2=k+1;i2<=8;i2++)
							m=0;
							m=max(max(a[i],a[i2]),max(a[k],a[j]));
							m=m*2;
							if(a[i]+a[j]+a[k]+a[i2]>m){
								ans+=1;
							//	cout<<a[i]<<"  "<<a[j]<<"  "<<a[k]<<"  "<<a[i2]<<endl;
							}
					}
				}
			}
			for(int i=1;i<=4;i++){
				for(int j=i+1;j<=5;j++){
					for(int k=j+1;k<=6;k++){
						for(int i2=k+1;i2<=7;i2++)
							for(int i3=i2+1;i3<=8;i3++)
								m=0;
								m=max(max(max(a[i],a[i2]),max(a[k],a[j])),a[i3]);
								m=m*2;
								if(a[i]+a[j]+a[k]+a[i2]+a[i3]>m){
									ans+=1;
							//	cout<<a[i]<<"  "<<a[j]<<"  "<<a[k]<<"  "<<a[i2]<<endl;
								}	
					}
				}
			}
			for(int i=1;i<=3;i++){
				for(int j=i+1;j<=4;j++){
					for(int k=j+1;k<=5;k++){
						for(int i2=k+1;i2<=6;i2++)
							for(int i3=i2+1;i3<=7;i3++)
								for(int i4=i3+1;i4<=8;i4++)
									m=0;
									m=max(max(max(max(a[i],a[i2]),max(a[k],a[j])),a[i3]),a[i4]);
									m=m*2;
									if(a[i]+a[j]+a[k]+a[i2]+a[i3]+a[i4]>m){
										ans+=1;
									}	
					}	
				}
			}
			for(int i=1;i<=2;i++){
				for(int j=i+1;j<=3;j++){
					for(int k=j+1;k<=4;k++){
						for(int i2=k+1;i2<=5;i2++)
							for(int i3=i2+1;i3<=6;i3++)
								for(int i4=i3+1;i4<=7;i4++)
									for(int i5=i4+1;i5<=8;i5++)
										m=0;
										m=(max(max(max(max(a[i],a[i2]),max(a[k],a[j])),a[i3]),a[i4])a[i5]);
										m=m*2;
										if(a[i]+a[j]+a[k]+a[i2]+a[i3]+a[i4]+a[i5]>m){
											ans+=1;
										}	
					}
				}
			}
		}
		if(n==9){
			for(int i=1;i<=7;i++){
				for(int j=i+1;j<=8;j++){
					for(int k=j+1;k<=9;k++){
						m=0;
						m=max(a[i],max(a[k],a[j]));
						m=m*2;
						if(a[i]+a[j]+a[k]>m){
							ans+=1;
						}
					}
				}
			}
			for(int i=1;i<=6;i++){
				for(int j=i+1;j<=7;j++){
					for(int k=j+1;k<=8;k++){
						for(int i2=k+1;i2<=9;i2++)
							m=0;
							m=max(max(a[i],a[i2]),max(a[k],a[j]));
							m=m*2;
							if(a[i]+a[j]+a[k]+a[i2]>m){
								ans+=1;
							//	cout<<a[i]<<"  "<<a[j]<<"  "<<a[k]<<"  "<<a[i2]<<endl;
							}
					}
				}
			}
			for(int i=1;i<=5;i++){
				for(int j=i+1;j<=6;j++){
					for(int k=j+1;k<=7;k++){
						for(int i2=k+1;i2<=8;i2++)
							for(int i3=i2+1;i3<=9;i3++)
								m=0;
								m=max(max(max(a[i],a[i2]),max(a[k],a[j])),a[i3]);
								m=m*2;
								if(a[i]+a[j]+a[k]+a[i2]+a[i3]>m){
									ans+=1;
							//	cout<<a[i]<<"  "<<a[j]<<"  "<<a[k]<<"  "<<a[i2]<<endl;
								}	
					}
				}
			}
			for(int i=1;i<=4;i++){
				for(int j=i+1;j<=5;j++){
					for(int k=j+1;k<=6;k++){
						for(int i2=k+1;i2<=7;i2++)
							for(int i3=i2+1;i3<=8;i3++)
								for(int i4=i3+1;i4<=9;i4++)
									m=0;
									m=max(max(max(max(a[i],a[i2]),max(a[k],a[j])),a[i3]),a[i4]);
									m=m*2;
									if(a[i]+a[j]+a[k]+a[i2]+a[i3]+a[i4]>Maxs){
										ans+=1;
									}	
					}	
				}
			}
			for(int i=1;i<=3;i++){
				for(int j=i+1;j<=4;j++){
					for(int k=j+1;k<=5;k++){
						for(int i2=k+1;i2<=6;i2++)
							for(int i3=i2+1;i3<=7;i3++)
								for(int i4=i3+1;i4<=8;i4++)
									for(int i5=i4+1;i5<=8;i5++)
										m=0;
										m=(max(max(max(max(a[i],a[i2]),max(a[k],a[j])),a[i3]),a[i4])a[i5]);
										m=m*2;
										if(a[i]+a[j]+a[k]+a[i2]+a[i3]+a[i4]+a[i5]>m){
											ans+=1;
										}	
					}	
				}
			}
			for(int i6=1;i6<=2;i6++){
				for(int i=1;i<=3;i++){
					for(int j=i+1;j<=4;j++){
						for(int k=j+1;k<=5;k++){
							for(int i2=k+1;i2<=6;i2++)
								for(int i3=i2+1;i3<=7;i3++)
									for(int i4=i3+1;i4<=8;i4++)
										for(int i5=i4+1;i5<=9;i5++)
											m=0;
											m=max((max(max(max(max(a[i],a[i2]),max(a[k],a[j])),a[i3]),a[i4])a[i5])a[i6]);
											m=m*2;
											if(a[i]+a[j]+a[k]+a[i2]+a[i3]+a[i4]+a[i5]+a[i6]>m){
												ans+=1;
											}	
						}
					}
				}
			} 
		}
		if(n==10){
			for(int i=1;i<=8;i++){
				for(int j=i+1;j<=9;j++){
					for(int k=j+1;k<=10;k++){
						m=0;
						m=max(a[i],max(a[k],a[j]));
						m=m*2;
						if(a[i]+a[j]+a[k]>m){
							ans+=1;
						}
					}
				}
			}
			for(int i=1;i<=7;i++){
				for(int j=i+1;j<=8;j++){
					for(int k=j+1;k<=9;k++){
						for(int i2=k+1;i2<=10;i2++)
							m=0;
							m=max(max(a[i],a[i2]),max(a[k],a[j]));
							m=m*2;
							if(a[i]+a[j]+a[k]+a[i2]>m){
								ans+=1;
							//	cout<<a[i]<<"  "<<a[j]<<"  "<<a[k]<<"  "<<a[i2]<<endl;
							}
					}
				}
			}
			for(int i=1;i<=6;i++){
				for(int j=i+1;j<=7;j++){
					for(int k=j+1;k<=8;k++){
						for(int i2=k+1;i2<=9;i2++)
							for(int i3=i2+1;i3<=10;i3++)
								m=0;
								m=max(max(max(a[i],a[i2]),max(a[k],a[j])),a[i3]);
								m=m*2;
								if(a[i]+a[j]+a[k]+a[i2]+a[i3]>m){
									ans+=1;
							//	cout<<a[i]<<"  "<<a[j]<<"  "<<a[k]<<"  "<<a[i2]<<endl;
								}	
					}
				}
			}
			for(int i=1;i<=5;i++){
				for(int j=i+1;j<=6;j++){
					for(int k=j+1;k<=7;k++){
						for(int i2=k+1;i2<=8;i2++)
							for(int i3=i2+1;i3<=9;i3++)
								for(int i4=i3+1;i4<=10;i4++)
									m=0;
									m=max(max(max(max(a[i],a[i2]),max(a[k],a[j])),a[i3]),a[i4]);
									m=m*2;
									if(a[i]+a[j]+a[k]+a[i2]+a[i3]+a[i4]>Maxs){
										ans+=1;
									}	
					}	
				}
			}
			for(int i=1;i<=4;i++){
				for(int j=i+1;j<=5;j++){
					for(int k=j+1;k<=6;k++){
						for(int i2=k+1;i2<=7;i2++)
							for(int i3=i2+1;i3<=8;i3++)
								for(int i4=i3+1;i4<=9;i4++)
									for(int i5=i4+1;i5<=10;i5++)
										m=0;
										m=(max(max(max(max(a[i],a[i2]),max(a[k],a[j])),a[i3]),a[i4])a[i5]);
										m=m*2;
										if(a[i]+a[j]+a[k]+a[i2]+a[i3]+a[i4]+a[i5]>m){
											ans+=1;
										}	
					}	
				}
			}
			for(int i6=1;i6<=3;i6++){
					for(int i=1;i<=4;i++){
						for(int j=i+1;j<=5;j++){
							for(int k=j+1;k<=6;k++){
								for(int i2=k+1;i2<=7;i2++)
									for(int i3=i2+1;i3<=8;i3++)
										for(int i4=i3+1;i4<=9;i4++)
											for(int i5=i4+1;i5<=10;i5++)
												m=0;
												m=max((max(max(max(max(a[i],a[i2]),max(a[k],a[j])),a[i3]),a[i4])a[i5])a[i6]);
												m=m*2;
												if(a[i]+a[j]+a[k]+a[i2]+a[i3]+a[i4]+a[i5]+a[i6]>m){
												ans+=1;
												}		
							}
						}
					}
				}
			for(int i7=1;i7<=2;i7++){
				for(int i6=1;i6<=3;i6++){
					for(int i=1;i<=4;i++){
						for(int j=i+1;j<=5;j++){
							for(int k=j+1;k<=6;k++){
								for(int i2=k+1;i2<=7;i2++)
									for(int i3=i2+1;i3<=8;i3++)
										for(int i4=i3+1;i4<=9;i4++)
											for(int i5=i4+1;i5<=10;i5++)
												m=0;
												m=(max((max(max(max(max(a[i],a[i2]),max(a[k],a[j])),a[i3]),a[i4])a[i5])a[i6])a[i7]);
												m=m*2;
												if(a[i]+a[j]+a[k]+a[i2]+a[i3]+a[i4]+a[i5]+a[i6]+a[i7]>m){
													ans+=1;
												}	
							}
						}
					}
				}
			} 
		}
		cout<<ans%MOD<<endl;
		return 0;
	}
	else{
		cout<<1<<endl;
	}*/
	
	return 0;
}
