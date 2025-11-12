#include<bits/stdc++.h>;
using namespace std;
int main(){
	//freope("number.in","r"stdin);
	//freope("number.out","w"stdout);
	int n,m;
	cin>>n>>m;
	int a[11];
	for(int i=1;i<=n*m;i++){
		cin>>a[i];
	}
	int s=0;
	for(int i=1;i<=n;i++){	
		int m2=m;
		int maxn=0;
		for(int j=1;j<=m;j++){
			s+=1;
			if(a[j]>maxn)
				maxn=a[s];
			if(a[1]!=maxn){
				a[s]=maxn;
			}
			else if(maxn==a[1]&&i%2!=0)
				cout<<i<<" "<<s<<endl;
			else if(maxn==a[1]&&i%2==0)
				cout<<i<<" "<<m2;
			//cout<<a[j]<<" "<<s<<" "<<m2<<" "<<j<<endl;
			//cout<<maxn<<" "<<endl;
			m2--;
		}
	}
	return 0;
} 
