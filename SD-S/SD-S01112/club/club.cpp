#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int t;
	cin>>t;
	int sum=0;
	while (sum!=t){
		int n,num=0;
		cin>>n;
		int a[2];
		for (int i=1;i<=n;i++){
			for (int j=0;j<n;j++){
				cin>>a[j];
			}
			if(a[0]<=a[1]&&a[2]<=a[1]){
			    num+=a[1];
		    }
		    else if(a[1]<=a[0]&&a[2]<=a[0]){
			    num+=a[0];
		    }
		    else {
			    num+=a[2];
		    }
		    
	    }
	    cout<<num<<endl;
	    sum+=1;
	}
	return 0;
}

