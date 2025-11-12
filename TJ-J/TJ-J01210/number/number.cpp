#include<bits/stdc++.h>
using namespace std;
//	freopen("number.in","r",stdin);
//	freopen("number.out","w",stdout);
int main(){

	string s;
	int ans;
	cin>>s;
	
 	  for(int i=1;i<=s.length;i++){

 	  if(i<'1'||i>'9'){
	  i+=1;
	}
  else{
  	ans++;
		}
	}	
		
	for(int j=0;j<ans.length;j++){
	
	if(ans[j][i]<ans[j+1][i+1]){
		ans[j+1][i+1]=ans[j][i];
	else
	ans[j][i]++;
	}
	
	}
	cout<<ans<<endl;
	return 0;
}
