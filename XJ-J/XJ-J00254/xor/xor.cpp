#include<iostream>
#include<vector>
using namespace std;
int n,k;
vector<int> a,s;
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	if(n<=10000){
		cin>>n>>k;
		for(int i=1;i<=n;i++){
			int x;
			cin>>x;
			a.push_back(x);
		}
		int l=0,r=0,maxn=-1;
		for(int i=1;i<=n;i++){
	        int num=0,f=0;
	        for(int j=r+1;j<n;j++){
	            for(int k=j;k<n;k++){
	                for(int m=j;m<=k;m++){
	                    num=num^a[m];
	                    if(num==k){
	                        l=j;
	                        r=m;
	                        f=1;
	                        break;
	                    }
	                }
	                if(f)break;
	            }
	            if(f)break;
	        }
	        if(r-l+1>maxn)maxn=r-l+1;
		}
		cout<<maxn;
	}else{
		cin>>n>>k;
		a.push_back(0);
		s.push_back(0);
		for(int i=1;i<=n;i++){
			int x;
			cin>>x;
			a.push_back(x);
			int tmp=s[i-1]^x; 
			s.push_back(tmp);
		}
		int r=0,maxn=-1;
		for(int i=1;i<=n;i++){
    	    for(int j=i;j<=n;j++){
        	    if(s[j]^s[i-1]==k){
        	        r=j;
            	}
        	}
        	if(r-i+1>maxn)maxn=r-i+1;
		}
		cout<<maxn;
	}
	return 0;
}
