#include <bits/stdc++.h>
using namespace std;
struct node{
	int xb,a,b,c,ay,by,cy;
}s[100005];
int cmda(node n,node m){
	return n.a>m.a;
}
int cmdb(node n,node m){
	return n.b>m.b;
}
int cmdc(node n,node m){
	return n.c>m.c;
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
    int t;
    cin>>t;
    while(t--){
    	int n,na=0,nb=0,nc=0,cnt=0;
    	cin>>n;
    	for(int i=1;i<=n;i++){
    		cin>>s[i].ay>>s[i].by>>s[i].cy;
			int minn=min(s[i].ay,min(s[i].by,s[i].cy));
			s[i].xb=i;
    		s[i].a=s[i].ay-minn;
    		s[i].b=s[i].by-minn;
    		s[i].c=s[i].cy-minn;
    		if(s[i].a>s[i].b&&s[i].a>s[i].c){
    			na++;
			}
			if(s[i].b>s[i].a&&s[i].b>s[i].c){
    			nb++;
			}
			if(s[i].c>s[i].b&&s[i].c>s[i].a){
    			nc++;
			}
		}
		sort(s+1,s+1+n,cmda);
		if(na>n/2){
			for(int i=1;i<=n/2;i++){
				cnt+=s[i].ay;
			}
			for(int i=n/2+1;i<=s[i].ay;i++){
				cnt+=max(s[i].by,s[i].cy);
			}
		}else{
			for(int i=1;i<=na;i++){
				cnt+=s[i].ay;
			}
		}
		sort(s+1,s+1+n,cmdb);
		if(nb>n/2){
			for(int i=1;i<=n/2;i++){
				cnt+=s[i].by;
			}
			for(int i=n/2+1;i<=s[i].by;i++){
				cnt+=max(s[i].ay,s[i].by);
			}
		}else{
			for(int i=1;i<=nb;i++){
				cnt+=s[i].by;
			}
		}
		sort(s+1,s+1+n,cmdc);
		if(nc>n/2){
			for(int i=1;i<=n/2;i++){
				cnt+=s[i].cy;
			}
			for(int i=n/2+1;i<=s[i].cy;i++){
				cnt+=max(s[i].ay,s[i].by);
			}
		}else{
			for(int i=1;i<=nc;i++){
				cnt+=s[i].cy;
			}
		}
		cout<<cnt<<endl;
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
