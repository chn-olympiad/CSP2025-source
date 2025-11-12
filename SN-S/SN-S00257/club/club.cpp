#include<bits/stdc++.h>
using namespace std;
struct my{
	int m1;
	int m2;
	int m3;
};
my a[100005];
int cm1,cm2,cm3;
		int b[100005];
		int c[100005];
		int c2[100005];
int main(){
	freopen(".in","r",stdin);
	freopen(".out","w",stdout);
	
	int t,n;
	cin>>t;
	for(int k=0;k<t;k++){
		cin>>n;
		int cnt=0;
//		vector<int> b;

//		vector<int> c;
//		vector<int> c2;
		for(int i=1;i<=n;i++){
			cin>>a[i].m1>>a[i].m2>>a[i].m3;
//cout<<"9678";			
			if(a[i].m1>=a[i].m2&&a[i].m1>=a[i].m3) c[i]=a[i].m1;
			else if(a[i].m2>=a[i].m1&&a[i].m2>=a[i].m3) c[i]=a[i].m2;
			else c[i]=a[i].m3;
//cout<<"1145814";
			if(a[i].m1>a[i].m2&&a[i].m1>a[i].m3) b[i]=1;
			else if(a[i].m2>a[i].m1&&a[i].m2>a[i].m3) b[i]=2;
			else b[i]=3;
			
			if(a[i].m1>=a[i].m2&&a[i].m2>=a[i].m3||a[i].m3>=a[i].m2&&a[i].m2>=a[i].m1) c2[i]=a[i].m2;
			else if(a[i].m2>=a[i].m1&&a[i].m1>=a[i].m3||a[i].m3>=a[i].m1&&a[i].m1>=a[i].m2) c2[i]=a[i].m1;
			else c2[i]=a[i].m3;
		}
		for(int i=1;i<=n;i++){
			if(b[i]==1){
				cm1++;
			}else if(b[i]==2) cm2++;
			else cm3++;
		}
		if(cm1<=n/2&&cm2<=n/2&&cm3<=n/2){
			for(int i=1;i<=n;i++){
				cnt+=c[i];
			}
			cout<<cnt<<endl;
			continue;
		}
		if(cm1>n/2){
			int p=0;
			for(int i=1;i<=n;i++){
				cnt+=c[i];
			}
			int ch[100005];
		//	for(int i=1;i<=n;i++){
//				int j=1;
//				if(b[i]==2){
//					ch[j]=i;
//					j++;
//				}
				
				for(int j=1;j<=n;j++){
					
					
					if(b[j]==1){
					ch[p]=j;
					p++;
				}
		//		cout<<"875875  "<<p<<"  875785";
				}
//				for(int l=0;l<p;l++){
//					cout<<ch[l]<<"  ";
//				}
//				for(int i=1;i<=sizeof(ch);i++){
				//	if(a[ch[i]].m2+c2[ch[i+1]]<=c2[ch[i]]+c[ch[i+1]]){
				
//					if(c[ch[i]]+c2[ch[i+1]]<=c2[ch[i]]+c[ch[i+1]]){
//					
//					//	cnt=cnt-a[ch[i]].m2+c[ch[i+1]];
//						cnt=cnt-c[ch[i]]+c2[ch[i]];
////						cm2--;
//						cout<<endl<<"jinitaimei"<<endl;

/*1
4
0 1 0
0 1 0
0 2 0
0 2 0
*/







//					}else cnt=cnt-c[ch[i+1]]+c2[ch[i+1]];
					
	//			if(cm2<=n/2) break;
			//	}
		//	}
			for(int q=0;q<p;q++){
				if(c[ch[q]]+c2[ch[q+1]]<=c2[ch[q]]+c[ch[q+1]]){
			//	if(c[ch[]])
					//	cnt=cnt-a[ch[i]].m2+c[ch[i+1]];
					
						cnt=cnt-c[ch[q]];
					//	cout<<"999 "<<cnt<<" 999";
						cnt+=c2[ch[q]];
						cm2--;
					//	cout<<"999 "<<cnt<<" 999";
				//		cout<<endl<<"jinitaimei"<<endl;
				}//else cnt=cnt-c[ch[q+1]]+c2[ch[q+1]];
				if(cm2<=n/2) break;
			}
			cout<<cnt<<endl;
			continue;
		}
		
		if(cm2>n/2){
			int p=0;
			for(int i=1;i<=n;i++){
				cnt+=c[i];
			}
			int ch[100005];
		//	for(int i=1;i<=n;i++){
//				int j=1;
//				if(b[i]==2){
//					ch[j]=i;
//					j++;
//				}
				
				for(int j=1;j<=n;j++){
					
					
					if(b[j]==2){
					ch[p]=j;
					p++;
				}
		//		cout<<"875875  "<<p<<"  875785";
				}
//				for(int l=0;l<p;l++){
//					cout<<ch[l]<<"  ";
//				}
//				for(int i=1;i<=sizeof(ch);i++){
				//	if(a[ch[i]].m2+c2[ch[i+1]]<=c2[ch[i]]+c[ch[i+1]]){
				
//					if(c[ch[i]]+c2[ch[i+1]]<=c2[ch[i]]+c[ch[i+1]]){
//					
//					//	cnt=cnt-a[ch[i]].m2+c[ch[i+1]];
//						cnt=cnt-c[ch[i]]+c2[ch[i]];
////						cm2--;
//						cout<<endl<<"jinitaimei"<<endl;

/*1
4
0 1 0
0 1 0
0 2 0
0 2 0
*/







//					}else cnt=cnt-c[ch[i+1]]+c2[ch[i+1]];
					
	//			if(cm2<=n/2) break;
			//	}
		//	}
			for(int q=0;q<p;q++){
				if(c[ch[q]]+c2[ch[q+1]]<=c2[ch[q]]+c[ch[q+1]]){
			//	if(c[ch[]])
					//	cnt=cnt-a[ch[i]].m2+c[ch[i+1]];
					
						cnt=cnt-c[ch[q]];
					//	cout<<"999 "<<cnt<<" 999";
						cnt+=c2[ch[q]];
						cm2--;
					//	cout<<"999 "<<cnt<<" 999";
				//		cout<<endl<<"jinitaimei"<<endl;
				}//else cnt=cnt-c[ch[q+1]]+c2[ch[q+1]];
				if(cm2<=n/2) break;
			}
			cout<<cnt<<endl;
			continue;
		}
		if(cm3>n/2){
			int p=0;
			for(int i=1;i<=n;i++){
				cnt+=c[i];
			}
			int ch[100005];
		//	for(int i=1;i<=n;i++){
//				int j=1;
//				if(b[i]==2){
//					ch[j]=i;
//					j++;
//				}
				
				for(int j=1;j<=n;j++){
					
					
					if(b[j]==3){
					ch[p]=j;
					p++;
				}
		//		cout<<"875875  "<<p<<"  875785";
				}
//				for(int l=0;l<p;l++){
//					cout<<ch[l]<<"  ";
//				}
//				for(int i=1;i<=sizeof(ch);i++){
				//	if(a[ch[i]].m2+c2[ch[i+1]]<=c2[ch[i]]+c[ch[i+1]]){
				
//					if(c[ch[i]]+c2[ch[i+1]]<=c2[ch[i]]+c[ch[i+1]]){
//					
//					//	cnt=cnt-a[ch[i]].m2+c[ch[i+1]];
//						cnt=cnt-c[ch[i]]+c2[ch[i]];
////						cm2--;
//						cout<<endl<<"jinitaimei"<<endl;

/*1
4
0 1 0
0 1 0
0 2 0
0 2 0
*/







//					}else cnt=cnt-c[ch[i+1]]+c2[ch[i+1]];
					
	//			if(cm2<=n/2) break;
			//	}
		//	}
			for(int q=0;q<p;q++){
				if(c[ch[q]]+c2[ch[q+1]]<=c2[ch[q]]+c[ch[q+1]]){
			//	if(c[ch[]])
					//	cnt=cnt-a[ch[i]].m2+c[ch[i+1]];
					
						cnt=cnt-c[ch[q]];
					//	cout<<"999 "<<cnt<<" 999";
						cnt+=c2[ch[q]];
						cm2--;
					//	cout<<"999 "<<cnt<<" 999";
				//		cout<<endl<<"jinitaimei"<<endl;
				}//else cnt=cnt-c[ch[q+1]]+c2[ch[q+1]];
				if(cm2<=n/2) break;
			}
			cout<<cnt<<endl;
			continue;
			continue;
		}
		

		
		
	
	}
	return 0;
} 
