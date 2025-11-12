#include<bits/stdc++.h>
using namespace std;
int t,n;
const int N=1e5+10;
struct node{
	int a,b,c;
}s[N];
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	while(t--){
		int x=0,y=0,z=0;
		int px=0,py=0,pz=0;
		int mx=INT_MAX,my=INT_MAX,mz=INT_MAX;
		int mx2,my2,mz2,mx3,my3,mz3;
		cin>>n;
		int p=n/2;
		for(int i=1;i<=n;i++){
			cin>>s[i].a>>s[i].b>>s[i].c;
			if(s[i].a==max(max(s[i].a,s[i].b),s[i].c)){
				px++;
				if(px<=p){
					x+=s[i].a;
					mx2=s[i].b;
					mx3=s[i].c;
					mx=s[i].a;
				}else{
					x+=s[i].a;
					px--;
					x-=mx;
					if(mx2>=mx3){
						y+=mx2;
						py++;
					}else{
						z+=mx3;
						pz++;
					}
				}
			}else if(s[i].b==max(max(s[i].a,s[i].b),s[i].c)){
				if(py<=p){
					y+=s[i].b;
					py++;
					my2=s[i].a;
					my3=s[i].c;
					my=s[i].b;
				}else{
					y+=s[i].b;
					y-=my;
					if(my2>=my3){
						x+=my2;
						px++;
					}else{
						x+=mx3;
						pz++;
					}
				}
			}else{
				if(pz<=p){
					z+=s[i].c;
					pz++;
					mz2=s[i].a;
					mz3=s[i].b;
					mz=s[i].c;
				}else{
					z+=s[i].c;
					z-=mz;
					if(mz3>mz2){
						y+=s[i].b;
						py++;
					}else{
						x+=s[i].a;
						px++;
					}
				}
			}
		}
		cout<<x+y+z;
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
