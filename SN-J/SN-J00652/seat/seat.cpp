 #include<bits/stdc++.h>
 using namespace std;
 int main(){
 	freopen("seat.in","r",stdin);
 	freopen("seat.out","w",stdout);
    int a[999][999],n,m,c,r,s[9999],t;
    cin>>n>>m;
    for(int i=0;i<n*m;i++){
    	cin>>s[i];
	}
    for(int i=0;i<n*m-1;i++){
    	for(int j=0;j<n*m-1;i++){
    		if(s[j]<s[j+1]){
    			t=s[j];
    			s[j]=s[j+i];
    			s[j+1]=t;
			}
		}
	}
	for(int i=0;i<n;i++){
		for(int j=0;i<m;i++){
			
		} 
	}
return 0;
 } 
