#include<bits/stdc++.h>
using namespace std;
const int N=1e5+10;
const int INF=1e9;
int t,n,c1,c2,c3,ans;
struct node{
    int d1,d2;
};
node q1[N],q2[N],q3[N];
bool cmp(node n1,node n2){
	return max(n1.d1,n1.d2)>max(n2.d1,n2.d2);
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
    scanf("%d",&t);
    while(t--){
    	scanf("%d",&n);
        c1=c2=c3=ans=0;
    	for(int i=1;i<=n;i++){
    		int x,y,z,ma=0;
    		scanf("%d%d%d",&x,&y,&z);
    		ma=max(x,max(y,z));
    		if(x==ma){
    			c1++;
    			q1[c1]={y-ma,z-ma};
			}else if(y==ma){
				c2++;
				q2[c2]={x-ma,z-ma};
			}else{
				c3++;
				q3[c3]={x-ma,y-ma};
			}
			ans+=ma;
		}
		while(c1>n/2||c2>n/2||c3>n/2){
			if(c1>n/2){
			    sort(q1+1,q1+c1+1,cmp);
		        for(int i=1;i<=c1-n/2;){
		        	if(q1[i].d1==-INF&&q1[i].d2==-INF)continue;
		        	//if(q1[i].f)continue;
		        	if(q1[i].d1>=q1[i].d2){
		        		ans+=q1[i].d1;
		        		c2++;i++;
		        		q2[c2]={-INF,q1[i].d2-q1[i].d1};
			    	}else{
			    		ans+=q1[i].d2;
			    		c3++;i++;
			    		q3[c3]={-INF,q1[i].d1-q1[i].d2};
			    	}
		    	}
		    	c1=n/2;
	    	}
	    	if(c2>n/2){
		    	sort(q2+1,q2+c2+1,cmp);
		    	for(int i=1;i<=c2-n/2;){
		    		if(q2[i].d1==-INF&&q2[i].d2==-INF)continue;
		        	//if(q2[i].f)continue;
		        	if(q2[i].d1>=q2[i].d2){
		        		ans+=q2[i].d1;
		    	    	c1++;i++;
		    	    	q1[c1]={-INF,q2[i].d2-q2[i].d1};
			    	}else{
				    	ans+=q2[i].d2;
				    	c3++;i++;
			    		q3[c3]={q2[i].d1-q2[i].d2,-INF};
			    	}
		    	}
		    	c2=n/2;
	    	}
	    	if(c3>n/2){
			    sort(q3+1,q3+c3+1,cmp);
		    	for(int i=1;i<=c3-n/2;){
		    		if(q3[i].d1==-INF&&q3[i].d2==-INF)continue;
		        	//if(q3[i].f)continue;
		        	if(q3[i].d1>=q3[i].d2){
		        		ans+=q3[i].d1;
		         		c1++;i++;
		        		q1[c1]={q3[i].d2-q3[i].d1,-INF};
		    		}else{
			    		ans+=q3[i].d2;
			    		c2++;i++;
			    		q2[c2]={q3[i].d1-q3[i].d2,-INF};
			    	}
		    	}
		    	c3=n/2;
	    	}
		}
		printf("%d\n",ans);
	}
	return 0;
}

