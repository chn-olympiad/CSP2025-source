#include<bits/stdc++.h>
using namespace std;
long long s[105];
int main(){
	freopen("seat.in","r",stdin)
	freopen("seat.out","w",stdout)
	int n,m,len;
	cin>>n>>m;
	len=n*m;
	for(int i=1;i<=len;i++){
		cin>>s[i];
	}
	int ans,x;
	ans=s[1];
	sort(s+1,s+1+len);
	for(int i=1;i<=n*m;i++){
		if(ans==s[i]){
			x=i;
			break; 
		}
	}
	int y;
	y=x/m;
	x%=m;
	if(y%2==0&&x==0){
		cout<<y<<" "<<x+1;
	}else if(y%2==0&&x>0){
		cout<<y+1<<" "<<m-x;
	}else if(y%2==1&&x==0){
		cout<<y<<" "<<m-x;
	}else{
		cout<<y<<" "<<m;
	}
	fclose(stdin)
	fclose(sdtout)
	return 0;
} 
