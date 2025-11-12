#ifndef _GLIBCXX_NO_ASSERT
#include <cassert>
#endif
#include <cctype>
#include <cerrno>
#include <cfloat>
#include <ciso646>
#include <climits>
#include <clocale>
#include <cmath>
#include <csetjmp>
#include <csignal>
#include <cstdarg>
#include <cstddef>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <ctime>
#if __cplusplus >= 201103L
#include <ccomplex>
#include <cfenv>
#include <cinttypes>
#include <cstdalign>
#include <cstdbool>
#include <cstdint>
#include <ctgmath>
#include <cwchar>
#include <cwctype>
#endif
#include <algorithm>
#include <bitset>
#include <complex>
#include <deque>
#include <exception>
#include <fstream>
#include <functional>
#include <iomanip>
#include <ios>
#include <iosfwd>
#include <iostream>
#include <istream>
#include <iterator>
#include <limits>
#include <list>
#include <locale>
#include <map>
#include <memory>
#include <new>
#include <numeric>
#include <ostream>
#include <queue>
#include <set>
#include <sstream>
#include <stack>
#include <stdexcept>
#include <streambuf>
#include <string>
#include <typeinfo>
#include <utility>
#include <valarray>
#include <vector>
#if __cplusplus >= 201103L
#include <array>
#include <atomic>
#include <chrono>
#include <condition_variable>
#include <forward_list>
#include <future>
#include <initializer_list>
#include <mutex>
#include <random>
#include <ratio>
#include <regex>
#include <scoped_allocator>
#include <system_error>
#include <thread>
#include <tuple>
#include <typeindex>
#include <type_traits>
#include <unordered_map>
#include <unordered_set>
#endif
#include<bits/stdc++.h>//火车头 
using namespace std;
int a[100050];
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	int ans=0,s=0,n;
	cin>>n;
	if(n<3){
		cout<<"0";
		return 0;
	}
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=1;i<=n;i++){
		if(a[i]==0 || a[1]+a[2]<=a[3] || a[2]+a[3]<=a[1] || a[3]+a[1]<=a[2]){
			cout<<"0";
			return 0;
		}
	}
	cout<<"3";
	return 0;
}


/*
10:43
距离考试结束还剩一个半小时，来写下退役感言
考试难度还可以，T1应该能打满，T2大概率也没什么大问题，T3，T4骗分
我小学5年级开始学信奥，现在已经快3年了
我学信奥的初衷是因为能玩你电脑 ，所以我成绩也不怎么样，考试成绩平平，洛谷估值最高时也才绿名
随着我身边的人一个个退役或报送，我对信奥的热情也渐渐淡去
我曾想过靠文化课，但以我中游的水准估计不太行 
说白了这是我第一次进入复赛 
考完就该原地退役，尘埃落定
如果我再选一次，我还会选信奥这条路吗？


会的。
就当增加人生体验吧.........
剩下的时间再检查一下

11:08 K!!!!!!!T2查出重大漏洞（行列搞反）

11:24成功修复 

11:26纠结要不要玩谷歌小恐龙  

11:34 T1,t2打满，求求了


	———————— —————— 
   |							| 
   ———————     ————— 
   		  	   |	 | 
		 	  |		| 						 
		 	 |	   | 					   
		    |	  | 					 
		   |	 | 
		  |		| 
	———		————		
	|				  |
	————————— 
	
	O
	
		———————— —————— 
   |							| 
   ———————     ————— 
   		  	   |	 | 
		 	  |		| 						 
		 	 |	   | 					   
		    |	  | 					 
		   |	 | 
		  |		| 
	———		————
	|				  |
	————————— 
		   
*/ 
