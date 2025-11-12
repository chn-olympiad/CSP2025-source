#include<bits/stdc++.h>
using namespace std;
int t;
struct STUDENT{
	int a,b,c;
	int max,mid;
	int cha;
}s[100005],s2[100005];
int n;
int as=0,bs=0,cs=0;
bool cmp(STUDENT x,STUDENT y){
	
	if(x.cha==y.cha){
		if(as>n/2) return x.a>y.a;
		else if(bs>n/2) return x.b>y.b;
		else return x.c>y.c;	
	}
	return x.cha>=y.cha;
}

int main(){
  freopen("club.in","r",stdin);
  freopen("club.out","w",stdout);
	cin>>t;
	while(t--){ 	
		cin>>n;
		memset(s,0,sizeof(s));
		memset(s2,0,sizeof(s2));
		as=0;
		bs=0;
		cs=0;
		for(int i=1;i<=n;++i){
			cin>>s[i].a>>s[i].b>>s[i].c;
			if(s[i].b==s[i].a&&s[i].c==s[i].b){
				as++;
				s[i].max=1;
				s[i].mid=2;
				s[i].cha=0;
			}
			if(s[i].a==s[i].b&&s[i].a>s[i].c){
				as++;
				s[i].max=1;
				s[i].mid=2;
				s[i].cha=0;
			}
			if(s[i].a==s[i].c&&s[i].a>s[i].b){
				as++;
				s[i].max=1;
				s[i].mid=3;
				s[i].cha=0;
			}
			if(s[i].c==s[i].b&&s[i].c>s[i].a){
				bs++;
				s[i].max=2;
				s[i].mid=3;
				s[i].cha=0;
			}
			if(s[i].a==s[i].b&&s[i].a<s[i].c){
				cs++;
				s[i].max=3;
				s[i].mid=2;
				s[i].cha=s[i].c-s[i].a;
			}
			if(s[i].a==s[i].c&&s[i].a<s[i].b){
				bs++;
				s[i].max=2;
				s[i].mid=1;
				s[i].cha=s[i].b-s[i].a;
			}
			if(s[i].c==s[i].b&&s[i].c<s[i].a){
				as++;
				s[i].max=1;
				s[i].mid=2;
				s[i].cha=s[i].a-s[i].b;
			}
			if(s[i].a>s[i].b&&s[i].b>s[i].c){
				as++;
				s[i].max=1;
				s[i].mid=2;
				s[i].cha=s[i].a-s[i].b;
			}
			if(s[i].a>s[i].c&&s[i].c>s[i].b){
				as++;
				s[i].max=1;
				s[i].mid=3;
				s[i].cha=s[i].a-s[i].c;
			}
			if(s[i].b>s[i].a&&s[i].a>s[i].c){
				bs++;
				s[i].max=2;
				s[i].mid=1;
				s[i].cha=s[i].b-s[i].a;
			}
			if(s[i].b>s[i].c&&s[i].c>s[i].a){
				bs++;
				s[i].max=2;
				s[i].mid=3;
				s[i].cha=s[i].b-s[i].c;
			}
			if(s[i].c>s[i].a&&s[i].a>s[i].b){
				cs++;
				s[i].max=3;
				s[i].mid=1;
				s[i].cha=s[i].c-s[i].a;
			}
			if(s[i].c>s[i].b&&s[i].b>s[i].a){
				cs++;
				s[i].max=3;
				s[i].mid=2;
				s[i].cha=s[i].c-s[i].b;
			}
		} 
		long long sum=0;
		if(max(as,max(bs,cs))<=n/2){
			for(int i=1;i<=n;++i){
				if(s[i].max==1){
					sum+=s[i].a;
				}
				else if(s[i].max==2){
					sum+=s[i].b;
				}
				else if(s[i].max==3){
					sum+=s[i].c;
				}
			}
			cout<<sum<<endl;
		}
		else{
			int cnt=0,cnt2;
			if(as>n/2){
				for(int i=1;i<=n;++i){
					if(s[i].max==1){
						cnt++;
						s2[cnt]=s[i];
					}
				}
				 cnt2=cnt;
				for(int i=1;i<=n;++i){
					if(s[i].max!=1){
						cnt2++;
					s2[cnt2]=s[i];
					}
				}
			}
			if(bs>n/2){
				for(int i=1;i<=n;++i){
					if(s[i].max==2){
						cnt++;
						s2[cnt]=s[i];
					}
				}
				 cnt2=cnt;
				for(int i=1;i<=n;++i){
					if(s[i].max!=2){
						cnt2++;
						s2[cnt2]=s[i];
					}
				}
			}
			if(cs>n/2){
				for(int i=1;i<=n;++i){
					if(s[i].max==3){
						cnt++;
						s2[cnt]=s[i];
					}
				}
				cnt2=cnt;
				for(int i=1;i<=n;++i){
					if(s[i].max!=3){
						cnt2++;
					s2[cnt2]=s[i];
					}
				}
			}
		sort(s2+1,s2+1+cnt,cmp);
//		for(int i=1;i<=n;++i){
//			printf("%d %d %d %d %d %d\n",s2[i].a,s2[i].b,s2[i].c,s2[i].max,s2[i].mid,s2[i].cha);
//		}
		for(int i=1;i<=n/2;++i){
			if(s2[i].max==1){
				sum+=s2[i].a;
			}
			if(s2[i].max==2){
				sum+=s2[i].b;
			}
			if(s2[i].max==3){
				sum+=s2[i].c;
			}
		}
			
		
		for(int i=n/2+1;i<=cnt;++i){
			if(s2[i].mid==1){
				sum+=s2[i].a;
			}
			if(s2[i].mid==2){
				sum+=s2[i].b;
			}
			if(s2[i].mid==3){
				sum+=s2[i].c;
			}
		}
		for(int i=cnt+1;i<=n;++i){
			if(s2[i].max==1){
				sum+=s2[i].a;
			}
			if(s2[i].max==2){
				sum+=s2[i].b;
			}
			if(s2[i].max==3){
				sum+=s2[i].c;
			}
		}
		cout<<sum<<endl;
	}
}
  fclose(stdin);
  fclose(stdout);
	return 0;
}
