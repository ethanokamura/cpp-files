#include <iostream>
#include <deque> 
using namespace std;

void printKMax(int arr[], int n, int k){
    // n is the number of elements
    // k is the size of sub array
    int right {k};
    int left {0};
    while (right <= n) {
        int max = arr[left];
        for (int i = left; i < right; i++) {
            if (arr[i] > max) max = arr[i];
        }
        cout << max << ' ';
        right++;
        left++;
    }
    cout << '\n';
}

int main(){
  
	int t;
	cin >> t;
	while(t>0) {
		int n,k;
    	cin >> n >> k;
    	int i;
    	int arr[n];
    	for(i=0;i<n;i++)
      		cin >> arr[i];
    	printKMax(arr, n, k);
    	t--;
  	}
  	return 0;
}