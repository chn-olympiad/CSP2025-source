#include <bits/stdc++.h>
using namespace std;

bool cmp(pair<int,int> l,pair<int,int> r){
    return l.second>=r.second;
}

bool cmpp(pair<int,int> l,pair<int,int> r){
    return l.second<=r.second;
}

int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int t;
	cin>>t;
	while(t--){
		int n;
		cin>>n;
		long long ans=0,ansp=0;
		bool flag[n+3]={};
		pair<int,int> a[n+3]={},b[n+3]={},c[n+3]={};
		int aa[n+3]={},bb[n+3]={},cc[n+3]={},aflag=0,bflag=0,cflag=0;
		double m=n*1.0/2;
		for(int i=0;i<n;i++){
			cin>>a[i].second>>b[i].second>>c[i].second;
			aa[i]=a[i].second;
			bb[i]=b[i].second;
			cc[i]=c[i].second;
			a[i].first=i;
			b[i].first=i;
			c[i].first=i;
		}
		sort(a,a+n,cmp);
		sort(b,b+n,cmp);
		sort(c,c+n,cmp);
		for(int i=0;i<n&&aflag+1<=m&&a[i].second>0;i++){
		    if(!flag[a[i].first]){
			    if(aa[a[i].first]>=bb[a[i].first]&&aa[a[i].first]>=cc[a[i].first]){
			        ans+=a[i].second;
		    	    flag[a[i].first]=1;
		    	    aflag++;
		        }
		    }
		}//a
		for(int i=0;i<n&&bflag+1<=m&&b[i].second>0;i++){
	       	if(!flag[b[i].first]){
	    		if(bb[b[i].first]>=cc[b[i].first]){
		   		    ans+=b[i].second;
		   		    flag[b[i].first]=1;
	       		    bflag++;
	       	    }
	       	}
	    }//b
	    for(int i=0;i<n&&cflag+1<=m&&c[i].second>0;i++){
	       	if(!flag[c[i].first]){
	       		ans+=c[i].second;
	       		flag[c[i].first]=1;
	       		cflag++;
	       	}
		}//c
		for(int i=0;i<n;i++){
			if(!flag[i]){
				if(aflag<m&&aa[i]>=bb[i]&&aa[i]>=cc[i]){
					ans+=aa[i];
				}else if(bflag<m&&bb[i]>=cc[i]){
					ans+=bb[i];
				}else{
					ans+=cc[i];
				}
			}
		}//***************************************************************************************************
		bool flagp[n+3]={};
		int aflagp=0,bflagp=0,cflagp=0;
		sort(a,a+n,cmpp);
		sort(b,b+n,cmpp);
		sort(c,c+n,cmpp);
		for(int i=0;i<n&&aflagp+1<=m;i++){
		    if(!flagp[a[i].first]){
			    if(aa[a[i].first]>=bb[a[i].first]&&aa[a[i].first]>=cc[a[i].first]){
			        ansp+=a[i].second;
		    	    flagp[a[i].first]=1;
		    	    aflagp++;
		        }
		    }
		}//a
		for(int i=0;i<n&&bflagp+1<=m;i++){
	       	if(!flagp[b[i].first]){
	    		if(bb[b[i].first]>=cc[b[i].first]){
		   		    ansp+=b[i].second;
		   		    flagp[b[i].first]=1;
	       		    bflagp++;
	       	    }
	       	}
	    }//b
	    for(int i=0;i<n&&cflagp+1<=m;i++){
	       	if(!flagp[c[i].first]){
	       		ansp+=c[i].second;
	       		flagp[c[i].first]=1;
	       		cflagp++;
	       	}
		}//c
		for(int i=0;i<n;i++){
			if(!flagp[i]){
				if(aflagp<m&&aa[i]>=bb[i]&&aa[i]>=cc[i]){
					ansp+=aa[i];
				}else if(bflagp<m&&bb[i]>=cc[i]){
					ansp+=bb[i];
				}else{
					ansp+=cc[i];
				}
			}
		}
		cout<<max(ans,ansp)<<endl;
	}
	return 0;
}
