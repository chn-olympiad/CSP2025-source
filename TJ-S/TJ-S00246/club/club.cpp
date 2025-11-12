#include<bits/stdc++.h>
using namespace std;
int a[100006][5];
int b[100006];
int c[100006];
int d[100006];
bool e[100006];
int f[4];
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int t;
	cin>>t;
	int n;
	int maxn;
	int max1;
	int max2;
	int max3;
	bool p = 1;
	long long k = 0;
	int max11;
	int max22;
	int max33;
	while(t--){
		cin>>n;
		k = 0;
		if(n == 2){
			for(int i = 1;i<=n;i++){
			    cin>>a[i][1];
			    cin>>a[i][2];
			    cin>>a[i][3];
		    }
		    for(int i = 1;i<=3;i++){
				for(int j = 1;j<=3;j++){
					if(a[1][i]+a[2][j]>maxn && i!=j){
						maxn = a[1][i]+a[2][j];
					}
				}
			}
			cout<<maxn<<"\n";
			continue;
		}else{
			p = 1;
			for(int i = 1;i<=n;i++){
			    cin>>b[i];
			    cin>>c[i];
			    cin>>d[i];
			    if(d[i]!=0){
			    	p = 0;
			    }
			    if(max1<b[i]){
			    	max1 = b[i];
			    	max11 = i;
				}
			    if(max2<c[i]){
			    	max2 = c[i];
			    	max22 = i;
				}
			    if(max3<d[i]){
			    	max3 = d[i];
			    	max33 = i;
				}
		    }
		    if(p){
		    	k = 0;
			    sort(b+1,b+n+1);
			    sort(c+1,c+n+1);
			    for(int i = n/2+1;i<=n;i++){
				    k = k+b[i]+c[i];
			    }
			    cout<<k<<"\n";
			    continue;
		    }else{
		    	k = k+max1;
		    	e[max11] = 1;
		    	f[1]++;
		    	if(!e[max22]){
		    		k = k+max2;
		    	    e[max22] = 1;
		    	    f[2]++;
				}
				if(!e[max33]){
					k = k+max3;
		    	    e[max33] = 1;
		    	    f[3]++;
				}
		    	for(int i = 1;i<=n;i++){
		    		if(!e[i]){
		    			if(b[i]>=c[i] && b[i]>=d[i] && f[1]+1<=n/2){
		    				k = k+b[i];
		    				e[i] = 1;
						}else if(c[i]>=d[i] && c[i]>=b[i] && f[2]+1<=n/2){
							k = k+c[i];
							e[i] = 1;
						}else{
							k = k+d[i];
							e[i] = 1;
						}
					}
				}
			}
			cout<<k<<"\n";
		}
	}
}

