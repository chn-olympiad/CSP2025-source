#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int t,n,a,b,c,max=0;
	bool q=1;
	cin>>t;
	vector<int> a1,a2,a3,b1,b2,b3,a123;
	for(int j=1;j<=t;j++){
		cin>>n;
		for(int i=1;i<=n;i++){
			cin>>a>>b>>c;
			if(b!=0||c!=0){
				q=0;
			}
			a1.push_back(a);
			a2.push_back(b);
			a3.push_back(c);
		}
		if(q==1){
			sort(a1.rbegin(),a1.rend());
			for(int i=0;i<n/2;i++){
			
				max+=a1[i];
			
			}
			cout<<max;
		}
		sort(a1.rbegin(),a1.rend());
		sort(a2.rbegin(),a2.rend());
		sort(a3.rbegin(),a3.rend());
		for(int i=0;i<n/2;i++){
		
			b1.push_back(a1[i]);
			b2.push_back(a2[i]);
			b3.push_back(a3[i]);
		}
		for(int i=0;i<n/2;i++){
			
			a123.push_back(b1[i]);
		
		}
		for(int i=0;i<n/2;i++){
			
			a123.push_back(b2[i]);
			
	}	
		for(int i=0;i<n/2;i++){
			
			a123.push_back(b3[i]);
			
		}
		sort(a123.rbegin(),a123.rend());
		for(int i=0;i<n;i++){
		
			max+=a123[i];
		
		}
		cout<<max;
		max=0;
		a1.clear();
		a2.clear();
		a3.clear();
		b1.clear();
		b2.clear();
		b3.clear();
		a123.clear();
	}

	return 0;
} 

	
