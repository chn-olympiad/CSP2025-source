#include<bits/stdc++.h>

using namespace std;
int a[1000010];
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
    int tmp=0;
    int n=0;
    cin >> n;
//    cout << sizeof(n) << endl;
    int temp = 10;
    int size =0;
    int i=0;
    while(n != 0){
    	a[i] = n % temp;
    	n /= 10;
//    	clog << "term "  << i << "  " << "=" << " " << a[i] << endl;
//    	clog << "n= " << n << endl;
    	i++;
    	size ++;
	}
//	cout << size << endl;
	for(int i=0; i<size; i++){
		for(int j=i+1; j<size; j++){
			if(a[i] < a[j]){
//				clog << "i=" << i << "    " << "j=" << j << "    " << a[i] << "and" << a[j] << endl;
				tmp = a[i];
				a[i] = a[j];
				a[j] = tmp;
//				clog << "result:" << endl;
//				for(int i=0; i<size; i++){
//					clog << a[i];
//				}
//				clog << endl;
			}else{
//				clog << "i=" << i << "    " << "j=" << j << "    " << "no swap  " <<a[i]<< "and" << a[j] << endl;
//				clog << "result:" << endl;
//				for(int i=0; i<size; i++){
//					clog << a[i];
//				}
//				clog << endl;
			    continue;
			}
		}
//		clog << "test" << i << " : " << a[i] << endl;
	}
	for(int i=0; i<size; i++){
		cout << a[i];
	}
	return 0;
}
