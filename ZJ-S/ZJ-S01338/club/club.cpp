#include <bits/stdc++.h>
using namespace std;
long long ccl1[100005],ccl2[100005],ccl3[100005],t,n,clb1[100005],clb2[100005],clb3[100005],cul,ct,c1c,c2c,c3c,mxi,res1,res2,ansss[6];
long long maxf(int a,int b,int c){
	if(a>=b&&a>=c){
		return a;
	}else if(b>=a&&b>=c){
		return b;
	}else{
		return c;
	}
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	cul=t;
	while(t--){
		c1c=0,c2c=0,c3c=0,res1=0,res2=0;
		cin>>n;
		for(int i=0;i<n;i++){
			cin>>clb1[i]>>clb2[i]>>clb3[i];
			ccl1[i]=clb1[i];
			ccl2[i]=clb2[i];
			ccl3[i]=clb3[i];
		}
		for(int i=0;i<n;i++){
			if(c1c==n/2){
				for(int j=0;j<n;j++){
					clb1[j]=0;
				}
			}
			if(c2c==n/2){
				for(int j=0;j<n;j++){
					clb2[j]=0;
				}
			}
			if(c3c==n/2){
				for(int j=0;j<n;j++){
					clb3[j]=0;
				}
			}
			res1+=maxf(clb1[i],clb2[i],clb3[i]);
			if(clb1[i]==maxf(clb1[i],clb2[i],clb3[i])){
				if(clb2[i]==maxf(clb1[i],clb2[i],clb3[i])){
					if(c1c<=c2c){
						c1c++;
					}else{
						c2c++;
					}
				}
				if(clb3[i]==maxf(clb1[i],clb2[i],clb3[i])){
					if(c1c<=c3c){
						c1c++;
					}else{
						c3c++;
					}
				}
				c1c++;
				continue;
			}
			if(clb2[i]==maxf(clb1[i],clb2[i],clb3[i])){
				if(clb1[i]==maxf(clb1[i],clb2[i],clb3[i])){
					if(c2c<=c1c){
						c2c++;
					}else{
						c1c++;
					}
				}
				if(clb3[i]==maxf(clb1[i],clb2[i],clb3[i])){
					if(c2c<=c3c){
						c2c++;
					}else{
						c3c++;
					}
				}
				c2c++;
				continue;
			}
			if(clb3[i]==maxf(clb1[i],clb2[i],clb3[i])){
				if(clb1[i]==maxf(clb1[i],clb2[i],clb3[i])){
					if(c3c<=c1c){
						c3c++;
					}else{
						c1c++;
					}
				}
				if(clb2[i]==maxf(clb1[i],clb2[i],clb3[i])){
					if(c3c<=c2c){
						c3c++;
					}else{
						c2c++;
					}
				}
				c3c++;
				continue;
			}
		}//ีýละ
		c1c=0,c2c=0,c3c=0;
		for(int i=n-1;i>=0;i--){
			if(c1c==n/2){
				for(int j=0;j<n;j++){
					ccl1[j]=0;
				}
			}
			if(c2c==n/2){
				for(int j=0;j<n;j++){
					ccl2[j]=0;
				}
			}
			if(c3c==n/2){
				for(int j=0;j<n;j++){
					ccl3[j]=0;
				}
			}
			res2+=maxf(ccl1[i],ccl2[i],ccl3[i]);
			if(ccl1[i]==maxf(ccl1[i],ccl2[i],ccl3[i])){
				if(ccl2[i]==maxf(ccl1[i],ccl2[i],ccl3[i])){
					if(c1c<=c2c){
						c1c++;
					}else{
						c2c++;
					}
				}
				if(ccl3[i]==maxf(ccl1[i],ccl2[i],ccl3[i])){
					if(c1c<=c3c){
						c1c++;
					}else{
						c3c++;
					}
				}
				c1c++;
				continue;
			}
			if(ccl2[i]==maxf(ccl1[i],ccl2[i],ccl3[i])){
				if(ccl1[i]==maxf(ccl1[i],ccl2[i],ccl3[i])){
					if(c2c<=c1c){
						c2c++;
					}else{
						c1c++;
					}
				}
				if(ccl3[i]==maxf(ccl1[i],ccl2[i],ccl3[i])){
					if(c2c<=c3c){
						c2c++;
					}else{
						c3c++;
					}
				}
				c2c++;
				continue;
			}
			if(ccl3[i]==maxf(ccl1[i],ccl2[i],ccl3[i])){
				if(ccl1[i]==maxf(ccl1[i],ccl2[i],ccl3[i])){
					if(c3c<=c1c){
						c3c++;
					}else{
						c1c++;
					}
				}
				if(ccl2[i]==maxf(ccl1[i],ccl2[i],ccl3[i])){
					if(c3c<=c2c){
						c3c++;
					}else{
						c2c++;
					}
				}
				c3c++;
				continue;
			}
		}
		ansss[ct]=max(res1,res2);
		ct++;
	}
	for(int i=0;i<cul;i++){
		if(i==cul-1){
			cout<<ansss[i];
		}else{
			cout<<ansss[i]<<endl;
		}
		
	}
	return 0;
}
