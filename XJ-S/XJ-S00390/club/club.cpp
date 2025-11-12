#include<bits/stdc++.h>
using namespace std;
int a[100005],b[100005],c[100005];
int d=0,e=0,f=0,maxx;
int o=0,p=0,q=0;
void dfs(int i,int j){
	if(a[i+1]>=b[i+1]&&a[i+1]>=c[i+1]&&d<maxx){
		d++;
		o+=a[i+1];
		dfs(i+1,1);
	}
	else if(b[i+1]>=a[1+i]&&b[i+1]>=c[i+1]&&e<maxx){
		e++;
		p+=b[i+1];
		dfs(i+1,2);
	}
	else{
		f++;
		q+=c[i+1];
		dfs(i+1,3);
	}
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int n,t;
	cin>>t;

	while(t--){
		cin>>n;
		maxx=n/2;
		for(int i=1;i<=n;i++){
			cin>>a[i]>>b[i]>>c[i];
			if(a[i]>=b[i]&&a[i]>=c[i]&&d<maxx){
				d++;
				o+=a[i];
			}
			else if(b[i]>=a[i]&&b[i]>=c[i]&&e<maxx){
				e++;
				p+=b[i];
			}
			else{
				f++;
				q+=c[i];
			}
		}
//		dfs(0,0);
//		if(a[1]>=b[1]&&a[1]>=c[1]){
//			d++;
//			o+=a[1];
//			dfs(1,1);
//		}
//		else if(b[1]>=a[1]&&b[1]>=c[1]){
//			e++;
//			p+=b[1];
//			dfs(1,2);
//		}
//		else{
//			f++;
//			q+=c[i+1];
//			dfs(1,3);
//		}
		cout<<o+p+q<<endl;
		d=0,e=0,f=0,o=0,p=0,q=0;
	}
	return 0;
} 
