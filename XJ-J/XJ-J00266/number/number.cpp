#include<iostream>
using namespace std;
int main()
{
  string s;
  int a[100],n;
  for(int i=1;i<=s.length();i++){
  	
  }
  if(a[i]==s.length()){
  	cout<<a[i];
  }
  else
  {
  	return 0;
  }
  for(int i=1;i<=n;i++){
  	cin>>a[i];
	if(a[i]<a[i+1]){
   		int t=a[i];
   		a[i]=a[i+1];
   		a[i+1]=t;
	   }
	   cout<<a[i]<<" ";
}

	return 0;
}
