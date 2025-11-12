//#include<bits/stdc++.h>
//using namespace std;
//const int N=5e3+10;
//int n,l[N],s[N];
//int ans=0,maxl,zl;
//bool check(int zl,int maxl,int gs){
//	if(zl>2*maxl&&gs>=3){
//		return 1;
//	}
//	return 0;
//}
//int main() {
////	freopen("polygon.in","r",stdin);
////	freopen("polygon.out","w",stdout);
//	cin>>n;
//	for(int i=1;i<=n;i++){
//		cin>>l[i];
//	}
//	sort(l+1,l+1+n);
//	for(int i=1;i<=n;i++){
//		s[i]=s[i-1]+l[i];
//	}
//	for(int i=3;i<=n;i++){
//		zl=s[i];
//		maxl=s[i]-s[i-1];
//		gs=i;
//		if(check(zl,maxl,gs)){
//			for(int j=i;j<=i-3;j++){
//				
//			}
//		}
//	}
//	cout<<ans;
//	return 0;
//}
#include<bits/stdc++.h>
using namespace std;
const int N=5e3+10,M=50;
int n,l[N];
int ans=0,maxl[M],zl[M];
bool check(int zl,int maxl) {
	if(zl>2*maxl) {
		return 1;
	}
	return 0;
}
int main() {
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1; i<=n; i++) {
		cin>>l[i];
	}
	sort(l+1,l+1+n);
	int ii=0;
	for(int i=1; i<=n; i++) {
		for(int j=i+1; j<=n; j++) {
			for(int k=j+1; k<=n; k++) {
				zl[++ii]=l[i]+l[j]+l[k];
				maxl[ii]=l[k];
			}
		}
	}
	if(n<=3) {
		for(int i=1; i<=ii; i++) {
			if(check(zl[i],maxl[i])) {
				ans++;
			}
		}
		cout<<ans;
		return 0;
	}
	for(int i4=1; i4<=n; i4++) {
		for(int i=i4+1; i<=n; i++) {
			for(int j=i+1; j<=n; j++) {
				for(int k=j+1; k<=n; k++) {
					zl[++ii]=l[i4]+l[i]+l[j]+l[k];
					maxl[ii]=l[k];
				}
			}
		}
	}
	for(int i5=1; i5<=n; i5++) {
		for(int i4=i5+1; i4<=n; i4++) {
			for(int i=i4+1; i<=n; i++) {
				for(int j=i+1; j<=n; j++) {
					for(int k=j+1; k<=n; k++) {
						zl[++ii]=l[i5]+l[i4]+l[i]+l[j]+l[k];
						maxl[ii]=l[k];
					}
				}
			}
		}
	}
	for(int i6=1; i6<=n; i6++) {
		for(int i5=i6+1; i5<=n; i5++) {
			for(int i4=i5+1; i4<=n; i4++) {
				for(int i=i4+1; i<=n; i++) {
					for(int j=i+1; j<=n; j++) {
						for(int k=j+1; k<=n; k++) {
							zl[++ii]=l[i6]+l[i5]+l[i4]+l[i]+l[j]+l[k];
							maxl[ii]=l[k];
						}
					}
				}
			}
		}
	}
	for(int i7=1; i7<=n; i7++) {
		for(int i6=i7+1; i6<=n; i6++) {
			for(int i5=i6+1; i5<=n; i5++) {
				for(int i4=i5+1; i4<=n; i4++) {
					for(int i=i4+1; i<=n; i++) {
						for(int j=i+1; j<=n; j++) {
							for(int k=j+1; k<=n; k++) {
								zl[++ii]=l[i7]+l[i6]+l[i5]+l[i4]+l[i]+l[j]+l[k];
								maxl[ii]=l[k];
							}
						}
					}
				}
			}
		}
	}
	for(int i8=1; i8<=n; i8++) {
		for(int i7=i8+1; i7<=n; i7++) {
			for(int i6=i7+1; i6<=n; i6++) {
				for(int i5=i6+1; i5<=n; i5++) {
					for(int i4=i5+1; i4<=n; i4++) {
						for(int i=i4+1; i<=n; i++) {
							for(int j=i+1; j<=n; j++) {
								for(int k=j+1; k<=n; k++) {
									zl[++ii]=l[i8]+l[i7]+l[i6]+l[i5]+l[i4]+l[i]+l[j]+l[k];
									maxl[ii]=l[k];
								}
							}
						}
					}
				}
			}
		}
	}
	for(int i9=1; i9<=n; i9++) {
		for(int i8=i9+1; i8<=n; i8++) {
			for(int i7=i8+1; i7<=n; i7++) {
				for(int i6=i7+1; i6<=n; i6++) {
					for(int i5=i6+1; i5<=n; i5++) {
						for(int i4=i5+1; i4<=n; i4++) {
							for(int i=i4+1; i<=n; i++) {
								for(int j=i+1; j<=n; j++) {
									for(int k=j+1; k<=n; k++) {
										zl[++ii]=l[i9]+l[i8]+l[i7]+l[i6]+l[i5]+l[i4]+l[i]+l[j]+l[k];
										maxl[ii]=l[k];
									}
								}
							}
						}
					}
				}
			}
		}
	}
	for(int i=1; i<=ii; i++) {
		if(check(zl[i],maxl[i])) {
			ans++;
		}
	}
	cout<<ans;
	return 0;
}
