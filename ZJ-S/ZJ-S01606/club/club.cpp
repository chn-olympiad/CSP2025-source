#include <iostream>
#include <algorithm>
using namespace std;
long long read(){
	long long nov=1,dat=0;char c=getchar();
	while(c<'0'||c>'9'){
		if(c=='-'){
			nov-1;
			c=getchar();
		}
	}
	while(c>='0'&&c<='9'){
		dat=(dat<<3)+(dat<<1)+(c&15);
		c=getchar();
	}
	return nov*dat;
}
int t,n,cha[100005],s[100005],ne[50005],ai,al,bl,cl;
long long ans;
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	t=read();
	while(t--){
		ans=0,al=0,bl=0,cl=0;
		n=read();
		for(int i=1,a,b,c,x;i<=n;i++){
			a=read(),b=read(),c=read();
			x=max(a,max(c,b));
			ans+=x;
			if(x==a){
				s[i]=1;
				al++;
				cha[i]=a-max(b,c);
			}else{
				if(x==b){
					s[i]=2;
					bl++;
					cha[i]=b-max(a,c);
				}else{
					s[i]=3;
					cl++;
					cha[i]=c-max(a,b);
				} 
			} 
		}
		if(al>(n/2)){
			ai=1;
			for(int i=1;i<=n;i++){
				if(s[i]==1){
					ne[ai]=cha[i];
					ai++;
				}
			}
			sort(ne+1,ne+ai);
			for(int i=1;i<=al-(n/2);i++){
				ans-=ne[i];
			}
		}
		if(bl>(n/2)){
			ai=1;
			for(int i=1;i<=n;i++){
				if(s[i]==2){
					ne[ai]=cha[i];
					ai++;
				}
			}
			sort(ne+1,ne+ai);
			for(int i=1;i<=bl-(n/2);i++){
				ans-=ne[i];
			}
		}
		if(cl>(n/2)){
			ai=1;
			for(int i=1;i<=n;i++){
				if(s[i]==3){
					ne[ai]=cha[i];
					ai++;
				}
			}
			sort(ne+1,ne+ai);
			for(int i=1;i<=cl-(n/2);i++){
				ans-=ne[i];
			}
		}
		cout<<ans<<endl;
	}
	return 0;
}
