#include <iostream>
using namespace std;

class Solution{
public:

	long long maxProduct(int *arr, int n) {

	    long long max = INT_MIN, start = 0, temp = 1;
	    for(int i=0; i<n; i++)
	    {
	        if(arr[i] == 0)
	        {
	            if(temp<0)
	            {
	                while(temp<0 && start<i)
	                {
	                    temp = temp/arr[start];
	                    start++;
	                }
	            }
	            if(start == i)
	                temp = 0;
	                
	            start = i+1;
	            if(temp > max)
	                max = temp;
	                
	            temp = 1;
	            continue;
	        }
	        
	        temp = arr[i] * temp;
	        
	        if(temp > max)
	            max = temp;
	    }
	    
	    if(temp<0)
	    {
	        while(temp<0 && start<n)
	        {
	            temp = temp/arr[start];
	            start++;
	        }
	    }
	    if(start != n)
	        return temp>max?temp:max;
	        
	    return max;
	}
};

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, i;
        cin >> n;
        int arr[n];
        for (i = 0; i < n; i++) {
            cin >> arr[i];
        }
        Solution ob;
        auto ans = ob.maxProduct(arr, n);
        cout << ans << "\n";
    }
    return 0;
}