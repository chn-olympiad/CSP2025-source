#include<bits/stdc++.h>
using namespace std;
struct me{
	int s1,s2,s3;
}a[100005];
bool cmp(int x,int y){
	return x>y; 
}
bool cmpx(me x,me y){
	return abs(x.s1-x.s2)>abs(y.s1-y.s2);
}
bool cmpy(me x,me y){
	if(abs(x.s1-x.s2)!=abs(y.s1-y.s2)){
		return abs(x.s1-x.s2)>abs(y.s1-y.s2);
	}else{
		return abs(x.s2-x.s3)>abs(y.s2-y.s3);
	}
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int n,t;bool fa,fb;long long sum;
	scanf("%d",&t);
	while(t--){
		fa=1;fb=1;
		sum=0;
		scanf("%d",&n);
		int man=n/2;
		for(int i=1;i<=n;++i){
			scanf("%d %d %d",&a[i].s1,&a[i].s2,&a[i].s3);
			if(a[i].s2!=0){
				fa=0;
			}
			if(a[i].s3!=0){
				fb=0;
			}
		}
		if(fa){//特殊A 
			int at[100005];
			for(int i=1;i<=n;++i){
				at[i]=a[i].s1;
			}	
			sort(at+1,at+n+1,cmp);
			for(int i=1;i<=man;++i){
				sum+=at[i];
			}
		}else if(fb){//特殊B 
			int a1=0,a2=0;
			sort(a+1,a+n+1,cmpx);
			for(int i=1;i<=n;++i){
				if(a[i].s1>=a[i].s2){
					if(a1<man){
						sum+=a[i].s1;
						++a1;
					}else{
						sum+=a[i].s2;
						++a2;
					}
				}else{
					if(a2<man){
						sum+=a[i].s2;
						++a2;
					}else{
						sum+=a[i].s1;
						++a1;
					}
				}
			}
		}else{//通用解 
			int a1=0,a2=0,a3=0;
			sort(a+1,a+n+1,cmpy);
			for(int i=1;i<=n;++i){
				if(a[i].s1>=a[i].s2){//若s1>=s2 
					if(a[i].s1>=a[i].s3){//s1>=s3
						if(a1<man){//s1 yes
							sum+=a[i].s1;
							++a1;
						}else{//s1 no
							if(a[i].s2>=a[i].s3){//s2>=s3
								if(a2<man){//s2 yes
									sum+=a[i].s2;
									++a2;
								}else{//s2 no
									sum+=a[i].s3;
									++a3;
								}
							}else{//s3>s2
								if(a3<man){//s3 yes
									sum+=a[i].s3;
									++a3;
								}else{//s3 no
									sum+=a[i].s2;
									++a2;
								}
							}
						} 
					}else{//s3>s1
						if(a3<man){
							sum+=a[i].s3;
							++a3;
						}else{
							if(a1<man){
								sum+=a[i].s1;
								++a1;
							}else{
								sum+=a[i].s2;
								++a2;
							}
						}
					}
				}else{//s1<s2
					if(a[i].s2>=a[i].s3){//s2>=s3
						if(a2<man){
							sum+=a[i].s2;
							++a2;
						}else{
							if(a[i].s1>=a[i].s3){
								if(a1<man){
									sum+=a[i].s1;
									++a1;
								}else{
									sum+=a[i].s3;
									++a3;
								}
							}else{
								if(a3<man){
									sum+=a[i].s3;
									++a3;
								}else{
									sum+=a[i].s1;
									++a1;
								}
							}
						}
					}else{//s3>s2
						if(a3<man){
							sum+=a[i].s3;
							++a3;
						}else{
							if(a2<man){
								sum+=a[i].s2;
								++a2;
							}else{
								sum+=a[i].s1;
								++a1;
							}
						}
					}
				}
			}
		}
		cout<<sum<<endl;
	}
	return 0;
}
