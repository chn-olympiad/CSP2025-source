#include<bits/stdc++.h>
using namespace std;
int m,n,k,t,a,b,c,l[10],s[10][105],r[10][105],he;
bool h=false;
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	for(int i=1;i<=t;i++){
		cin>>n;
		for(int i=1;i<=n;i++){
			cin>>a>>b>>c;
			m=max(a,b);
			m=max(m,c);
			s[1][i]=a;
			s[2][i]=b;
			s[3][i]=c;
			if(m==c&&l[3]<=n/2) l[3]++,r[3][i]=m,he+=m;
			else {
				if(b==c) {
					l[2]++;
					r[2][i]=m;
					m=0;
					continue;
				}
				else if(a==c) {
					l[1]++;
					r[1][i]=m;
					m=0;
					continue;
				}
				else if(l[3]>n/2&&l[2]<n/2&&l[1]<n/2) {
					for(int j=1;j<i;j++){
						if(r[3][j]+max(b,a)<m+max(s[2][j],s[1][j])){
							r[3][i]=m;
							he+=m;
							he-=r[3][j];
							he+=max(s[2][j],s[1][j]);
							
							m=max(s[2][j],s[1][j]);
							k=r[3][j];
						}
						else if(k+max(s[2][j],s[1][j])>s[3][j]+m) {
							r[3][i]=k;
							he+=k;
							he-=s[3][j];
							he+=max(s[2][j],s[1][j]);
							m=max(s[2][j],s[1][j]);
							k=r[3][j];
						}
					} 
				}
	
			}
			if(m==b&&l[2]<=n/2) {
				l[2]++;
				r[2][i]=m;
				he+=m;
			}
			else {
				if(b==c) {
					l[3]++;
					r[3][i]=m;
					m=0;
					continue;
				}
				else if(a==b) {
					l[1]++;
					r[1][i]=m;
					m=0;
					continue;
				}
				else if(l[2]>n/2&&l[1]<n/2&&l[1]<n/2) {
					for(int j=1;j<i;j++){
						if(r[2][j]+max(c,a)<m+max(s[3][j],s[1][j])){
							r[2][i]=m;
							he+=m;
							he-=r[2][j];
							he+=max(s[3][j],s[1][j]);
							
							m=max(s[3][j],s[1][j]);
							k=r[2][j];
						}
						else if(k+max(s[3][j],s[1][j])>s[2][j]+m) {
							r[2][i]=k;
							he+=k;
							he-=s[2][j];
							he+=max(s[3][j],s[1][j]);
							m=max(s[3][j],s[1][j]);
							k=r[2][j];
						}
					} 
				}
	
			
			}
			if(m==a&&l[1]<=n/2) l[1]++,r[1][i]=m,he+=m;
			else {
				if(a==c) {
					l[3]++;
					r[3][i]=m;
					m=0;
					continue;
				}
				else if(a==b) {
					l[2]++;
					r[2][i]=m;
					m=0;
					continue;
				}
				else if(l[1]>n/2&&l[3]<n/2&&l[2]<n/2) {
					for(int j=1;j<i;j++){
						if(r[1][j]+max(c,b)<m+max(s[3][j],s[2][j])){
							r[1][i]=m;
							he+=m;
							he-=r[1][j];
							he+=max(s[3][j],s[2][j]);
							
							m=max(s[3][j],s[2][j]);
							k=r[1][j];
						}
						else if(k+max(s[3][j],s[2][j])>s[1][j]+m) {
							r[1][i]=k;
							he+=k;
							he-=s[1][j];
							he+=max(s[3][j],s[2][j]);
							m=max(s[3][j],s[2][j]);
							k=r[1][j];
						}
					} 
				}
	
			
			}
			m=0;
			
		}
		for(int i=1;i<=10;i++){
			for(int j=1;j<=105;j++){
				s[i][j]=0;
				r[i][j]=0;
		}		
		}
		cout<<he;
	}
	return 0;
}
