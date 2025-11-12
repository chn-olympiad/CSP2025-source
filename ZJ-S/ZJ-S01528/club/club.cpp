#include<bits/stdc++.h>
using namespace std;
long long k,t,n,a[20010],b[20010],c[20010],d,e,f;
int ans=0,o[20010],m;
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	for(int j=0;j<t;j++){
	cin>>n;
	k=n/2;
		for(int i=0;i<n;i++){
				cin>>a[i]>>b[i]>>c[i];
		o[j]=max(a[i],b[i]),m=max(b[i],c[i]),o[j]=max(o[j],m);
		if(o[j]==a[i])d++;
		if(o[j]==b[i])e++;
		if(o[j]==c[i])f++;
	if(abs(d-e)<=k && abs(d-f)<=k && abs(e-f)<=k){
	ans=ans+o[j];
	
	}
	else if(abs(d-e)>k || abs(d-f)>k || abs(e-f)>k &&o[j]==a[i]){
		o[j]=max(b[i],c[i]);
		if(o[j]==a[i])d++;
		if(o[j]==b[i])e++;
		if(o[j]==c[i])f++;
		if(abs(d-e)<=k && abs(d-f)<=k && abs(e-f)<=k){
	ans=ans+o[j];
	
	}	
}
	else if(abs(d-e)>k || abs(d-f)>k || abs(e-f)>k &&o[j]==b[i]){
		o[j]=max(a[i],c[i]);
		if(o[j]==a[i])d++;
		if(o[j]==b[i])e++;
		if(o[j]==c[i])f++;
		if(abs(d-e)<=k && abs(d-f)<=k && abs(e-f)<=k){
	ans=ans+o[j];
	
	}
}
	else {
		o[j]=max(a[i],c[i]);
	if(o[j]==a[i])d++;
		if(o[j]==b[i])e++;
		if(o[j]==c[i])f++;
		if(abs(d-e)<=k && abs(d-f)<=k && abs(e-f)<=k){
	ans=ans+o[j];
	
		}
	}
}

	cout<<ans<<endl;
	ans=0;
	}
	return 0;
}


