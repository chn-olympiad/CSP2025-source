#include<bits/stdc++.h>
using namespace std;

int jc(int o){
	if(o==0) return 1;
	int s=1;
	for(int i=2;i<=o;i++){
		s*=i;
	}
	return s;
}

int zh(int o){
	int s=0;
	for(int i=0;i<=o;i++){
		s=s+jc(o)/(jc(i)*jc(o-i));
	}
	return s;
}

int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);	
	int n;
	cin>>n;
	int a[5005];
	int c=0,s,u;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	reverse(a+1,a+n+1);
	for(int i=1;i<=n-2;i++){
		for(int j=i+1;j<=n-1;j++){
			for(int k=j+1;k<=n;k++){
				s=a[j]+a[k];
				u=k; 
				if(s>a[i]){
					c+=zh(n-k);
				}
				else{
					while(s<=a[i]&&u<n){
						u++;
						s+=a[u];		
					}
					if(s>a[i]){
						c+=zh(n-u);
					}
				}
			}
		}
	}
	cout<<c;
	return 0;
}

