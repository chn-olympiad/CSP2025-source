#include<bits/stdc++.h>
using namespace std;
int m[200005][3];
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int t,n;
	long long s;
	vector<int> A[2],B[2],C[2],h;
	cin>>t;
	while(t!=0){
		s=0;
		cin>>n;
		for(int i=0;i<n;i++){
			cin>>m[i][0]>>m[i][1]>>m[i][2];
			h.push_back(m[i][0]);
			h.push_back(m[i][1]);
			h.push_back(m[i][2]);
			A[0].push_back(i);
			B[0].push_back(i);
			C[0].push_back(i);
			h.push_back(m[i][0]+m[i][1]+m[i][2]);
		}
		for(int i=0;i<A[0].size();i++){
			int j=i;
			t=A[j][0];
			while(j>=1&&A[j-1][0]>t){
				A[j][0]=A[j-1][0];
				j--;
			}
			A[j][0]=t;
		}
		for(int i=0;i<B[0].size();i++){
			int j=i;
			t=B[j][0];
			while(j>=1&&B[j-1][0]>t){
				B[j][0]=B[j-1][0];
				j--;
			}
			B[j][0]=t;
		}
		for(int i=0;i<C[0].size();i++){
			int j=i;
			t=C[j][0];
			while(j>=1&&C[j-1][0]>t){
				C[j][0]=C[j-1][0];
				j--;
			}
			C[j][0]=t;
		}
		for(int i=0;i<h.size();i++){
			int j=i;
			t=h[j];
			while(j>=1&&h[j-1]>t){
				h[j]=h[j-1];
				j--;
			}
			h[j]=t;
		}
		/*for(int i=0;i<n;i++){
			cout<<A[i]<<B[i]<<C[i]<<endl;
		}*/
		for(int i=h.size();i>=0;i--){
			s+=h[1];
		}
		cout<<s<<endl;
		t--;
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
/*#include<bits/stdc++.h>
using namespace std;
struct bumen{
	int a;
	int b;
	int c;
}m[100005];
int main(){
for(int i=1;i<=n;i++){
			int j=i;
			t=m[j][0];
			while(j>=2&&m[j-1][0]>t){
				m[j][0]=m[j-1][0];
				j--;
			}
			m[j][0]=t;
		}
		for(int i=1;i<=n;i++){
			int j=i;
			t=m[j][1];
			while(j>=2&&m[j-1][1]>t){
				m[j][1]=m[j-1][1];
				j--;
			}
			m[j][1]=t;
		}
		for(int i=1;i<=n;i++){
			int j=i;
			t=m[j][2];
			while(j>=2&&m[j-1][2]>t){
				m[j][2]=m[j-1][2];
				j--;
			}
			m[j][2]=t;
		}
	//freopen("club.in","r",stdin);
	//freopen("club.out","w",stdout);
	int t,n;
	long long s=0;
	cin>>t;
	
	while(t--){
		cin>>n;
		for(int i=1;i<=n;i++){
			cin>>m[i].a>>m[i].b>>m[i].c;
		}
		for(int i=1;i<=n;i++){
			int j=i;
			t=m[j].a;
			while(j>=2&&m[j-1].a>t){
				m[j]=m[j-1];
				j--;
			}
			m[j].a=t;
		}
		for(int i=1;i<=n;i++){
			int j=i;
			t=m[j].b;
			while(j>=2&&m[j-1].b>t){
				m[j]=m[j-1];
				j--;
			}
			m[j].b=t;
		}
		for(int i=1;i<=n;i++){
			int j=i;
			t=m[j].c;
			while(j>=2&&m[j-1].c>t){
				m[j]=m[j-1];
				j--;
			}
			m[j].c=t;
		}
		for(int i=1;i<=n;i++){
			cout<<m[i].a<<m[i].b<<m[i].c<<endl;
		}
	}
	
	//fclose(stdin);
	//fclose(stdout);
	return 0;
}*/
/*#include<iostream>
#include<cmath>
#include<vector>
using namespace std;
struct bumen{
	int a;
	int b;
	int c;
}x;
char p[600005];
int q[600005];
int main(){
	//freopen("club.in","r",stdin);
	//freopen("club.out","w",stdout);
	int t,n,d=-1,a=0,b=0,c=0;
	long long s=0;
	cin>>t;
	vector<int> h;
	while(t--){
		cin>>n;
		for(int i=1;i<=n;i++){
			cin>>x.a>>x.b>>x.c;
			p[x.a]='a';
			p[x.b]='b';
			p[x.c]='c';
			q[x.a]=i;
			q[x.b]=i;
			q[x.c]=i;
			if(d<max(max(x.a,x.b),x.c))
				d=max(max(x.a,x.b),x.c);
			x.a=0;
			x.b=0;
			x.c=0;
		}
		for(int i=d;i>=0;i--){
			if(p[i]=='a'||p[i]=='b'||p[i]=='c'){
				int f=1;
				for(int j=0;j<h.size();j++){
					if(q[i]==q[j]){
						f=0;
					}
				}
				if(f){
					if(p[i]==a){
						a++;
					}if(p[i]==b){
						b++;
					}if(p[i]==c){
						c++;
					}
					h.push_back(q[i]);
				}
				p[i]='0';
				q[i]=0;
				
			}
		}
	}
	/*for(int i=d;i>=0;i--){
			cout<<i<<" "<<p[i]<<" "<<q[i]<<endl;
		}
	//fclose(stdin);
	//fclose(stdout);
	return 0;
}*/
