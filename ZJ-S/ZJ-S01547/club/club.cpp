#include<bits/stdc++.h>
using namespace std;
int cnt[10005];
int a[100005][5],b[10005][5],d[10005],x[10005];
int c[5],m[5],f;
int t;
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int n;
    cin>>n;
    for(int p=1;p<=n;p++){
	    for (int i=1;i<=10000;i++){
	    	for(int j=1;j<=3;j++){
	    		a[i][j]=0;
	    		b[i][j]=0;
	    		c[j]=0;
	    		m[j]=0;
			}
			d[i]=0;
			x[i]=0;
		}
		
		cin>>t;
		for(int i=1;i<=t;i++){
		    for(int j=1;j<=3;j++){
		    	cin>>a[i][j];
		    	if(a[i][j]>b[i][1]){
		    			b[i][2]=a[i][1];
		    			b[i][1]=a[i][j];
		    			x[i]=j;
					}
		    	else if(a[i][j]>b[i][2]){
		    			b[i][3]=a[i][2];
		    			b[i][2]=a[i][j];
					}
				else {
						b[i][3]=a[i][j];
					}
					
				}
				d[i]=b[i][1];
			}
		for(int i=t;i>=2;i--){
			for(int j=1;j<=i;j++){
				if(d[i]>d[j]){
						f=d[i];
						d[i]=d[j];
						d[j]=f;
						f=x[i];
						x[i]=x[j];
						x[j]=f;
						f=b[i][2];
						b[i][2]=b[j][2];
						b[j][2]=f;
				}
			}
		}
		for(int i=1;i<=t;i++){
			if(c[x[i]]<t/2){
					c[x[i]]++;
					cnt[p]+=d[i];
				}
			else{
					cnt[p]+=b[i][2];
				}
				
		}
	}
	for(int p=1;p<=n;p++){
    	cout<<cnt[p]<<endl;
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
