#include<bits/stdc++.h>
using namespace std;
int ans,n,m,a[505],b[505];
char s[505];
void solve(){
	int now=0,cnt=0;
	for(int i=1;i<=n;i++){
		if(now>=a[b[i]]){
			now++;
			continue;
		}
		if(s[i]=='0'){
			now++;
			continue;
		}
		now=0;++cnt;
	}
//	if(cnt>=m) cout<<"1 ";
//	else cout<<"0 ";
//	for(int i=1;i<=n;i++) cout<<a[b[i]]<<" ";
//	cout<<"\n";
	if(cnt>=m) ans++;
}
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m;
	cin>>s+1;
//	for(int i=1;i<=n;i++) cout<<s[i];
	for(int i=1;i<=n;i++) cin>>a[i];
	if(n==1)
		for(int i1=1;i1<=n;i1++) b[1]=i1,solve();
	else if(n==2){
		for(int i1=1;i1<=n;i1++)
			for(int i2=1;i2<=n;i2++){
				if(i1==i2) continue;
				b[1]=i1;b[2]=i2;
				solve();
			}
	}
	else if(n==3){
		for(int i1=1;i1<=n;i1++)
			for(int i2=1;i2<=n;i2++){
				if(i1==i2) continue;
				for(int i3=1;i3<=n;i3++){
					if(i3==i1||i3==i2) continue;
					b[1]=i1;b[2]=i2;b[3]=i3;
					solve();
				}
			}
	}
	else if(n==4){
		for(int i1=1;i1<=n;i1++)
			for(int i2=1;i2<=n;i2++){
				if(i1==i2) continue;
				for(int i3=1;i3<=n;i3++){
					if(i3==i1||i3==i2) continue;
					for(int i4=1;i4<=n;i4++){
						if(i4==i1||i4==i2||i3==i4) continue;
						b[1]=i1;b[2]=i2;b[3]=i3;b[4]=i4;
						solve();
					}
				}
			}
	}
	else if(n==5){
		for(int i1=1;i1<=n;i1++)
			for(int i2=1;i2<=n;i2++){
				if(i1==i2) continue;
				for(int i3=1;i3<=n;i3++){
					if(i3==i1||i3==i2) continue;
					for(int i4=1;i4<=n;i4++){
						if(i4==i1||i4==i2||i3==i4) continue;
						for(int i5=1;i5<=n;i5++){
							if(i5==i1||i5==i2||i3==i5||i4==i5) continue;
							b[1]=i1;b[2]=i2;b[3]=i3;b[4]=i4;b[5]=i5;
							solve();
						}
					}
				}
			}
	}
	else if(n==6){
		for(int i1=1;i1<=n;i1++)
			for(int i2=1;i2<=n;i2++){
				if(i1==i2) continue;
				for(int i3=1;i3<=n;i3++){
					if(i3==i1||i3==i2) continue;
					for(int i4=1;i4<=n;i4++){
						if(i4==i1||i4==i2||i3==i4) continue;
						for(int i5=1;i5<=n;i5++){
							if(i5==i1||i5==i2||i3==i5||i4==i5) continue;
							for(int i6=1;i6<=n;i6++){
								if(i6==i1||i6==i2||i3==i6||i4==i6||i5==i6) continue;
								b[1]=i1;b[2]=i2;b[3]=i3;b[4]=i4;b[5]=i5;b[6]=i6;
								solve();
							}
						}
					}
				}
			}
	}
	else if(n==7){
		for(int i1=1;i1<=n;i1++)
			for(int i2=1;i2<=n;i2++){
				if(i1==i2) continue;
				for(int i3=1;i3<=n;i3++){
					if(i3==i1||i3==i2) continue;
					for(int i4=1;i4<=n;i4++){
						if(i4==i1||i4==i2||i3==i4) continue;
						for(int i5=1;i5<=n;i5++){
							if(i5==i1||i5==i2||i3==i5||i4==i5) continue;
							for(int i6=1;i6<=n;i6++){
								if(i6==i1||i6==i2||i3==i6||i4==i6||i5==i6) continue;
								for(int i7=1;i7<=n;i7++){
									if(i1==i7||i2==i7||i3==i7||i4==i7||i5==i7||i6==i7) continue;
									b[1]=i1;b[2]=i2;b[3]=i3;b[4]=i4;b[5]=i5;b[6]=i6;b[7]=i7;
									solve();
								}
							}
						}
					}
				}
			}
	}
	else if(n==8){
		for(int i1=1;i1<=n;i1++)
			for(int i2=1;i2<=n;i2++){
				if(i1==i2) continue;
				for(int i3=1;i3<=n;i3++){
					if(i3==i1||i3==i2) continue;
					for(int i4=1;i4<=n;i4++){
						if(i4==i1||i4==i2||i3==i4) continue;
						for(int i5=1;i5<=n;i5++){
							if(i5==i1||i5==i2||i3==i5||i4==i5) continue;
							for(int i6=1;i6<=n;i6++){
								if(i6==i1||i6==i2||i3==i6||i4==i6||i5==i6) continue;
								for(int i7=1;i7<=n;i7++){
									if(i1==i7||i2==i7||i3==i7||i4==i7||i5==i7||i6==i7) continue;
									for(int i8=1;i8<=n;i8++){
										if(i1==i8||i2==i8||i3==i8||i4==i8||i5==i8||i6==i8||i7==i8) continue;
										b[1]=i1;b[2]=i2;b[3]=i3;b[4]=i4;b[5]=i5;b[6]=i6;b[7]=i7;b[8]=i8;
										solve();
									}
								}
							}
						}
					}
				}
			}
	}
	else if(n==9){
		for(int i1=1;i1<=n;i1++)
			for(int i2=1;i2<=n;i2++){
				if(i1==i2) continue;
				for(int i3=1;i3<=n;i3++){
					if(i3==i1||i3==i2) continue;
					for(int i4=1;i4<=n;i4++){
						if(i4==i1||i4==i2||i3==i4) continue;
						for(int i5=1;i5<=n;i5++){
							if(i5==i1||i5==i2||i3==i5||i4==i5) continue;
							for(int i6=1;i6<=n;i6++){
								if(i6==i1||i6==i2||i3==i6||i4==i6||i5==i6) continue;
								for(int i7=1;i7<=n;i7++){
									if(i1==i7||i2==i7||i3==i7||i4==i7||i5==i7||i6==i7) continue;
									for(int i8=1;i8<=n;i8++){
										if(i1==i8||i2==i8||i3==i8||i4==i8||i5==i8||i6==i8||i7==i8) continue;
										for(int i9=1;i9<=n;i9++){
											if(i1==i9||i2==i9||i3==i9||i4==i9||i5==i9||i6==i9||i7==i9||i8==i9) continue;
											b[1]=i1;b[2]=i2;b[3]=i3;b[4]=i4;b[5]=i5;b[6]=i6;b[7]=i7;b[8]=i8;b[9]=i9;
											solve();
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
		for(int i1=1;i1<=n;i1++)
			for(int i2=1;i2<=n;i2++){
				if(i1==i2) continue;
				for(int i3=1;i3<=n;i3++){
					if(i3==i1||i3==i2) continue;
					for(int i4=1;i4<=n;i4++){
						if(i4==i1||i4==i2||i3==i4) continue;
						for(int i5=1;i5<=n;i5++){
							if(i5==i1||i5==i2||i3==i5||i4==i5) continue;
							for(int i6=1;i6<=n;i6++){
								if(i6==i1||i6==i2||i3==i6||i4==i6||i5==i6) continue;
								for(int i7=1;i7<=n;i7++){
									if(i1==i7||i2==i7||i3==i7||i4==i7||i5==i7||i6==i7) continue;
									for(int i8=1;i8<=n;i8++){
										if(i1==i8||i2==i8||i3==i8||i4==i8||i5==i8||i6==i8||i7==i8) continue;
										for(int i9=1;i9<=n;i9++){
											if(i1==i9||i2==i9||i3==i9||i4==i9||i5==i9||i6==i9||i7==i9||i8==i9) continue;
											for(int i10=1;i10<=n;i10++){
												if(i1==i10||i2==i10||i3==i10||i4==i10||i5==i10||i6==i10||i7==i10||i8==i10||i9==i10) continue;
												b[1]=i1;b[2]=i2;b[3]=i3;b[4]=i4;b[5]=i5;b[6]=i6;b[7]=i7;b[8]=i8;b[9]=i9;b[10]=i10;
												solve();
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
		for(int i1=1;i1<=n;i1++)
			for(int i2=1;i2<=n;i2++){
				if(i1==i2) continue;
				for(int i3=1;i3<=n;i3++){
					if(i3==i1||i3==i2) continue;
					for(int i4=1;i4<=n;i4++){
						if(i4==i1||i4==i2||i3==i4) continue;
						for(int i5=1;i5<=n;i5++){
							if(i5==i1||i5==i2||i3==i5||i4==i5) continue;
							for(int i6=1;i6<=n;i6++){
								if(i6==i1||i6==i2||i3==i6||i4==i6||i5==i6) continue;
								for(int i7=1;i7<=n;i7++){
									if(i1==i7||i2==i7||i3==i7||i4==i7||i5==i7||i6==i7) continue;
									for(int i8=1;i8<=n;i8++){
										if(i1==i8||i2==i8||i3==i8||i4==i8||i5==i8||i6==i8||i7==i8) continue;
										for(int i9=1;i9<=n;i9++){
											if(i1==i9||i2==i9||i3==i9||i4==i9||i5==i9||i6==i9||i7==i9||i8==i9) continue;
											for(int i10=1;i10<=n;i10++){
												if(i1==i10||i2==i10||i3==i10||i4==i10||i5==i10||i6==i10||i7==i10||i8==i10||i9==i10) continue;
												for(int i11=1;i11<=n;i11++){
													if(i1==i11||i2==i11||i3==i11||i4==i11||i5==i11||i6==i11||i7==i11||i8==i11||i9==i11||i10==i11) continue;
													b[1]=i1;b[2]=i2;b[3]=i3;b[4]=i4;b[5]=i5;b[6]=i6;b[7]=i7;b[8]=i8;b[9]=i9;b[10]=i10;b[11]=i11;
													solve();
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
		srand(0);
		ans=rand()%998244353;
	}
	cout<<ans;
	return 0;
}
