#include<bits/stdc++.h>
using namespace std;
int t;
int const N=1e5+5;
struct F{
	int a1,a2,a3;
	int b1,b2,b3;
	int c1,c2,c3;
	int f;
}a[N];
bool qq(F x,F y){
	return x.c1<y.c1;
}
bool q13(F x,F y){
	return x.a1-x.a3<y.a1<y.a3;
}
bool q12(F x,F y){
	return x.a1-x.a2<y.a1<y.a2;
}
bool q23(F x,F y){
	return x.a2-x.a3<y.a2<y.a3;
}
bool q21(F x,F y){
	return x.a2-x.a1<y.a2<y.a1;
}
bool q32(F x,F y){
	return x.a3-x.a2<y.a3<y.a2;
}
bool q31(F x,F y){
	return x.a3-x.a1<y.a3<y.a1;
}
bool ww(F x,F y){
	return x.a1>y.a1;
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
	cin>>t;
	while(t--){
		long long ans=0;
		int n;
		cin>>n;
		
		int q1=n/2;
		int q2=n/2;
		int q3=n/2;
		for(int i=1;i<=n;i++){
			cin>>a[i].a1>>a[i].a2>>a[i].a3;
			a[i].f=0;
			int maxn=-1e9;
			maxn=max(a[i].a2,a[i].a1);
			maxn=max(maxn,a[i].a3);
			
			a[i].b1=maxn;
			
			int minn=1e9;
			minn=min(a[i].a1,a[i].a2);
			minn=min(a[i].a3,minn);
			
			a[i].b3=minn;
			a[i].b2=a[i].a1+a[i].a2+a[i].a3-minn-maxn;
			a[i].c1=a[i].b1-a[i].b2;
			a[i].c2=a[i].b2-a[i].b3;
			a[i].c3=a[i].b1-a[i].b3;
			
		//	cout<<a[i].b1<<" "<<a[i].b2<<" "<<a[i].b3<<"\n";
		}
		int flag=0;
		for(int i=1;i<=n;i++){
				if(a[i].a2!=0||a[i].a3!=0){
				flag=1;
			}
		}
		if(flag==0){
			ans=0;
			sort(a+1,a+1+n,ww);
			for(int i=1;i<=n/2;i++){
				//cout<<a[i].a1<<" ";
				ans+=a[i].a1;
			}
		}
		ans=0;
			
		for(int i=1;i<=n;i++){
			if(a[i].a1==a[i].b1){
				q1--;
				ans+=a[i].a1;
			}
			if(a[i].a2==a[i].b1){
				q2--;
				ans+=a[i].a2;
			}
			if(a[i].a3==a[i].b1){
				q3--;
				ans+=a[i].a3;
			}
		}
			
	//	cout<<q1<<" "<<q2<<" "<<q3; 
		if(q1>=0&&q2>=0&&q3>=0){
			cout<<ans<<"\n";
		}else{
			if(q1<0&&q2>=0&&q3>=0){//1111
				int o=-q1;
				for(int i=1;i<=o;i++){
					//ans-=a[i].c1;
					sort(1+a,1+a+n,qq);
					if(a[i].a1-a[i].a2==a[i].c1){
						if(q2-1>=0){
							ans-=a[i].c1;
							q2--;
							a[i].f=1;
						}else{
							if(q3-1>=0){
								sort(a+1,a+1+n,q13);///
								for(int i=1;i<=n;i++){
									if(a[i].f!=1){
										ans=ans-(a[i].a1-a[i].a3);
										q3--;
										a[i].f=1;
										break;
									}
								}
								
							}
						}
					}
					if(a[i].a1-a[i].a3==a[i].c1){
						if(q3-1>=0){
							ans-=a[i].c1;
							q3--;
							a[i].f=1;
						}else{
							if(q2-1>=0){
								sort(a+1,a+1+n,q12);
								for(int i=1;i<=n;i++){
									if(a[i].f!=1){
										ans=ans-(a[i].a1-a[i].a2);//
										q2--;
										a[i].f=1;
										break;
									}
								}
								
							}
						}
					}
					
				}
			}else{
				if(q2<0&&q1>=0&&q3>=0){//2222
				int o=-q2;
				for(int i=1;i<=o;i++){
					//ans-=a[i].c1;
					sort(1+a,1+a+n,qq);
					if(a[i].a2-a[i].a1==a[i].c1){//
						if(q1-1>=0){
							ans-=a[i].c1;
							q1--;
							a[i].f=1;
						}else{
							if(q3-1>=0){
								sort(a+1,a+1+n,q23);
								for(int i=1;i<=n;i++){
									if(a[i].f!=1){
										ans=ans-(a[i].a2-a[i].a3);
										q3--;
										a[i].f=1;
										break;
									}
								}
								
							}
						}
					}
					if(a[i].a2-a[i].a3==a[i].c1){
						if(q3-1>=0){
							ans-=a[i].c1;
							q3--;
							a[i].f=1;
						}else{
							if(q1-1>=0){
								sort(a+1,a+1+n,q21);
								for(int i=1;i<=n;i++){
									if(a[i].f!=1){
										ans=ans-(a[i].a2-a[i].a1);
										q1--;
										a[i].f=1;
										break;
									}
								}
								
							}
						}
					}
					
				}	
				}else{
					if(q3<0&&q1>=0&&q2>=0){//3333
				int o=-q3;
				for(int i=1;i<=o;i++){
					//ans-=a[i].c1;
					sort(1+a,1+a+n,qq);
					if(a[i].a3-a[i].a1==a[i].c1){//
						if(q1-1>=0){
							ans-=a[i].c1;
							q1--;
							a[i].f=1;
						}else{
							if(q2-1>=0){
								sort(a+1,a+1+n,q32);
								for(int i=1;i<=n;i++){
									if(a[i].f!=1){
										ans=ans-(a[i].a3-a[i].a2);
										q2--;
										a[i].f=1;
										break;
									}
								}
								
							}
						}
					}
					if(a[i].a3-a[i].a2==a[i].c1){
						if(q2-1>=0){
							ans-=a[i].c1;
							q2--;
							a[i].f=1;
						}else{
							if(q1-1>=0){
								sort(a+1,a+1+n,q31);
								for(int i=1;i<=n;i++){
									if(a[i].f!=1){
										ans=ans-(a[i].a3-a[i].a1);
										q1--;
										a[i].f=1;
										break;
									}
								}
								
							}
						}
					}
					
				}	
				}else if(q1<0&&q2<0&&q3>=0){//4444
					int o=-q1;
					sort(a+1,a+1+n,q13);
					for(int i=1;i<=o;i++){
						if(q3-1>=0){
							if(a[i].f!=1){
								ans=ans-(a[i].a1-a[i].a3);
								a[i].f=1;
								q3--;
							}
						}
						
					}
					int p=-q2;
					sort(a+1,a+1+n,q23);
					for(int i=1;i<=p;i++){
						if(q3-1>=0){
							if(a[i].f!=1){
								ans=ans-(a[i].a2-a[i].a3);
								a[i].f=1;
								q3--;
							}
						}
						
					}
				}else if(q1<0&&q3<0&&q2>=0){//555
					int o=-q1;
					sort(a+1,a+1+n,q12);
					for(int i=1;i<=o;i++){
						if(q3-1>=0){
							if(a[i].f!=1){
								ans=ans-(a[i].a1-a[i].a2);
								a[i].f=1;
								q2--;
							}
						}
						
					}
					int p=-q3;
					sort(a+1,a+1+n,q32);
					for(int i=1;i<=p;i++){
						if(q3-1>=0){
							if(a[i].f!=1){
								ans=ans-(a[i].a3-a[i].a2);
								a[i].f=1;
								q2--;
							}
						}
						
					}
				}else if(q1>=0&&q2<0&&q3<0){//666
					int o=-q2;
					sort(a+1,a+1+n,q21);
					for(int i=1;i<=o;i++){
						if(q1-1>=0){
							if(a[i].f!=1){
								ans=ans-(a[i].a2-a[i].a1);
								a[i].f=1;
								q1--;
							}
						}
						
					}
					int p=-q3;
					sort(a+1,a+1+n,q31);
					for(int i=1;i<=p;i++){
						if(q1-1>=0){
							if(a[i].f!=1){
								ans=ans-(a[i].a3-a[i].a1);
								a[i].f=1;
								q1--;
							}
						}
						
					}
				}
					
					
				}
			
				
			}
		}
		cout<<ans<<"\n";
		
	}

	return 0;
}
