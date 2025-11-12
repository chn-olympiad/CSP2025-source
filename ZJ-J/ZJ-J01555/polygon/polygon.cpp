#include<bits/stdc++.h>
using namespace std;
int n,x[10005];
int main(){
	//freopen(" polygon.in","r",stdin);
	//freopen(" polygon.out","w",stdout);
	cin>>n;
	for(int i=0;i<n;i++){
		cin>>x[i];
	}
	if(n<3)cout<<0;
	if(n==3){
		int ans=0;
		for(int a=0;a<=1;a++){
			for(int b=0;b<=1;b++){
				for(int c=0;c<=1;c++){
					int add=0,maxx=0;
					if(a){
						add+=x[0];
						maxx=max(maxx,x[0]);
					}
					if(b){
						add+=x[1];
						maxx=max(maxx,x[1]);
					}
					if(c){
						add+=x[2];
						maxx=max(maxx,x[2]);
					}
					if(add>2*maxx)ans++;
				}
			}	
		}
		cout<<ans;
	}
	if(n==4){
		int ans=0;
		for(int a=0;a<=1;a++){
			for(int b=0;b<=1;b++){
				for(int c=0;c<=1;c++){
					for(int d=0;d<=1;d++){
						int add=0,maxx=0;
						if(a){
							add+=x[0];
							maxx=max(maxx,x[0]);
						}
						if(b){
							add+=x[1];
							maxx=max(maxx,x[1]);
						}
						if(c){
							add+=x[2];
							maxx=max(maxx,x[2]);
						}
						if(d){
							add+=x[3];
							maxx=max(maxx,x[3]);
						}
						if(add>2*maxx)ans++;
					}
				}
			}	
		}
		cout<<ans;
	}
	if(n==5){
		int ans=0;
		for(int a=0;a<=1;a++){
			for(int b=0;b<=1;b++){
				for(int c=0;c<=1;c++){
					for(int d=0;d<=1;d++){
						for(int e=0;e<=1;e++){
							int add=0,maxx=0;
							if(a){
								add+=x[0];
								maxx=max(maxx,x[0]);
							}
							if(b){
								add+=x[1];
								maxx=max(maxx,x[1]);
							}
							if(c){
								add+=x[2];
								maxx=max(maxx,x[2]);
							}
							if(d){
								add+=x[3];
								maxx=max(maxx,x[3]);
							}
							if(e){
								add+=x[4];
								maxx=max(maxx,x[4]);
							}
							if(add>2*maxx)ans++;
						}	
					}
				}
			}	
		}
		cout<<ans;
	}
	if(n==6){
		int ans=0;
		for(int a=0;a<=1;a++){
			for(int b=0;b<=1;b++){
				for(int c=0;c<=1;c++){
					for(int d=0;d<=1;d++){
						for(int e=0;e<=1;e++){
							for(int f=0;f<=1;f++){
								int add=0,maxx=0;
								if(a){
									add+=x[0];
									maxx=max(maxx,x[0]);
								}
								if(b){
									add+=x[1];
									maxx=max(maxx,x[1]);
								}
								if(c){
									add+=x[2];
									maxx=max(maxx,x[2]);
								}
								if(d){
									add+=x[3];
									maxx=max(maxx,x[3]);
								}
								if(e){
									add+=x[4];
									maxx=max(maxx,x[4]);
								}
								if(f){
									add+=x[5];
									maxx=max(maxx,x[5]);
								}
								if(add>2*maxx)ans++;
							}	
						}	
					}
				}
			}	
		}
		cout<<ans;
	}
	if(n==7){
		int ans=0;
		for(int a=0;a<=1;a++){
			for(int b=0;b<=1;b++){
				for(int c=0;c<=1;c++){
					for(int d=0;d<=1;d++){
						for(int e=0;e<=1;e++){
							for(int f=0;f<=1;f++){
								for(int g=0;g<=1;g++){
									int add=0,maxx=0;
								if(a){
									add+=x[0];
									maxx=max(maxx,x[0]);
								}
								if(b){
									add+=x[1];
									maxx=max(maxx,x[1]);
								}
								if(c){
									add+=x[2];
									maxx=max(maxx,x[2]);
								}
								if(d){
									add+=x[3];
									maxx=max(maxx,x[3]);
								}
								if(e){
									add+=x[4];
									maxx=max(maxx,x[4]);
								}
								if(f){
									add+=x[5];
									maxx=max(maxx,x[5]);
								}
								if(g){
									add+=x[6];
									maxx=max(maxx,x[6]);
								}
								if(add>2*maxx)ans++;
								}	
							}	
						}	
					}
				}
			}	
		}
		cout<<ans;
	}
	return 0;
}
