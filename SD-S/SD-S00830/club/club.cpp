#include<bits/stdc++.h>
using namespace std;
const long long N=1e5+5;
struct edg{
	long long a,b,c;
}k[N];
long long cmp2(long long x,long long y,long long z){
	return max(max(x,y),max(y,z));
}
long long cmp3(long long x,long long y,long long z){
	return min(min(max(x,y),max(y,z)),max(x,z));
}
bool cmp(edg a,edg b){
	if((cmp2(a.a,a.b,a.c)-cmp3(a.a,a.b,a.c))!=(cmp2(b.a,b.b,b.c)-cmp3(b.a,b.b,b.c))){
		return (cmp2(a.a,a.b,a.c)-cmp3(a.a,a.b,a.c))>(cmp2(b.a,b.b,b.c)-cmp3(b.a,b.b,b.c));
	}
	else{
		return cmp2(a.a,a.b,a.c)>cmp2(b.a,b.b,b.c);
	}
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdin);
    long long n,T;
    cin>>T;
    while(T--){
    	cin>>n;
    	for(int i=1;i<=n;i++){
    		cin>>k[i].a>>k[i].b>>k[i].c;
    		
		}
		sort(k+1,k+n+1,cmp);
		long long ans=0,ans1=0,ans2=0,ans3=0,kk=0;
		for(int i=1;i<=n;i++){
			if(k[i].a==cmp2(k[i].a,k[i].b,k[i].c)){
				if(ans1<n/2){
					ans+=cmp2(k[i].a,k[i].b,k[i].c);
					ans1++;
				}
				else{
					ans+=cmp3(k[i].a,k[i].b,k[i].c);
				}
				
			}
			if(k[i].b==cmp2(k[i].a,k[i].b,k[i].c)){
				if(ans2<n/2){
					ans+=cmp2(k[i].a,k[i].b,k[i].c);
					ans2++;
				}
				else{
					ans+=cmp3(k[i].a,k[i].b,k[i].c);
				}
				
			}
			if(k[i].c==cmp2(k[i].a,k[i].b,k[i].c)){
				if(ans3<n/2){
					ans+=cmp2(k[i].a,k[i].b,k[i].c);
					ans3++;
				}
				else{
					ans+=cmp3(k[i].a,k[i].b,k[i].c);
				}
				
			}

		}
		 
		cout<<ans<<endl;
	}
	return 0;
} 
