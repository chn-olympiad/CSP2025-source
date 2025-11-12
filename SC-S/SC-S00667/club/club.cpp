#include<bits/stdc++.h>
using namespace std;
long long vss[1000005];
struct ll{
	long long a;
	long long b;
	long long c;
	long long zy;
	long long cy;
}s[1000005];
struct a1{
	long long cs,xh;
}s1[1000005];


struct c1{
	long long cs,xh;
}s3[1000005];


struct b1{
	long long cs,xh;
}s2[1000005];


bool cmp(a1 i,a1 j){
	return i.cs<j.cs;
}
bool cm(b1 i,b1 j){
	return i.cs<j.cs;
}
bool cp(c1 i,c1 j){
	return i.cs<j.cs;
}
long long cn=0;
int main (){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	long long t;
	cin>>t;
	while(t--){
		long long n;
		cin>>n;
		long long ans=0;
		for(long long i=1;i<=n;i++){
				s3[i].cs=0;
				s3[i].xh=0;
				s2[i].cs=0;
				s2[i].xh=0;
				s1[i].cs=0;
				s1[i].xh=0;
				s[i].a=0;
				s[i].b=0;
				s[i].c=0;
				vss[i]=0;
		}
		
		for(int i=1;i<=n;i++){
			long long ma=0;
			long long cnt=0;
			long long mi=1e18;
			long long zx=0;
			for(long long j=1;j<=3;j++){
				if(j==1){
					cin>>s[i].a;
					if(s[i].a>ma){
						cnt=j;
						ma=s[i].a;
					}
					mi=min(s[i].a,mi);
					zx+=s[i].a;
				}
				if(j==2){
					cin>>s[i].b;	
					if(s[i].b>ma){
						cnt=j;
						ma=s[i].b;
					}
					mi=min(s[i].b,mi);
					zx+=s[i].b;
				}
				if(j==3){
					cin>>s[i].c;
					if(s[i].c!=0){
						cn++;
					}
						if(s[i].c>ma){
						cnt=j;
						ma=s[i].c;
					}
					mi=min(s[i].c,mi);
					zx+=s[i].c;
				}
//				cout<<i<<"： mi:"<<mi<<"      ma:"<<ma<<"   zx:"<<zx<<endl;
			}
				if(cnt==1){
					s1[i].cs=zx-mi-ma-ma;
					s1[i].xh=i;
				}
				if(cnt==2){
					s2[i].cs=zx-mi-ma-ma;
					s2[i].xh=i;
//					cout<<cnt<<":::::::::::::::::::::::"<<i<<endl;
				}
				if(cnt==3){
					s3[i].cs=zx-mi-ma-ma;
					s3[i].xh=i;	
				}
				
		}
		
		sort(s1+1,s1+1+n,cmp);
		sort(s2+1,s2+1+n,cm);
		sort(s3+1,s3+1+n,cp);
		
		
		
		for(long long i=1;i<=n;i++){
//			cout<<s1[i].cs<<" "<<s1[i].xh<<"    GFHGFHGFDSHH"<<endl;
			long long o=s1[i].xh;
			if(vss[o]==1){
				continue;
			}
			if(s1[i].cs==0){
				break;
			}
			vss[o]=1;
			if(i>n/2){
				ans+=max(s[o].b,s[o].c);
			}else{
				ans+=s[o].a; 
			}
		}
//		cout<<ans<<"    GHFRFBHNTRHBN GTRE"<<endl<<endl<<endl;
		for(long long i=1;i<=n;i++){
//			cout<<s2[i].cs<<" "<<s2[i].xh<<"      FDBFFHGFBN"<<endl;
			long long o=s2[i].xh;
			if(vss[o]==1){
				continue;
			}
			if(s2[i].cs==0){
				break;
			}
			vss[o]=1;
//			cout<<i<<":::::::/;;;;;;;;"<<endl;
			if(i>n/2){
				ans+=max(s[o].a,s[o].c);
			}else{
				ans+=s[o].b; 
//				cout<<s[o].b<<" ::::::::::"<<ans<<endl;
				
			}
		}
//		cout<<ans<<"         GFHJYRCVGB/ndl<<endl<<endl;
		for(long long i=1;i<=n;i++){
//				cout<<s1[i].cs<<" "<<s1[i].xh<<"    DGSAFRRERE"<<endl;
			long long o=s3[i].xh;
			if(vss[o]==1){
				continue;
			}
			if(s3[i].cs==0){
				break;
			}
			vss[o]=1;
			if(i>n/2){
				ans+=max(s[o].b,s[o].a);
			}else{
				ans+=s[o].c; 
			}
		}
		cout<<ans<<"\n";
	}
	
	return 0;
}