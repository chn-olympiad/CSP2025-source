#include<bits/stdc++.h>
using namespace std;
long long a[100005],b[100005],c[100005];
long long ans=0,anss=0;
int main(){
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    long long t;
	cin >> t;
    while(t--){
        long long n;
        cin >> n;
        long long nn=n/2;
        cin >> a[1] >> b[1] >> c[1];
        if(b[1]==0 && c[1]==0){
            for(int ii=2;ii<=n;ii++){
				cin >> a[ii] >> b[ii] >> c[ii];
			}
			sort(b+1,b+1+n);
			for(int ii=n;ii>nn;ii--){
				ans+=b[ii];
			}
			cout << ans << endl;
		}else if(nn==1){
            cin >> a[2] >> b[2] >> c[2];
            long long aa=max(a[1],a[2]);
            long long bb=max(b[1],b[2]);
            long long cc=max(c[1],c[2]);
            if(aa==a[1] && bb==b[1]){
            	if(aa+b[2]<bb+a[2]){
            		aa=a[2];
				}
				else{
					bb=b[2];
				}
			}
			if(aa==a[2] && bb==b[2]){
            	if(aa+b[1]<bb+a[1]){
            		aa=a[1];
				}
				else{
					bb=b[1];
				}
			}
			if(aa==a[1] && cc==c[1]){
            	if(aa+c[2]<cc+a[2]){
            		aa=a[2];
				}
				else{
					cc=c[2];
				}
			}
			if(aa==a[2] && cc==c[2]){
            	if(aa+c[1]<cc+a[1]){
            		aa=a[1];
				}
				else{
					cc=c[1];
				}
			}
			if(bb==b[1] && cc==c[1]){
            	if(bb+c[2]<cc+b[2]){
            		bb=b[2];
				}
				else{
					cc=c[2];
				}
			}
			if(bb==a[2] && cc==c[2]){
            	if(bb+c[2]<cc+b[2]){
            		bb=b[1];
				}
				else{
					cc=c[1];
				}
			}
            anss=max(aa+bb,aa+cc);
            ans=max(anss,bb+cc);
            cout << ans << endl;
		} 
		else{
			anss=max(a[1],b[1]);
            anss=max(anss,c[1]);
            ans+=anss;
            anss=0;
        	for(int i=2;i<=n;i++){
            	cin >> a[i] >> b[i] >> c[i];
            	anss=max(a[i],b[i]);
            	anss=max(anss,c[i]);
            	ans+=anss;
            	anss=0;
        	}
    		cout << ans << endl;
    	}
    	ans=0;
    }
    return 0;
}
