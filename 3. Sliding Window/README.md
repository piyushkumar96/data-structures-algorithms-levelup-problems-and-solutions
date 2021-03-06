# Sliding Window
1. Sub Array Sum Problem.
   <br /> [Question](/3.%20Sliding%20Window/docs/1.SlidingWindow-Question1.jpg)
   <br /> [Solution](/3.%20Sliding%20Window/1.question1-solution.cpp)
   <br />

   | Method | TimeComplexity | SpaceComplexity | Source |
      |---|---|---|---|
   | Brute Force  | O(N^3) | O(1) |
   | Prefix SumArray | O(N^2)  | O(N) |
   | Prefix SumArray + Binary Search | O(Nlog(N))  | O(N) |
   | Sliding Window | O(N) | O(1) | [Link](/3.%20Sliding%20Window/1.question1-solution.cpp) |

2. Longest Unique SubSequence String Problem.
   <br /> [Question](/3.%20Sliding%20Window/docs/2.SlidingWindow-Question2.jpg)
   <br /> [Solution](/3.%20Sliding%20Window/2.question2-solution.cpp)
   <br />

   | Method | TimeComplexity | SpaceComplexity | Source | 
      |---|---|---|---|
   | Brute Force  | O(N^3) | O(1) | [Link](https://www.geeksforgeeks.org/length-of-the-longest-substring-without-repeating-characters/) |
   | Sliding Window | O(N^2) | O(1) | [Link](https://www.geeksforgeeks.org/length-of-the-longest-substring-without-repeating-characters/) |
   | Sliding Window + Extra Space(lastIndex[]) | O(N)  | O(N) | [Link](/3.%20Sliding%20Window/2.question2-solution.cpp) |

3. Smallest Window String Problem.
   <br /> [Question](/3.%20Sliding%20Window/docs/3.SlidingWindow-Question3.jpg)
   <br /> [Solution](/3.%20Sliding%20Window/3.question3-solution.cpp)
   <br />

   | Method | TimeComplexity | SpaceComplexity | Source | 
      |---|---|---|---|
   | Brute Force | O(N^3) | O(1) | [Link](https://www.geeksforgeeks.org/find-the-smallest-window-in-a-string-containing-all-characters-of-another-string/) |
   | Sliding Window | O(N) | O(1) | [Link](/3.%20Sliding%20Window/3.question3-solution.cpp) |

4. Sliding Window Maximum Problem.
   <br /> [Question](/3.%20Sliding%20Window/docs/4.SlidingWindow-Question4.jpg)
   <br /> [Solution](/3.%20Sliding%20Window/4.question4-solution.cpp)
   <br />

   | Method | TimeComplexity | SpaceComplexity | Source | 
      |---|---|---|---|
   | Brute Force | O(N*K) | O(1) | [Link](https://www.geeksforgeeks.org/sliding-window-maximum-maximum-of-all-subarrays-of-size-k/) |
   | Sliding Window | O(N*K) | O(1) | [Link](/3.%20Sliding%20Window/4.question4-solution.cpp) |
   | Self Balancing BST | O(N*LogK)  | O(K) | [Link](https://www.geeksforgeeks.org/sliding-window-maximum-maximum-of-all-subarrays-of-size-k/) |
   | Deque| O(N)  | O(K) | [Link](https://www.geeksforgeeks.org/sliding-window-maximum-maximum-of-all-subarrays-of-size-k/) |

5. Count SubArray with Target Sum Problem.
   <br /> [Question](/3.%20Sliding%20Window/docs/5.SlidingWindow-Question5.jpg)
   <br /> [Solution](/3.%20Sliding%20Window/5.question5-solution.cpp)
   <br />

   | Method | TimeComplexity | SpaceComplexity | Source | 
   |---|---|---|---|
   | Brute Force | O(N^2) | O(1) | [Link](https://www.geeksforgeeks.org/number-subarrays-sum-exactly-equal-k/) |
   | Sliding Window | O(N) | O(N) | [Link](/3.%20Sliding%20Window/5.question5-solution.cpp) |
