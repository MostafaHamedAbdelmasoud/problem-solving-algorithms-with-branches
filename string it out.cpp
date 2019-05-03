

Let A and B be two strings made up of alphabets such that A = A[1-n], B = B[1-m]. We say B is a subsequence of A if there exists a sequence of indices i1 < i2 <.. m of A such that A[ik] = B[k].
Given B[1-m], a string of characters from some alphabets, B^i is defined as string with the characters of B each repeating i times. For example, (abbacc)^3 = aaabbbbbbaaacccccc. Also, B^0 is the empty string.

Given strings X, Y made up of characters from 'a' - 'z' find the maximum value of M such that X^M is a subsequence of Y.

Input
The first line of the input contains a positive integer t <= 20, denoting the no. of test cases.
The following 2t lines contain the value of X and Y for the cases.
The description of the test cases follow one after the other.
Line 2k contains the value of X for case k; (1 <= k <= t)
Line 2k+1 contains the value of Y for case k; (1 <= k <= t).
The no. of characters in X , Y will be <= 500010.
Output
The output must contain t lines, each line corresponding to a test case. The value on the kth line should be the value of M for the kth pair of X and Y.

Example
Input: 
3 
abc 
aabbcc 
abc 
bbccc 
abcdef 
abc

Output: 
2 
0 
0







solution:


#include <stdio.h>
#include <string.h>
#include <unordered_map>
#include <map>
#include <algorithm>

using namespace std;

typedef long long ll;

const int N = 5e5+5, M = 1e6+6, MOD = 1e9+7, OO = 0x3f3f3f3f;

char X[N], Y[N];
int n, m;

bool ok(int p){
  int j = 0;
  for(int i = 0 ; i < n ; ++i){
    int matched = 0;
    for( ; j < m && matched < p ; ++j){
      if(X[i] == Y[j])  ++matched;
    }
    if(matched < p)  return 0;      //string 2 ended
  }
  return 1;
}

int binarySearch(){
  int lo = 0, mid, hi = 5e5+1;
  while(lo < hi){
    mid = (lo+hi+1)/2;
    if(ok(mid)) lo = mid;
    else  hi = mid-1;
  }
  return lo;
}

int t;

int main(){
  scanf("%d", &t);
  while(t--){
    scanf("%s %s", X, Y);
    n = strlen(X);
    m = strlen(Y);
    printf("%d\n", binarySearch());
  }
  return 0;
}



