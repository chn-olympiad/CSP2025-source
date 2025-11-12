#include<bits/stdc++.h>
using namespace std;
long long t,n,k,o[3];
struct uuu{
	int a,b,c;
};
int pxa(uuu x,uuu y){
	return x.a<y.a;
}
int pxb(uuu x,uuu y){
	return x.b<y.b;
}
int pxc(uuu x,uuu y){
	return x.c<y.c;
}
uuu s[100005];

int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	while(t--){
		cin>>n;
		for(int i=1;i<=n;i++){
			cin>>s[i].a>>s[i].b>>s[i].c;
			if(s[i].a>s[i].b and s[i].a>s[i].c){
				o[0]+=1;
				k+=s[i].a;
			}else if(s[i].b>s[i].a and s[i].b>c[i]){
				o[1]+=1;
				k+=s[i].b;
			}else{
				o[2]+=1;
				k+=c[i];
			}
			if(o[0]>n/2){
				sort(s+1,s+1+n,pxa);
				if(o[1]<n/2 and o[2]<n/2){
					if(s.b[i]>s.c[i]){
						o[0]-1;
						o[1]++;
						k-=s[i].a;
						k+=s[i].b;
					}else if(s.b[i]<s.c[i]){
						o[0]-1;
						o[2]++;
						k-=s[i].a;
						k+=s[i].c;
					}else{
						if(n/2-o[1] > n/2-o[2]){
							o[0]-1;
							o[1]++;
							k-=s[i].a;
							k+=s[i].b;
						}else{
							o[0]-1;
							o[2]++;
							k-=s[i].a;
							k+=s[i].c;
						}
					}
				}
			}
			if(o[1]>n/2){
				sort(s+1,s+1+n,pxb);
				if(o[0]<n/2 and o[2]<n/2){
					if(s.a[i]>s.c[i]){
						o[1]-1;
						o[0]++;
						k-=s[i].b;
						k+=s[i].a;
					}else if(s.a[i]<s.c[i]){
						o[1]-1;
						o[2]++;
						k-=s[i].b;
						k+=s[i].c;
					}else{
						if(n/2-o[0] > n/2-o[2]){
							o[1]-1;
							o[0]++;
							k-=s[i].b;
							k+=s[i].a;
						}else{
							o[1]-1;
							o[2]++;
							k-=s[i].b;
							k+=s[i].c;
						}
					}
				}
			}
			if(o[2]>n/2){
				sort(s+1,s+1+n,pxb);
				if(o[0]<n/2 and o[1]<n/2){
					if(s.a[i]>s.b[i]){
						o[2]-1;
						o[0]++;
						k-=s[i].b;
						k+=s[i].a;
					}else if(s.a[i]<s.b[i]){
						o[2]-1;
						o[1]++;
						k-=s[i].c;
						k+=s[i].b;
					}else{
						if(n/2-o[0] > n/2-o[1]){
							o[2]-1;
							o[0]++;
							k-=s[i].b;
							k+=s[i].a;
						}else{
							o[1]-1;
							o[2]++;
							k-=s[i].b;
							k+=s[i].c;
						}
					}
				}
			}
			cout<<k;
		}
	}
	return 0;
} 
