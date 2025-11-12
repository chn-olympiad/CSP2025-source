#include <bits/stdc++.h>
using namespace std;
int a1[100005],b1[100005],c1[100005];
int z[100005];

int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
    int t;
    cin >> t;
    while (t--) {
	    int a3=0,b3=0,c3=0;int a2=0,b2=0,c2=0;
    	int n;
    	cin >> n;
    	for(int i=0;i<n;i++){
    		cin>>a1[i]>>b1[i]>>c1[i];
    		z[i]=max({a1[i],b1[i],c1[i]});
		}
		for(int i=0;i<n;i++){
			if(z[i]==a1[i]&&z[i]!=b1[i]&&z[i]!=c1[i]){
			    if(a2+1>n/2) {
			    	if(b1[i]>c1[i]&&b2+1<n/2){
			    		b2++;
			    		b3+=b1[i];
					}
				    else{
				    	c2++;
			    		c3+=c1[i];
					}
				}//
			else{
				a2++;
				a3+=a1[i];
			}
			}
			if(z[i]!=a1[i]&&z[i]==b1[i]&&z[i]!=c1[i]){
				if(b2+1>n/2) {
			    	if(a1[i]>c1[i]&&a2+1<n/2){
			    		a2++;
			    		a3+=a1[i];
					}
				    else{
				    	c2++;
			    		c3+=c1[i];
					}
				}//
				else {
					b2++;
					b3+=b1[i];	
				}	
			}
			if(z[i]!=a1[i]&&z[i]!=b1[i]&&z[i]==c1[i]){
				if(c2+1>n/2) {
			    	if(b1[i]>a1[i]&&a2+1<n/2){
			    		b2++;
			    		b3+=b1[i];
					}
				    else{
				    	a2++;
			    		a3+=a1[i];
					}
				}//
				else {
				    c2++;
				    c3+=c1[i];	
				}
			}
			if(a1[i]==b1[i]&&a1[i]==c1[i]){
				int minn=min({a2,b2,c2});
				if(minn=a2){
				    a2++;
				    a3+=a1[i];
				}
	            if(minn=b2){
	            	b2++;
	            	b3+=b1[i];
				}
				if(minn=c2){
					c2++;
					c3+=c1[i];
				}
			}
			if(a1[i]==b1[i]&&a1[i]!=c1[i]){
				if(a2>b2){
					b2++;
					b3+=b1[i];
				}
				else {
					a2++;
					a3+=a1[i];
				}
			}
			if(a1[i]!=b1[i]&&b1[i]==c1[i]){
				if(c2>b2){
					b2++;
					b3+=b1[i];
				}
				else {
					c2++;
					c3+=c1[i];
				}
			}
			if(a1[i]!=b1[i]&&a1[i]==c1[i]){
				if(c2>a2){
					a2++;
					a3+=a1[i];
				}
				else {
					c2++;
					c3+=c1[i];
				}
			}
		}int sum=c3+a3+b3;
		cout << sum << endl;
	}
	return 0;
}
