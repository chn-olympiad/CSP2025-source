#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int t;
	cin>>t;
	for(int i=0;i<t;i++){
		int n;
		int a2=0,b2=0,c2=0,m2=0;
		cin>>n;
		int p[n][3];
		for(int j=0;j<n;j++){
			for(int k=0;k<3;k++){
				cin>>p[j][k];
			}
		}
		int a[n],b[n],c[n],m[n];
		for(int j=0;j<n;j++){
				a[j]=-1;
				b[j]=-1;
				c[j]=-1;
				m[j]=-1;
		}
		for(int j=0;j<n;j++){
			if(p[j][0]>p[j][1] and p[j][0]>p[j][2]){
				a[a2]=j;
				a2++;
			}
			else if(p[j][1]>p[j][2] and p[j][1]>p[j][0]){
				b[b2]=j;
				b2++;
			}
			else if(p[j][2]>p[j][1] and p[j][2]>p[j][0]){
				c[c2]=j;
				c2++;
			}
			else{
				m[m2]=j;
				m2++;
			}
		}
		if(m2!=0){
			for(int j=0;j<m2;j++){
				if(p[m[j]][0]>=p[m[j]][1] and p[m[j]][0]>=p[m[j]][2]){
					a[a2]=p[m[j]][0];
					a2++;
				}
				else if(p[m[j]][1]>=p[m[j]][0] and p[m[j]][1]>=p[m[j]][2]){
					b[b2]=p[m[j]][1];
					b2++;
				}
				else{
					c[c2]=p[m[j]][2];
					c2++;
				}	
			}
		}
		if(a2>n/2){
			for(int k=1;k<=a2-n/2;k=k){
				int maxx=0,ma=0;
				for(int j=0;j<a2;j++){
					if(max(p[j][1],p[j][2])>maxx){
						maxx=max(p[j][1],p[j][2]);
						ma=j;
					}
				}
				if(maxx!=0){
					if(p[ma][1]>=p[ma][2]){
						if(b2<n/2){
							a2--;
							b2++;
							b[b2-1]=a[ma];
							a[ma]=a[a2];
							}
						else{
							a2--;
							c2++;
							c[c2-1]=a[ma];
							a[ma]=a[a2];
							}
						}
					if(p[ma][1]<p[ma][2]){
						if(c2<n/2){
							a2--;
							c2++;
							c[c2-1]=a[ma];
							a[ma]=a[a2];
							}
						else{
							a2--;
							b2++;
							b[b2-1]=a[ma];
							a[ma]=a[a2];
							}
						}
					}
					else{
						for(int j=0;j<a2;j++){
							if(b2>=c2){
								a2--;
								c2++;
								c[c2-1]=a[j];
								a[j]=a[a2];
							}
							else{
								a2--;
								b2++;
								b[b2-1]=a[j];
								a[j]=a[a2];
							}
						}
					}
				}
			}
		if(b2>n/2){
			for(int k=1;k<=b2-n/2;k=k){
				int maxx=0,mb=0;
				for(int j=0;j<b2;j++){
					if(max(p[j][0],p[j][2])>maxx){
						maxx=max(p[j][0],p[j][2]);
						mb=j;
					}
				}
				if(maxx!=0){
					if(p[mb][0]>=p[mb][2]){
						if(a2<n/2){
							b2--;
							a2++;
							a[a2-1]=b[mb];
							b[mb]=b[b2];
							}
						else{
							b2--;
							c2++;
							c[c2-1]=b[mb];
							b[mb]=b[b2];
						}
					}
					if(p[mb][0]<p[mb][2]){
						if(c2<n/2){
							b2--;
							c2++;
							c[c2-1]=b[mb];
							b[mb]=b[b2];	
						}
					    else{
					    	b2--;
							a2++;
							a[a2-1]=b[mb];
							b[mb]=b[b2];
						}
					}
				}
				else{
					for(int j=0;j<b2;j++){
						if(a2<=c2){
							b2--;
							a2++;
							a[a2-1]=b[j];
							b[j]=b[b2];
							}
						else{
							b2--;
							c2++;
							c[c2-1]=b[j];
							b[j]=b[b2];
							}
						}
					}
			}
		}
		if(c2>n/2){
			for(int k=1;k<=c2-n/2;k=k){
				int maxx=0,mc=0;
				for(int j=0;j<c2;j++){
					if(max(p[j][0],p[j][1])>maxx){
						maxx=max(p[j][0],p[j][1]);
						mc=j;
					}
				}
				if(maxx!=0){
					if(p[mc][0]>=p[mc][1]){
						if(a2<n/2){
							c2--;
							a2++;
							a[a2-1]=c[mc];
							c[mc]=c[c2];
						}
						else{
							c2--;
							b2++;
							b[b2-1]=c[mc];
							c[mc]=c[c2];	
						}
					}
					if(p[mc][0]<p[mc][1]){
						if(b2<n/2){
							c2--;
							b2++;
							b[b2-1]=c[mc];
							c[mc]=c[c2];
						}
						else{
							c2--;
							a2++;
							a[a2-1]=c[mc];
							c[mc]=c[c2];
						}
					}
				}
				else{
					for(int j=0;j<a2;j++){
						if(a2>=b2){
								c2--;
								b2++;
								b[b2-1]=c[j];
								c[j]=c[c2];
							}
						else{
								c2--;
								a2++;
								a[a2-1]=c[j];
								c[j]=c[c2];
							}
						}
					}
			}
		}
		int ans=0;
		for(int j=0;j<a2;j++){
			ans+=p[a[j]][0];
		}
		for(int j=0;j<b2;j++){
			ans+=p[b[j]][1];
		}
		for(int j=0;j<c2;j++){
			ans+=p[c[j]][2];
		}
		cout<<ans<<endl;
	}
	return 0;
} 
