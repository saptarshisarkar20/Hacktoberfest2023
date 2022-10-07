# Minimum Dual Area
Problem Code: DAREA
## Problem Link:  https://www.codechef.com/JUNE21B/problems/DAREA
## What to Do:
 - Go to folder: "./CP/CodeChef/DAREA"
 - Take your GitHUB username id like "hrithik339", "hacker-boy", etc or anything which you have.
 - File extension = ".cpp" in this issue.
## Problem:
Given N points in a 2D space, find the minimum sum of areas of rectangles required to cover all the points given that we can use at most 2 non-overlapping rectangles whose sides can touch. The rectangles must be axis-aligned, meaning the sides are vertical and horizontal.

## Input:
- The first line contains an integer T, the number of test cases. Then the test cases follow.
- Each test case contains N+1 lines of input.
- The first line contains a single integer N, the number of points.
- The next N lines each contain two integers xi, yi, the coordinates of the i-th point.
#### Note:  Points need not be distinct.

## Output
- For each test case, output in a single line the answer to the problem.

## Constraints
 - 1≤T≤105
 - 1≤N≤105
 - 0≤xi,yi≤109
 - The sum of N over all test cases is at most 105.

## Sample Input 1 :
```
3
1
100 100
4
1 100
100 100
100 1
1 1
5
1 100
100 100
100 1
1 1
50 50
```
## Sample Output 1 :
```
0
0
4851
```

## Explanation : 
 - Case 1: Since there is only one point, the minimum area of a rectangle to cover this point is 0.
 - Case 2: We can have rectangles as 2 opposite sides of the square. Since the width of the rectangles is 0, the total area is also 0.
 ![image](https://user-images.githubusercontent.com/64575577/135620742-930afa64-bd0f-470e-8f7d-1739b29d51c9.png)
 - Case 3: The optimal solution is with the rectangles having endpoints {(1,1),(100,1),(1,50),(100,50)} and {(1,100),(1,100),(100,100),(100,100)}. Therefore the total area is 49⋅99+0⋅99=4851
![image](https://user-images.githubusercontent.com/64575577/135620800-176b5941-b4ad-4dc8-91c5-b59bed4df2f1.png)