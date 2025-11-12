#include<bits/stdc++.h>
using namespace std;
int n,m,mid,me,mp;
int s[105];
int l,h;
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++){
		cin>>s[i];
	}
	me=s[1];
	sort(s+1,s+n*m+1);
	int j=n*m;
	for(int i=1;i<=n*m/2;i++){
		mid=s[i];
		s[i]=s[j];
		s[j]=mid;
		j--;
	}
	for(int i=1;i<=n*m;i++){
		if(s[i]==me){
			mp=i;
			break;
		}
	}
	if(mp%n==0){
		l=mp/n;
		if(l%2!=0){
			h=n;
		}else if(l%2==0){
			h=1;
		}
	}else if(mp%n!=0){
		l=mp/n+mp%n;
		if(l%2!=0){
			h=mp%n;
		}else if(l%2==0){
			h=mp/n+mp%n;
		}
	}
	cout<<l<<" "<<h;
	fclose(stdin);
	fclose(stdout);
	return 0;
} 
