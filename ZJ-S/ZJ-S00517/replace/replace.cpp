#include<bits/stdc++.h>
#define int long long
using namespace std;
string s1[100100],s2[100100],str1,str2;
int n,i,ans,len,t,w,len1,len2,j,q,tt;
signed main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	scanf("%lld%lld",&n,&q);getchar();
	for (i=1;i<=n;i++){
		cin>>s1[i]>>s2[i];getchar();
	}
	while (q--){
		ans=0;
		cin>>str1>>str2;
		len=str1.size();
		for (i=0;i<len;i++)
		  if (str1[i]!=str2[i]) {
		  	tt=i;
		  	break;
		  }
		for (i=len-1;i>=0;i--)
		  if (str1[i]!=str2[i]) {
		  	w=i;
		  	break;
		  }
	  for (i=1;i<=n;i++){
	  	if (s1[i].size()<(w-tt+1)) continue;
	  	len1=str1.size();len2=s1[i].size();
	  	t=0;
	  	for (j=0;j<len1;j++){
//	  	cout<<j<<' '<<endl;
	  		if (s1[i][t]==str1[j]&&s2[i][t]==str2[j]) {
	  			t+=1;
	  			if (t==len2) {
	  				ans++;
	  				break;
				  }
			  }
			  else {
			  //	cout<<j<<' '<<t<<endl;
			  	j=j-t;
			  	t=0;
			  }
		  }
	 }
	  printf("%lld\n",ans);
	}
}