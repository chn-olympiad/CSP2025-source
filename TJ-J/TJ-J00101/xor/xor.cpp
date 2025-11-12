#include <bits/stdc++.h>
using namespace std;
const int MAXN=1e3+99;
int a[MAXN];
//int want[MAXN];
//int t1[MAXN];
//int b[MAXN][MAXN];
//int caled[MAXN];
//int pass[MAXN];
//long long idx1=0; 
//int to21(int num){
//	memset(t1,0,sizeof(t1));
//	idx1=0;
//	if(num==0){
//	    idx1=1;
//	    memset(t1,0,sizeof(t1));
//	} 
//	while(num>0){
//		idx1++;
//		t1[idx1]=num%2;
//		num/=2;
//	}
//	return 0;
//}
//int cal(){
//	int n=max(idx1,idx2);
//	for(int i=1;i<=n;i++){
//		if(t1[i]==t2[i]){
//			caled[i]=1;
//		}else{
//			caled[i]=0;
//		}
//	}
//}
//bool check(){
//	bool d=true;
//	for(int i=1;i<=max(w_idx,idx1);i++){
//		if(want[i]!=caled[i]){
//			d=false;
//		}
//	} 
//	if(d){
//		ans++;
//		return true;
//	}
//	return false;
//}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	long long n,k,ans=0;
	cin>>n>>k;
   	for(int i=1;i<=n;i++){
   		cin>>a[i];
    }
    bool allone=true;
    for(int i=1;i<=n;i++){
    	if(a[i]!=1){
    		allone=false;
		}
	}
    if(k==0&&allone){
    	cout<<n/3<<endl;
    	return 0;
	}
	if(k==0&&!allone){
		for(int i=1;i<=n;i++){
			if(a[i]==0){
				ans++;
			}
			if(a[i]==1&&a[i+1]==1&&a[i+2]==1){
				ans++;
				i+=3;
			}
		}
	}
	cout<<ans<<endl; 
//    for(int i=1;i<=n;i++){
//    	to21(a[i]);
//    	for(int j=1;j<=idx1;j++){
//    		b[i][j]=t1[j];
//		}
//	}
////	for(int i=1;i<=n;i++){
////		for(int j=1;j<=n;j++){
////			cout<<b[i][j];
////		}
////		cout<<endl;
////	}
//    to21(k);
//    for(int i=1;i<=idx1;i++){
//    	want[i]=t1[i];
//	}
//	long long w_idx=idx1;
//	memset(t1,0,sizeof(t1));
//	idx1=0;
//	for(int i=1;i<=n;i++){//==k pass[i]=1;
//		bool d=true;
//		to21(a[i]);
//		for(int i=1;i<=max(w_idx,idx1);i++){
//			if(want[i]!=t1[i]){
//				d=false;
//			}
//		} 
//		if(d){
//			pass[i]=1;
//		}
//		cout<<endl;
//	}
//	for(int i=1;i<=n;i++){
//		int len=2;
//		len++;
//		for(int j=1;j<=len;j++){
//			int cnt=0;
//			if(cnt==len){
//				
//			}
//			if(!pass[i]){
//				cnt++;
//			}else if()
//		}
//	} 
////	cout<<ans<<endl;
	return 0;
}

/*
4 2
2 1 0 3
*/
