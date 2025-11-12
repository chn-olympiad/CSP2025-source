#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("seat1.in","r",stdin);
	freopen("seat1.out","w",stdout);
	int n,m;
	int r=1;
	int c=1;
	cin>>n>>m;
	string s;
	for(int i=0;i<n*m;i++){
		cin>>s;
	sort(s.begin(),s.end());
		if(s[i]<s[i+1]){
			r++;
			if(r>m){
				c++;
			}
		}	
	}
	cout<<c<<" "<<r;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
