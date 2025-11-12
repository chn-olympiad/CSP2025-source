#include<bits/stdc++.h>
#define f(a,b) for(int a=b;a<=n;a++)
using namespace std;
const int N=5000+5;
int n,a[N],ans;
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	f(i,1) cin>>a[i];
	//3
	f(i,1){
		f(j,i+1){
			f(k,j+1){
				int s=a[i]+a[j]+a[k];
				int mx=max(a[i],max(a[j],a[k]));
				if(s>mx*2) ans++;
			}
		}
	}
	//4
	f(i,1){
		f(j,i+1){
			f(k,j+1){
				f(h,k+1){
					int s=a[i]+a[j]+a[k]+a[h];
					int mx=max(a[i],max(a[j],max(a[k],a[h])));
					if(s>mx*2) ans++;
				}
			}
		}
	}
	//5
	f(i,1){
		f(j,i+1){
			f(k,j+1){
				f(h,k+1){
					f(l,h+1){
						int s=a[i]+a[j]+a[k]+a[h]+a[l];
						int mx=max(a[i],max(a[j],max(a[k],max(a[h],a[l]))));
						if(s>mx*2) ans++;
					}
				}
			}
		}
	}
	//6
	f(i,1){
		f(j,i+1){
			f(k,j+1){
				f(h,k+1){
					f(l,h+1){
						f(o,l+1){
							int s=a[i]+a[j]+a[k]+a[h]+a[l]+a[o];
							int mx=max(a[i],max(a[j],max(a[k],max(a[h],max(a[l],a[o])))));
							if(s>mx*2) ans++;
						}
					}
				}
			}
		}
	}
	//7
	f(i,1){
		f(j,i+1){
			f(k,j+1){
				f(h,k+1){
					f(l,h+1){
						f(o,l+1){
							f(p,o+1){
								int s=a[i]+a[j]+a[k]+a[h]+a[l]+a[o]+a[p];
								int mx=max(a[i],max(a[j],max(a[k],max(a[h],max(a[l],max(a[o],a[p]))))));
								if(s>mx*2) ans++;
							}
						}
					}
				}
			}
		}
	}
	//8
	f(i,1){
		f(j,i+1){
			f(k,j+1){
				f(h,k+1){
					f(l,h+1){
						f(o,l+1){
							f(p,o+1){
								f(u,p+1){
									int s=a[i]+a[j]+a[k]+a[h]+a[l]+a[o]+a[p]+a[u];
									int mx=max(a[i],max(a[j],max(a[k],max(a[h],max(a[l],max(a[o],max(a[p],a[u])))))));
									if(s>mx*2) ans++;
								}
							}
						}
					}
				}
			}
		}
	}
	//9
	f(i,1){
		f(j,i+1){
			f(k,j+1){
				f(h,k+1){
					f(l,h+1){
						f(o,l+1){
							f(p,o+1){
								f(u,p+1){
									f(y,u+1){
										int s=a[i]+a[j]+a[k]+a[h]+a[l]+a[o]+a[p]+a[u]+a[y];
										int mx=max(a[i],max(a[j],max(a[k],max(a[h],max(a[l],max(a[o],max(a[p],max(a[u],a[y]))))))));
										if(s>mx*2) ans++;
									}
								}
							}
						}
					}
				}
			}
		}
	}
	//10
	f(i,1){
		f(j,i+1){
			f(k,j+1){
				f(h,k+1){
					f(l,h+1){
						f(o,l+1){
							f(p,o+1){
								f(u,p+1){
									f(y,u+1){
										f(t,y+1){
											int s=a[i]+a[j]+a[k]+a[h]+a[l]+a[o]+a[p]+a[u]+a[y]+a[t];
											int mx=max(a[i],max(a[j],max(a[k],max(a[h],max(a[l],max(a[o],max(a[p],max(a[u],max(a[y],a[t])))))))));
											if(s>mx*2) ans++;
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
	fclose(stdin);
	fclose(stdout);
	return 0;
}
