#include <iostream>
#include <stack>

/*
================================================================================
LEETCODE 232: IMPLEMENT QUEUE USING STACKS
================================================================================
  
1. THE CORE CONCEPT & PROBLEM CONSTRAINTS
--------------------------------------------------------------------------------
* Goal: Build a FIFO (Queue) behavior out of two LIFO (Stack) structures.
* Core Mechanism: Pouring elements from one stack to another *reverses* their 
  order. Reversing a LIFO structure naturally yields a FIFO sequence.
* Architecture:
  - Stack 1 (`s1`): Input holding pen. All new elements are lazily pushed here.
  - Stack 2 (`s2`): Output channel. Ready-to-read elements sit here in FIFO order.

2. LOGICAL SNARES & HISTORICAL MISTAKES (WHAT TO WATCH OUT FOR)
--------------------------------------------------------------------------------
* Unconditional Pouring (The Mixing Bug): 
  - Mistake: Pouring `s1` into `s2` on *every* pop/peek operation.
  - Consequence: New items land on top of older items already in `s2`, 
    shattering the FIFO order.
  - Fix: Only shift elements from `s1` to `s2` when `s2` is *completely empty*.
* State Persistence Failures:
  - Mistake: Using a copy (`s2 = s1`) instead of shifting (`s1.pop()`).
  - Consequence: Elements are never truly deleted from the queue's memory state.
* The `empty()` Desync:
  - Mistake: Checking only one stack (e.g., `return s2.empty();`).
  - Consequence: Flips a false positive if elements exist in `s1` but haven't 
    been shifted to `s2` yet. The queue is only empty if *both* stacks are empty.

3. ALGORITHMIC EFFICIENCY & INTERVIEW EXPECTATIONS
--------------------------------------------------------------------------------
* Time Complexity:
  - Push: O(1) constant time.
  - Pop / Peek: Amortized O(1) constant time.
    * Concept: While a single pop operation *can* trigger an O(N) shift loop 
      when `s2` is empty, each element is pushed, shifted, and popped exactly 
      once across its lifetime. Over N operations, the total work averages out.
  - Empty: O(1) constant time.
* Space Complexity: O(N) to store the elements.

4. SENIOR-LEVEL CODE CLEANLINESS & MODERN C++ TIPS
--------------------------------------------------------------------------------
* Streamlined Loops: A simple `while (!s1.empty())` is completely sufficient 
  to drain a stack. Do not track dynamic sizes with nested `for` loops.
* Encapsulation: Keep the shifting logic in a zero-argument private helper 
  function since member variables are already directly accessible.
* Ownership Optimization: Use `std::move(s1.top())` when pushing to `s2`. This 
  avoids deep-copying heavy objects in memory and transfers data seamlessly.
================================================================================
*/

class MyQueue
{
private:
    std::stack<int> s1;
    std::stack<int> s2;

    void shiftStacks()
    {
        if (s2.empty())
        {
            while (!s1.empty())
            {
                s2.push(std::move(s1.top()));
                s1.pop();
            }
        }
    }
public:
    MyQueue() {
        
    }
    
    void push(int x) {
        s1.push(std::move(x));
    }
    
    int pop() {
        shiftStacks();
        int dummy = s2.top();
        s2.pop();
        return dummy;
    }
    
    int peek() {
        shiftStacks();
        return s2.top();
    }
    
    bool empty() {
        return s1.empty() && s2.empty();
    }
};

/**
 * Your MyQueue object will be instantiated and called as such:
 * MyQueue* obj = new MyQueue();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->peek();
 * bool param_4 = obj->empty();
 */

int main()
{
    MyQueue myQueue;
    myQueue.push(1);
    myQueue.push(2);
    myQueue.peek();
    myQueue.pop();
    std::cout << ( myQueue.empty() ? "The queue is empty!\n" : "The queue is Not empty!\n");
    return 0;
}