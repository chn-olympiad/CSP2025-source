#include<bits/stdc++.h>
using namespace std;
int t;
int n,a[3][100005],mi[100005],mi1[100005],mi2[100005];
bool bj1(int x,int y){
	return (a[0][x]-mi[x]) < a[0][y] - mi[y];
}
bool bj2(int x,int y){
	return a[1][x] - a[2][x] < a[1][y] - a[2][y];
}
bool bj3(int x,int y){
	return (a[1][x]-mi1[x]) < a[1][y] - mi1[y];
}
bool bj4(int x,int y){
	return (a[2][x]-mi2[x]) < a[2][y] - mi2[y];
}
bool bj5(int x,int y){
	return a[2][x] - a[1][x] < a[2][y] - a[1][y];
}
bool bj6(int x,int y){
	return a[2][x] - a[0][x] < a[2][y] - a[0][y];
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	scanf("%d",&t);
	while(t--){
		int sum = 0;
		bool os1 = 0,os2 = 0;
		vector<int> v[3];
		scanf("%d",&n);
		for(int i = 0;i < n;i++){
			scanf("%d%d%d",&a[0][i],&a[1][i],&a[2][i]);
			mi[i] = max(a[1][i],a[2][i]);
			mi1[i] = max(a[0][i],a[2][i]);
			mi2[i] = max(a[1][i],a[0][i]);
			//cout<<a[0][i]<<' '<<a[1][i]<<' '<<a[2][i]<<' '<<mi[i]<<endl;
			if(a[0][i] < a[1][i]){
				if(a[1][i]<a[2][i]){
					v[2].push_back(i);
					sum+=a[2][i];
				}
				else{
					v[1].push_back(i);
					sum+=a[1][i];
				}
			}else if(a[0][i] < a[2][i]){
				v[2].push_back(i);
				sum+=a[2][i];
			}else{
				v[0].push_back(i);
				sum+=a[0][i];
			}
		}
		//cout<<v[2].size()<<' '<<n/2<<' ';
		if(v[0].size()>n/2){
			//cout<<"(";
			os1 = 1;
			sort(v[0].begin(),v[0].end(),bj1);
			for(int i = 0;i < v[0].size()-n/2;i++){
				//cout<<v[0][i]<<endl;
				if(a[1][v[0][i]]>a[2][v[0][i]]){
					sum = sum - a[0][v[0][i]] + a[1][v[0][i]];
					v[1].push_back(v[0][i]);	
				}
				else {
					sum = sum - a[0][v[0][i]] + a[2][v[0][i]];
					v[2].push_back(v[0][i]);
				}
			}
		}
		if(v[1].size()>n/2){
			os2 = 1;
			if(os1){
				sort(v[1].begin(),v[1].end(),bj2);
				for(int i = 0;i < v[1].size()-n/2;i++){
					sum = sum - a[1][v[1][i]] + a[2][v[1][i]];
				}
			}else{
				sort(v[1].begin(),v[1].end(),bj3);
				for(int i = 0;i < v[1].size()-n/2;i++){
					if(a[0][v[1][i]]>a[2][v[1][i]]&&v[0].size()<n/2){
						sum = sum - a[1][v[1][i]] + a[0][v[1][i]];
						v[0].push_back(v[1][i]);	
					}
					else {
						sum = sum - a[1][v[1][i]] + a[2][v[1][i]];
						v[2].push_back(v[1][i]);
					}
				}
			}
		}
		if(v[2].size()>n/2){
			if(os1){
				sort(v[2].begin(),v[2].end(),bj5);
				for(int i = 0;i < v[2].size()-n/2;i++){
					sum = sum - a[2][v[2][i]] + a[1][v[2][i]];
				}
			}else if(os2){
//				cout<<")";
				sort(v[2].begin(),v[2].end(),bj6);
				for(int i = 0;i < v[2].size()-n/2;i++){
					sum = sum - a[2][v[2][i]] + a[0][v[2][i]];
				}
			}else{
				sort(v[2].begin(),v[2].end(),bj4);
				for(int i = 0;i < v[2].size()-n/2;i++){
					if(a[0][v[2][i]]>a[1][v[2][i]]&&v[0].size()<n/2){
						sum = sum - a[2][v[2][i]] + a[0][v[2][i]];
						v[0].push_back(v[2][i]);	
					}
					else {
						sum = sum - a[2][v[2][i]] + a[1][v[2][i]];
						v[1].push_back(v[2][i]);
					}
				}
			}
		}
//		for(int i = 0;i < v[0].size();i++){
//			printf("%d ",v[0][i]);
//		}
//		printf("\n");
//		for(int i = 0;i < v[1].size();i++){
//			printf("%d ",v[1][i]);
//		}
//		printf("\n");
//		for(int i = 0;i < v[2].size();i++){
//			printf("%d ",v[2][i]);
//		}
//		printf("\n");
		printf("%d\n",sum);
	}
	return 0;
}
