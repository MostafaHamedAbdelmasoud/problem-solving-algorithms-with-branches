It is raining again! Youssef really forgot that there is a chance of rain in March, so he didn't fix the roof of his house. Youssef's roof is 1-D, and it contains n holes that make the water flow into the house, the position of hole i is denoted as xi where (0 ≤ i < n). Youssef has to put strips at the bottoms of those holes in order to prevent the water from flowing. Let's say there is a hole in position 4 and another hole in position 6, and Youssef decided to use a strip of length 3 to cover those two holes, then he places the strip from position 4 to 6 (it covers positions 4,5,6) and it covers the two holes. He can buy exactly k strips, and he must pay a price equal to the longest strip he buys. What is the minimum length l he can choose as the longest strip in order to keep his house safe?

Input
The input consists of several test cases. The first line of the input contains a single integer T, the number of the test cases. Each test case consists of two lines: the first line contains two space-separated integers, n and k (1 ≤ k < n ≤ 100000), denoting the number of the holes in the roof, and the number of the strips he can buy respectively. The second line of the test case contains n integers (x0, x1, ..., xn - 1): (0 ≤ xi ≤ 109), denoting the positions of holes (these numbers are given in an increasing order).

Output
For each test case print a single line containing a single integer denoting the minimum length l he can choose in order to buy k strips (the longest of them is of length l) and cover all the holes in his house using them.

Example
Input
3
5 2
1 2 3 4 5
7 3
1 3 8 9 10 14 17
5 3
1 2 3 4 20
Output
3
4
2


solution:


#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const int N = 1e5+1, M = 1e6+6, MOD = 98765431, OO = 0x3f3f3f3f;

int t, n, k, hole[N];

bool ok(int l){
  int nextHole = 0;
  for(int i = 0 ; i < k ; ++i){
    nextHole = upper_bound(hole, hole+n, hole[nextHole]+l-1)-hole;
    if(nextHole == n) return 1;
  }
  return 0;
}

int binarySearch(){
  int lo = 1, hi = 2e9, mid;
  while(lo < hi){
    mid = (lo+hi)/2;
    if(ok(mid)) hi = mid;
    else  lo = mid+1;
  }
  return lo;
}

int main(){
  scanf("%d", &t);
  while(t--){
    scanf("%d %d", &n, &k);
    for(int i = 0 ; i < n ; ++i)  scanf("%d", hole+i);
    printf("%d\n", binarySearch());
  }
  return 0;
}


/*
*/
