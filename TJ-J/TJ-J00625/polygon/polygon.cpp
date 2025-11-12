#include<bits/stdc++.h>
using namespace std;
long long n,t,t1,ans;
long long m[10005];
int f3(){
	int ans=0;
	for(int a=1;a<=n-2;a++){
		for(int b=a+1;b<=n-1;b++){
			for(int c=b+1;c<=n;c++){
				t=m[a]+m[b]+m[c];
				t1=max(m[a],max(m[b],m[c]))*2;
				if(t>t1){
					ans++;
				}
			}
		}
	}
	return ans;
}int f4(){
	int ans=0;
	for(int a=1;a<=n-3;a++){
		for(int b=a+1;b<=n-2;b++){
			for(int c=b+1;c<=n-1;c++){
				for(int d=c+1;d<=n;d++){
					t=m[a]+m[b]+m[c]+m[d];
					t1=max(max(m[a],m[d]),max(m[b],m[c]))*2;
					if(t>t1){
						ans++;
					}
				}
			}
		}
	}
	return ans;
}int f5(){
	int ans=0;
	for(int a=1;a<=n-4;a++){
		for(int b=a+1;b<=n-3;b++){
			for(int c=b+1;c<=n-2;c++){
				for(int d=c+1;d<=n-1;d++){
					for(int e=d+1;e<=n;e++){
						t=m[a]+m[b]+m[c]+m[d]+m[e];
						t1=max(max(m[a],m[b]),max(m[c],max(m[d],m[e])))*2;
						if(t>t1){
							ans++;
						}
					}
				}
			}
		}
	}
	return ans;
}int f6(){
	int ans=0;
	for(int a=1;a<=n-5;a++){
		for(int b=a+1;b<=n-4;b++){
			for(int c=b+1;c<=n-3;c++){
				for(int d=c+1;d<=n-2;d++){
					for(int e=d+1;e<=n-1;e++){
						for(int f=e+1;f<=n;f++){
							t=m[a]+m[b]+m[c]+m[d]+m[e];
							t1=max(max(m[a],m[b]),max(max(m[c],m[d]),max(m[e],m[f])))*2;
							if(t>t1){
								ans++;
							}
						}
					}
				}
			}
		}
	}
	return ans;
}int f7(){
	int ans=0;
	for(int a=1;a<=n-6;a++){
		for(int b=a+1;b<=n-5;b++){
			for(int c=b+1;c<=n-4;c++){
				for(int d=c+1;d<=n-3;d++){
					for(int e=d+1;e<=n-2;e++){
						for(int f=e+1;f<=n-1;f++){
							for(int g=e+1;g<=n;g++){
								t=m[a]+m[b]+m[c]+m[d]+m[e]+m[f]+m[g];
								t1=max(max(m[a],max(m[b],m[c])),max(max(m[d],m[e]),max(m[f],m[g])))*2;
								if(t>t1){
									ans++;
								}
							}
						}
					}
				}
			}
		}
	}
	return ans;
}int f8(){
	int ans=0;
	for(int a=1;a<=n-7;a++){
		for(int b=a+1;b<=n-6;b++){
			for(int c=b+1;c<=n-5;c++){
				for(int d=c+1;d<=n-4;d++){
					for(int e=d+1;e<=n-3;e++){
						for(int f=e+1;f<=n-2;f++){
							for(int g=e+1;g<=n-1;g++){
								for(int h=g+1;g<=n;h++){
									t=m[a]+m[b]+m[c]+m[d]+m[e]+m[f]+m[g]+m[h];
									t1=max(max(m[a],max(m[b],m[c])),max(max(max(m[d],m[e]),max(m[f],m[g])),m[h]))*2;
									if(t>t1){
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
	return ans;
}int f9(){
	int ans=0;
	for(int a=1;a<=n-7;a++){
		for(int b=a+1;b<=n-6;b++){
			for(int c=b+1;c<=n-5;c++){
				for(int d=c+1;d<=n-4;d++){
					for(int e=d+1;e<=n-3;e++){
						for(int f=e+1;f<=n-2;f++){
							for(int g=e+1;g<=n-1;g++){
								for(int h=g+1;g<=n;h++){
									for(int i=h+1;i<=n;i++){
										t=m[a]+m[b]+m[c]+m[d]+m[e]+m[f]+m[g]+m[h]+m[i];
										t1=max(max(m[a],max(m[b],m[c])),max(max(max(m[d],m[e]),max(m[f],m[g])),max(m[h],m[i])))*2;
										if(t>t1){
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
	return ans;
}
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>m[i];
	}if(n==3){
		t=m[1]+m[2]+m[3];
		t1=max(m[1],max(m[2],m[3]))*2;
		if(t>=t1){
			ans++;
		}
	}else if(n==4){
		ans+=f3();
		t=m[1]+m[2]+m[3]+m[4];
		t1=max(max(m[1],m[2]),max(m[3],m[4]))*2;
		if(t>=t1){
			ans++;
		}
	}else if(n==5){
		ans+=f3()+f4();
		t=m[1]+m[2]+m[3]+m[4]+m[5];
		t1=max(max(m[1],m[2]),max(m[3],max(m[4],m[5])))*2;
		if(t>t1){
			ans++;
		}
	}else if(n==6){
		ans+=f3()+f4()+f5();
		t=m[1]+m[2]+m[3]+m[4]+m[5]+m[6];
		t1=max(max(m[1],m[2]),max(max(m[3],m[4]),max(m[5],m[6])))*2;
		if(t>t1){
			ans++;
		}
	}else if(n==7){
		ans+=f3()+f4()+f5()+f6();
		t=m[1]+m[2]+m[3]+m[4]+m[5]+m[6]+m[7];
		t1=max(max(m[1],max(m[2],m[3])),max(max(m[4],m[5]),max(m[6],m[7])))*2;
		if(t>t1){
			ans++;
		}
	}else if(n==8){
		ans+=f3()+f4()+f5()+f6()+f7();
		t=m[1]+m[2]+m[3]+m[4]+m[5]+m[6]+m[7]+m[8];
		t1=max(max(max(m[1],m[2]),max(m[3],m[4])),max(max(m[5],m[6]),max(m[7],m[8])))*2;
		if(t>t1){
			ans++;
		}
	}else if(n==9){
		ans+=f3()+f4()+f5()+f6()+f7()+f8();
		t=m[1]+m[2]+m[3]+m[4]+m[5]+m[6]+m[7]+m[8]+m[9];
		t1=max(max(max(m[1],m[2]),max(m[3],m[4])),max(max(max(m[5],m[6]),max(m[7],m[8])),m[9]))*2;
		if(t>t1){
			ans++;
		}
	}else if(n==10){
		ans+=f3()+f4()+f5()+f6()+f7()+f8()+f9();
		t=m[1]+m[2]+m[3]+m[4]+m[5]+m[6]+m[7]+m[8]+m[9]+m[10];
		t1=max(max(max(m[1],m[2]),max(m[3],m[4])),max(max(max(m[5],m[6]),max(m[7],m[8])),max(m[9],m[10])))*2;
		if(t>t1){
			ans++;
		}
	}
	cout<<ans<<endl;
	return 0;
}
