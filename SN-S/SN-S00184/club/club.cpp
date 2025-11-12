#include<bits/stdc++.h>
using namespace std;
struct per{
	int x, y;
};
bool cmp(per x,per y){
	return x.y>y.y;
}
struct pers{
	vector<per>a;
	bool u;
};
struct node{
	int c, p;
};
bool cmp1(pers x,pers y){
	return x.a[0].y>y.a[0].y;
}
bool cmp2(node x,node y){
	return x.c<y.c;
}
bool cmp3(node x,node y){
	return x.c>y.c;
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int t;
	cin>>t;
	while(t--){
		int n;
	    cin>>n;
        pers a[n]={};
        for(int i=0;i<n;i++){
        	for(int j=0;j<3;j++){
        		a[i].a.push_back({0,0});
			}
         	cin>>a[i].a[0].y>>a[i].a[1].y>>a[i].a[2].y;
    	    a[i].a[0].x=0,a[i].a[1].x=1,a[i].a[2].x=2;
    	    sort(a[i].a.begin(),a[i].a.end(),cmp);
	    }
	    int s[3]={};
	    int maxx=n/2;
	    int tot=0;
	    sort(a,a+n,cmp1);
	    vector<node>l,nl;
	    for(int i=0;i<n;i++){
		   if(s[a[i].a[0].x]<maxx){
		      s[a[i].a[0].x]++;
		      tot+=a[i].a[0].y;
			  a[i].u=1;
			  l.push_back({a[i].a[0].y-a[i].a[1].y,i});
		   }else  nl.push_back({a[i].a[0].y-a[i].a[1].y,i});
	    }
	    sort(l.begin(),l.end(),cmp2);
	    sort(nl.begin(),nl.end(),cmp3);
	    int ma=-1;
	    for(int i=0;i<min(l.size(),nl.size());i++){
	    	if(nl[0].c>l[i].c){
	    		ma=i;
			}
		}
	
	    for(int i=0;i<n;i++){
	    	if(!a[i].u){
	    	   s[a[i].a[1].x]++;
		       tot+=a[i].a[1].y;
			}
		}
		int j=0;
		for(int i=ma;i>=0;i--){
			
			if(nl[j].c>l[i].c&&s[a[l[i].p].a[1].x]<=maxx&&s[a[nl[j].p].a[0].x]<=maxx){
				tot+=nl[j].c-l[i].c;
				j++;
				s[a[l[i].p].a[1].x]++;
				s[a[nl[j].p].a[0].x]++;
			}
		}
	    cout<<tot<<'\n';
	}

}

