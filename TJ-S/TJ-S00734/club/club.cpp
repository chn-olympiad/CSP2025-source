#include<bits/stdc++.h>
using namespace std;
const int K=1e5+5;
long long a[K][4]= {},n,c[K]= {},d[K]= {},e[K]= {};
long long sum;
long long b[32]= {};
bool cmd(long long a,long long b) {
	return a>b;
}
bool kk() {
	long long a1=0,a2=0,a3=0;
	for(int i=1; i<=n; i++) {
		if(b[i]==1) a1++;
		else if(b[i]==2) a2++;
		else if(b[i]==3) a3++;
	}
	if(max(max(a1,a2),a3)<=n/2) return true;
	return false;
}
int main() {
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int N;
	cin>>N;
	while(N--) {
		sum=-1;
		cin>>n;
		long long x=0,y=0,z=0;
		bool k=true;
		for(int i=1; i<=n; i++) {
			cin>>a[i][1]>>a[i][2]>>a[i][3];
			c[i]=a[i][1],d[i]=a[i][2],e[i]=a[i][3];
			if(a[i][2]==1&&a[i][3]==1) ;
			else k=false;
		}
		if(k) {
			sort(c+1,c+n+1,cmd);
			for(int i=1; i<=n/2; i++) {
				sum+=c[i];
			}
			cout<<sum<<endl;
		} else if(n==2) {
			for(int i1=1; i1<=3; i1++) {
				for(int i2=1; i2<=3; i2++) {
					if(i1!=i2) sum=max(a[1][i1]+a[2][i2],sum);
				}
			}
		} else if(n==4) {
			for(int i1=1; i1<=3; i1++) {
				for(int i2=1; i2<=3; i2++) {
					for(int i3=1; i3<=3; i3++) {
						for(int i4=1; i4<=3; i4++) {
							if(i1==i2&&i1!=i3&&i1!=i4||i1==i3&&i1!=i2&&i1!=i4||i1==i4&&i1!=i2&&i1!=i3||i2==i3&&i2!=i4&&i1!=i2||i2==i4&&i2!=i1&&i2!=i3||i3==i4&&i3!=i2&&i3!=i4) {
								sum=max(a[1][i1]+a[2][i2]+a[3][i3]+a[4][i4],sum);
							}
						}
					}
				}
			}
		} else if(n==10) {
			for(int i1=1; i1<=3; i1++) {
				for(int i2=1; i2<=3; i2++) {
					for(int i3=1; i3<=3; i3++) {
						for(int i4=1; i4<=3; i4++) {
							for(int i5=1; i5<=3; i5++) {
								for(int i6=1; i6<=3; i6++) {
									for(int i7=1; i7<=3; i7++) {
										for(int i8=1; i8<=3; i8++) {
											for(int i9=1; i9<=3; i9++) {
												for(int i10=1; i10<=3; i10++) {
													b[1]=i1,b[2]=i2,b[3]=i3,b[4]=i4,b[5]=i5,b[6]=i6,b[7]=i7,b[8]=i8,b[9]=i9,b[10]=i10;
													if(kk()) {
														sum=max(a[1][i1]+a[2][i2]+a[3][i3]+a[4][i4]+a[5][i5]+a[6][i6]+a[7][i7]+a[8][i8]+a[9][i9]+a[10][i10],sum);
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
		cout<<sum<<endl;
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
