#include <iostream>
#include <vector>

/*
 * Problem: LeetCode 169 - Majority Element
 * 
 * Foundational Algorithmic Insights:
 * This solution implements the Boyer-Moore Majority Vote Algorithm. The algorithm 
 * works on a suffix-balancing principle: we maintain a 'candidate' and a 'count'. 
 * As we iterate, if the current element matches the candidate, we increment the count. 
 * If it differs, we decrement the count, effectively neutralizing one instance of the 
 * candidate with one instance of a non-candidate. Because the true majority element 
 * appears more than floor(n / 2) times, it will mathematically dominate the 
 * cancellation process and remain as the final candidate standing.
 *
 * Complexity Analysis:
 * - Time Complexity: O(n)
 *   We perform a single pass through the input array of size n, executing constant-time 
 *   O(1) conditional checks at each step.
 * - Space Complexity: O(1)
 *   The algorithm only allocates two primitive integer variables ('candidate' and 
 *   'count'), requiring no additional or scaled heap memory.
 */

class Solution
{
public:
    int majorityElement(const std::vector<int>& nums)
    {
        int candidate = 0;
        int count = 0;

        for (const int num : nums)
        {
            if (count == 0)
            {
                candidate = num;
                count = 1;
            }
            else if (num == candidate) 
            {
                count++;
            }
            else
            {
                count--;
            }
        }
        return candidate;
    }
};

int main()
{
    std::vector<int> nums = {2,2,1,1,1,2,2};
    Solution sol;
    std::cout << "The majority element is: " << sol.majorityElement(nums) << std::endl;
    return 0;
}


/*
**Boyer-Moore Voting Algorithm
The Boyer-Moore algorithm is an elegant streaming protocol designed
to find a majority element in a single pass using constant space.
It treats the problem as a series of political proxy battles:
whenever two different elements pair up, they eliminate each other's voting power.
Because the majority choice possesses more than 50% of the total voting power,
it is mathematically impossible for minority elements to gather enough combined strength to
eliminate all instances of the majority element.

**Misra-Gries Elephant Finder AlgorithmThe Misra-Gries algorithm is a direct, generalized extension of Boyer-Moore
used in heavy-hitter and data-streaming applications (often called "Elephant Finding" because
it looks for the massive elements dominating a data stream).
While Boyer-Moore is hardcoded to find an element appearing more than \(1/2\) of the time using 1 counter,
Misra-Gries can find all elements that appear more than \(1/k\) of the time using \(k-1\) counters.
How it works: It stores up to \(k-1\) distinct candidates in a small map/associative array.
If a new streaming element matches an existing candidate, its specific counter increments.
If the map has open space, the new element is added with a count of 1.
If the map is full and a brand new element arrives, all \(k-1\) counters are decremented by 1.
Any candidate whose counter hits 0 is evicted.
The Parallel: Just like Boyer-Moore cancels out 2 distinct elements at a time,
Misra-Gries cancels out \(k\) distinct elements at a time.
It reduces the problem from tracking millions of unique IDs to tracking a tiny, constant fraction of key-value pairs.
*/