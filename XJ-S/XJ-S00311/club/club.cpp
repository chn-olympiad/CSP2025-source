#include<bits/stdc++.h>
using namespace std;

int t=0;
int s[20010][4][3]={};
int m[20010][4][3]={};
int ans[6]={};

int fri_fri(int a[4][3]){
	for(int i=0;i<3;i++){
		for(int j=0;j<2;j++){
			if(a[j][0]<a[j+1][0]){
				int x[3];
				x[0]=a[j][0];
				x[1]=a[j][1];
				a[j][0]=a[j+1][0];
				a[j][1]=a[j+1][1];
				a[j+1][0]=x[0];
				a[j+1][1]=x[1];
			}
		}
	}
	return a[0][0];
}
int fri_sec(int a[4][3]){
	for(int i=0;i<3;i++){
		for(int j=0;j<2;j++){
			if(a[j][0]<a[j+1][0]){
				int x[3];
				x[0]=a[j][0];
				x[1]=a[j][1];
				a[j][0]=a[j+1][0];
				a[j][1]=a[j+1][1];
				a[j+1][0]=x[0];
				a[j+1][1]=x[1];
			}
		}
	}
	return a[0][1];
}
int sec_fri(int a[4][3]){
	for(int i=0;i<3;i++){
		for(int j=0;j<2;j++){
			if(a[j][0]<a[j+1][0]){
				int x[3];
				x[0]=a[j][0];
				x[1]=a[j][1];
				a[j][0]=a[j+1][0];
				a[j][1]=a[j+1][1];
				a[j+1][0]=x[0];
				a[j+1][1]=x[1];
			}
		}
	}
	return a[1][0];
}
int sec_sec(int a[4][3]){
	for(int i=0;i<3;i++){
		for(int j=0;j<2;j++){
			if(a[j][0]<a[j+1][0]){
				int x[3];
				x[0]=a[j][0];
				x[1]=a[j][1];
				a[j][0]=a[j+1][0];
				a[j][1]=a[j+1][1];
				a[j+1][0]=x[0];
				a[j+1][1]=x[1];
			}
		}
	}
	return a[1][1];
}
int thr_fri(int a[4][3]){
	for(int i=0;i<3;i++){
		for(int j=0;j<2;j++){
			if(a[j][0]<a[j+1][0]){
				int x[3];
				x[0]=a[j][0];
				x[1]=a[j][1];
				a[j][0]=a[j+1][0];
				a[j][1]=a[j+1][1];
				a[j+1][0]=x[0];
				a[j+1][1]=x[1];
			}
		}
	}
	return a[2][0];
}
int thr_sec(int a[4][3]){
	for(int i=0;i<3;i++){
		for(int j=0;j<2;j++){
			if(a[j][0]<a[j+1][0]){
				int x[3];
				x[0]=a[j][0];
				x[1]=a[j][1];
				a[j][0]=a[j+1][0];
				a[j][1]=a[j+1][1];
				a[j+1][0]=x[0];
				a[j+1][1]=x[1];
			}
		}
	}
	return a[2][1];
}

int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	for(int o=0;o<t;o++){
		int n=0;
		cin>>n;
		for(int p=0;p<n;p++){
			cin>>s[p][0][0]>>s[p][1][0]>>s[p][2][0];
		}
		for(int i=0;i<n;i++){
			s[i][0][1]=0;
			s[i][1][1]=1;
			s[i][2][1]=2;
		}
		for(int i=0;i<n;i++){
			m[i][0][0]=fri_fri(s[i]);
			m[i][1][0]=sec_fri(s[i]);
			m[i][2][0]=thr_fri(s[i]);
			m[i][0][1]=fri_sec(s[i]);
			m[i][1][1]=sec_sec(s[i]);
			m[i][2][1]=thr_sec(s[i]);
		}
		for(int j=0;j<n*n;j++){
			for(int i=0;i<n;i++){
				if(m[i][0][0]<m[i+1][0][0]){
					int b[4][3];
					b[0][0]=m[i][0][0];
					b[0][1]=m[i][0][1];
					b[1][0]=m[i][1][0];
					b[1][1]=m[i][1][1];
					b[2][0]=m[i][2][0];
					b[2][1]=m[i][2][1];
					m[i][0][0]=m[i+1][0][0];
					m[i][0][1]=m[i+1][0][1];
					m[i][1][0]=m[i+1][1][0];
					m[i][1][1]=m[i+1][1][1];
					m[i][2][0]=m[i+1][2][0];
					m[i][2][1]=m[i+1][2][1];
					m[i+1][0][0]=b[0][0];
					m[i+1][0][1]=b[0][1];
					m[i+1][1][0]=b[1][0];
					m[i+1][1][1]=b[1][1];
					m[i+1][2][0]=b[2][0];
					m[i+1][2][1]=b[2][1];
				}
			}
		}
		int flag0=0;
		int flag1=0;
		int flag2=0;
		int cnt=0;
		for(int i=n-1;i>=0;i--){
			if(m[i][0][1]==0){
				if(flag0<=n/2){
					cnt+=m[i][0][0];
					flag0+=1;
				}else{
					if(m[i][1][1]==1){
						if(flag1<n/2){
							cnt+=m[i][1][0];
							flag1+=1;
						}else{
							cnt+=m[i][2][0];
							flag2+=1;
						}
					}else if(m[i][1][1]==2){
						if(flag2<n/2){
							cnt+=m[i][1][0];
							flag2+=1;
						}else{
							cnt+=m[i][2][0];
							flag1+=1;
						}
					}
				}
			}else if(m[i][0][1]==1){
				if(flag1<=n/2){
					cnt+=m[i][0][0];
					flag1+=1;
				}else{
					if(m[i][1][1]==0){
						if(flag0<n/2){
							cnt+=m[i][1][0];
							flag0+=1;
						}else{
							cnt+=m[i][2][0];
							flag2+=1;
						}
					}else if(m[i][1][1]==2){
						if(flag2<n/2){
							cnt+=m[i][1][0];
							flag2+=1;
						}else{
							cnt+=m[i][2][0];
							flag0+=1;
						}
					}
				}
			}else if(m[i][0][1]==2){
				if(flag2<=n/2){
					cnt+=m[i][0][0];
					flag2+=1;
				}else{
					if(m[i][1][1]==1){
						if(flag1<n/2){
							cnt+=m[i][1][0];
							flag1+=1;
						}else{
							cnt+=m[i][2][0];
							flag0+=1;
						}
					}else if(m[i][1][1]==0){
						if(flag0<n/2){
							cnt+=m[i][1][0];
							flag0+=1;
						}else{
							cnt+=m[i][2][0];
							flag1+=1;
						}
					}
				}
			}
		}
		ans[o]=cnt;	
	}
	for(int i=0;i<t;i++){
		cout<<ans[i]<<endl;
	}
	return 0;
} 
