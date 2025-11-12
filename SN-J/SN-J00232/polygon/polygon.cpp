#include<bits/stdc++.h>
using namespace std;
int a[1000001],s[1000001],n,k2,w;
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	if(n<3){
		cout<<0;
		return 0;
	}
	else if(n==3){
		int w=max(a[1],a[2]);
		w=max(w,a[3]);
		if(a[1]+a[2]+a[3]>w*2) k2=1;
		else k2=0;
	}
	else if(n==4){
		for(int i=1;i<=n;i++){
			for(int j=i;j<=n;j++){
				for(int k=j;k<=n;k++){
					int w=max(a[i],a[j]);
					w=max(w,a[k]);
					if(a[i]+a[j]+a[k]>w*2&&i!=j&&i!=k&&j!=k) k2++;
				}
			}
		}
		int w=max(a[1],a[2]);
		w=max(w,a[3]);
		w=max(w,a[4]);
		if(a[1]+a[2]+a[3]+a[4]>w*2) k2++;
	}
	else if(n==5){
		for(int i=1;i<=n;i++){
			for(int j=i;j<=n;j++){
				for(int k=j;k<=n;k++){
					int w=max(a[i],a[j]);
					w=max(w,a[k]);
					if(a[i]+a[j]+a[k]>w*2&&i!=j&&i!=k&&j!=k) k2++;
				}
			}
		}
		for(int i=1;i<=n;i++){
			for(int j=i;j<=n;j++){
				for(int k=j;k<=n;k++){
					for(int h=k;h<=n;h++){
						int w=max(a[i],a[j]);
						w=max(w,a[k]);
						w=max(w,a[h]);
						if(a[i]+a[j]+a[k]+a[h]>w*2&&i!=j&&i!=k&&j!=k&&i!=h&&j!=h&&k!=h) k2++;
					}
					
				}
			}
		}
		int w=max(a[1],a[2]);
		w=max(w,a[3]);
		w=max(w,a[5]);
		w=max(w,a[4]);
		if(a[1]+a[2]+a[3]+a[4]+a[5]>w*2) k2++;
	}
	
	else if(n==6){
		for(int i=1;i<=n;i++){
			for(int j=i;j<=n;j++){
				for(int k=j;k<=n;k++){
					int w=max(a[i],a[j]);
					w=max(w,a[k]);
					if(a[i]+a[j]+a[k]>w*2&&i!=j&&i!=k&&j!=k) k2++;
				}
			}
		}
		for(int i=1;i<=n;i++){
			for(int j=i;j<=n;j++){
				for(int k=j;k<=n;k++){
					for(int h=k;h<=n;h++){
						int w=max(a[i],a[j]);
						w=max(w,a[k]);
						w=max(w,a[h]);
						if(a[i]+a[j]+a[k]+a[h]>w*2&&i!=j&&i!=k&&j!=k&&i!=h&&j!=h&&k!=h) k2++;
					}
					
				}
			}
		}
		for(int i=1;i<=n;i++){
			for(int j=i;j<=n;j++){
				for(int k=j;k<=n;k++){
					for(int h=k;h<=n;h++){
						for(int g=h;g<=n;g++){
							int w=max(a[i],a[j]);
							w=max(w,a[k]);
							w=max(w,a[h]);
							w=max(w,a[g]);
							if(a[i]+a[j]+a[k]+a[h]+a[g]>w*2&&i!=j&&i!=k&&j!=k&&i!=h&&j!=h&&k!=h&&g!=i&&g!=j&&g!=k&&g!=h) k2++;
						}
					
					}
					
				}
			}
		}
		int w=max(a[1],a[2]);
		w=max(w,a[3]);
		w=max(w,a[5]);
		w=max(w,a[4]);
		w=max(w,a[6]);
		if(a[1]+a[2]+a[3]+a[4]+a[5]>w*2) k2++;
	}
	
	else if(n==7){
		for(int i=1;i<=n;i++){
			for(int j=i;j<=n;j++){
				for(int k=j;k<=n;k++){
					int w=max(a[i],a[j]);
					w=max(w,a[k]);
					if(a[i]+a[j]+a[k]>w*2&&i!=j&&i!=k&&j!=k) k2++;
				}
			}
		}
		for(int i=1;i<=n;i++){
			for(int j=i;j<=n;j++){
				for(int k=j;k<=n;k++){
					for(int h=k;h<=n;h++){
						int w=max(a[i],a[j]);
						w=max(w,a[k]);
						w=max(w,a[h]);
						if(a[i]+a[j]+a[k]+a[h]>w*2&&i!=j&&i!=k&&j!=k&&i!=h&&j!=h&&k!=h) k2++;
					}
					
				}
			}
		}
		for(int i=1;i<=n;i++){
			for(int j=i;j<=n;j++){
				for(int k=j;k<=n;k++){
					for(int h=k;h<=n;h++){
						for(int g=h;g<=n;g++){
							int w=max(a[i],a[j]);
							w=max(w,a[k]);
							w=max(w,a[h]);
							w=max(w,a[g]);
							if(a[i]+a[j]+a[k]+a[h]+a[g]>w*2&&i!=j&&i!=k&&j!=k&&i!=h&&j!=h&&k!=h&&g!=i&&g!=j&&g!=k&&g!=h) k2++;
						}
					
					}
					
				}
			}
		}
		for(int i=1;i<=n;i++){
			for(int j=i;j<=n;j++){
				for(int k=j;k<=n;k++){
					for(int h=k;h<=n;h++){
						for(int g=h;g<=n;g++){
							for(int f=g;f<=n;f++){
								int w=max(a[i],a[j]);
								w=max(w,a[k]);
								w=max(w,a[h]);
								w=max(w,a[g]);
								w=max(w,a[f]);
								if(a[i]+a[j]+a[k]+a[h]+a[g]+a[f]>w*2&&i!=j&&i!=k&&j!=k&&i!=h&&j!=h&&k!=h&&g!=i&&g!=j&&g!=k&&g!=h&&f!=i&&f!=j&&f!=k&&f!=h&&f!=g) k2++;
							}
							
						}
					
					}
					
				}
			}
		}
		int w=max(a[1],a[2]);
		w=max(w,a[3]);
		w=max(w,a[5]);
		w=max(w,a[4]);
		w=max(w,a[6]);
		w=max(w,a[7]);
		if(a[1]+a[2]+a[3]+a[4]+a[5]+a[6]>w*2) k2++;
	}
	
	else if(n==8){
		for(int i=1;i<=n;i++){
			for(int j=i;j<=n;j++){
				for(int k=j;k<=n;k++){
					int w=max(a[i],a[j]);
					w=max(w,a[k]);
					if(a[i]+a[j]+a[k]>w*2&&i!=j&&i!=k&&j!=k) k2++;
				}
			}
		}
		for(int i=1;i<=n;i++){
			for(int j=i;j<=n;j++){
				for(int k=j;k<=n;k++){
					for(int h=k;h<=n;h++){
						int w=max(a[i],a[j]);
						w=max(w,a[k]);
						w=max(w,a[h]);
						if(a[i]+a[j]+a[k]+a[h]>w*2&&i!=j&&i!=k&&j!=k&&i!=h&&j!=h&&k!=h) k2++;
					}
					
				}
			}
		}
		for(int i=1;i<=n;i++){
			for(int j=i;j<=n;j++){
				for(int k=j;k<=n;k++){
					for(int h=k;h<=n;h++){
						for(int g=h;g<=n;g++){
							int w=max(a[i],a[j]);
							w=max(w,a[k]);
							w=max(w,a[h]);
							w=max(w,a[g]);
							if(a[i]+a[j]+a[k]+a[h]+a[g]>w*2&&i!=j&&i!=k&&j!=k&&i!=h&&j!=h&&k!=h&&g!=i&&g!=j&&g!=k&&g!=h) k2++;
						}
					
					}
					
				}
			}
		}
		for(int i=1;i<=n;i++){
			for(int j=i;j<=n;j++){
				for(int k=j;k<=n;k++){
					for(int h=k;h<=n;h++){
						for(int g=h;g<=n;g++){
							for(int f=g;f<=n;f++){
								int w=max(a[i],a[j]);
								w=max(w,a[k]);
								w=max(w,a[h]);
								w=max(w,a[g]);
								w=max(w,a[f]);
								if(a[i]+a[j]+a[k]+a[h]+a[g]+a[f]>w*2&&i!=j&&i!=k&&j!=k&&i!=h&&j!=h&&k!=h&&g!=i&&g!=j&&g!=k&&g!=h&&f!=i&&f!=j&&f!=k&&f!=h&&f!=g) k2++;
							}
							
						}
					
					}
					
				}
			}
		}
		for(int i=1;i<=n;i++){
			for(int j=i;j<=n;j++){
				for(int k=j;k<=n;k++){
					for(int h=k;h<=n;h++){
						for(int g=h;g<=n;g++){
							for(int f=g;f<=n;f++){
								for(int d=f;d<=n;d++){
									int w=max(a[i],a[j]);
									w=max(w,a[k]);
									w=max(w,a[h]);
									w=max(w,a[g]);
									w=max(w,a[f]);
									w=max(w,a[d]);
									if(a[i]+a[j]+a[k]+a[h]+a[g]+a[f]+a[d]>w*2&&i!=j&&i!=k&&j!=k&&i!=h&&j!=h&&k!=h&&g!=i&&g!=j&&g!=k&&g!=h&&f!=i&&f!=j&&f!=k&&f!=h&&f!=g&&d!=i&&d!=j&&d!=k&&d!=h&&d!=g&&d!=f) k2++;
								}
								
							}
							
						}
					
					}
					
				}
			}
		}
		int w=max(a[1],a[2]);
		w=max(w,a[3]);
		w=max(w,a[5]);
		w=max(w,a[4]);
		w=max(w,a[6]);
		w=max(w,a[7]);
		w=max(w,a[8]);
		if(a[1]+a[2]+a[3]+a[4]+a[5]+a[6]+a[7]+a[8]>w*2) k2++;
	}
	else if(n==9){
		for(int i=1;i<=n;i++){
			for(int j=i;j<=n;j++){
				for(int k=j;k<=n;k++){
					int w=max(a[i],a[j]);
					w=max(w,a[k]);
					if(a[i]+a[j]+a[k]>w*2&&i!=j&&i!=k&&j!=k) k2++;
				}
			}
		}
		for(int i=1;i<=n;i++){
			for(int j=i;j<=n;j++){
				for(int k=j;k<=n;k++){
					for(int h=k;h<=n;h++){
						int w=max(a[i],a[j]);
						w=max(w,a[k]);
						w=max(w,a[h]);
						if(a[i]+a[j]+a[k]+a[h]>w*2&&i!=j&&i!=k&&j!=k&&i!=h&&j!=h&&k!=h) k2++;
					}
					
				}
			}
		}
		for(int i=1;i<=n;i++){
			for(int j=i;j<=n;j++){
				for(int k=j;k<=n;k++){
					for(int h=k;h<=n;h++){
						for(int g=h;g<=n;g++){
							int w=max(a[i],a[j]);
							w=max(w,a[k]);
							w=max(w,a[h]);
							w=max(w,a[g]);
							if(a[i]+a[j]+a[k]+a[h]+a[g]>w*2&&i!=j&&i!=k&&j!=k&&i!=h&&j!=h&&k!=h&&g!=i&&g!=j&&g!=k&&g!=h) k2++;
						}
					
					}
					
				}
			}
		}
		for(int i=1;i<=n;i++){
			for(int j=i;j<=n;j++){
				for(int k=j;k<=n;k++){
					for(int h=k;h<=n;h++){
						for(int g=h;g<=n;g++){
							for(int f=g;f<=n;f++){
								int w=max(a[i],a[j]);
								w=max(w,a[k]);
								w=max(w,a[h]);
								w=max(w,a[g]);
								w=max(w,a[f]);
								if(a[i]+a[j]+a[k]+a[h]+a[g]+a[f]>w*2&&i!=j&&i!=k&&j!=k&&i!=h&&j!=h&&k!=h&&g!=i&&g!=j&&g!=k&&g!=h&&f!=i&&f!=j&&f!=k&&f!=h&&f!=g) k2++;
							}
							
						}
					
					}
					
				}
			}
		}
		for(int i=1;i<=n;i++){
			for(int j=i;j<=n;j++){
				for(int k=j;k<=n;k++){
					for(int h=k;h<=n;h++){
						for(int g=h;g<=n;g++){
							for(int f=g;f<=n;f++){
								for(int d=f;d<=n;d++){
									int w=max(a[i],a[j]);
									w=max(w,a[k]);
									w=max(w,a[h]);
									w=max(w,a[g]);
									w=max(w,a[f]);
									w=max(w,a[d]);
									if(a[i]+a[j]+a[k]+a[h]+a[g]+a[f]+a[d]>w*2&&i!=j&&i!=k&&j!=k&&i!=h&&j!=h&&k!=h&&g!=i&&g!=j&&g!=k&&g!=h&&f!=i&&f!=j&&f!=k&&f!=h&&f!=g&&d!=i&&d!=j&&d!=k&&d!=h&&d!=g&&d!=f) k2++;
								}
								
							}
							
						}
					
					}
					
				}
			}
		}
		for(int i=1;i<=n;i++){
			for(int j=i;j<=n;j++){
				for(int k=j;k<=n;k++){
					for(int h=k;h<=n;h++){
						for(int g=h;g<=n;g++){
							for(int f=g;f<=n;f++){
								for(int d=f;d<=n;d++){
									for(int p=d;p<=n;p++){
										int w=max(a[i],a[j]);
										w=max(w,a[k]);
										w=max(w,a[h]);
										w=max(w,a[g]);
										w=max(w,a[f]);
										w=max(w,a[d]);
										w=max(w,a[p]);
										if(a[i]+a[j]+a[k]+a[h]+a[g]+a[f]+a[d]+a[p]>w*2&&i!=j&&i!=k&&j!=k&&i!=h&&j!=h&&k!=h&&g!=i&&g!=j&&g!=k&&g!=h&&f!=i&&f!=j&&f!=k&&f!=h&&f!=g&&d!=i&&d!=j&&d!=k&&d!=h&&d!=g&&d!=f&&p!=i&&p!=j&&p!=k&&p!=h&&p!=g&&p!=f&&p!=d) k2++;
									}
								}
								
							}
							
						}
					
					}
					
				}
			}
		}
		int w=max(a[1],a[2]);
		w=max(w,a[3]);
		w=max(w,a[5]);
		w=max(w,a[4]);
		w=max(w,a[6]);
		w=max(w,a[7]);
		w=max(w,a[8]);
		w=max(w,a[9]);
		if(a[1]+a[2]+a[3]+a[4]+a[5]+a[6]+a[7]+a[8]+a[9]>w*2) k2++;
	}
	
	else if(n==9){
		for(int i=1;i<=n;i++){
			for(int j=i;j<=n;j++){
				for(int k=j;k<=n;k++){
					int w=max(a[i],a[j]);
					w=max(w,a[k]);
					if(a[i]+a[j]+a[k]>w*2&&i!=j&&i!=k&&j!=k) k2++;
				}
			}
		}
		for(int i=1;i<=n;i++){
			for(int j=i;j<=n;j++){
				for(int k=j;k<=n;k++){
					for(int h=k;h<=n;h++){
						int w=max(a[i],a[j]);
						w=max(w,a[k]);
						w=max(w,a[h]);
						if(a[i]+a[j]+a[k]+a[h]>w*2&&i!=j&&i!=k&&j!=k&&i!=h&&j!=h&&k!=h) k2++;
					}
					
				}
			}
		}
		for(int i=1;i<=n;i++){
			for(int j=i;j<=n;j++){
				for(int k=j;k<=n;k++){
					for(int h=k;h<=n;h++){
						for(int g=h;g<=n;g++){
							int w=max(a[i],a[j]);
							w=max(w,a[k]);
							w=max(w,a[h]);
							w=max(w,a[g]);
							if(a[i]+a[j]+a[k]+a[h]+a[g]>w*2&&i!=j&&i!=k&&j!=k&&i!=h&&j!=h&&k!=h&&g!=i&&g!=j&&g!=k&&g!=h) k2++;
						}
					
					}
					
				}
			}
		}
		for(int i=1;i<=n;i++){
			for(int j=i;j<=n;j++){
				for(int k=j;k<=n;k++){
					for(int h=k;h<=n;h++){
						for(int g=h;g<=n;g++){
							for(int f=g;f<=n;f++){
								int w=max(a[i],a[j]);
								w=max(w,a[k]);
								w=max(w,a[h]);
								w=max(w,a[g]);
								w=max(w,a[f]);
								if(a[i]+a[j]+a[k]+a[h]+a[g]+a[f]>w*2&&i!=j&&i!=k&&j!=k&&i!=h&&j!=h&&k!=h&&g!=i&&g!=j&&g!=k&&g!=h&&f!=i&&f!=j&&f!=k&&f!=h&&f!=g) k2++;
							}
							
						}
					
					}
					
				}
			}
		}
		for(int i=1;i<=n;i++){
			for(int j=i;j<=n;j++){
				for(int k=j;k<=n;k++){
					for(int h=k;h<=n;h++){
						for(int g=h;g<=n;g++){
							for(int f=g;f<=n;f++){
								for(int d=f;d<=n;d++){
									int w=max(a[i],a[j]);
									w=max(w,a[k]);
									w=max(w,a[h]);
									w=max(w,a[g]);
									w=max(w,a[f]);
									w=max(w,a[d]);
									if(a[i]+a[j]+a[k]+a[h]+a[g]+a[f]+a[d]>w*2&&i!=j&&i!=k&&j!=k&&i!=h&&j!=h&&k!=h&&g!=i&&g!=j&&g!=k&&g!=h&&f!=i&&f!=j&&f!=k&&f!=h&&f!=g&&d!=i&&d!=j&&d!=k&&d!=h&&d!=g&&d!=f) k2++;
								}
								
							}
							
						}
					
					}
					
				}
			}
		}
		for(int i=1;i<=n;i++){
			for(int j=i;j<=n;j++){
				for(int k=j;k<=n;k++){
					for(int h=k;h<=n;h++){
						for(int g=h;g<=n;g++){
							for(int f=g;f<=n;f++){
								for(int d=f;d<=n;d++){
									for(int p=d;p<=n;p++){
										int w=max(a[i],a[j]);
										w=max(w,a[k]);
										w=max(w,a[h]);
										w=max(w,a[g]);
										w=max(w,a[f]);
										w=max(w,a[d]);
										w=max(w,a[p]);
										if(a[i]+a[j]+a[k]+a[h]+a[g]+a[f]+a[d]+a[p]>w*2&&i!=j&&i!=k&&j!=k&&i!=h&&j!=h&&k!=h&&g!=i&&g!=j&&g!=k&&g!=h&&f!=i&&f!=j&&f!=k&&f!=h&&f!=g&&d!=i&&d!=j&&d!=k&&d!=h&&d!=g&&d!=f&&p!=i&&p!=j&&p!=k&&p!=h&&p!=g&&p!=f&&p!=d) k2++;
									}
								}
								
							}
							
						}
					
					}
					
				}
			}
		}
		for(int i=1;i<=n;i++){
			for(int j=i;j<=n;j++){
				for(int k=j;k<=n;k++){
					for(int h=k;h<=n;h++){
						for(int g=h;g<=n;g++){
							for(int f=g;f<=n;f++){
								for(int d=f;d<=n;d++){
									for(int p=d;p<=n;p++){
										for(int o=p;o<=n;o++){
											int w=max(a[i],a[j]);
											w=max(w,a[k]);
											w=max(w,a[h]);
											w=max(w,a[g]);
											w=max(w,a[f]);
											w=max(w,a[d]);
											w=max(w,a[p]);
											w=max(w,a[o]);
											if(a[i]+a[j]+a[k]+a[h]+a[g]+a[f]+a[d]+a[p]+a[o]>w*2&&i!=j&&i!=k&&j!=k&&i!=h&&j!=h&&k!=h&&g!=i&&g!=j&&g!=k&&g!=h&&f!=i&&f!=j&&f!=k&&f!=h&&f!=g&&d!=i&&d!=j&&d!=k&&d!=h&&d!=g&&d!=f&&p!=i&&p!=j&&p!=k&&p!=h&&p!=g&&p!=f&&p!=d&&o!=i&&o!=j&&o!=k&&o!=h&&o!=g&&o!=g&&o!=f&&o!=d&&o!=p) k2++;
										}
										
									}
								}
								
							}
							
						}
					
					}
					
				}
			}
		}
		int w=max(a[1],a[2]);
		w=max(w,a[3]);
		w=max(w,a[5]);
		w=max(w,a[4]);
		w=max(w,a[6]);
		w=max(w,a[7]);
		w=max(w,a[8]);
		w=max(w,a[9]);
		w=max(w,a[10]);
		if(a[1]+a[2]+a[3]+a[4]+a[5]+a[6]+a[7]+a[8]+a[9]+a[10]>w*2) k2++;
	}
	cout<<k2;
}
