#include <bits/stdc++.h>
using namespace std;
int t,n,w[100005][6],sum,aa,bb,cc;
int s[100005],l=1;
void cf(int i){
	int mx=0;
	for(int j=1;j<=3;j++){
		if(w[i][4]!=j){
			if(w[i][j]>=mx){
				mx=w[i][j];
				w[i][5]=j;
			}
		}		
	}	
}
int main(){
	//freopen("club.in","r",stdin);
	//freopen("club.out","w",stdout);
	cin>>t;
	while(t--){
		cin>>n;
		memset(w,0,sizeof(w));
		memset(s,0,sizeof(s));
		aa=0,bb=0,cc=0,sum=0,l=1;
		for(int i=1;i<=n;i++){
			cin>>w[i][1]>>w[i][2]>>w[i][3];
			int a=w[i][1],b=w[i][2],c=w[i][3];
			if(a>=max(b,c)){
				w[i][4]=1;
                cf(i);
			}else
		    if(b>=max(a,c)){
	    		w[i][4]=2;
                cf(i);
	    	}else
	    	if(c>=max(b,a)){
		    	w[i][4]=3;
			    cf(i);
	    	}		
            if(w[i][4]==1)aa++;
            if(w[i][4]==2)bb++;
            if(w[i][4]==3)cc++;
            sum+=w[i][w[i][4]];
    	}            
		int mxx,o;
        if(aa>=max(bb,cc))mxx=1,o=aa-(n/2);
        if(bb>=max(aa,cc))mxx=2,o=bb-(n/2);
        if(cc>=max(aa,bb))mxx=3,o=cc-(n/2);
            if(o>=0){
            	int mr=o;
            	for(int i=1;i<=n;i++){
            		if(w[i][4]==mxx){
            			s[l]=w[i][w[i][4]]-w[i][w[i][5]];
            			l++;
					}
				}
				sort(s+1,s+l);
				for(int i=1;i<=mr;i++){
					sum-=s[i];
				}
				cout<<sum<<endl;
			}else{
				cout<<sum<<endl;
			}
		}
	return 0;
}
