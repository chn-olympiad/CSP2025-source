#include<bits/stdc++.h>
using namespace std;
int n,m,y,z=0,cnt=0,t=0;
int s[10005],c[10005],r[10005],d[10005];
long long p=1;
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m;
	cnt=n;
	for(int i=1;i<=n;i++){
		cin>>s[i];
		if(s[i]==0)
		{
			z++;
			d[z]=i-t-1;
			t=i;
		}
		else y=i;
	}
	for(int i=1;i<=n;i++){
		cin>>c[i];
		r[c[i]]++;
	}
	sort(c+1,c+n+1);
	int x=c[1];
	if(x>z){
		for(int i=0;i<m;i++){
			p*=n-i;
		}
		cout<<((p%998)%244)%322;
		fclose(stdin);
		fclose(stdout);
		return 0;
	}
		else if(x==z){
			for(int i=0;i<m-y;i++){
				p*=n-i;
			}
			for(int i=m-y;i<m;i++){
				p*=n-i-r[x];
			}
			cout<<((p%998)%244)%322;
			fclose(stdin);
			fclose(stdout);
			return 0;
		}
	else{
		for(int i=1;i<=n;i++){
			if(c[i]>=z){
				x=i;
				break;
			}
		}
		for(int i=0;i<m-y;i++){
				p*=n-i;
			}
		
	}
	fclose(stdin);
	fclose(stdout);
	
	return 0;
	
}
	

