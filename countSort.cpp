#include <iostream>
#include <vector>


/** The main function that sort the given vector in  
descending order 

A : vector of integers
k : maximum value in a vector A

*/

std::vector<int> countSortDesc(std::vector<int> A, int k)  
{  
    // C : vector of length k + 1 of zeroes
    // R : vector of length A of zeroes
    std::vector<int> C (k+1, 0);
    std::vector<int> R (A.size(),0);
    // pos : variable indicating a position in vector R
    int pos = 0;

    // updates vector C with counting the number of times every number appears
    // in vector A
    for(int j = 0; j <= A.size(); j++)
    {
        C[A[j]] = C[A[j]] + 1;
    }

    // updates vector R with final sorted numbers
    for(int i = k; i >= 0; --i)
    {
        int r = 0;
        for(r = pos; r < pos + C[i]; r++)
        {
            R[r] = i;
        }
        pos = r;
    }

    return R;
}


int main(){
    std::vector <int> vect {0,2,7,4,0,3};
    std::vector<int> result;
    for (auto i: countSortDesc(vect, 7))
        std::cout << i << ' ';

    return 0;
}
