#include<bits/stdc++.h>
using namespace std;
inline long long read(){
	long long ans=0,f=1;
	char ch=getchar();
	while(!isdigit(ch)){
		if(ch=='-') f=-1;
		ch=getchar();
	}
	while(isdigit(ch)){
		ans=ans*10+ch-'0';
		ch=getchar();
	}
	return ans*f;
}
int maxxx(int a[100010],int b){
	int ans=INT_MIN;
	for(int i=0;i<b;i++){
		ans=max(ans,a[i]);
	}
	return ans;
}
int t,n,m1[100010],m2[100010],m3[100010],m,ma1,ma2,ma3,ans1,ans2; 
int main(){
	freopen("club.in","r", stdin);
	freopen("club.out","w", stdout);
	t=read();
	while(t--){
		n=read();
		
		m=n/2;
		for(int i=0;i<n;i++){
			 m1[i]=read();
			 m2[i]=read();
			 m3[i]=read();
		}
		if(n==2){
			ans1=max(maxxx(m1,n),max(maxxx(m2,n),maxxx(m3,n)));
			for(int i=0;i<n;i++){
			if(m1[i]==ans1||m2[i]==ans1||m3[i]==ans1){
				m1[i]=0;
				m2[i]=0;
				m3[i]=0;
			} 
			
			
			}
			ans2=max(maxxx(m1,n),max(maxxx(m2,n),maxxx(m3,n)));
			cout << ans1+ans2 << endl;
		
			}
		else{
			ma1= max(max(maxxx(m1,n),maxxx(m2,n)),max(maxxx(m2,n),maxxx(m3,n)));
			for(int i=0;i<n;i++){
				if(m1[i]==ma1||m2[i]==ma1||m3[i]==ma1){
					m1[i]=0;
					m2[i]=0;
					m3[i]=0;
				} 
			}
			ma2= max(max(maxxx(m1,n),maxxx(m2,n)),max(maxxx(m2,n),maxxx(m3,n)));
			for(int i=0;i<n;i++){
				if(m1[i]==ma2||m2[i]==ma2||m3[i]==ma2){
					m1[i]=0;
					m2[i]=0;
					m3[i]=0;
				} 
			}
			ma3= max(max(maxxx(m1,n),maxxx(m2,n)),max(maxxx(m2,n),maxxx(m3,n)));
			cout <<ma1 + ma2 + ma3 << endl;
		}
			
	}
	
	return 0;
}

